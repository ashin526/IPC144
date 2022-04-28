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
#include<stdio.h>
#include "commonHelpers.h"
#include "account.h"
// Function 1: getAccount
void getAccount(struct Account* accountData){
    printf("Account Data: New Record\n");
    printf("----------------------------------------\n");
    printf("Enter the account number: ");
    accountData->account_no = getInteger();
    printf("\n");
    printf("Enter the account type (A=Agent | C=Customer): ");
    accountData->account_type = getCharOption("AC");
    printf("\n");
}

// Function 2: getPerson
void getPerson(struct Account* accountData){
    int getCurrentYear;
    int min_year, max_year;
    printf("Person Data Input\n");
    printf("----------------------------------------\n");
    getCurrentYear = currentYear();
    min_year = getCurrentYear - 110;
    max_year = getCurrentYear - 18;
    printf("Enter the person's full name (%d chars max): ", FULLNAME);
    getCString(accountData->person.country, LOW_BOUND, FULLNAME);
    printf("Enter birth year (current age must be between %d and %d): ", MIN_AGE, MAX_AGE);
    accountData->person.birth = getIntFromRange(min_year, max_year);
    printf("Enter the household Income: $");
    accountData->person.income = getPositiveDouble();
    printf("Enter the country (%d chars max.): ", COUN_SIZE);
    getCString(accountData->person.country, LOW_BOUND, COUN_SIZE);
    printf("\n");
}

// Function 3: getUserLogin
void getUserLogin(struct Account* accountData){
    printf("User Login Data Input\n");
    printf("----------------------------------------\n");
    printf("Enter user login (%d chars max): ", LOGIN);
    getCString(accountData->Ulogin.login, LOW_BOUND, LOGIN);
    printf("Enter the password (must be %d chars in length): ", PASSWORD);
    getCString(accountData->Ulogin.password, LOW_BOUND, PASSWORD);
    printf("\n");
}