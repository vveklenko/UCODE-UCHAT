#include "../inc/uchat_client.h"

// Initialize database, if it does not exist.
void mx_database_init(void) {
    sqlite3 *db = mx_opening_db();
    int exit = 0;
    char *message_error;
    char *sql = "CREATE TABLE IF NOT EXISTS USERS("
        "NAME      TEXT NOT NULL, "
        "SURENAME  TEXT NOT NULL, "
        "PSEUDONIM TEXT NOT NULL, "
        "DESCRIPTION TEXT NOT NULL);";
    exit = sqlite3_exec(db, sql, NULL, 0, &message_error);
    mx_dberror(db, exit, "Error to create USERS table");
    sqlite3_close(db);
}
