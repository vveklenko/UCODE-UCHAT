#include "../inc/uchat_client.h"

void mx_init_global_vars(void) {
    // Containers
    window = NULL;
    main_area = NULL;
    authorization_area = NULL;
    chat_area = NULL;
    message_enter_area = NULL;
    chats_list = NULL;
    settings_menu = NULL;

    // Temporary variables for edit user form
    NewFirstName = NULL;
    NewSecondName = NULL;
    NewPseudonim = NULL;
    NewDescription = NULL;
    NewAvatar = NULL;

    language = 0;
    text_for_labels = NULL;
}
