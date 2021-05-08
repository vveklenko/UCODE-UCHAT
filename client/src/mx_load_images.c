#include "../inc/uchat_client.h"

void mx_load_images(void) {
    messages_image.box = gtk_event_box_new();
    messages_image.active = false;
    gtk_widget_set_valign(GTK_WIDGET(messages_image.box), GTK_ALIGN_END);
    gtk_widget_set_size_request(GTK_WIDGET(messages_image.box), L_FIELD_WIDTH / 2 + 1, 55);
    gtk_widget_set_name(GTK_WIDGET(messages_image.box), "messages_image");

    settings_image.box = gtk_event_box_new();
    settings_image.active = true;
    gtk_widget_set_state_flags(GTK_WIDGET(settings_image.box), GTK_STATE_FLAG_CHECKED, TRUE);
    gtk_widget_set_valign(GTK_WIDGET(settings_image.box), GTK_ALIGN_END);
    gtk_widget_set_size_request(GTK_WIDGET(settings_image.box), L_FIELD_WIDTH / 2, 55);
    gtk_widget_set_name(GTK_WIDGET(settings_image.box), "settings_image");

    t_active_image = &settings_image;
}
