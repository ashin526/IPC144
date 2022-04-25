/*
	==================================================
	Workshop #6 (Part-1):
	==================================================
	Name   : Anna Shin
	ID     : 131283210
	Email  : ashin8@myseneca.ca	
	Section: NHH
*/

// ----------------------------------------------------------------------------
// defines/macros
#define MAX_NUM_PRODUCTS 3
#define SERVING_SIZE 64

// ----------------------------------------------------------------------------
// structures
typedef struct {
	int sku;
	double price;
	int calories;
	double weight;
} CatFoodInfo;

// PART-1

// Function: 1. Get user input of int type and validate for a positive number
int getIntPositive(int *);
// Function: 2. Get user input of double type and validate for a positive number
double getDoublePositive(double *);
// Function: 3. Opening Message
void openingMessage(const int);
// Function: 4. Get user input for cat food product
CatFoodInfo getCatFoodInfo(const int);
// Function: 5. Display the formatted table header
void displayCatFoodHeader();
// Function: 6. Display a formatted record of cat food data
void displayCatFoodData(const CatFoodInfo);
// 7. Logic entry point
void start();
