/*
	==================================================
	Workshop #6 (Part-2):
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
#define KG_IN_LBS 2.20462

// ----------------------------------------------------------------------------
// structures
typedef struct {
	int sku;
	double price;
	int calories;
	double weight;
} CatFoodInfo;

typedef struct {
	int sku2;
	double price2;
	int calories2;
	double pounds;
	double kg;
	int g;
	double totalser;
	double perser;
	double calser;
} ReportData;

// ----------------------------------------------------------------------------
// function prototypes
// PART-1

// Function: 1. Get user input of int type and validate for a positive number
int getIntPositive(int *);
// Function: 2. Get user input of double type and validate for a positive number
double getDoublePositive(double *);
// Function: 3. Opening Message
void openingMessage(const int);
// Function: 4. Get user input for cat food product
CatFoodInfo getCatFoodInfo(const int i);
// Function: 5. Display the formatted table header
void displayCatFoodHeader();
// Function: 6. Display a formatted record of cat food data
void displayCatFoodData(const int sku, const double* price, const int calrories, const double* weight);

// ----------------------------------------------------------------------------
// PART-2

// 8. convert lbs: kg
double convertLbsKg(const double* lbs, double* kg);
// 9. convert lbs: g
int convertLbsG(const double* lbs, int* g);
// 10. convert lbs: kg / g
void convertLbs(const double* lbs_conv, double* kg, int* g);
// 11. calculate: servings based on gPerServ
double calculateServings(const int vol, const int sum, double* result);
// 12. calculate: cost per serving
double calculateCostPerServing(const double* price, const double* result, double* CostofResult);
// 13. calculate: cost per calorie
double calculateCostPerCal(const double* pro_price, const double* total_cal, double* cal_res);
// 14. Derive a reporting detail record based on the cat food product data
ReportData calculateReportData(const CatFoodInfo getDetailCatFood);
// 15. Display the formatted table header for the analysis results
void displayReportHeader(void);
// 16. Display the formatted data row in the analysis table
void displayReportData(const ReportData display, const int cheap);
// 17. Display the findings (cheapest)
void displayFinalAnalysis(const CatFoodInfo cheaper_product);
// ----------------------------------------------------------------------------
// 7. Logic entry point
void start();
