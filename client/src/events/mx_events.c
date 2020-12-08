#include "../../inc/uchat_client.h"

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

// Blackout
//==============================================================
void blackout_click(GtkWidget *widget, GdkEventButton *event) {
    if (event->type == GDK_BUTTON_PRESS && event->button == 1
        && ((event->x < CUR_WIDTH / 3 - 10 || event->x > CUR_WIDTH / 3 - 10 + 450)
            || (event->y < CUR_HEIGHT / 5 - 50 || event->y > CUR_HEIGHT / 5 - 50 + 520))) {
        gtk_widget_destroy(GTK_WIDGET(authorization_backout));
    }
}
//==============================================================

// Close image
//========================================================
void close_image_click_event(GtkWidget *widget, GdkEventButton *event) {
    if (event->type == GDK_BUTTON_PRESS && event->button == 1) {
        free(NewFirstName);
        NewFirstName = NULL;
        free(NewPseudonim);
        NewPseudonim = NULL;
        free(NewDescription);
        NewDescription = NULL;
        g_object_unref(G_OBJECT(NewAvatar));
        gtk_widget_destroy(GTK_WIDGET(authorization_backout));
    }
}
//========================================================
