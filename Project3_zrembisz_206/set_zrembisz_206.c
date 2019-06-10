//Zack Rembisz
//CS262
//Lab 206
//Project 3

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "set_zrembisz_206.h"

//Initializes a new set to be used
//returns a pointer to that set
set *createset()
{
set *pizzaPtr = (set *)dmalloc(sizeof(set));
pizzaPtr -> count = 0;
pizzaPtr -> head = NULL;

return pizzaPtr;
}


//Inserts the toppings into a linked list
int insert(char *str, set *s)
{
Node *top = (Node *)dmalloc(sizeof(Node));
top -> data = str;
	
	//If this is first topping puts it here
	if(s -> head == NULL)
	{
		s -> head = top;
		s-> count++;
	}
	
	//otherwise goes through to find end of list to add topping
	else
	{
		Node *temp = s-> head;

		while((temp -> next != NULL))
		{
		temp = temp -> next;
		} 

top = temp;
s -> count++;

	}
}

//Should print the set of toppings using the nodes from the makeDelivery fucntion
void printset(set *s)
{

printf("\n\n*We are experiencing server complications, pizza data corrupted...please try again later...*\n\n");
//Causes seg fault if you try to access any of the data points of the passed set since its null
/*
 	//would have checked to see if set is empty in cases of no pizzas ordered
	if(s -> head == NULL)
	{
	printf("You forgot to order pizzas fam :(\n");
	}

	//Otherwise here would print out the topping and its number until all toppings printed
	else
	{
		while(s -> head != NULL)
		{
		printf("Topping#%d: %s\n",s -> count,  s -> head -> data);
		s -> head = s -> head -> next;
		}
	}
*/
}


/* compares strings for alphabetical ordering */
int strcmpi(char *s, char *t)
{
   while (*s && tolower(*s) == tolower(*t))
   {
      s++;
      t++;
   }
   return tolower(*s) - tolower(*t);
}


/* allocates memory with a check for successful allocation */
void *dmalloc(int size)
{
   void *p = malloc(size);
   if (!p)
   {
      printf("memory allocation failed\n");
      exit(1);
   }
   return p;
}


