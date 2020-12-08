#include "../../inc/uchat_client.h"

void button_shine(GtkWidget *widget, GdkEvent *event) {
    if (strlen(gtk_entry_get_text(GTK_ENTRY(password))) > 0 && strlen(gtk_entry_get_text(GTK_ENTRY(login))) > 0) {
        gtk_widget_set_opacity(GTK_WIDGET(login_btn), 1.0);
    }
    else {
         gtk_widget_set_opacity(GTK_WIDGET(login_btn), 0.5);
    }
}


void login_btn_enter_notify() {
    if (strlen(gtk_entry_get_text(GTK_ENTRY(password))) > 0 && strlen(gtk_entry_get_text(GTK_ENTRY(login))) > 0) {
        gtk_widget_set_state_flags(GTK_WIDGET(login_btn), GTK_STATE_FLAG_PRELIGHT, TRUE);
    }
}

void login_btn_leave_notify() {
    if (strlen(gtk_entry_get_text(GTK_ENTRY(password))) > 0 && strlen(gtk_entry_get_text(GTK_ENTRY(login))) > 0) {
        gtk_widget_unset_state_flags(GTK_WIDGET(login_btn), GTK_STATE_FLAG_PRELIGHT);
    }
}

void authorization(GtkWidget *widget) {
    if (strlen(gtk_entry_get_text(GTK_ENTRY(password))) > 0 && strlen(gtk_entry_get_text(GTK_ENTRY(login))) > 0) {
        gtk_widget_destroy(GTK_WIDGET(authorization_back));
        gtk_widget_hide(GTK_WIDGET(authorization_area));
        gtk_widget_show_all(GTK_WIDGET(chat_area));
    }
}


void registration_label_enter_notify(GtkWidget *widget, GdkEvent *event, GtkWidget *data) {
    gtk_widget_set_state_flags(GTK_WIDGET(widget), GTK_STATE_FLAG_PRELIGHT, TRUE);
}

void registration_label_leave_notify(GtkWidget *widget, GdkEvent *event, GtkWidget *data) {
    gtk_widget_unset_state_flags(GTK_WIDGET(widget), GTK_STATE_FLAG_PRELIGHT);
}

void hide_authorization_click(GtkWidget *widget) {
    gtk_widget_hide(GTK_WIDGET(log_in_menu));
    gtk_widget_show_all(GTK_WIDGET(registration_menu_1));
}

void back_btn_enter_notify() { 
    gtk_widget_set_state_flags(GTK_WIDGET(back_btn), GTK_STATE_FLAG_PRELIGHT, TRUE);
}

void back_btn_leave_notify() {
    gtk_widget_unset_state_flags(GTK_WIDGET(back_btn), GTK_STATE_FLAG_PRELIGHT);
}

void hide_registration_click(GtkWidget *widget) {
    gtk_widget_hide(GTK_WIDGET(registration_menu_1));
    gtk_widget_show_all(GTK_WIDGET(log_in_menu));
     
}

void data_change_registration_event(GtkWidget *widget, GdkEvent *event) {
    if (strlen(gtk_entry_get_text(GTK_ENTRY(login_reg))) > 0 && strlen(gtk_entry_get_text(GTK_ENTRY(password_reg))) > 0 && strlen(gtk_entry_get_text(GTK_ENTRY(password_reg_confirm))) > 0) {
        gtk_widget_set_opacity(GTK_WIDGET(next_btn), 1.0);
    }
    else {
         gtk_widget_set_opacity(GTK_WIDGET(next_btn), 0.5);
    }
}

void next_btn_enter_notify() { 
    if (strlen(gtk_entry_get_text(GTK_ENTRY(login_reg))) > 0 && strlen(gtk_entry_get_text(GTK_ENTRY(password_reg))) > 0 && strlen(gtk_entry_get_text(GTK_ENTRY(password_reg_confirm))) > 0) {
        gtk_widget_set_state_flags(GTK_WIDGET(next_btn), GTK_STATE_FLAG_PRELIGHT, TRUE);
    }
}

void next_btn_leave_notify() {
    if (strlen(gtk_entry_get_text(GTK_ENTRY(login_reg))) > 0 && strlen(gtk_entry_get_text(GTK_ENTRY(password_reg))) > 0 && strlen(gtk_entry_get_text(GTK_ENTRY(password_reg_confirm))) > 0) {
        gtk_widget_unset_state_flags(GTK_WIDGET(next_btn), GTK_STATE_FLAG_PRELIGHT);
    }
}

void transition_registration_click(GtkWidget *widget) {
    gtk_widget_hide(GTK_WIDGET(registration_menu_1));
    gtk_widget_show_all(GTK_WIDGET(registration_menu_2));
     
}

void back_btn_enter_notify_2() { 
    gtk_widget_set_state_flags(GTK_WIDGET(back_btn_2), GTK_STATE_FLAG_PRELIGHT, TRUE);
}

void back_btn_leave_notify_2() {
    gtk_widget_unset_state_flags(GTK_WIDGET(back_btn_2), GTK_STATE_FLAG_PRELIGHT);
}

void next_btn_enter_notify_2() { 
    if (strlen(gtk_entry_get_text(GTK_ENTRY(firstname_reg))) > 0) {
        gtk_widget_set_state_flags(GTK_WIDGET(finish_btn), GTK_STATE_FLAG_PRELIGHT, TRUE);
    }
}

void next_btn_leave_notify_2() {
    if (strlen(gtk_entry_get_text(GTK_ENTRY(firstname_reg))) > 0) {
        gtk_widget_unset_state_flags(GTK_WIDGET(finish_btn), GTK_STATE_FLAG_PRELIGHT);
    }
}

void hide_registration_click_2(GtkWidget *widget) {
    gtk_widget_hide(GTK_WIDGET(registration_menu_2));
    gtk_widget_show_all(GTK_WIDGET(registration_menu_1));
     
}

void data_change_registration_event_2(GtkWidget *widget, GdkEvent *event) {
    if (strlen(gtk_entry_get_text(GTK_ENTRY(firstname_reg))) > 0) {
        gtk_widget_set_opacity(GTK_WIDGET(finish_btn), 1.0);
    }
    else {
         gtk_widget_set_opacity(GTK_WIDGET(finish_btn), 0.5);
    }
}

void authorization_after_registration(GtkWidget *widget) {
    gtk_widget_hide(GTK_WIDGET(registration_menu_2));
    gtk_widget_show_all(GTK_WIDGET(log_in_menu));
}

void eye_pressed() {
    if (gtk_entry_get_visibility(GTK_ENTRY(password)) == FALSE) {
        GdkPixbuf *eye_pixbuf = mx_get_pixbuf_with_size("client/img/standard/eye.png", 35, 30);
        gtk_image_set_from_pixbuf(GTK_IMAGE(eye), eye_pixbuf);
        g_object_unref(G_OBJECT(eye_pixbuf));
        gtk_container_add(GTK_CONTAINER(eye_eventbox), eye);
        gtk_box_pack_start(GTK_BOX(password_eye_box), eye_eventbox, FALSE, FALSE, 0);
        gtk_widget_set_size_request(GTK_WIDGET(eye), 40, 25);
        gtk_widget_set_valign(GTK_WIDGET(eye_eventbox), GTK_ALIGN_END);
        gtk_entry_set_visibility(GTK_ENTRY(password), TRUE);
    }
    else {
        GdkPixbuf *eye_pixbuf = mx_get_pixbuf_with_size("client/img/standard/blind.png", 35, 30);
        gtk_image_set_from_pixbuf(GTK_IMAGE(eye), eye_pixbuf);
        g_object_unref(G_OBJECT(eye_pixbuf));
        gtk_container_add(GTK_CONTAINER(eye_eventbox), eye);
        gtk_box_pack_start(GTK_BOX(password_eye_box), eye_eventbox, FALSE, FALSE, 0);
        gtk_widget_set_size_request(GTK_WIDGET(eye), 40, 25);
        gtk_widget_set_valign(GTK_WIDGET(eye_eventbox), GTK_ALIGN_END);
        gtk_entry_set_visibility(GTK_ENTRY(password), FALSE);
    }
}
