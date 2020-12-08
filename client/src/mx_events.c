#include "../inc/uchat_client.h"

void image_click(GtkWidget *widget, GdkEventButton *event, t_img_button *data) {
    if (event->type == GDK_BUTTON_PRESS && event->button == 1) {
        if (!(data->active)) {
            gtk_widget_set_state_flags(GTK_WIDGET(widget), GTK_STATE_FLAG_CHECKED, FALSE);
            data->active = true;
        }
        else {
            gtk_widget_unset_state_flags(GTK_WIDGET(widget), GTK_STATE_FLAG_CHECKED);
            data->active = false;
        }
    }
}
void image_enter_notify(GtkWidget *widget) {
    gtk_widget_set_state_flags(GTK_WIDGET(widget), GTK_STATE_FLAG_PRELIGHT, TRUE);
}
void image_leave_notify(GtkWidget *widget) {
    gtk_widget_unset_state_flags(GTK_WIDGET(widget), GTK_STATE_FLAG_PRELIGHT);
}

// Messages button
//=============================================================
void messages_enter_notify(GtkWidget *widget) {
    gtk_widget_set_state_flags(GTK_WIDGET(widget), GTK_STATE_FLAG_PRELIGHT, FALSE);
}

void messages_leave_notify(GtkWidget *widget) {
    gtk_widget_unset_state_flags(GTK_WIDGET(widget), GTK_STATE_FLAG_PRELIGHT);
}

void messages_click(GtkWidget *widget, GdkEventButton *event) {
    if (messages_image.active) return;
    if (event->type == GDK_BUTTON_PRESS && event->button == 1) {
        if (t_active_image != NULL) {
            gtk_widget_unset_state_flags(GTK_WIDGET(t_active_image->box), GTK_STATE_FLAG_CHECKED);        
            t_active_image->active = false;
        }
        t_active_image = &messages_image;
        t_active_image->active = true;

        gtk_widget_set_state_flags(GTK_WIDGET(widget), GTK_STATE_FLAG_CHECKED, FALSE);
        gtk_widget_hide(GTK_WIDGET(active_leftbar_container));
        active_leftbar_container = chats_list;
        gtk_widget_show(GTK_WIDGET(active_leftbar_container));
    }
    if (widget) {}
}
//=============================================================

// Contacts button
//=============================================================
void contacts_enter_notify(GtkWidget *widget) {
    gtk_widget_set_state_flags(GTK_WIDGET(widget), GTK_STATE_FLAG_PRELIGHT, FALSE);
}

void contacts_leave_notify(GtkWidget *widget) {
    gtk_widget_unset_state_flags(GTK_WIDGET(widget), GTK_STATE_FLAG_PRELIGHT);
}

void contacts_click(GtkWidget *widget, GdkEventButton *event) {
    if (contacts_image.active) return;
    if (event->type == GDK_BUTTON_PRESS && event->button == 1) {
        if (t_active_image != NULL) {
            gtk_widget_unset_state_flags(GTK_WIDGET(t_active_image->box), GTK_STATE_FLAG_CHECKED);        
            t_active_image->active = false;
        }
        t_active_image = &contacts_image;
        t_active_image->active = true;
        
        gtk_widget_set_state_flags(GTK_WIDGET(widget), GTK_STATE_FLAG_CHECKED, FALSE);
        gtk_widget_hide(GTK_WIDGET(active_leftbar_container));
        active_leftbar_container = contacts_list;
        gtk_widget_show(GTK_WIDGET(active_leftbar_container));
    }
    if (widget) {}
}
//=============================================================

// Settings button
//=============================================================
void settings_enter_notify(GtkWidget *widget) {
    gtk_widget_set_state_flags(GTK_WIDGET(widget), GTK_STATE_FLAG_PRELIGHT, FALSE);
}

void settings_leave_notify(GtkWidget *widget) {
    gtk_widget_unset_state_flags(GTK_WIDGET(widget), GTK_STATE_FLAG_PRELIGHT);
}

void settings_click(GtkWidget *widget, GdkEventButton *event) {
    if (settings_image.active) return;
    if (event->type == GDK_BUTTON_PRESS && event->button == 1) {
        if (t_active_image != NULL) {
            gtk_widget_unset_state_flags(GTK_WIDGET(t_active_image->box), GTK_STATE_FLAG_CHECKED);
            t_active_image->active = false;
        }
        t_active_image = &settings_image;
        t_active_image->active = true;

        gtk_widget_set_state_flags(GTK_WIDGET(widget), GTK_STATE_FLAG_CHECKED, FALSE);
        gtk_widget_hide(GTK_WIDGET(active_leftbar_container));
        active_leftbar_container = settings_menu;
        gtk_widget_show(GTK_WIDGET(active_leftbar_container));
    }
    if (widget) {}
}
//=============================================================

// Add button
//========================================================
void add_enter_notify(GtkWidget *widget) {
    gtk_widget_set_state_flags(GTK_WIDGET(widget), GTK_STATE_FLAG_PRELIGHT, FALSE);
}

void add_leave_notify(GtkWidget *widget) {
    gtk_widget_unset_state_flags(GTK_WIDGET(widget), GTK_STATE_FLAG_PRELIGHT);
}
//========================================================

// Message entry field
//=================================================================================
void entry_chat_fill_event(GtkWidget *widget, GdkEvent *event) {
    int len = strlen(gtk_entry_buffer_get_text(gtk_entry_get_buffer(GTK_ENTRY(widget))));
    if (len > 0) {
        gtk_widget_hide(GTK_WIDGET(ban_image.box));
        gtk_widget_show(GTK_WIDGET(tick_image.box));
    }
    else {
        gtk_widget_hide(GTK_WIDGET(tick_image.box));
        gtk_widget_show(GTK_WIDGET(ban_image.box));
    }
    if (event) {}
}
//=================================================================================

// Tick button
//=========================================================

//========================================================

// More button
//=========================================================
void more_enter_notify(GtkWidget *widget) {
    gtk_widget_set_state_flags(GTK_WIDGET(widget), GTK_STATE_FLAG_PRELIGHT, TRUE);
}

void more_leave_notify(GtkWidget *widget) {
    gtk_widget_unset_state_flags(GTK_WIDGET(widget), GTK_STATE_FLAG_PRELIGHT);
}
//=========================================================

// Edit_user icon in settings menu
//==================================
void edit_user_enter_notify(GtkWidget *widget) {
    gtk_widget_set_state_flags(GTK_WIDGET(widget), GTK_STATE_FLAG_PRELIGHT, TRUE);
    gtk_widget_set_state_flags(GTK_WIDGET(edit_user_image.box), 
        GTK_STATE_FLAG_PRELIGHT, FALSE);
}

void edit_user_leave_notify(GtkWidget *widget) {
    gtk_widget_unset_state_flags(GTK_WIDGET(widget), GTK_STATE_FLAG_PRELIGHT);
    gtk_widget_unset_state_flags(GTK_WIDGET(edit_user_image.box), GTK_STATE_FLAG_PRELIGHT);
}

void edit_user_click(GtkWidget *widget, GdkEventButton *event) {
    if (event->type == GDK_BUTTON_PRESS && event->button == 1) {
        mx_create_edit_user_form();
        gtk_widget_show_all(GTK_WIDGET(back_blackout));
    }
    if (widget) {}
}
//==================================

// Change_account icon in settings menu
//==================================
void change_account_enter_notify(GtkWidget *widget) {
    gtk_widget_set_state_flags(GTK_WIDGET(widget), GTK_STATE_FLAG_PRELIGHT, TRUE);
    gtk_widget_set_state_flags(GTK_WIDGET(change_account_image.box), 
        GTK_STATE_FLAG_PRELIGHT, FALSE);
}

void change_account_leave_notify(GtkWidget *widget) {
    gtk_widget_unset_state_flags(GTK_WIDGET(widget), GTK_STATE_FLAG_PRELIGHT);
    gtk_widget_unset_state_flags(GTK_WIDGET(change_account_image.box), 
        GTK_STATE_FLAG_PRELIGHT);
}
//==================================

// Chat_settings icon in settings menu
//======================================
void chat_settings_enter_notify(GtkWidget *widget) {
    gtk_widget_set_state_flags(GTK_WIDGET(widget), GTK_STATE_FLAG_PRELIGHT, TRUE);
    gtk_widget_set_state_flags(GTK_WIDGET(chat_settings_image.box), 
        GTK_STATE_FLAG_PRELIGHT, FALSE);
}

void chat_settings_leave_notify(GtkWidget *widget) {
    gtk_widget_unset_state_flags(GTK_WIDGET(widget), GTK_STATE_FLAG_PRELIGHT);
    gtk_widget_unset_state_flags(GTK_WIDGET(chat_settings_image.box), 
        GTK_STATE_FLAG_PRELIGHT);
}
//==================================

// Language icon in settings menu
//================================
void language_enter_notify(GtkWidget *widget) {
    gtk_widget_set_state_flags(GTK_WIDGET(widget), GTK_STATE_FLAG_PRELIGHT, TRUE);
    gtk_widget_set_state_flags(GTK_WIDGET(language_image.box), 
        GTK_STATE_FLAG_PRELIGHT, FALSE);
}

void language_leave_notify(GtkWidget *widget) {
    gtk_widget_unset_state_flags(GTK_WIDGET(widget), GTK_STATE_FLAG_PRELIGHT);
    gtk_widget_unset_state_flags(GTK_WIDGET(language_image.box), 
        GTK_STATE_FLAG_PRELIGHT);
}
//=================================

// Blackout
//==============================================================
void blackout_leave_notify_event() {
    printf("flkdsf\n");
}

void blackout_click(GtkWidget *widget, GdkEventButton *event) {
    if (event->type == GDK_BUTTON_PRESS && event->button == 1) {
        gtk_widget_destroy(GTK_WIDGET(back_blackout));
    }
    if (widget) {}
}
//==============================================================

// Close image
//========================================================
void close_image_enter_notify_event(GtkWidget *widget) {
    gtk_widget_set_state_flags(GTK_WIDGET(widget), GTK_STATE_FLAG_PRELIGHT, TRUE);
}

void close_image_leave_notify_event(GtkWidget *widget) {
    gtk_widget_unset_state_flags(GTK_WIDGET(widget), GTK_STATE_FLAG_PRELIGHT);
}

void close_image_click_event(GtkWidget *widget, GdkEventButton *event) {
    if (event->type == GDK_BUTTON_PRESS && event->button == 1) {
        gtk_widget_destroy(GTK_WIDGET(back_blackout));
    }
    if (widget) {}
}
//Registration menu
//========================================================
void data_change_event(GtkWidget *widget, GdkEvent *event) {
    if (strlen(gtk_entry_get_text(GTK_ENTRY(password))) > 0 && strlen(gtk_entry_get_text(GTK_ENTRY(login))) > 0) {
        gtk_widget_set_opacity(GTK_WIDGET(login_btn), 1.0);
    }
    else {
         gtk_widget_set_opacity(GTK_WIDGET(login_btn), 0.5);
    }

    if (event) {}
    if (widget) {}
}

void login_btn_enter_notify_event() {
    if (strlen(gtk_entry_get_text(GTK_ENTRY(password))) > 0 && strlen(gtk_entry_get_text(GTK_ENTRY(login))) > 0) {
        gtk_widget_set_state_flags(GTK_WIDGET(login_btn), GTK_STATE_FLAG_PRELIGHT, TRUE);
    }
}

void login_btn_leave_notify_event() {
    if (strlen(gtk_entry_get_text(GTK_ENTRY(password))) > 0 && strlen(gtk_entry_get_text(GTK_ENTRY(login))) > 0) {
        gtk_widget_unset_state_flags(GTK_WIDGET(login_btn), GTK_STATE_FLAG_PRELIGHT);
    }
}


void registration_label_enter_notify_event(GtkWidget *widget, GdkEvent *event, GtkWidget *data) {
    gtk_widget_set_state_flags(GTK_WIDGET(widget), GTK_STATE_FLAG_PRELIGHT, TRUE);
    if (data) {}
    if (event) {}
}

void registration_label_leave_notify_event(GtkWidget *widget, GdkEvent *event, GtkWidget *data) {
    gtk_widget_unset_state_flags(GTK_WIDGET(widget), GTK_STATE_FLAG_PRELIGHT);
        if (data) {}
    if (event) {}
}

void hide_autorization_click(GtkWidget *widget) {
    gtk_widget_hide(GTK_WIDGET(log_in_menu));
    gtk_widget_show_all(GTK_WIDGET(registration_menu_1));
    if(widget) {}
}

void back_btn_enter_notify_event() { 
    gtk_widget_set_state_flags(GTK_WIDGET(back_btn), GTK_STATE_FLAG_PRELIGHT, TRUE);
}

void back_btn_leave_notify_event() {
    gtk_widget_unset_state_flags(GTK_WIDGET(back_btn), GTK_STATE_FLAG_PRELIGHT);
}

void hide_registration_click(GtkWidget *widget) {
    gtk_widget_hide(GTK_WIDGET(registration_menu_1));
    gtk_widget_show_all(GTK_WIDGET(log_in_menu));
    if(widget) {}
}

void data_change_registration_event(GtkWidget *widget, GdkEvent *event) {
    if (strlen(gtk_entry_get_text(GTK_ENTRY(login_reg))) > 0 && strlen(gtk_entry_get_text(GTK_ENTRY(password_reg))) > 0 && strlen(gtk_entry_get_text(GTK_ENTRY(password_reg_confirm))) > 0) {
        gtk_widget_set_opacity(GTK_WIDGET(next_btn), 1.0);
    }
    else {
         gtk_widget_set_opacity(GTK_WIDGET(next_btn), 0.5);
    }

    if (event) {}
    if (widget) {}
}

void next_btn_enter_notify_event() { 
    if (strlen(gtk_entry_get_text(GTK_ENTRY(login_reg))) > 0 && strlen(gtk_entry_get_text(GTK_ENTRY(password_reg))) > 0 && strlen(gtk_entry_get_text(GTK_ENTRY(password_reg_confirm))) > 0) {
        gtk_widget_set_state_flags(GTK_WIDGET(next_btn), GTK_STATE_FLAG_PRELIGHT, TRUE);
    }
}

void next_btn_leave_notify_event() {
    if (strlen(gtk_entry_get_text(GTK_ENTRY(login_reg))) > 0 && strlen(gtk_entry_get_text(GTK_ENTRY(password_reg))) > 0 && strlen(gtk_entry_get_text(GTK_ENTRY(password_reg_confirm))) > 0) {
        gtk_widget_unset_state_flags(GTK_WIDGET(next_btn), GTK_STATE_FLAG_PRELIGHT);
    }
}

void transition_registration_click(GtkWidget *widget) {
    gtk_widget_hide(GTK_WIDGET(registration_menu_1));
    gtk_widget_show_all(GTK_WIDGET(registration_menu_2));
    if(widget) {}
}

void back_btn_enter_notify_event_2() { 
    gtk_widget_set_state_flags(GTK_WIDGET(back_btn_2), GTK_STATE_FLAG_PRELIGHT, TRUE);
}

void back_btn_leave_notify_event_2() {
    gtk_widget_unset_state_flags(GTK_WIDGET(back_btn_2), GTK_STATE_FLAG_PRELIGHT);
}

void next_btn_enter_notify_event_2() { 
    if (strlen(gtk_entry_get_text(GTK_ENTRY(firstname_reg))) > 0) {
        gtk_widget_set_state_flags(GTK_WIDGET(next_btn_2), GTK_STATE_FLAG_PRELIGHT, TRUE);
    }
}

void next_btn_leave_notify_event_2() {
    if (strlen(gtk_entry_get_text(GTK_ENTRY(firstname_reg))) > 0) {
        gtk_widget_unset_state_flags(GTK_WIDGET(next_btn_2), GTK_STATE_FLAG_PRELIGHT);
    }
}

void hide_registration_click_2(GtkWidget *widget) {
    gtk_widget_hide(GTK_WIDGET(registration_menu_2));
    gtk_widget_show_all(GTK_WIDGET(registration_menu_1));
    if(widget) {}
}

void data_change_registration_event_2(GtkWidget *widget, GdkEvent *event) {
    if (strlen(gtk_entry_get_text(GTK_ENTRY(firstname_reg))) > 0) {
        gtk_widget_set_opacity(GTK_WIDGET(next_btn_2), 1.0);
    }
    else {
         gtk_widget_set_opacity(GTK_WIDGET(next_btn_2), 0.5);
    }

    if (event) {}
    if (widget) {}
}

void autorization_after_registration(GtkWidget *widget) {
    gtk_widget_hide(GTK_WIDGET(registration_menu_2));
    gtk_widget_show_all(GTK_WIDGET(log_in_menu));
    if(widget) {}
}

void autorization(GtkWidget *widget) {
    gtk_widget_show_all(GTK_WIDGET(main_area));
    gtk_widget_hide(GTK_WIDGET(back_black));
    if(widget) {}
}
