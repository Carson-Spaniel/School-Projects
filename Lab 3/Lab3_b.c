//Carson Spaniel
#include <stdio.h>

int main() {
  char s[1000];
  int h = 0;

  printf("Enter a sentence to flip all alphebetical characters:\n");
  gets(s);

  for (int i = 0; s[i]!='\0'; i++)
    {
        if(s[i] >= 'a' && s[i] <= 'z') {
         s[i] = s[i] - 32;
          }
        else if(s[i] >= 'A' && s[i] <= 'Z') {
         s[i] = s[i] + 32;
          }
        else
        { 
        s[i] = s[i];
        }
      }
    while (s[h] != '\0')
  {
    printf("%c", s[h]);
    h++;
  }
  
  return 0;
}