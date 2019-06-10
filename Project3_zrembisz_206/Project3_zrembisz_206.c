//Zachery Rembisz
//CS 262
//Lab206
//Project3_zrembisz_206.c


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "set_zrembisz_206.h"


//Struct for delivery node
typedef struct deliverynode
{
	set *data;
	struct deliverynode *next;
}Deliverynode;


//Prototypes
set makeDelivery(Deliverynode **);



int main(){

char answer;

//makes a dummy node for a list of deliveries and sets the next value to null
Deliverynode *headDummyNode = (Deliverynode *)dmalloc(sizeof(Deliverynode));
headDummyNode -> next = NULL;
//creates a set that will hold the delvery orders and allow deliveries to be printed
set *pizzaList = (set *)dmalloc(sizeof(set));


//Acts like the menu, repeating until 'n' is entered
while(1 == 1)
{	
	
printf("\nWould you like make a new pizza?!?!  (y/n)\n");
fgets(&answer, 10, stdin);

	
	switch(answer)
	{
		case 'y':				
			//Starts a new delivery order using the dummy node
			makeDelivery(&headDummyNode);
			break;				
		case 'n':
			printf("\nYour current list of orders are as follows:\n");
			printset(pizzaList);
			printf("\nYou are now exiting the program...bye, bye...\n");
			exit(0);
			break;	
		default:
			printf("\nNot a valid selection! Try again please!\n");
			break;	

	}	

}

}




set makeDelivery(Deliverynode **headDummyNode)
{
char top[25] = "filler";

Deliverynode *newDelivery = (Deliverynode *)dmalloc(sizeof(Deliverynode));
        
        if((*headDummyNode) -> next == NULL)
        {       
                (*headDummyNode) -> next = newDelivery;
        }
        else
        {       
                Deliverynode *temp = (*headDummyNode) -> next;
                (*headDummyNode) -> next = newDelivery;
                newDelivery -> next = temp;
        
        }

printf("Creating a new pizza now...\n");
set *newPizza = createset();
newDelivery -> data = newPizza;

printf("\nPlease enter your intial topping here:");
fgets(top, 25, stdin);


while(top[0] != '\n')
{
printf("\nPlease enter another topping to add ~OR~ hit 'enter' to stop and confirm current toppings:");
fgets(top, 25, stdin);
strtok(top, "\n");
 
printf("top is holding: %s\n", top);
       
        if(strlen(top) != 0)
        {       
                insert(top, newPizza);
        }

        else
        {
                printf("\nFinished adding to pizza...");
        }

}
return *newPizza;
}








