#include <stdio.h>
#include "stdint.h"
#include "stdbool.h"
#include <sqlite3.h>

#include "ExitScore.h"
#include "dbhandler.h"



typedef struct {

uint16_t points;
uint8_t dartC;
} player;

int main(){

int preferedG = 0;
player player1;
player1.points = 0;
player1.dartC = 0;

sqlite3 *db = NULL;
openDB(&db);

char pref[5];

bool gamestate = false;
bool guestMode = false;

while(1){

printf("[G]uest,  [U]ser,  [N]ew user");
scanf("%s", pref);

if(pref == 'G'){
guestMode = true;
}
else if(pref == 'U'){
//finne gjeldende bruker ved hjelp av id
}
else if(pref == 'N'){
//ny bruker
}
else{
printf("invalid choice");
}


printf("\n");
printf("would you like 301 or 501?\n");
scanf("%d", &preferedG);

if(preferedG == 301 || preferedG == 501){
player1.points = preferedG;
gamestate = true;
printf("game choosen\n");
}

else{
player1.points = preferedG;
gamestate = false;
printf("invalid choice\n");
}


while(gamestate){

int buf_score;

printf("Please input score: ");
scanf("%d", &buf_score);

if(buf_score < 180){
player1.points -= buf_score;
player1.dartC += 3;

if(player1.points == 0){
gamestate = false;
printf("well done");
}

printf("\n");
printf("points = %d\n", player1.points);
printf("darts thrown = %d\n", player1.dartC);
printf("%s\n", calc_score(player1.points));
printf("\n");
}

else{
printf("invalid score!");
}


}
}
return 0;
}


