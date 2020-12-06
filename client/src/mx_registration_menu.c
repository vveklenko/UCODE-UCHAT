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
    log_in_menu = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    gtk_box_pack_start(GTK_BOX(registration_menu), log_in_menu, FALSE, FALSE, 0);
    gtk_widget_set_size_request(GTK_WIDGET(registration_menu), 400, 400);
    gtk_widget_set_name(GTK_WIDGET(registration_menu), "registration_menu_form");
    gtk_fixed_put(GTK_FIXED(black_background), registration_menu,
    CUR_WIDTH / 5 + 70, CUR_HEIGHT / 5);

    //inscription Log in
    GtkWidget *log_in = gtk_label_new("Autorization");
    gtk_box_pack_start(GTK_BOX(log_in_menu), log_in, FALSE, FALSE, 0);
    gtk_widget_set_name(GTK_WIDGET(log_in), "Autorization");

    

    login = gtk_entry_new();
    gtk_widget_set_sensitive(GTK_WIDGET(login), FALSE);
    gtk_widget_set_sensitive(GTK_WIDGET(login), TRUE);
    gtk_widget_set_name(GTK_WIDGET(login), "entry_data");
    gtk_widget_set_size_request(GTK_WIDGET(login), 400, 50);
    gtk_entry_set_placeholder_text(GTK_ENTRY(login), "Enter an username");
    gtk_box_pack_start(GTK_BOX(log_in_menu), login, FALSE, FALSE, 0);

    password = gtk_entry_new();
    gtk_widget_set_sensitive(GTK_WIDGET(password), FALSE);
    gtk_widget_set_sensitive(GTK_WIDGET(password), TRUE);
    gtk_widget_set_name(GTK_WIDGET(password), "entry_data");
    gtk_widget_set_size_request(GTK_WIDGET(password), 400, 50);
    gtk_entry_set_placeholder_text(GTK_ENTRY(password), "Enter a password");
    gtk_box_pack_start(GTK_BOX(log_in_menu), password, FALSE, FALSE, 0);
    
    login_btn = gtk_event_box_new();
    GtkWidget *login_btn_label = gtk_label_new("Log in");
    gtk_container_add(GTK_CONTAINER(login_btn), login_btn_label);

    gtk_box_pack_start(GTK_BOX(log_in_menu), login_btn, FALSE, FALSE, 30);
    gtk_widget_set_name(GTK_WIDGET(login_btn), "login_button");
    gtk_widget_set_opacity(GTK_WIDGET(login_btn), 0.5);
    gtk_widget_set_size_request(GTK_WIDGET(login_btn), 200, 50);
    gtk_widget_set_halign(GTK_WIDGET(login_btn), GTK_ALIGN_CENTER);
    g_signal_connect(G_OBJECT(login_btn), "enter-notify-event",
        G_CALLBACK(btn_enter_notify_event), NULL);
    g_signal_connect(G_OBJECT(login_btn), "leave-notify-event",
        G_CALLBACK(btn_leave_notify_event), NULL);

    g_signal_connect(G_OBJECT(password), "changed",
        G_CALLBACK(data_change_event), NULL);
    g_signal_connect(G_OBJECT(login), "changed",
        G_CALLBACK(data_change_event), NULL);

    gtk_widget_unset_state_flags(GTK_WIDGET(login_btn), GTK_STATE_FLAG_PRELIGHT);

    //link registration
    GtkWidget *registration = gtk_event_box_new();
    GtkWidget *registration_lable = gtk_label_new("Follow this link to registration");
    gtk_container_add(GTK_CONTAINER(registration), registration_lable);
    gtk_box_pack_start(GTK_BOX(log_in_menu), registration, FALSE, FALSE, 10);
    gtk_widget_set_name(GTK_WIDGET(registration), "Registration");
    g_signal_connect(G_OBJECT(registration), "enter-notify-event",
        G_CALLBACK(registration_label_enter_notify_event), registration_lable);
    g_signal_connect(G_OBJECT(registration), "leave-notify-event",
        G_CALLBACK(registration_label_leave_notify_event), registration_lable);

}
