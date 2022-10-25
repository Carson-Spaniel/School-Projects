//Carson Spaniel
#include <stdio.h>
#include <stdlib.h>
struct node
{
	float value;
	struct node* next;
};
struct node* head = NULL;

void displayList()
{
	struct node* nodePtr;

	nodePtr = head;

	while (nodePtr)
	{
		printf("%.2f  ", nodePtr->value);

		nodePtr = nodePtr->next;
	}
}

void insert_end(float num)
{
	struct node* newNode;
	struct node* nodeptr;

	newNode = (struct node*)malloc(sizeof(struct node));
	newNode->value = num;
	newNode->next = NULL;

	if (head == NULL)
	{
		head = newNode;
	}
	else
	{
		nodeptr = head;

		while (nodeptr->next != NULL)
		{
			nodeptr = nodeptr->next;
		}

		nodeptr->next = newNode;
	}
}

void insertNode(double num)
{
	struct node* newNode;
	struct node* nodePtr;
	struct node* previousNode = NULL;

	newNode = (struct node*)malloc(sizeof(struct node));
	newNode->value = num;

	if (!head)
	{
		head = newNode;
		newNode->next = NULL;
	}
	else
	{
		nodePtr = head;

		previousNode = NULL;

		while (nodePtr != NULL && nodePtr->value < num)
		{
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
		}
				
		previousNode->next = newNode;
		newNode->next = nodePtr;		
	}
}

int entergrades(exam[])
{
    printf("Enter seven exam scores for your class\n");
  int i;
  for (i=0;i<7;i++){
    printf("Enter grade for Exam %d: ",i+1);
    scanf("%d",&exam[i]);
    insert_end(exam[i]);
    }
}

int display(exam[])
{
	printf("List of Exam Grades: ");
	displayList();
	printf("\n");
}

int average(exam[])
{
  int sum=0;
  double average=0;
  int i=0;

	struct node* nodePtr;

	nodePtr = head;

	while (nodePtr)
	{
		i++;
		sum = sum + nodePtr->value;

		nodePtr = nodePtr->next;
	}
  
  average = (sum/i);
  printf("Class average: %.2f\n", average);
}

int main()
{
  int *exam[7];
  int i;
  entergrades(&exam[i]);
  printf("\nHere are all the exam scores you have entered:\n");
  display(exam[i]);
  average(&exam[i]);
}
