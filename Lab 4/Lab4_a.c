//Carson Spaniel

#include <stdio.h>
#include <string.h>

struct Moviedata{
char title[20];
char director[50];
int year;
int runningtime;
};

void display(struct Moviedata movie1, struct Moviedata movie2){
  printf("Movie 1\n");
  printf("Title        : %s\n",movie1.title);
  printf("Director     : %s\n",movie1.director);
  printf("Released     : %d\n",movie1.year);
  printf("Running Time : %d minutes\n\n",movie1.runningtime);

  printf("Movie 2\n");
  printf("Title        : %s\n",movie2.title);
  printf("Director     : %s\n",movie2.director);
  printf("Released     : %d\n",movie2.year);
  printf("Running Time : %d minutes\n",movie2.runningtime);
}

int main(void) {
  struct Moviedata movie1;
  struct Moviedata movie2;
  
  strcpy(movie1.title, ("Alien Covenant"));
  strcpy(movie1.director, ("Byron Haskin"));
  movie1.year = 2017;
  movie1.runningtime = 88;

  strcpy(movie2.title, ("The Dark Tower"));
  strcpy(movie2.director, ("Nikolaj Arcel"));
  movie2.year = 2018;
  movie2.runningtime = 118;

  display(movie1,movie2);
  return 0;
}