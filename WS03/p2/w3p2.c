/*
	==================================================
	Workshop #3 (Part-2):
	==================================================
	Name    : Anna Shin
	ID      : 131283210
	Email   : ashin8@myseneca.ca
	Section : NHH
*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define LOG_DAYS 3
#define MIN_YEAR 2010
#define MAX_YEAR 2021
int main(){
	const int JAN=1,DEC=12;
	int year, mon, day;
	double morning=0, evening=0, sumMorning=0, sumEvening=0, avgMorning=0, avgEvening=0, totalsum=0, totalavg=0;

    printf("General Well-being Log\n"); 
    printf("======================\n"); 
    printf("Set the year and month for the well-being log (YYYY MM): "); 
    scanf("%d %d", &year, &mon);
    
    while ((year < MIN_YEAR || year > MAX_YEAR) || (mon < JAN || mon > DEC)) { 
        if (year < MIN_YEAR || year > MAX_YEAR) { 
            printf("   ERROR: The year must be between 2010 and 2021 inclusive\n"); 
            } 
        if (mon < JAN || mon > DEC) { 
            printf("   ERROR: Jan.(1) - Dec.(12)\n"); 
            } 
        printf("Set the year and month for the well-being log (YYYY MM): "); 
        scanf("%d %d", &year, &mon);
    }

	printf("\n*** Log date set! ***\n");
	int i;
	for (i=1; i<=LOG_DAYS; i++){
		switch (mon){
			case 1:
				printf ("\n%d-JAN-%02d\n", year, i);
				break;
			case 2:
				printf ("\n%d-FEB-%02d\n", year, i);
				break;
			case 3:
				printf ("\n%d-MAR-%02d\n", year, i);
				break;
			case 4:
				printf ("\n%d-APR-%02d\n", year, i);
				break;
			case 5:
				printf ("\n%d-MAY-%02d\n", year, i);
				break;
			case 6:
				printf ("\n%d-JUN-%02d\n", year, i);
				break;
			case 7:
				printf ("\n%d-JUL-%02d\n", year, i);
				break;
			case 8:
				printf ("\n%d-AUG-%02d\n", year, i);
				break;
			case 9:
				printf ("\n%d-SEP-%02d\n", year, i);
				break;
			case 10:
				printf ("\n%d-OCT-%02d\n", year, i);
				break;
			case 11:
				printf ("\n%d-NOV-%02d\n", year, i);
				break;
			case 12:
				printf ("\n%d-DEC-%02d\n", year, i);
				break;
			default:
				break;
		}
		do {
			day = 1;
			printf("   Morning rating (0.0-5.0): ");
			scanf("%lf", &morning);
			
			if (morning < 0.0 || morning > 5.0){
				printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
			day = 0;
			}
		}
		while(day==0);
		do {
			day = 1;
			printf("   Evening rating (0.0-5.0): ");
			scanf("%lf", &evening);
			if (evening < 0.0 || evening > 5.0){
				printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
			day = 0;
			}
		}
		while(day==0);
		sumMorning += morning;
		sumEvening += evening;
		totalsum = sumMorning + sumEvening;
		avgMorning = sumMorning / LOG_DAYS;
		avgEvening = sumEvening / LOG_DAYS;
		totalavg = (avgMorning + avgEvening) / 2;
	}
	printf("\n");
	printf("Summary\n");
	printf("=======\n");
	printf("Morning total rating: %.3lf\n", sumMorning);
	printf("Evening total rating: %.3lf\n", sumEvening);
	printf("----------------------------\n");
	printf("Overall total rating: %.3lf\n\n", totalsum);
	printf("Average morning rating:  %.1lf\n", avgMorning);
	printf("Average evening rating:  %.1lf\n", avgEvening);
	printf("----------------------------\n");
	printf("Average overall rating:  %.1lf\n", totalavg);

	return 0;
}
