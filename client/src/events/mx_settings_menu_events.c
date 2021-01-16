#include "../../inc/uchat_client.h"

// Edit_user icon
//=================================================================================
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
    }
}
//=================================================================================

// Account settings icon
//=================================================================================
void account_settings_enter_notify(GtkWidget *widget) {
    gtk_widget_set_state_flags(GTK_WIDGET(widget), GTK_STATE_FLAG_PRELIGHT, TRUE);
    gtk_widget_set_state_flags(GTK_WIDGET(account_settings_image.box), 
        GTK_STATE_FLAG_PRELIGHT, FALSE);
}

void account_settings_leave_notify(GtkWidget *widget) {
    gtk_widget_unset_state_flags(GTK_WIDGET(widget), GTK_STATE_FLAG_PRELIGHT);
    gtk_widget_unset_state_flags(GTK_WIDGET(account_settings_image.box), 
        GTK_STATE_FLAG_PRELIGHT);
}

void account_settings_click(GtkWidget *widget, GdkEventButton *event) {
    if (event->type == GDK_BUTTON_PRESS && event->button == 1) {
        mx_create_account_settings_form();
    }
}
//=================================================================================

// Change_account icon
//=================================================================================
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

void change_account_click(GtkWidget *widget, GdkEventButton *event) {
    if (event->type == GDK_BUTTON_PRESS && event->button == 1) {
        mx_create_registration_menu();
    }
}
//=================================================================================

// Chat_settings icon
//=================================================================================
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
//=================================================================================

// Language icon
//=================================================================================
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

void language_click(GtkWidget *widget, GdkEventButton *event) {
    if (event->type == GDK_BUTTON_PRESS && event->button == 1) {
        mx_create_language_menu();
    }
}
//=================================================================================
