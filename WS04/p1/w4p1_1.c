#define _CRT_SECURE_NO_WARNINGS
#define MIN_ITEMS 1
#define MAX_ITEMS 10
#include <stdio.h>
int main()
{
const double MIN_INCOME = 500 , MAX_INCOME = 400000;
int priority[10], key, flag = 0, itemList = 0;
double cost[10], income = 0, sum = 0;
char financeOption[10];

printf("+--------------------------+\n");
printf("+   Wish List Forecaster   |\n");
printf("+--------------------------+\n\n");

while (flag == 0)
{
printf("Enter your monthly NET income: $");
scanf("%lf", &income);

if (income < MIN_INCOME)
{
printf("ERROR: You must have a consistent monthly income of at least $500.00\n\n");
}
if (income > MAX_INCOME)
{
printf("ERROR: Liar! I'll believe you if you enter a value no more than $400000.00\n\n");
}
if ((income >= MIN_INCOME) && (income <= MAX_INCOME))
{
flag = 1;
}
}

flag = 0;
while (flag == 0)
{
printf("\nHow many wish list items do you want to forecast?: ");
scanf("%d", &itemList);

if ((itemList < 1) || (itemList > MAX_ITEMS))
{
printf("ERROR: List is restricted to between 1 and 10 items.\n");
}
else
{
flag = 1;
}
}

for (key = 0; key < itemList; key++)
{
printf("\nItem-%d Details:\n", (key + 1));
flag = 0;
while (flag == 0)
{
printf(" Item cost: $");
scanf("%lf", &cost[key]);
if (cost[key] < 100)
{
printf(" ERROR: Cost much be at least $100.00\n");
}
else
{
sum = sum + cost[key];
flag = 1;
}
}

flag = 0;
while (flag == 0)
{
printf(" How important is it to you? [1=must have, 2=important, 3=want]: ");
scanf("%d", &priority[key]);
if (priority[key] < 1 || priority[key] > 3)
{
printf(" ERROR: Value must be between 1 and 3\n");
}
else
{
flag = 1;
}
}

flag = 0;
while (flag == 0)
{
printf(" Does this item have financing options? [y/n]: ");
scanf("%s", &financeOption[key]);
if (financeOption[key] != 'y' && financeOption[key] != 'n')
{
printf(" ERROR: Must be a lowercase \'y\' or \'n\'\n");
}
else
{
flag = 1;
}
}
}

printf("\nItem Priority Finansed Cost\n");
printf("---- -------- -------- -----------\n");

for (key = 0; key < itemList; key++)
{
printf("%3d %5d %7c %11.2lf\n", (key + 1), priority[key], financeOption[key], cost[key]);
}

printf("---- -------- -------- -----------\n");
printf(" $%11.2lf\n\n", sum);

printf("Best of luck in all your future endeavours!");

return 0;
}