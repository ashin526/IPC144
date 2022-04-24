/*
	==================================================
	Workshop #4 (Part-2):
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
	int priority[10], wish, done = 0, items = 0, selection, year, month, importance;
	double cost[10], income = 0, sum = 0, sum1 = 0, sum2 = 0, sum3 = 0;
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

		while (done >= 0){
			printf("\nHow do you want to forecast your wish list?\n");
			printf(" 1. All items (no filter)\n");
			printf(" 2. By priority\n");
			printf(" 0. Quit/Exit\n");
			printf("Selection: ");
			scanf("%d", &selection);

			if (selection == 0){
				printf("\nBest of luck in all your future endeavours!");
				break;
			} 
			else if (selection == 1){
				month = sum / income;
				year = month / 12 ;
				month = (month%12) + 1;
				printf("\n====================================================\n");

				printf("Filter:   All items\n");
				printf("Amount:   $%1.2lf\n", sum);
				printf("Forecast: %d years, %d months\n", year, month);

				for (wish = 0; wish < items; wish++){
					if (finance[wish] == 'y'){
						printf("NOTE: Financing options are available on some items.\n");
						printf("      You can likely reduce the estimated months.\n");

						break;
					}
				}

				printf("====================================================\n");
			}
				else if (selection == 2){
					printf("\nWhat priority do you want to filter by? [1-3]: ");
					scanf("%d", &importance);
						if (importance == 1){
							for (wish = 0; wish < items; wish++){
								if (priority[wish] == 1){
										sum1 = sum1 + cost[wish];
										month = sum1 / income;
										year = month / 12;
										month = (month % 12) + 1;
								}
							}
				printf("\n====================================================\n");
					printf("Filter:   by priority (1)\n");
					printf("Amount:   $%1.2lf\n", sum1);
					printf("Forecast: %d years, %d months\n", year, month);

				for (wish = 0; wish < items; wish++){
					if (finance[wish] == 'y'){
						printf("NOTE: Financing options are available on some items.\n");
						printf("      You can likely reduce the estimated months.\n");
						break;
					}
				}

				printf("====================================================\n");
				}

				else if (importance == 2){
					for (wish = 0; wish < items; wish++){
						if (priority[wish] == 2){
							sum2 = sum2 + cost[wish];
							month = sum2 /income;
							year = month / 12;
							month = (month % 12) + 1;
						}
					}

				printf("\n====================================================\n");
				printf("Filter:   by priority (2)\n");
				printf("Amount:   $%1.2lf\n", sum2);
				printf("Forecast: %d years, %d months\n", year, month);
					for (wish = 0; wish < items; wish++){
						if (finance[wish] == 'y'){
							break;
						}
					}
				printf("====================================================\n");
				}

				else if (importance == 3){
					for (wish = 0; wish < items; wish++){
						if (priority[wish] == 3){
							sum3 = sum3 + cost[wish];
							month = sum3 / income;
							year = month / 12;
							month = (month % 12) + 1;
						}
					}
				printf("\n====================================================\n");
					printf("Filter:   by priority (3)\n");
					printf("Amount:   $%1.2lf\n", sum3);
					printf("Forecast: %d years, %d months\n", year, month);

					for (wish = 0; wish < items; wish++){
						if (finance[wish] == 'y'){
							printf("NOTE: Financing options are available on some items.\n");
							printf("      You can likely reduce the estimated months.\n");
							break;
						}
					}
					printf("====================================================\n");
				}
			}
				else
				printf ("\nERROR: Invalid menu selection.\n");

			}

	return 0;
}

