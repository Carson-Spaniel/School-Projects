//Carson Spaniel

#include <stdio.h>
#include <stdlib.h>
struct node
{
	float value;
	struct node* next;
	struct node* prev;
};
struct node* head = NULL;

void displayList()
{
	struct node* nodePtr;
	struct node* lastNode = NULL;
	if (head == NULL)
	{
		printf("List is empty\n");
		return;
	}

	nodePtr = head;
  
	while (nodePtr)
	{
		printf("%.0f  ", nodePtr->value);

		lastNode = nodePtr;

		nodePtr = nodePtr->next;
	}
	//printf("Last address: %p  \n\n", lastNode);
	printf("\n\nPrinting backwards: ");
  
	nodePtr = lastNode;
  
	while (nodePtr != NULL)
	{
		printf("%.0f  ", nodePtr->value);
		
		nodePtr = nodePtr->prev;
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
		newNode->prev=NULL;
	}
	else
	{

		nodeptr = head;
    
		while (nodeptr->next != NULL)
		{			
			nodeptr = nodeptr->next;
		}
		
		newNode->prev = nodeptr;
		nodeptr->next = newNode;
	}
}

void mid()
{
  int i=0;
  int j=0;
  int mid;
  struct node* nodePtr;

  	nodePtr = head;

	while (nodePtr)
	{
  i = i+1;
	nodePtr = nodePtr->next;
	}

  mid = i/2;
  nodePtr = head;

  for (j=0;j<mid;j++)
  {
    nodePtr = nodePtr->next;
    }
    printf("Middle ticket #: %.0f\n", nodePtr->value);
    printf("Ticket to the right: %.0f\n", nodePtr->prev->value);
    printf("Ticket to the left: %.0f\n", nodePtr->next->value);
}

int main()
{
	insert_end(4525856);
	insert_end(8653154);
	insert_end(2543679);
  insert_end(9543567);
	insert_end(5909866);
	insert_end(2468576);
  insert_end(9845645);

	printf("Values in the list: ");
	displayList();
	printf("\n\n");

  mid();
}
