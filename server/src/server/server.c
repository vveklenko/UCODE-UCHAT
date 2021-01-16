#include "../../inc/server.h"

static server_context_t ctx;
static pthread_mutex_t ctx_mutex = PTHREAD_MUTEX_INITIALIZER;


static void server_context_init(void) {
    pthread_mutex_lock(&ctx_mutex);
    FD_ZERO (&ctx.read_descriptors);
    ctx.head.sock_fd = -1;
    ctx.head.is_logged = false;
    ctx.head.next = NULL;
    pthread_mutex_unlock(&ctx_mutex);
}

static void server_context_free(void) {
    pthread_mutex_lock(&ctx_mutex);
    for (connected_client_list_t *p = ctx.head.next; p != NULL; p = p->next) {
        close(p->sock_fd);
    }
    mx_socket_list_free(&ctx.head);
    pthread_mutex_unlock(&ctx_mutex);
}

/*
 * Checks, whether client closed the connection.
 * if true => deletes socket from server context.
 */
static bool update_connections(fd_set *descriptors) {
    char buffer[256];
    bool status = true;
    if (descriptors == NULL) return false;

    pthread_mutex_lock(&ctx_mutex);  
    for (connected_client_list_t *s = ctx.head.next; s != NULL; s = s->next) {
        if (recv(s->sock_fd, buffer, sizeof(buffer), MSG_PEEK | MSG_DONTWAIT) == 0) {
            mx_write_to_log("Connection on socket with socket fd %d was closed\n", 1);
            close(s->sock_fd);
            FD_CLR(s->sock_fd, &ctx.read_descriptors);
            if (mx_socket_list_remove(&ctx.head, s->sock_fd) < 0) {
                status = false;
            }
        }
    }
    *descriptors = ctx.read_descriptors;    
    pthread_mutex_unlock(&ctx_mutex);
    return status;
}


static void *handle_server(void *param) {
    int status;
    fd_set read_descriptors;
    struct timeval tv = wait_time(1, 0);

    while(true) {    
        update_connections(&read_descriptors);
        status = select(FD_SETSIZE, &read_descriptors, NULL, NULL, &tv);
        if (status <= 0) continue;
        
        pthread_mutex_lock(&ctx_mutex);
        //for (connected_client_list_t *p = ctx.head.next; p != NULL; p = p->next) {
        //    if (handle_connection(read_descriptors, p))
        //        break;
        //}
        pthread_mutex_unlock(&ctx_mutex);
    }
    return NULL;
}
int main(int argc,const char **argv) {
    mx_check_argv(argc, argv);
    int port = atoi(argv[1]);
    mx_check_port(port);
    int listening_socket = mx_listening_socket(port);
    mx_deamon();
    listen(listening_socket, 128);
    pthread_t server_thread;
    int err = pthread_create(&server_thread, NULL, handle_server, NULL);
    mx_error("Can not create new thread", err);
    while(true) {
        struct sockaddr_in client;
        socklen_t client_len = sizeof(client);
        int newsocketfd = accept(listening_socket, (struct sockaddr *)&client, &client_len);
        if (newsocketfd < 0) {
            continue;
        }
        pthread_mutex_lock(&ctx_mutex);
        int status = mx_socket_list_add(&ctx.head, newsocketfd);
        if (status == 0)
            FD_SET(newsocketfd, &ctx.read_descriptors);
        pthread_mutex_unlock(&ctx_mutex);
        mx_error("Unable to add socket descriptor to the list", status);
    }
}
