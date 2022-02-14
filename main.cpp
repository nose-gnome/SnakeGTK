#include <iostream>
#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>
#include <gtkmm.h>


#include <math.h>
#include <ctype.h>
#include <App.h>
//GtkWidget *window;
GtkBuilder *builder;



int main(int argc, char *argv[]) {
//    gtk_init(&argc, &argv); // init GTK
    auto app = App::create();
    app->run(argc, argv);

//    window = GTK_WIDGET(gtk_builder_get_object(builder, "Main Menu"));
//    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
//
//    gtk_builder_connect_signals(builder, NULL);
//
//    gtk_widget_show(window);

    return 0;
}
