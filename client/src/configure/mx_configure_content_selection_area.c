#include "../../inc/uchat_client.h"

void mx_configure_content_selection_area(GtkWidget **content_selection_area) {
    // A container which contains section with images and a line just below it
    *content_selection_area = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    gtk_fixed_put(GTK_FIXED(chat_area), *content_selection_area, 0, 48);

    GtkWidget *image_container = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
    gtk_widget_set_size_request(GTK_WIDGET(image_container), L_FIELD_WIDTH, 40);
    gtk_box_pack_start(GTK_BOX(*content_selection_area), image_container, TRUE, FALSE, 0);

    // A line which is under the images
    GtkWidget *delimiter = gtk_drawing_area_new();
    gtk_box_pack_start(GTK_BOX(*content_selection_area), delimiter, TRUE, FALSE, 15);
    gtk_widget_set_size_request(GTK_WIDGET(delimiter), L_FIELD_WIDTH, 1);
    g_signal_connect(G_OBJECT(delimiter), "draw",
                     G_CALLBACK(mx_draw_event_delimiter), NULL);

    gtk_box_pack_start(GTK_BOX(image_container),
        messages_image.box, TRUE, FALSE, 30);
    gtk_box_pack_start(GTK_BOX(image_container),
        contacts_image.box, TRUE, FALSE, 30);
    gtk_box_pack_start(GTK_BOX(image_container),
        settings_image.box, TRUE, FALSE, 30);

    g_signal_connect(G_OBJECT(messages_image.box), "enter-notify-event",
        G_CALLBACK(messages_enter_notify), NULL);
    g_signal_connect(G_OBJECT(messages_image.box), "leave-notify-event",
        G_CALLBACK(messages_leave_notify), NULL);
    g_signal_connect(G_OBJECT(messages_image.box), "button_press_event",
        G_CALLBACK(messages_click), NULL);

    g_signal_connect(G_OBJECT(contacts_image.box), "enter-notify-event",
        G_CALLBACK(contacts_enter_notify), NULL);
    g_signal_connect(G_OBJECT(contacts_image.box), "leave-notify-event",
        G_CALLBACK(contacts_leave_notify), NULL);
    g_signal_connect(G_OBJECT(contacts_image.box), "button_press_event",
        G_CALLBACK(contacts_click), NULL);

    g_signal_connect(G_OBJECT(settings_image.box), "enter-notify-event",
        G_CALLBACK(settings_enter_notify), NULL);
    g_signal_connect(G_OBJECT(settings_image.box), "leave-notify-event",
        G_CALLBACK(settings_leave_notify), NULL);
    g_signal_connect(G_OBJECT(settings_image.box), "button_press_event",
        G_CALLBACK(settings_click), NULL);
}