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
