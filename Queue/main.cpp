#include <iostream>

#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

typedef struct queue
{
	int value;

	struct queue *next;
	
} Queue;

Queue *head = NULL;

Queue *end = NULL;

void Put(int item) 
{
	Queue *newQueue = (Queue*)malloc(sizeof(Queue));

	newQueue->value = item;
	newQueue->next = NULL;
	
	if(head == NULL)
		head = end = newQueue;
	else
	{
		end->next = newQueue;
		
		end = newQueue;
	}
}

int Get()
{
	if(head == NULL) return -1;
	
	int item = head->value;
	
	if(head == end)
	{
		free(head);
		head = end = NULL;		
	}
	else
	{
		
		Queue *_head = head;
	
		head = head->next;

		free(_head);
	}

	return item;
}

int Peek()
{
	if(head == NULL)
		return -1;

	return head->value;
}

int main(int argc, char** argv) 
{

	int keepGoing = 1;

	int wybor, item;

	while(keepGoing == 1)
	{

		printf("1. Put \n");

		printf("2. Get \n");

		printf("3. Peek \n");

		printf("4. Koniec \n");

		scanf("%d", &wybor);

		switch(wybor)
		{

			case 1:

				printf("Put item: "); scanf("%d", &item);

				Put(item);

				break;

			case 2:

				printf("(%d)", Get());

				break;

			case 3:

				printf("<%d>", Peek());

				break;

			case 4:

				keepGoing = 0;

				break;

		}

		printf("\n ----------------------------- \n");
	}

	return 0;

}


