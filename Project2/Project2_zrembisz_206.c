#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Prototypes
void readCipherKey();
int optionSwitch(int optionNum);
void printMenu();
void optionTwo();
void straightToTheBank();
void decodeCipher();


int main(){

//int *optionPtr;
printMenu();
return 0;

}




void printMenu(){
int optionNum;

printf("Welcome to the Beale Cipher program, what would you like to do first?\n"); //This is the menu prompt
printf("-To read in the name of a text file to use as a cipher key, enter '1'\n");
printf("-To create a cipher using the input file, enter '2'\n");
printf("-To decode an existing cipher, enter '3'\n");
printf("-To have some fun, enter '4'\n");
printf("-To exit the program, enter '5'\n");
printf("Enter the option: ");
scanf(" %d", &optionNum); //Reads in the choice selected by the user

optionSwitch(optionNum);

}




int optionSwitch(int optionNum){
int option;
option = optionNum;

switch(option){ //takes user to desired choice

case 1 :
	printf("\nOption 1 selected\n");
	readCipherKey();
	return 0;
	break;
case 2 :
	printf("\nOption 2 selected\n");
	optionTwo();
	return 0;
	break;
case 3 : 
	printf("\nOption 3 selected\n");
	decodeCipher();
	return 0;
	break;
case 4:
	printf("\nSuper Secret option selected...\n");
	straightToTheBank();
	return 0;
	break;
default: 
	printf("\nExiting program now...\n");
	return 0;
	break;
}

}





void readCipherKey(){

int i = 0;
FILE *infile = NULL;	//declares a new input file pointer
char buff[5000];
char fpath[100];	 //stores path to desired file to read in
char *spos;
char* words[5000];
char lwords[5000];
//char **pointerToWords = &words[i];
int x;

printf("\n\nPlease enter the ENTIRE name of the file you would like to read in: \n");
scanf(" %s", &fpath);
printf("\n");
infile = fopen(fpath, "r");
	if(infile==NULL)
	{
		printf("\n%s FILE NOT FOUND\n\n", fpath);
		printMenu();
	}

while (fgets(buff,5000,infile) != NULL)
	{
	spos = strtok(buff," ',.");
		while(spos != NULL)
		{
		printf("%s\n", spos);
		words[i] = spos;	//puts each token'ed word into a array
		i++;			//keeps track of how many words
		spos = strtok(NULL, " ',.");
		}
	}
printf("Value of i is: %d\n", i);

for(x = 0;x < i; x++)
{
int y = x + 1;
//strcpy(lwords[x], = words[x]);		//Causes a seg fault
printf("The %d element is: %s\n",y,words[x]);
}

fclose(infile);

printMenu(); //goes back to main menu to select other options
}



void optionTwo(){

printf("This section of the code has been locked. To unlock OPTION 2 DLC, please purchase the DLC expansion\n");printf("Cost: $59.99\n");
printf("Content incuded: Absolutely nothing\n");
printf("Developed by Ubisoft (tm)\n\n");
printMenu();

}



void straightToTheBank(){

printf("Congratualtions! You have discovered the Beale treasure!\n"); //prints out eh big bucks
printf("     -------     \n");
printf("    |   $   |    \n");
printf("    |   1   |    \n");
printf("    |   0   |    \n");
printf("    |   0   |    \n");
printf("    |   0   |    \n");
printf("     -------     \n");

}



void decodeCipher(){

FILE *infile = NULL;    //declares a new input file pointer
char buff[1000];
char fpath[100];         //stores path to desired file to read in
char *spos;
char *decipherText[1000];
int i;
int coordinates[2000];
int x;


printf("\n\nPlease enter the ENTIRE name of file containing the encoded text: \n");
scanf(" %s", &fpath);
printf("\n");
infile = fopen(fpath, "r");
        if(infile==NULL)
        {
                printf("\n%s FILE NOT FOUND\n\n", fpath);
                printMenu();
        }


while (fgets(buff,1000,infile) != NULL)
        {
        
                while(spos != NULL)
                {
                printf("%s\n", spos);
                decipherText[i] = spos;        //puts each token'ed word into a array
                i++;                    //keeps track of how many words
                spos = strtok(NULL, " ',.");
                }
for(x = 0; x<i;x++)
{
coordinates[x] = atoi(decipherText[x]);
}



//No matter what I tried, I couldnt figure out how to sperate the words from the array into characters so i could check them against the encoded numbers.

}

}
