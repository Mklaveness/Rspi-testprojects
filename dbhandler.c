#include "dbhandler.h"
#include <sqlite3.h>

#include "stdint.h"

void openDB(sqlite3 **db){
int rc = sqlite3_open("Dartscores.db", db);

if(rc != SQLITE_OK){
printf("kunne ikke åpne spiller databasen\n");
}
else{
printf("DB'n åpna sukksesfult\n");
}
}


int findPlayer(sqlite3 **db, int id){
sqlite3_stmt *stmt;

const char *sql = "select * from Brukere where id = ?";

int rc = sqlite3_prepare_v2(*db, sql, -1, &stmt, NULL);
if(rc != SQLITE_OK){
fprintf(stderr, "could not run sql statement: %s\n", sqlite3_errmsg(*db));
return -1;
}

rc = sqlite3_bind_int(stmt, 1, id);
if(rc != SQLITE_OK){
sqlite3_finalize(stmt);
printf("could not bind id to querry");
return -1;
}

rc = sqlite3_step(stmt);
if(rc == SQLITE_ROW){
int player = sqlite3_column_int(stmt, 0);
sqlite3_finalize(stmt);
return player;
}
else{
printf("could not find any player");
sqlite3_finalize(stmt);
return -1;
}
}
