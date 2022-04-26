/*
	==================================================
    Assignment #1 Milestone #1
	==================================================
	Name    : Anna Shin
	Email   : ashin8@myseneca.ca
	Section : NHH
*/
#define _CRT_SECURE_NO_WARNINGS
// SYSTEM LIBRARY
#include<stdio.h>
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
	//guarantee an integer value is entered and returned.
int getInteger(void){
	int getInt = 0;
	char newline = 0;
	do{
		scanf("%d%c", &getInt, &newline);
		if (newline != '\n'){
			clearStandardInputBuffer();
			printf("ERROR: Value must be an integer: ");
		}
	} 
	while (newline != '\n');
	return getInt;
}

//guarantee a positive integer value is entered and returned.
int getPositiveInteger(void){
	int repeat = 1;
	int getPos = 0;
	do{
		getPos = getInteger();
		if (getPos <= 0){
			printf("ERROR: Value must be a positive integer greater than zero: ");
		}
		else{
			repeat = 0;
		}
	} 
	while (repeat);
	return getPos;
}

//guarantee a double value is entered and returned.
double getDouble(void){
	double getDouble = 0.0;
	char newline = 0;
	do{
		scanf("%lf%c", &getDouble, &newline);
		if (newline != '\n'){
			clearStandardInputBuffer();
			printf("ERROR: Value must be a double floating-point number: ");
		}
	} 
	while (newline != '\n');
	return getDouble;
}

//guarantee a positive double value is entered and returned.
double getPositiveDouble(void){
	double getDouble_pos = 0.0;
	int repeat = 1;
	do{
		getDouble_pos = getDouble();
		if (getDouble_pos <= 0){
			printf("ERROR: Value must be a positive double floating-point number: ");
		}
		else{
			repeat = 0;
		}
	} 
	while (repeat);
	return getDouble_pos;
}

int getIntFromRange(int lowerBound, int upperBound){
	int get_int_range = 0;
	int repeat = 1;
	do{
		get_int_range = getInteger();
		if (get_int_range < lowerBound || get_int_range > upperBound){
			printf("ERROR: Value must be between -3 and 11 inclusive: ");
		}
		else{
			repeat = 0;
		}
	} 
	while (repeat);
	return get_int_range;
}

char getCharOption(const char checkString[]){
	char inputchar = 0;
	int i = 0, count =0, repeat =1;

	for (i = 0; checkString[i] != '\0'; i++){
		count++;
	}
	do{
		scanf("%c", &inputchar);
		clearStandardInputBuffer();
		for (i = 0; i < count && repeat; i++){
			if (inputchar == checkString[i]){
				repeat = 0;
			}
		}
		if (repeat){
			printf("ERROR: Character must be one of [%s]: ", checkString);
		}
	}
	while (repeat);
	return inputchar;
}

void getCString(char* charPointer, int minChar, int maxChar){
	int i = 0, j = 0, count =0, repeat =1;
	char inputstring[500];
	do{
		scanf("%500[^\n]", inputstring);
		clearStandardInputBuffer();
		count = 0;
		for (i = 0; inputstring[i] != '\0'; i++){
			count++;
		}
		if (count < minChar && (minChar != maxChar)){
			printf("ERROR: String length must be between %d and %d chars:", minChar, maxChar);
		}
		else if ((count <minChar || count>maxChar) && minChar == maxChar){
			printf("ERROR: String length must be exactly %d chars: ",minChar);
		}
		else if (count > maxChar && (minChar != maxChar)){
			printf("ERROR: String length must be no more than %d chars: ",maxChar);
		}
		else{
			for (j = 0; j < count; j++){
				charPointer[j] = inputstring[j];
			}
			repeat = 0;
		}
	} 
	while (repeat);
}