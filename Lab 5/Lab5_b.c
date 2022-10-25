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

int display()
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

int highlow(exam[])
{
    int i=0;
    double highest=exam[0];
    double lowest=exam[0];
    for(i=0;i<=6;i++) 
    {
    if (exam[i]>highest)
      {
        highest = exam[i];
      }
    if (exam[i]<lowest)
      {
        lowest = exam[i];
      }
  }
  printf("  Highest value: %.2f Highest address: %p\n", highest, &highest);
  printf("  Lowest value: %.2f Lowest address: %p\n", lowest, &lowest);
}

void modifyNode(exam[])
 {
  struct node* newNode;
	struct node* nodePtr;
	struct node* previousNode = NULL;	
    int i=0;
    double lowest=exam[0];
    for(i=0;i<=6;i++) 
    {
    if (exam[i]<lowest)
      {
        lowest = exam[i];
      }

    }

   nodePtr = head;

   while (nodePtr)
     {
       if(nodePtr->value == lowest)
        {
          nodePtr->value = 70;

        }
      nodePtr = nodePtr->next;
      }
  lowest = 70;
  printf("  Address of the new node with the lowest value: %p\n", &lowest);
}

void deleteNode(exam[])
{
	struct node* nodePtr;
    int i=0;
    double highest=exam[0];
    for(i=0;i<=6;i++) 
    {
    if (exam[i]>highest)
      {
        highest = exam[i];
      }
  }
     nodePtr = head;

      struct node *temp;

      if((nodePtr)->value == highest)
      {
          temp = nodePtr;
          nodePtr = nodePtr->next;
          free(temp);
      }
      
      else
      {
          struct node *previousNode = head;
          while(previousNode->next != NULL)
          {
              if(previousNode->next->value == highest)
              {
                  temp = previousNode->next;
                  previousNode->next = previousNode->next->next;
                  free(temp);
                  break;
              }
              else
                  previousNode = previousNode->next;
          }
      }
}

int main()
{
  int *exam[7];
  int i;
  //Part 1
  entergrades(&exam[i]);
  printf("1) Highest and the Lowest exam scores among the linked list:\n");
  highlow(&exam[i]);
  display();
  average(&exam[i]);

  //Part 2
  printf("\n2) Replace the lowest exam score with a new node that has the value 70:\n");
  modifyNode(&exam[i]);
  display();

  //Part 3
  printf("\n3) Delete the highest exam score from the list and display the list:\n");
  deleteNode(&exam[i]);
  display();

  //Part 4
  printf("\n4) Calculate and display the class average:\n");
  average(&exam[i]);
}