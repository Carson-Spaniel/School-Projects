#include <stdio.h>
int MAX = 5;
int stackArray[5];
int top = -1;

void push(int val)
{
	if (top == MAX - 1)
	{
		printf("\n STACK OVERFLOW");//Stack is full
	}
	else
	{
		top++;
		stackArray[top] = val;
	}
}
int pop()
{
  int val;
	if (top == -1)
	{
		printf("\n STACK UNDERFLOW");//Stack is empty
	}
	else
	{
		val = stackArray[top];
		//stackArray[top] = NULL;
		top--;
		return val;
	}
}

void add(){
  int val1;
  int val2;
  int sum;

  val1 = pop();
  val2 = pop();

  sum = val1 + val2;

  push(sum);
}

void divide(){
  int val1;
  int val2;
  int q;

  val1 = pop();
  val2 = pop();

  q = val1 / val2;

  push(q);
}

void display()
{
	int i;
	if (top == -1)
		printf("\n STACK IS EMPTY");
	else
	{
		for (i = top; i >= 0; i--)//Showing top of the stack first
		{
			printf("\n|%d|", stackArray[i]);
		}
  }
}

int main() {
  int val;
  
  printf("Pushing 5 values to the stack: ");
  printf("Pushing 10");
	push(10);
  printf("Pushing 12");
	push(12);
  printf("Pushing 15");
	push(15);
  printf("Pushing 20");
	push(20);
  printf("Pushing 25");
  push(25);

  printf("\nDisplaying the stack: ");
  display();

  printf("\n\n\nAdding top two numbers and pushing the sum onto the stack:");
  add();
	printf("\nDisplaying the stack: ");
	display();

    printf("\n\nPops the first two values off the stack and divide. Then push it back onto the stack:");
  divide();
	printf("\nDisplaying the stack: ");
	display();

  printf("\n\nPopping values from the stack:\n");
  val = pop();
  printf("%d\n",val);
  val = pop();
  printf("%d\n",val);
  val = pop();
  printf("%d\n",val);

  printf("\nAttempting to pop a value that isn't there:");
  pop();
  

  
	return 0;
}

