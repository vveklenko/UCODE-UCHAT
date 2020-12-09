#include "../inc/uchat_client.h"

gboolean mx_draw_event_background(GtkWidget *widget, cairo_t *cr, gpointer user_data) {
    // Left area
    cairo_set_source_rgba(cr, MX_1F1F1F, MX_1F1F1F, MX_1F1F1F, 1);
    cairo_rectangle(cr, 0, 0, L_FIELD_WIDTH, CUR_HEIGHT);
    cairo_fill(cr);

    // Right area
    cairo_set_source_rgba(cr, MX_E1E1E1, MX_E1E1E1, MX_E1E1E1, 1);
    cairo_rectangle(cr, L_FIELD_WIDTH, 0, CUR_WIDTH - CUR_WIDTH / 3, CUR_HEIGHT);
    cairo_fill(cr);
    return FALSE;
}

gboolean mx_draw_event_message_enter_area(GtkWidget *widget, cairo_t *cr, gpointer user_data) {
    cairo_set_source_rgba(cr, MX_1F1F1F, MX_1F1F1F, MX_1F1F1F, 1);
    cairo_rectangle(cr, 0, 0, CUR_WIDTH - CUR_WIDTH / 3, 50);
    cairo_fill(cr);
    return FALSE;
}

gboolean mx_draw_event_delimiter(GtkWidget *widget, cairo_t *cr) {
    cairo_set_source_rgba(cr, MX_E1E1E1, MX_E1E1E1, MX_E1E1E1, 1);
    cairo_rectangle(cr, 0, 0, L_FIELD_WIDTH, 1);
    cairo_fill(cr);
    return FALSE;
}

gboolean mx_draw_event_image_avatar(GtkWidget *widget, cairo_t *cr, GdkPixbuf **img_data) {
    int img_w, img_h;
    gtk_widget_get_size_request(GTK_WIDGET(widget), &img_w, &img_h);
    GdkPixbuf *pixbuf = gdk_pixbuf_scale_simple(GDK_PIXBUF(*img_data), 
        img_w, img_h, GDK_INTERP_BILINEAR);
    gdk_cairo_set_source_pixbuf(cr, pixbuf, 0, 0);
    g_object_unref(G_OBJECT(pixbuf));

    double x = 0,
        y = 0,
        width = img_w,
        height = img_h,
        aspect = 1.0,                       /* aspect ratio */
        corner_radius = height / 2.7;       /* and corner curvature radius */
    double radius = corner_radius / aspect;
    double degrees = M_PI / 180.0;

    cairo_new_sub_path (cr);
    cairo_arc (cr, x + width - radius, y + radius, radius, -90 * degrees, 0 * degrees);
    cairo_arc (cr, x + width - radius, y + height - radius, radius, 0 * degrees, 90 * degrees);
    cairo_arc (cr, x + radius, y + height - radius, radius, 90 * degrees, 180 * degrees);
    cairo_arc (cr, x + radius, y + radius, radius, 180 * degrees, 270 * degrees);
    cairo_close_path (cr);

    cairo_fill(cr);
    return FALSE;
}

gboolean mx_draw_event_authorization_back(GtkWidget *widget, cairo_t *cr) {
    cairo_set_source_rgba(cr, MX_1F1F1F, MX_1F1F1F, MX_1F1F1F, 1);
    cairo_rectangle(cr, 0, 0, CUR_WIDTH, CUR_HEIGHT);
    cairo_fill(cr);
    return FALSE;
}
