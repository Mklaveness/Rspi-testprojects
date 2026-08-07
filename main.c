#include <stdio.h>
#include "stdint.h"
#include "stdbool.h"
#include <sqlite3.h>

#include "ExitScore.h"
#include "dbhandler.h"
#include "Player.h"


typedef struct {

uint16_t points;
uint8_t dartC;
} player;

int main(){

int preferedG = 0;
player player1;
player1.points = 0;
player1.dartC = 0;
char P_username[30];

sqlite3 *db = NULL;
openDB(&db);

char pref[2];

bool gamestate = false;
bool guestMode = false;

while(1){

printf("[G]uest,  [U]ser,  [N]ew user\n");
scanf("%s", pref);

if(pref[0] == 'G'){
guestMode = true;
printf("Welcome guest:)\n");
}

else if(pref[0] == 'U'){
printf("please type your username: ");
scanf("%29s", P_username);
findPlayer(&db, P_username);
}

else if(pref[0] == 'N'){

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


