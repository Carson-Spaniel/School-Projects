//Carson Spaniel
#include <stdio.h>

int main() {
  char firststring[50] = "Appending a string";
	char secondstring[25] = " to the end";

  int i = 0;
  while (firststring[i] != '\0')
    {
      i++;
    }
  int j = 0;
  while (secondstring[j] != 0)
    {
      firststring[i] = secondstring[j];
      i++;
      j++;
    }
  
  int h;
  //for (h = 0; h < i; h++)
  //{
  //  printf("%c", firststring[h]);
  //}

  //printf("\n");
  
  for (h = i; h > -1; h--)
  {
    printf("%c", firststring[h]);
  }
}