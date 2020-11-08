#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include <gtk/gtk.h>
#include <time.h>
#include "Timer/timer.h"

#include "Timer/timer.h"
#include "Statistics/stats.h"

static GtkEntry* entry;
static GtkLabel* timer;
static GtkButton* stats;
static GtkButton* pauser;

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
    pauser = GTK_BUTTON(gtk_builder_get_object(builder, "pause"));


    g_object_unref(builder);

    gtk_widget_show(window);                
    gtk_main();

    clock_t start_t;
    char* display;
    start_t=clock();
    display=Timer_get(atoi(time), start_t);

    while(atoi(time)*60!=start_t){
        gtk_label_set_text(GTK_LABEL(timer),display);
    }

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

char* on_enter_pushed(){
	const char* time = gtk_entry_get_text(entry);
	if(is_valid_input(time)){
		gtk_label_set_text(timer, time);
        return time;
	}else{
		gtk_label_set_text(timer, "Sorry that input isn't valid.");
	}
}

void pause_clicked(){
	return;
}
<<<<<<< HEAD
=======

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
>>>>>>> a1a271fadaec4729fbaf96d807d879f766a81580
