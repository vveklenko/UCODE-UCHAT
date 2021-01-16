#include "../../inc/uchat_client.h"

// change_password icon
//=================================================================================
void password_change_enter_notify(GtkWidget *widget, GdkEvent *event, GtkWidget *data) {
    gtk_widget_set_state_flags(GTK_WIDGET(widget), GTK_STATE_FLAG_PRELIGHT, TRUE);
    gtk_widget_set_state_flags(GTK_WIDGET(edit_password_change_icon), GTK_STATE_FLAG_PRELIGHT, TRUE);
}

void password_change_leave_notify(GtkWidget *widget, GdkEvent *event, GtkWidget *data) {
    gtk_widget_unset_state_flags(GTK_WIDGET(widget), GTK_STATE_FLAG_PRELIGHT);
    gtk_widget_unset_state_flags(GTK_WIDGET(edit_password_change_icon), GTK_STATE_FLAG_PRELIGHT);
}

void password_change_click(GtkWidget *widget, GdkEventButton *event) {
    if (event->type == GDK_BUTTON_PRESS && event->button == 1) {
        mx_create_edit_user_form();
    }
}
//=================================================================================

// delete_account icon
//=================================================================================
void user_delete_enter_notify(GtkWidget *widget, GdkEvent *event, GtkWidget *data) {
    gtk_widget_set_state_flags(GTK_WIDGET(widget), GTK_STATE_FLAG_PRELIGHT, TRUE);
    gtk_widget_set_state_flags(GTK_WIDGET(edit_user_delete_icon), GTK_STATE_FLAG_PRELIGHT, TRUE);
}

void user_delete_leave_notify(GtkWidget *widget, GdkEvent *event, GtkWidget *data) {
    gtk_widget_unset_state_flags(GTK_WIDGET(widget), GTK_STATE_FLAG_PRELIGHT);
    gtk_widget_unset_state_flags(GTK_WIDGET(edit_user_delete_icon), GTK_STATE_FLAG_PRELIGHT);
}

void user_delete_click(GtkWidget *widget, GdkEventButton *event) {
    if (event->type == GDK_BUTTON_PRESS && event->button == 1) {
        mx_create_edit_user_form();
    }
}
