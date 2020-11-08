#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include <gtk/gtk.h>

#include "Timer/timer.h"

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

void on_enter_pushed(){
	const char* time = gtk_entry_get_text(entry);
	if(is_valid_input(time)){
		gtk_label_set_text(timer, time);
	}else{
		gtk_label_set_text(timer, "Sorry that input isn't valid.");
	}
}

void pause_clicked(){
	return;
}