/*
======================================================
workshop #2 (Part-1)
======================================================
Name    : Anna Shin
ID      : 131283210
Email   : ashin8@myseneca.ca
Section : NHH
*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
    int toonie, loonie, quarter;
    double dollars, toore, loore, quare;

    printf("Change Maker Machine\n");
    printf("====================\n");
    printf("Enter dollars and cents amount to convert to coins: $");
    scanf("%lf", &dollars);

	toonie = dollars * 100 / 200;
	toore = dollars - (toonie * 2);
    printf("\n$2.00 Toonies  X %d (remaining: $%.2lf)", toonie, toore);

    loonie = toore * 100 / 100;
    loore = toore - (loonie * 1);
    printf("\n$1.00 Loonies  X %d (remaining: $%.2lf)", loonie, loore);

    quarter = loore * 100 / 25;
    quare = loore - (quarter * 0.25);
    printf("\n$0.25 Quarters X %d (remaining: $%.2lf)", quarter, quare);

    printf("\n\nMachine error! Thank you for letting me keep $%.2lf!\n", quare);

    return 0;
}