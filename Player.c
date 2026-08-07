#include "Player.h"
#include "stdio.h"
#include "string.h"

#include "sqlite3.h"


int findPlayer(sqlite3 **db, char *username){
sqlite3_stmt *stmt;

const char *sql = "select * from player where username = ?";

int rc = sqlite3_prepare_v2(*db, sql, -1, &stmt, NULL);
if(rc != SQLITE_OK){
fprintf(stderr, "could not run sql statement: %s\n", sqlite3_errmsg(*db));
return -1;
}

rc = sqlite3_bind_text(stmt, 1, username, -1, SQLITE_TRANSIENT);
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


int addPlayer(sqlite3 **db, char *name, int tlf, char *email, char *username){
sqlite3_stmt *stmt;

const char *sql = "INSERT INTO player(name, tlfnr, email, username) VALUES (?, ?, ?, ?)";

int rc = sqlite3_prepare_v2(*db, sql, -1, &stmt, NULL);

if(rc != SQLITE_OK){
printf("prepare statement failed: %s\n", sqlite3_errmsg(*db));
return -1;
}

sqlite3_bind_text(stmt, 1, name, -1, SQLITE_TRANSIENT);
sqlite3_bind_int(stmt, 2, tlf);
sqlite3_bind_text(stmt, 3, email, -1, SQLITE_TRANSIENT);
sqlite3_bind_text(stmt, 4, username, -1, SQLITE_TRANSIENT);

rc = sqlite3_step(stmt);

if(rc != SQLITE_DONE){
printf("insert failed: %s\n", sqlite3_errmsg(*db));
sqlite3_finalize(stmt);
return -1;
}

sqlite3_finalize(stmt);
return 0;
}







