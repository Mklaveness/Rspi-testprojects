#ifndef PLAYER_H
#define PLAYER_H

#include "sqlite3.h"

typedef struct{
int id;
char name[30];
int tlfnr;
char email[30];
char username[30];
} user;


int findPlayer(sqlite3 **db, char *username);
int addPlayer(sqlite3 **db, char *name, int tlf, char *email, char *username);

#endif

