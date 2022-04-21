/*
======================================================
workshop #2 (Part-2)
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
    int toonie, loonie, quarter, dime, nickel, pennie, amount;
    double dollars, fee, remain;

    printf("Change Maker Machine\n");
    printf("====================\n");
    
    printf("Enter dollars and cents amount to convert to coins: $");
    scanf("%lf", &dollars);

    fee = dollars * 0.05;
    printf("Service fee (5.0 percent): %.2lf\n", fee);

    remain = dollars - fee;
    printf("Balance to dispense: $%.2lf\n", remain);

    amount = remain * 100;

    toonie = amount / 200;
    amount = amount % 200;
    printf("\n$2.00 Toonies  X %d (remaining: $%.2lf)", toonie, (double)amount/100);

    loonie = amount / 100;
    amount = amount % 100;
    printf("\n$1.00 Loonies  X %d (remaining: $%.2lf)", loonie, (double)amount/100);

    quarter = amount / 25;
    amount = amount % 25;
    printf("\n$0.25 Quarters X %d (remaining: $%.2lf)", quarter, (double)amount/100);

    dime = amount / 10;
    amount = amount % 10;
    printf("\n$0.10 Dimes    X %d (remaining: $%.2lf)", dime, (double)amount/100);

    nickel = amount / 5;
    amount = amount % 5;
    printf("\n$0.05 Nickels  X %d (remaining: $%.2lf)", nickel, (double)amount/100);

    pennie = amount / 1;
    amount = amount % 1;
    printf("\n$0.01 Pennies  X %d (remaining: $%.2lf)", pennie, (double)amount/1);

    printf("\n\nAll coins dispensed!");

    return 0;
}