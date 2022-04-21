/*
	==================================================
	Workshop #3 (Part-1):
	==================================================
	Name   : Anna Shin
	ID      : 131283210
	Email   : ashin8@myseneca.ca
	Section : NHH
*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define MIN_YEAR 2010
#define MAX_YEAR 2021
int main(){
	const int JAN=1,DEC=12;
	int year, mon;

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

	printf("\n*** Log date set! ***");
		if (mon == 1)
			printf("\nLog starting date: %d-JAN-01", year);
		else if (mon == 2)
			printf("\n\nLog starting date: %d-FEB-01", year);
		else if (mon == 3)
			printf("\n\nLog starting date: %d-MAR-01", year);
		else if (mon == 4)
			printf("\n\nLog starting date: %d-APR-01", year);
		else if (mon == 5)
			printf("\n\nLog starting date: %d-MAY-01", year);
		else if (mon == 6)
			printf("\n\nLog starting date: %d-JUN-01", year);
		else if (mon == 7)
			printf("\n\nLog starting date: %d-JUL-01", year);
		else if (mon == 8)
			printf("\n\nLog starting date: %d-AUG-01", year);
		else if (mon == 9)
			printf("\n\nLog starting date: %d-SEP-01", year);
		else if (mon == 10)
			printf("\n\nLog starting date: %d-OCT-01", year);
		else if (mon == 11)
			printf("\n\nLog starting date: %d-NOV-01", year);
		else if (mon == 12)
			printf("\n\nLog starting date: %d-DEC-01", year);
	
	return 0;
}