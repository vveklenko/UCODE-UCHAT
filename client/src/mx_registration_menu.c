#include "../inc/uchat_client.h"

void mx_registration_menu() {
    //background
    back_black = gtk_event_box_new();
    GtkWidget *black_background = gtk_fixed_new();
    gtk_widget_set_name(GTK_WIDGET(back_black), "back_black");
    gtk_widget_set_state_flags(GTK_WIDGET(back_black), GTK_STATE_FLAG_NORMAL, TRUE);
    gtk_container_add(GTK_CONTAINER(back_black), black_background);
    gtk_fixed_put(GTK_FIXED(main_area), back_black, 0, 0);
    gtk_widget_set_size_request(GTK_WIDGET(black_background), CUR_WIDTH, CUR_HEIGHT);

    //registration_menu
    registration_menu = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    gtk_widget_set_size_request(GTK_WIDGET(registration_menu), 400, 400);
    gtk_widget_set_name(GTK_WIDGET(registration_menu), "registration_menu_form");
    gtk_fixed_put(GTK_FIXED(black_background), registration_menu,
    CUR_WIDTH / 5 + 70, CUR_HEIGHT / 5);


    GtkWidget *log_in = gtk_label_new("Log in");
    gtk_box_pack_start(GTK_BOX(registration_menu), log_in, FALSE, FALSE, 0);
    gtk_widget_set_name(GTK_WIDGET(log_in), "Login");

    GtkWidget *entry_username = gtk_entry_new();
    gtk_widget_set_sensitive(GTK_WIDGET(*entry_username), FALSE);
    gtk_widget_set_name(GTK_WIDGET(*entry_username), "entry_chat");
    gtk_box_pack_start(GTK_BOX(chat_container), *entry_username, TRUE, TRUE, 8);
    gtk_entry_set_placeholder_text(GTK_ENTRY(*entry_username), "Write a message...");
    g_signal_connect(G_OBJECT(*entry_username), "changed", G_CALLBACK(entry_chat_fill_event), NULL);
}
