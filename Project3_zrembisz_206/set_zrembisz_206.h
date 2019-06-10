#include <stdlib.h>
#include <stdio.h>
#include <string.h>


typedef struct node
{
	char *data;
	struct node *next;
}Node;


typedef struct
{
        Node *head;
        int count;
} set;

//Prototypes
set *createset();
int insert(char*, set*);
void printset(set*);
void *dmalloc(int size);
//int makeDelivery(Deliverynode **);



