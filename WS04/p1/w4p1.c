/*
	==================================================
	Workshop #4 (Part-1):
	==================================================
	Name    : Anna Shin
	ID      : 131283210
	Email   : ashin8@myseneca.ca
	Section : NHH
*/
#define _CRT_SECURE_NO_WARNINGS
#define MIN_ITEMS 1
#define MAX_ITEMS 10
#include <stdio.h>
int main(){

	const double min_income = 500 , max_income= 400000;
	int priority[10], wish, done = 0, items = 0;
	double cost[10], income = 0, sum = 0;
	char finance[10];

	printf("+--------------------------+\n");
	printf("+   Wish List Forecaster   |\n");
	printf("+--------------------------+\n\n");

	while (done == 0){
		printf("Enter your monthly NET income: $");
		scanf("%lf", &income);

		if (income < min_income){
			printf("ERROR: You must have a consistent monthly income of at least $500.00\n\n");
		}
		if (income > max_income){
			printf("ERROR: Liar! I'll believe you if you enter a value no more than $400000.00\n\n");
		}
		if ((income >= min_income) && (income <= max_income)){
			done = 1;
		}
	}

	done = 0;
	while (done == 0){	
		printf("\nHow many wish list items do you want to forecast?: ");
		scanf("%d", &items);

		if ((items < MIN_ITEMS) || (items > MAX_ITEMS)){
			printf("ERROR: List is restricted to between 1 and 10 items.\n");
		}
		else
			done = 1;
	}

	for (wish = 0; wish < items; wish++){
		printf("\nItem-%d Details:\n", (wish + 1));
		done = 0;

		while (done == 0){
			printf("   Item cost: $");
			scanf("%lf", &cost[wish]);
			if (cost[wish] < 100){
				printf("      ERROR: Cost must be at least $100.00\n");
			}
			else{
				sum = sum + cost[wish];
				done = 1;
			}
		}	

		done = 0;
		while (done == 0){
			printf("   How important is it to you? [1=must have, 2=important, 3=want]: ");
			scanf("%d", &priority[wish]);

			if (priority[wish] < 1 || priority[wish] > 3){
				printf("      ERROR: Value must be between 1 and 3\n");
			}
			else
				done = 1;
		}

		done = 0;
		while (done == 0){
			printf("   Does this item have financing options? [y/n]: ");
			scanf("%s", &finance[wish]);
			
			if (finance[wish] != 'y' && finance[wish] != 'n'){
				printf("      ERROR: Must be a lowercase \'y\' or \'n\'\n");
			}
			else
				done = 1;
		}
	}

	printf("\nItem Priority Financed        Cost\n");
	printf("---- -------- -------- -----------\n");

	for (wish = 0; wish < items; wish++){
		printf("%3d  %5d    %5c    %11.2lf\n", (wish + 1), priority[wish], finance[wish], cost[wish]);
	}

	printf("---- -------- -------- -----------\n");
	printf("                      $%11.2lf\n", sum);

	printf("\nBest of luck in all your future endeavours!");

	return 0;
}
