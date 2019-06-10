#include <stdlib.h>
#include <stdio.h>

int rollDice();
void printRules();
int playGame(double);

int main(){

double bank = 100;
printRules();
printf("\n\nCurrent bank amount = %lf", bank);
playGame(bank);
return 0;
}

int rollDice(){

static int rolls[5];
int i;
int seed;
int sum;
int userinteraction = 0;


printf("\nPlease enter a integer for seed: ");
scanf(" %d", &seed);
srandom(seed);


printf("Please enter '1' to roll the dice: ");
scanf(" %d", &userinteraction);

if(userinteraction = 1){
for(i = 0; i < 2; i++){
rolls[i] = rand()%6+1;
}

printf("Dice 1 rolled: ");
printf("%d\n", rolls[0]);
printf("Dice 2 rolled: ");
printf("%d\n", rolls[1]);

sum = rolls[0] + rolls[1];
return sum;
}
else{
printf("\nFine! I`f you don't want to roll the dice, you don't get to play.");
}
}

void printRules(){

printf("The basic rules of Craps are as follow:\n");
printf("You can bet for yourself (Pass Line) or against (Don't Pass Line)\n");
printf("For Pass Line:\n\t -A combined FIRST dice roll of 7 or 11 is an automatic win");
printf("\n\t -A combined FIRST roll of 2,3, or 12 is an immediate loss");
printf("\n\t -If the first roll is a number other than 2, 3, 7, 11 or 12, the number that is rolled is called the 'point'");
printf("\n\t -At this point you  may press the bet (aka double up)");
printf("\n\t -The goal now is to roll your original point (first dice roll) or until rolling a 7 which ends your run");
printf("\n\n For Don't Pass Line:\n\t -A combined FIRST dice roll of 2,3, or 12 is an automatic win");
printf("\n\t -A combined FIRST roll of 7 or 11 is an immediate loss");
printf("\n\t -A combined FIRST roll of a number other than 2, 3, 7, 11 or 12 will set your 'point'");
printf("\n\t -The goal now is to roll a 7 to win the bet, and if you roll your point number again, you lose the bet");
printf("\n\t -(Pressing the bet is the same as for 'Pass Line')");

}


int playGame(double initial){

double cbank = initial;
double bet = 0;
char choice;
int play;


while(bet < 5){
printf("\nHow much would you like to bet? (Minimum of 5.00):\n");
scanf(" %lf", &bet);
}

printf("\nTo play 'for' yourself, press 'f'");
printf("\n\t OR");
printf("\nTo play 'against' youself, press 'a'\n");
scanf("%s", &choice);

switch(choice){

	case 'f':
	case 'F':
		printf("\nPass Line selected\n");
		play = 1;
		break;

	case 'a':
	case 'A':
		printf("\nDon't Pass Line selected\n");
		play = 2;
		break;
	
	default:
		printf("\nThat was an invalid input. Please try again!\n");
		break;
}

if(play == 1){
		int sum = rollDice();
		if(sum == 7 || sum == 11){
			printf("You win!\n");
			return (bet + cbank);
		}
		else if(sum == 2 || sum == 3 || sum == 12){
			printf("You lose!\n");
			return (cbank - bet);
		}
		else{
			int point = sum;
			int ndr = 0;
			int loopbreak = 1;
			while(loopbreak = 1){
			ndr = rollDice();
				if(ndr == point){
				printf("You Win!\n");
				return (bet + cbank);
				break;
				}
				else if(ndr == 7){
				printf("You lose!\n");
				return (cbank - bet);
				}
				else{
				printf("\n Welp, you got niether");
				}
			}

			
		}
}

else if(play == 2){

		int sum = rollDice();
                if(sum == 2 || sum == 3 || sum == 12){
                        printf("You win!\n");
                        return (bet + cbank);
                }
                else if(sum == 7 || sum == 11){
                        printf("You lose!\n");
                        return (cbank - bet);
                }
                else{
                        int point = sum;
                        int ndr = 0;
                        int loopbreak = 1;
                        while(loopbreak = 1){
                        ndr = rollDice();
                                if(ndr == point){
                                printf("You Lose!\n");
                                return (cbank + bet);
                                break;
                                }
                                else if(ndr == 7){
                                printf("You Win!\n");
                                return (cbank + bet);
                                }
                                else{
                                printf("\n Welp, you got niether");
                                }
                        }                               

                        
               } 





}				
else{
	printf("This shouldn't be possible");
}

}
