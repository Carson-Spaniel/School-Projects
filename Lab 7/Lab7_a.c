//Carson Spaniel
#include <stdio.h>
#include <stdlib.h>

struct node
{
  int data;
  struct node *next;
};

struct node *top = NULL;

void push(int val)
{
  struct node *nptr = malloc(sizeof(struct node));
  nptr->data = val;
  nptr->next = top;
  top = nptr;
}
int pop()
{
  int val;
  if (top == NULL)
  {
    printf("\n\nStack is empty ");
  }
  else
  {
    struct node *temp;
    temp = top;
    top = top->next;
    val = temp->data;
    return val;
    free(temp);
  }
}

void display()
{
  struct node *temp;
  temp = top;
  while (temp != NULL)
  {
      printf(" |%d|\n", temp->data);
      temp = temp->next;
  }
}

void win()
{
  int ticket;
  int val=0;
  struct node *temp;
  temp = top;

  printf("Enter your lottery ticket number: ");
  scanf("%d",&ticket);
  
  while (temp != NULL)
  {
    if (temp->data == ticket)
    {
      val = 1;
      break;
    }
    temp = temp->next;
  }
  if(val == 1) {
    printf("  Congratulations, you won!\n");
  }
  else {
    printf("  Sorry, you need to buy more tickets!\n");
  }
}

void change()
{
  int i=0;
  int j=0;
  int val[5];
  int mid=0;
  int h=0;
  struct node *temp;
  temp = top;
  
  while (temp != NULL)
  {
    i++;
    temp = temp->next;
  }
  mid = i/2;
  h = i - mid;
  
  for(j=0; j < h; j++)
  {
    val[j] = pop();
  }

  push(7653459);

  for(j=h-2; j > -1; j--)
  {
    push(val[j]);
  }
}

int main() {
  int val;
  
  printf("Pushing 7 values to the stack...");
	push(4525856);
	push(8653154);
	push(2543679);
	push(9543567);
  push(5909866);
	push(2468576);
  push(9845645);

  printf("\nDisplaying the stack: \n");
  display();
  printf("\n");

  win();

  change();
  printf("\nDisplaying the stack: \n");
  display();
}

