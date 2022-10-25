//lab2-b
//Carson Spaniel

#include <stdio.h>

int main()
{
  float food[3][5];

  float total;
  
 int i, j;
 for(i=1; i<4; i++) {
   total = 0;
    for(j=1;j<6;j++) {
       printf("Pounds of food for Monkey #%d on day #%d:", i, j);
       scanf("%f", &food[i][j]);
         total += food[i][j];
    }
   
   printf("Monkey #%d ate %.1f pounds worth of food\n",i,total);
   printf("\n");
 }

	return 0;
}

