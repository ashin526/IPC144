// #############################################################################################
//  Assignment: 1 
//  Milestone : 3
// #############################################################################################
//  Student Name  : Anna Shin
//  Student ID    : 131283210
//  Student Email : ashin8@myseneca.ca 
//  Course Section: NHH
// #############################################################################################
#define _CRT_SECURE_NO_WARNINGS
// SYSTEM LIBRARY
#include<stdio.h>
#include <string.h>
#include <time.h>
// USER LIBRARY
#include "commonHelpers.h"
int currentYear(void){
	time_t currentTime = time(NULL);
	return localtime(&currentTime)->tm_year + 1900;
}
void clearStandardInputBuffer(void){
	while (getchar() != '\n'){
	; // On purpose: do nothing
	}
}
//Ensures that integer values are entered and returned.
int getInteger(void){
	int getInt = 0;
	char nl = 0;
	do{
		scanf("%d%c", &getInt, &nl);
		if (nl != '\n'){
			clearStandardInputBuffer();
			printf("ERROR: Value must be an integer: ");
		}
	} 
	while (nl != '\n');
	return getInt;
}

// Ensures that a positive interger values are entered and returned.
int getPositiveInteger(void){
	int flag = 1;
	int getPos = 0;
	do{
		getPos = getInteger();
		if (getPos <= 0){
			printf("ERROR: Value must be a positive integer greater than zero: ");
		}
		else{
			flag = 0;
		}
	} 
	while (flag);
	return getPos;
}


//Ensures that a double values are entered and returned.
double getDouble(void){
	double getDouble = 0.0;
	char nl = 0;
	do{
		scanf("%lf%c", &getDouble, &nl);
		if (nl != '\n'){
			clearStandardInputBuffer();
			printf("ERROR: Value must be a double floating-point number: ");
		}
	} 
	while (nl != '\n');
	return getDouble;
}

//Ensures that a positive double values are entered and returned.
double getPositiveDouble(void){
	double getDouble_pos = 0.0;
	int flag = 1;
	do{
		getDouble_pos = getDouble();
		if (getDouble_pos <= 0){
			printf("ERROR: Value must be a positive double floating-point number: ");
		}
		else{
			flag = 0;
		}
	} 
	while (flag);
	return getDouble_pos;
}

//Ensures that a positive double values are entered and returned.
double getPositiveDouble2(){
	double getDouble_pos2 = 0.0;
	int flag = 1;
	do{
		getDouble_pos2 = getDouble();
		if (getDouble_pos2 <= 0){
			printf("ERROR: Value must be a positive double floating-point number: ");
		}
		else{
			flag = 0;
		}
	}
	while(flag);
	return getDouble_pos2;
}

//Ensures that an integer value is entered within the range (inclusive) and returned.
int getIntFromRange(int lowerBound, int upperBound){
	int get_int_range = 0;
	int flag = 1;
	do{
		get_int_range = getInteger();
		if (get_int_range < lowerBound || get_int_range > upperBound){
			printf("ERROR: Value must be between %d and %d inclusive: ", lowerBound, upperBound);
		}
		else{
			flag = 0;
		}
	} 
	while (flag);
	return get_int_range;
}

// Ensures that a single character value is entered and returned within a valid character list (defined by the received C string argument).
char getCharOption(const char checkString[]){
	char inputchar[30];
	int i, count, flag;

	do{
		flag = 1;
		count = 0;
		scanf (" %30[^\n]s", inputchar);
		for(i=0; inputchar[i] != '\0'; i++){
			count++;
		}
		if(count != 1){
			flag = 1;
		}
		else{
			for(i=0; checkString[i] != '\0'; i++){
				if (inputchar[0]== checkString[i]){
					flag = 0;
				}
			}
		}
	
	if (flag) {
		printf("ERROR: Character must be one of [");
		for(i=0; checkString[i] != '\0'; i++){
			printf("%c", checkString[i]);
		}
		printf("]: ");
	}
	clearStandardInputBuffer();
	}
	while (flag);
	return inputchar[0];
}

// Ensure that C string values containing the number of characters within the specified range as the second and third arguments are entered (and returned through the first argument pointer).
void getCString(char* charPointer, int lowerBound, int upperBound){
    int	i, invalidinput;
	int flag = 0;
    char inputstring[30];
	char* address = inputstring;
    do
    {
        scanf("%30[^\n]s", inputstring);
        int count = 0;
		invalidinput = 0;
        for (i = 0; inputstring[i] != '\0'; i++){
        	count++;
        }
        if (lowerBound == upperBound && count != lowerBound){
			invalidinput = 1;
        	printf("ERROR: String length must be exactly %d chars: ", lowerBound);
        }
        else if (count > upperBound){
			invalidinput = 1;
        	printf("ERROR: String length must be no more than %d chars: ", upperBound);
        }
        else if (count < lowerBound){
			invalidinput = 1;
        	printf("ERROR: String length must be between %d and %d chars: ", lowerBound, upperBound);
        }
		clearStandardInputBuffer();
    } while (invalidinput);
        for (i = 0; inputstring[i] != '\0'; i++){
	        charPointer[i] = address[i];
			flag++;
			}
			charPointer[flag] ='\0';
}