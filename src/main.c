#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include <gtk/gtk.h>
#include <pthread.h>

#include "Timer/timer.h"
#include "Statistics/stats.h"

static GtkEntry* entry;
static GtkLabel* timer;
static GtkButton* stats;

int main(int argc, char *argv[])
{
    GtkBuilder  *builder; 
    GtkWidget   *window;

    gtk_init(&argc, &argv);

    builder = gtk_builder_new_from_file("glade/window_main.glade");

    window = GTK_WIDGET(gtk_builder_get_object(builder, "window_main"));
    gtk_builder_connect_signals(builder, NULL);


    /*	Initialize Widgits */
    entry = GTK_ENTRY(gtk_builder_get_object(builder, "entry"));
    timer = GTK_LABEL(gtk_builder_get_object(builder, "timer"));
    stats = GTK_BUTTON(gtk_builder_get_object(builder, "stats"));


    g_object_unref(builder);

    gtk_widget_show(window);                
    gtk_main();

    return 0;
}

// called when window is closed
void on_window_main_destroy()
{
    gtk_main_quit();
}

bool is_valid_input(const char* input){
	for(int i=0; i<strlen(input); i++){
		if(input[i]<'0' || input[i]>'9'){
			return false;
		}
	}
	if(atoi(input) < 1) return false;
	return true;
}

static gboolean count_timer(void* args){
    gchar *text = g_strdup_printf ("%d:%d", Timer_get()/60, Timer_get()%60);
    gtk_label_set_label(timer, text);
    g_free(text);
    if(Timer_isOver()){
        return G_SOURCE_REMOVE;
    }
    return G_SOURCE_CONTINUE;
}


void on_enter_pushed(){
	const char* time = gtk_entry_get_text(entry);
	if(is_valid_input(time)){
        Stats_add_new_session_length_in_minutes(atoi(time));
        Timer_start(atoi(time));
        //g_timeout_add (1000 /* milliseconds */, on_timeout, label);
        g_timeout_add (1000 /* milliseconds */, count_timer, timer);
	}else{
		gtk_label_set_text(timer, "Sorry that input isn't valid.");
	}
}

void open_stats(){
    GtkBuilder  *stats_builder; 
    GtkWidget   *stats_window;

    stats_builder = gtk_builder_new_from_file("glade/stats.glade");

    stats_window = GTK_WIDGET(gtk_builder_get_object(stats_builder, "stats_window"));
    gtk_builder_connect_signals(stats_builder, NULL);

    GtkLabel* total = GTK_LABEL(gtk_builder_get_object(stats_builder, "total"));
    GtkLabel* mean = GTK_LABEL(gtk_builder_get_object(stats_builder, "mean"));
    GtkLabel* recent = GTK_LABEL(gtk_builder_get_object(stats_builder, "recent"));

    char string[100];

    sprintf(string, "%ld minutes", Stats_get_total());
    gtk_label_set_text(total, string);

    sprintf(string, "%ld minutes", Stats_get_mean());
    gtk_label_set_text(mean, string);

    sprintf(string, "%ld minutes", Stats_get_recent());
    gtk_label_set_text(recent, string);


    g_object_unref(stats_builder);

    gtk_widget_show(stats_window);            
}
