#include "../../inc/uchat_client.h"

void mx_configure_settings_menu_area() {
    settings_menu = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    gtk_widget_set_size_request(GTK_WIDGET(settings_menu), L_FIELD_WIDTH, CUR_HEIGHT - 105);
    gtk_widget_set_name(GTK_WIDGET(settings_menu), "settings_menu");

    gtk_fixed_put(GTK_FIXED(chat_area), settings_menu, 0, 105);

    // Profile info section
    //==============================================================================================
    GtkWidget *user_profile_preview_eventbox = gtk_event_box_new();
    gtk_widget_set_name(GTK_WIDGET(user_profile_preview_eventbox), "user_profile_preview_eventbox");
    GtkWidget *user_profile_preview_box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
    gtk_widget_set_name(GTK_WIDGET(user_profile_preview_box), "user_profile_preview_box");
    gtk_container_add(GTK_CONTAINER(user_profile_preview_eventbox), user_profile_preview_box);
    gtk_box_pack_start(GTK_BOX(settings_menu), user_profile_preview_eventbox, FALSE, FALSE, 0);
    
    GtkWidget *avatar = gtk_drawing_area_new();
    gtk_widget_set_size_request(GTK_WIDGET(avatar), 70, 70);
    g_signal_connect(G_OBJECT(avatar), "draw", G_CALLBACK(mx_draw_event_image_avatar), &t_user.avatar);
    gtk_box_pack_start(GTK_BOX(user_profile_preview_box), avatar, FALSE, FALSE, 0);
    GtkWidget *user_info_preview = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);
    gtk_box_pack_start(GTK_BOX(user_profile_preview_box), user_info_preview, FALSE, FALSE, 31);
    
    char *username_tmp = strdup(t_user.FirstName);
    username_tmp = mx_strjoin(username_tmp, " ");
    username_tmp = mx_strjoin(username_tmp, t_user.SecondName);
    username = gtk_label_new(username_tmp);
    free(username_tmp);
    
    gtk_widget_set_name(GTK_WIDGET(username), "username_preview");
    char *tmp_pseudonim = "@";
    tmp_pseudonim = mx_strjoin(tmp_pseudonim, t_user.pseudonim);
    user_pseudonim = gtk_label_new(tmp_pseudonim);
    free(tmp_pseudonim);
    gtk_widget_set_name(GTK_WIDGET(user_pseudonim), "user_pseudonim_preview");
    gtk_box_pack_start(GTK_BOX(user_info_preview), username, TRUE, FALSE, 0);
    gtk_widget_set_halign(username, GTK_ALIGN_START);
    gtk_box_pack_start(GTK_BOX(user_info_preview), user_pseudonim, TRUE, FALSE, 0);
    //==============================================================================================

    // "Edit profile" section
    //==============================================================================================
    GtkWidget *edit_user_eventbox = gtk_event_box_new();
    gtk_widget_set_name(GTK_WIDGET(edit_user_eventbox), "edit_user_eventbox");
    GtkWidget *edit_user_box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
    gtk_widget_set_name(GTK_WIDGET(edit_user_box), "change_box");
    gtk_container_add(GTK_CONTAINER(edit_user_eventbox), edit_user_box);
    gtk_box_pack_start(GTK_BOX(settings_menu), edit_user_eventbox, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(edit_user_box), edit_user_image.box, FALSE, FALSE, 0);
    GtkWidget *label_edit_user = gtk_label_new("Edit profile");
    gtk_widget_set_name(GTK_WIDGET(label_edit_user), "label_edit_user");
    gtk_box_pack_start(GTK_BOX(edit_user_box), label_edit_user, FALSE, FALSE, 50);

    g_signal_connect(G_OBJECT(edit_user_eventbox), "enter-notify-event",
        G_CALLBACK(edit_user_enter_notify), NULL);
    g_signal_connect(G_OBJECT(edit_user_eventbox), "leave-notify-event",
        G_CALLBACK(edit_user_leave_notify), NULL);
    g_signal_connect(G_OBJECT(edit_user_eventbox), "button_press_event",
        G_CALLBACK(edit_user_click), NULL);   
    //==============================================================================================

    // "Change account" section
    //==============================================================================================
    GtkWidget *change_account_eventbox = gtk_event_box_new();
    gtk_widget_set_name(GTK_WIDGET(change_account_eventbox), "change_account_eventbox");
    GtkWidget *change_account_box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
    gtk_widget_set_name(GTK_WIDGET(change_account_box), "change_box");
    gtk_container_add(GTK_CONTAINER(change_account_eventbox), change_account_box);
    gtk_box_pack_start(GTK_BOX(settings_menu), change_account_eventbox, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(change_account_box), change_account_image.box, FALSE, FALSE, 0);
    GtkWidget *label_change_account = gtk_label_new("Change account");
    gtk_widget_set_name(GTK_WIDGET(label_change_account), "label_change_account");
    gtk_box_pack_start(GTK_BOX(change_account_box), label_change_account, FALSE, FALSE, 50);

    g_signal_connect(G_OBJECT(change_account_eventbox), "enter-notify-event",
        G_CALLBACK(change_account_enter_notify), NULL);
    g_signal_connect(G_OBJECT(change_account_eventbox), "leave-notify-event",
        G_CALLBACK(change_account_leave_notify), NULL);
    g_signal_connect(G_OBJECT(change_account_eventbox), "button_press_event",
        G_CALLBACK(change_account_click), NULL); 
    //==============================================================================================

    // "Chat settings" section
    //==============================================================================================
    GtkWidget *chat_settings_eventbox = gtk_event_box_new();
    gtk_widget_set_name(GTK_WIDGET(chat_settings_eventbox), "chat_settings_eventbox");
    GtkWidget *chat_settings_box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
    gtk_widget_set_name(GTK_WIDGET(chat_settings_box), "change_box");
    gtk_container_add(GTK_CONTAINER(chat_settings_eventbox), chat_settings_box);
    gtk_box_pack_start(GTK_BOX(settings_menu), chat_settings_eventbox, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(chat_settings_box), chat_settings_image.box, FALSE, FALSE, 0);
    GtkWidget *label_chat_settings = gtk_label_new("Chat settings");
    gtk_widget_set_name(GTK_WIDGET(label_chat_settings), "label_chat_settings");
    gtk_box_pack_start(GTK_BOX(chat_settings_box), label_chat_settings, FALSE, FALSE, 50);

    g_signal_connect(G_OBJECT(chat_settings_eventbox), "enter-notify-event",
        G_CALLBACK(chat_settings_enter_notify), NULL);
    g_signal_connect(G_OBJECT(chat_settings_eventbox), "leave-notify-event",
        G_CALLBACK(chat_settings_leave_notify), NULL);
    //==============================================================================================

    // "Language" section
    //==============================================================================================
    GtkWidget *language_eventbox = gtk_event_box_new();
    gtk_widget_set_name(GTK_WIDGET(language_eventbox), "language_eventbox");
    GtkWidget *language_box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
    gtk_widget_set_name(GTK_WIDGET(language_box), "language_box");
    gtk_container_add(GTK_CONTAINER(language_eventbox), language_box);
    gtk_box_pack_start(GTK_BOX(settings_menu), language_eventbox, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(language_box), language_image.box, FALSE, FALSE, 0);
    GtkWidget *label_language = gtk_label_new("Language");
    gtk_widget_set_name(GTK_WIDGET(label_language), "label_language");
    gtk_box_pack_start(GTK_BOX(language_box), label_language, FALSE, FALSE, 50);

    g_signal_connect(G_OBJECT(language_eventbox), "enter-notify-event",
        G_CALLBACK(language_enter_notify), NULL);
    g_signal_connect(G_OBJECT(language_eventbox), "leave-notify-event",
        G_CALLBACK(language_leave_notify), NULL);
    //==============================================================================================

    // Footer section
    //==============================================================================================
    GtkWidget *label_impulse = gtk_label_new("Impulse");
    gtk_widget_set_name(GTK_WIDGET(label_impulse), "label_impulse");
    GtkWidget *label_version = gtk_label_new("Alpha version");
    gtk_widget_set_name(GTK_WIDGET(label_version), "label_version");
    gtk_box_pack_start(GTK_BOX(settings_menu), label_impulse, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(settings_menu), label_version, TRUE, TRUE, 0);

    gtk_widget_set_valign(GTK_WIDGET(label_impulse), GTK_ALIGN_END);
    gtk_widget_set_valign(GTK_WIDGET(label_version), GTK_ALIGN_END);
    //============================================================================================== 
}
