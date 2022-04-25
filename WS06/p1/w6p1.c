/*
	==================================================
	Workshop #6 (Part-1):
	==================================================
	Name   : Anna Shin
	ID     : 131283210
	Email  : ashin8@myseneca.ca	
	Section: NHH
*/

#define _CRT_SECURE_NO_WARNINGS
// System Libraries
#include <stdio.h>
// User-Defined Libraries
#include "w6p1.h"

// ----------------------------------------------------------------------------
// PART-1
// 1. Get user input of int type and validate for a positive non-zero number
// (return the number while also assigning it to the pointer argument)
int getIntPositive(int *number){
	int rtnVal=0;
	do{
		scanf("%d", &rtnVal);
		if(rtnVal <=0)
			printf("ERROR: Enter a positive value: ");
	}
	while(rtnVal <=0 );
	if(number != NULL)
		*number = rtnVal;
	return rtnVal;
}

// 2. Get user input of double type and validate for a positive non-zero number
// (return the number while also assigning it to the pointer argument)
double getDoublePositive(double *number){
	double rtnVal=0.0;
	do{
		scanf("%lf", &rtnVal);
		if(rtnVal <=0.0)
			printf("ERROR: Enter a positive value: ");
	}
	while(rtnVal <= 0.0);
	if(number != NULL)
		*number = rtnVal;
	return rtnVal;
}

// 3. Opening Message (include the number of products that need entering)
void openingMessage(const int num_of_products){
	printf("Cat Food Cost Analysis\n");
	printf("======================\n\n");

	printf("Enter the details for %d dry food bags of product data for analysis.\n", MAX_NUM_PRODUCTS);

	printf("NOTE: A 'serving' is %dg\n", SERVING_SIZE);

	return;
}

// 4. Get user input for the details of cat food product
CatFoodInfo getCatFoodInfo(const int seq_num){
	CatFoodInfo cfi = {0};
	printf("\nCat Food Product #%d\n", seq_num);
	printf("--------------------\n");
	printf("SKU           : ");
	cfi.sku = getIntPositive(NULL);
	printf("PRICE         : $");
	cfi.price = getDoublePositive(0);
	printf("WEIGHT (LBS)  : ");
	getDoublePositive(&cfi.weight);
	printf("CALORIES/SERV.: ");
	getIntPositive(&cfi.calories);
	return cfi;	
}

// 5. Display the formatted table header
void displayCatFoodHeader(void)
{
	printf("\nSKU         $Price    Bag-lbs Cal/Serv\n");
	printf("------- ---------- ---------- --------\n");
	return;
}

// 6. Display a formatted record of cat food data
void displayCatFoodData(const CatFoodInfo cfi){
	printf("%07d %10.2lf %10.1lf %8d\n", cfi.sku, cfi.price, cfi.weight, cfi.calories);
	return;
}
// ----------------------------------------------------------------------------
// 7. Logic entry point
void start(){
	CatFoodInfo cfi[MAX_NUM_PRODUCTS];
	int i;
	openingMessage(MAX_NUM_PRODUCTS);
	for (i=0; i<MAX_NUM_PRODUCTS; i++)
		cfi[i]=getCatFoodInfo(i+1);
	displayCatFoodHeader();
	for (i=0; i<MAX_NUM_PRODUCTS; i++)
		displayCatFoodData(cfi[i]);
	return;
}