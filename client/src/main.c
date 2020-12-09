#include "../inc/uchat_client.h"

int main(int argc, char *argv[]) {
    // Containers
    window = NULL;
    main_area = NULL;
    authorization_area = NULL;
    chat_area = NULL;
    message_enter_area = NULL;
    chats_list = NULL;
    settings_menu = NULL;


    NewFirstName = NULL;
    NewSecondName = NULL;
    NewPseudonim = NULL;
    NewDescription = NULL;
    NewAvatar = NULL;


    GtkWidget *left_header = NULL;
    GtkWidget *content_selection_area = NULL;
    GtkWidget *entry_search = NULL;
    GtkWidget *entry_chat = NULL;
    
    // Drawing areas
    GtkWidget *background = NULL;

    mx_init_user();
    mx_change_user_name("Vitalii", "Svietkov");
    mx_change_user_pseudonim("mypseudo");
    mx_change_user_description("Hello, World!");
  
    gtk_init(&argc, &argv);

    GtkCssProvider *cssProvider = gtk_css_provider_new();
    gtk_css_provider_load_from_path(cssProvider, "client/css/uchat.css", NULL);
    gtk_style_context_add_provider_for_screen(gdk_screen_get_default(),
        GTK_STYLE_PROVIDER(cssProvider), GTK_STYLE_PROVIDER_PRIORITY_USER);

    mx_load_images();
  
    // Create a new window
    window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    mx_init_window(&window);

    // Create a main area where all widgets will be shown
    mx_configure_main_area(&background, &window);

    // Create a header for left area
    mx_configure_left_header(&left_header, &entry_search);

    // Create a selection area
    mx_configure_content_selection_area(&content_selection_area);

    // Create a chat enter area
    mx_configure_message_enter_area(&message_enter_area, &entry_chat);

    // Create a chat list area
    chats_list = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    gtk_fixed_put(GTK_FIXED(chat_area), chats_list, 0, 95);
    active_leftbar_container = NULL;

    // Create a contacts list area
    contacts_list = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    gtk_fixed_put(GTK_FIXED(chat_area), contacts_list, 0, 95);

    // Create a settings menu
    mx_configure_settings_menu_area();

    gtk_widget_show_all (window);
    // Hide unneccessary widgets
    gtk_widget_hide(GTK_WIDGET(tick_image.box));
    gtk_widget_hide(GTK_WIDGET(contacts_list));
    gtk_widget_hide(GTK_WIDGET(settings_menu));
    gtk_widget_hide(GTK_WIDGET(message_enter_area));
    // Return sensativity for entries
    gtk_widget_set_sensitive(GTK_WIDGET(entry_search), TRUE);
    gtk_widget_set_sensitive(GTK_WIDGET(entry_chat), TRUE);


    gtk_main();
    g_object_unref(G_OBJECT(t_user.avatar));
    free(t_user.FirstName);
    free(t_user.SecondName);
    free(t_user.pseudonim);
    free(t_user.description);
  
    return 0;
}
