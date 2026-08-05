#include "Player.h"
#include "stdio.h"

#include "sqlite3"

void add_player(sqlite3 *db, char name){

const char *sql = "INSERT INTO players (name) VALUES (?);
sqlite3_bind_text(

}
