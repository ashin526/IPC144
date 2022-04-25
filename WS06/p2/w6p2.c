/*
	==================================================
	Workshop #6 (Part-2):
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
#include "w6p2.h"

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
	printf("\nCat Food Product #%d\n", seq_num+1);
	printf("--------------------\n");
	printf("SKU           : ");
	cfi.sku = getIntPositive(&cfi.sku);
	printf("PRICE         : $");
	cfi.price = getDoublePositive(&cfi.price);
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
void displayCatFoodData(const int sku, const double* price, const int calories, const double* weight){
	printf("%07d %10.2lf %10.1lf %8d\n", sku, *price, *weight, calories);
	return;
}

// 8. convert lbs: kg (divide by 2.20462)
double convertLbsKg(const double* lbs, double* kg){
	double i;
	i = *lbs / KG_IN_LBS;
	if (kg != NULL){
		*kg = i;
	}
	return(i);
}

// 9. convert lbs: g (call convertKG, then * 1000)
int convertLbsG(const double* lbs, int* g){
	int j;
	j = convertLbsKg(lbs, 0) * 1000;
	if (g != NULL){
		*g = j;
	}
	return(j);
}

// 10. convert lbs: kg and g
void convertLbs(const double* lbs_conv, double* kg, int* g){
	convertLbsKg(lbs_conv, kg);
	convertLbsG(lbs_conv, g);
}

// 11. calculate: servings based on gPerServ
double calculateServings(const int vol, const int sum, double* result){
	double i;
	i = (double)sum / (double)vol;
	if (result != NULL){
		*result = i;
	}
	return(i);
}

// 12. calculate: cost per serving
double calculateCostPerServing(const double* price, const double* result, double* CostofResult){
	double cost = 0;
	cost = *price / *result;
	if (CostofResult != NULL){
		*CostofResult = cost;
	}
	return(cost);
}

// 13. calculate: cost per calories
double calculateCostPerCal(const double* price, const double* calories, double* Costcalories){
	double cost = 0;
	cost = *price / *calories;
	if (Costcalories != NULL){
		*Costcalories = cost;
	}
	return(cost);
}

// 14. Derive a reporting detail record based on the cat food product data
ReportData calculateReportData(CatFoodInfo cfi){
	ReportData display;
	double cal;
	display.sku2 = cfi.sku;
	display.price2 = cfi.price;
	display.pounds = cfi.weight;
	display.calories2 = cfi.calories;
	display.kg = convertLbsKg(&cfi.weight, &display.kg);
	display.g = convertLbsG(&cfi.weight, &display.g);
	display.totalser = calculateServings(SERVING_SIZE, display.g, &display.totalser);
	display.perser = calculateCostPerServing(&display.price2, &display.totalser, &display.perser);
	cal = display.calories2 * display.totalser;
	display.calser = calculateCostPerCal(&display.price2, &cal, &display.calser);
	return(display);
}

// 15. Display the formatted table header for the analysis results
void displayReportHeader(void)
{
	printf("\nAnalysis Report (Note: Serving = %dg\n", SERVING_SIZE);
	printf("---------------\n");
	printf("SKU         $Price    Bag-lbs     Bag-kg     Bag-g Cal/Serv Servings  $/Serv   $/Cal\n");
	printf("------- ---------- ---------- ---------- --------- -------- -------- ------- -------\n");
}

// 16. Display the formatted data row in the analysis table
void displayReportData(ReportData display, const int cheap){
printf("%07d %10.2lf %10.1lf %10.4lf %9d %8d %8.1lf %7.2lf %7.5lf", display.sku2, display.price2, display.pounds, display.kg, display.g, display.calories2, display.totalser, display.perser, display.calser);
}

// 17. Display the findings (cheapest)
void displayFinalAnalysis(CatFoodInfo cheap_product){
	printf("\n");
	printf("Final Analysis\n--------------\n");
	printf("Based on the comparison data, the PURRR-fect economical option is:\n");
	printf("SKU:%07d Price: $%.2lf\n\n", cheap_product.sku, cheap_product.price);
	printf("Happy shopping!\n");
}


// ----------------------------------------------------------------------------

// 7. Logic entry point
void start(void){
	CatFoodInfo cfi[MAX_NUM_PRODUCTS];
	int i = 0, cheapproduct = 0;
	openingMessage(MAX_NUM_PRODUCTS);
	for (i = 0; i < MAX_NUM_PRODUCTS; i++){
		cfi[i] = getCatFoodInfo(i);
	}
	displayCatFoodHeader();
	for (i = 0; i < MAX_NUM_PRODUCTS; i++){
		displayCatFoodData(cfi[i].sku, &cfi[i].price, cfi[i].calories, &cfi[i].weight);
	}
	
	ReportData repArray[MAX_NUM_PRODUCTS];
	displayReportHeader();
	for (i = 0; i < MAX_NUM_PRODUCTS; i++){
		repArray[i] = calculateReportData(cfi[i]);
		if (repArray[i].perser < repArray[i - 1].perser){
			cheapproduct = i;
		}
	}
	int j;
	for (j = 0; j < MAX_NUM_PRODUCTS; j++){
		ReportData x = { 0 };
		x = repArray[j];
		displayReportData(x, cheapproduct);
		if (cheapproduct == j){
			printf(" ***");
		}
		printf("\n");
	}
	displayFinalAnalysis(cfi[cheapproduct]);
}