//Carson Spaniel

#include <stdio.h>
#include <string.h>

struct Player{
int playerid;
int playerpoints;
}player[4];

void getPlayerInfo(struct Player*)
{
  int i=0;
  for(i=0;i<=3;i++) {
    printf("\nPLAYER #%d\n",i+1);
    printf("---------");
    printf("\nPlayer's six digit ID: ");
    scanf("%d",&player[i].playerid);
    
    printf("Points scorced: ");
    scanf("%d",&player[i].playerpoints);
    
    }
}

void showInfo(struct Player)
{
  printf("\nPlayer ID     Points Scored\n");
  int i=0;
  for(i=0;i<=3;i++) {
  printf("%d        %d\n",player[i].playerid,player[i].playerpoints);
  }
}

int getTotalPoints(struct Player[], int)
{
  int sum=0;
  int i=0;
    for(i=0;i<=3;i++) {
    sum = sum + player[i].playerpoints;
  }
  printf("\nTOTAL POINTS: %d", sum);
}

int main(void) {
  int sum=0;
  int i=0;
  getPlayerInfo(&player[i]);
  showInfo(player[i]);
  getTotalPoints(&player[i], sum);
}