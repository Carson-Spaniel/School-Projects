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
	struct node* nodePtr;  // To move through the list

	// Position nodePtr at the head of the list.
	nodePtr = head;

	// While nodePtr points to a node, traverse
	// the list.
	while (nodePtr)
	{
		// Display the value in this node.
		printf("%.2f  ", nodePtr->value);

		// Move to the next node.
		nodePtr = nodePtr->next;
	}
}

void insert_end(float num)//Appending a node
{
	struct node* newNode;// To point to a new node
	struct node* nodeptr;// To move through the list

	newNode = (struct node*)malloc(sizeof(struct node));
	newNode->value = num;
	newNode->next = NULL;//This node will become the last node in the list, its next pointer must be a null pointer.

	if (head == NULL)// If there are no nodes in the list, make newNode the first node.
	{
		head = newNode;//Making head point to the new node's location.
		//Note: newNode pointer variable contains the address of this node’s location. But newNode->next has the address of the node it is pointing too next in the list.	
	}
	else// Otherwise, insert newNode at end.
	{
		//The code uses nodePtr to travel down the list. It does this by first assigning nodePtr to start/head.
		nodeptr = head;// Initialize nodePtr to "head/start" of list. Now it's at the start of the list. 

		// Find the last node in the list.
		while (nodeptr->next != NULL)//While this is not nullptr
		{
			nodeptr = nodeptr->next;
		}//The last node will be the one whose next member points to nullptr.

		nodeptr->next = newNode;// Insert newNode as the last node.
		//Now the last node in the list point to the new node, instead of the nullptr.
		//But the newNode point to the nullptr.
	}
}

void insertNode(double num)
{
	struct node* newNode;					// A new node
	struct node* nodePtr;					// To traverse the list
	struct node* previousNode = NULL;	// The previous node

	// Allocate a new node and store num there.
	newNode = (struct node*)malloc(sizeof(struct node));
	newNode->value = num;

	// If there are no nodes in the list
	// make newNode the first node
	if (!head)
	{
		head = newNode;
		newNode->next = NULL;
	}
	else  // Otherwise, insert newNode
	{
		// Position nodePtr at the head of list.
		nodePtr = head;

		// Initialize previousNode to nullptr.
		previousNode = NULL;

		// Skip all nodes whose value is less than num.
		while (nodePtr != NULL && nodePtr->value < num)//nodePtr != nullptr: if it's not at the very end of the list
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
