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
