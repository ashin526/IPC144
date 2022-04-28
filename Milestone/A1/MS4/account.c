// #############################################################################################
//  Assignment: 1 
//  Milestone : 4
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
    struct UserLogin ses ={ { 0 } };
    printf("Account Data: New Record\n");
    printf("----------------------------------------\n");
    printf("Enter the account number: ");
    accountData->account_no = getInteger();
    printf("\n");
    printf("Enter the account type (A=Agent | C=Customer): ");
    accountData->account_type = getCharOption("AC");
    getPerson(&accountData->Person);
    if (accountData->account_type == 'A'){
        getUserLogin(&accountData->Login);
    }
    else {
        accountData->Login = ses;
    }
    return;
}

// Function 2: getPerson
void getPerson(struct Person* accountPerson){
    int getCurrentYear;
    int min_year, max_year;
    printf("\nPerson Data Input\n");
    printf("----------------------------------------\n");
    getCurrentYear = currentYear();
    min_year = getCurrentYear - 110;
    max_year = getCurrentYear - 18;
    printf("Enter the person's full name (%d chars max): ", FULLNAME);
    getCString(accountPerson->fullname, LOW_BOUND, FULLNAME);
    printf("Enter birth year (current age must be between %d and %d): ", MIN_AGE, MAX_AGE);
    accountPerson->birth = getIntFromRange(min_year, max_year);
    printf("Enter the household Income: $");
    accountPerson->income = getPositiveDouble();
    printf("Enter the country (%d chars max.): ", COUN_SIZE);
    getCString(accountPerson->country, LOW_BOUND, COUN_SIZE);
    printf("\n");
}

// Function 3: getUserLogin
void getUserLogin(struct UserLogin* accountLogin){
    printf("User Login Data Input\n");
    printf("----------------------------------------\n");
    printf("Enter user login (%d chars max): ", LOGIN);
    getCString(accountLogin->login, LOW_BOUND, LOGIN);
    printf("Enter the password (must be %d chars in length): ", PASSWORD);
    getCString(accountLogin->password, LOW_BOUND, PASSWORD);
    printf("\n");
}


//Function 4: Display's the update menu options for the account.
void updateAccount(struct Account* accountUpdate){
    struct UserLogin ses ={ { 0 } };
    int select;
    int count = 1;
    while (count){
        printf("Update Account: %d (%s)\n", accountUpdate->account_no, accountUpdate->Person.fullname);
        printf("----------------------------------------\n");
        printf("1) Update account type (current value: %c)\n", accountUpdate->account_type);
        printf("2) Person\n");
        printf("3) Login\n");
        printf("0) Done\n");
        printf("Selection: ");
            select = getIntFromRange(0, 3);
        printf("\n");
        switch (select){
            case 1:
                printf("Enter the account type (A=Agent | C=Customer): ");
                accountUpdate->account_type = getCharOption("AC");
                if (accountUpdate->account_type == 'A'){
                    printf("\nAgent type accounts require a user login.  Please enter this information now:\n\n");
                    getUserLogin(&accountUpdate->Login);
                }
                else
                {
                    accountUpdate->Login = ses;
                    printf("\n");
                }
            break;

            case 2:
                updatePerson(&accountUpdate->Person);
            break;
        
            case 3:
                if (accountUpdate -> account_type == 'C'){
                    printf("ERROR:  Customer account types don't have user logins!\n\n");
                }
                else
                {
                    updateUserLogin(&accountUpdate->Login);
                }
            break;
        
            case 0:
                count = 0;
            break;
        }
    }
}

//Function 5: Menu with options to modifying specific members of a person:
void updatePerson (struct Person* personUpdate) {
    int updateoption, count = 1;
    while (count){
        printf("Person Update Options\n");
        printf("----------------------------------------\n");
        printf("1) Full name (current value: %s)\n", personUpdate->fullname);
        printf("2) Household Income (current value: $%.2lf)\n", personUpdate->income);
        printf("3) Country (current value: %s)\n", personUpdate->country);
        printf("0) Done\n");
        printf("Selection: ");
        updateoption = getIntFromRange(0, 3);
        printf("\n");
        switch (updateoption){
            case 1:
            printf("Enter the person's full name (%d chars max): ", FULLNAME);
            getCString(personUpdate->fullname, LOW_BOUND, FULLNAME);
            printf("\n");
            break;

            case 2:
                printf("Enter the household Income: $");
                personUpdate->income = getPositiveDouble();
                printf("\n");
            break;

            case 3:
            printf("Enter the country (%d chars max.): ", COUN_SIZE);
            getCString(personUpdate->country, LOW_BOUND, COUN_SIZE);
            printf("\n");
            break;
            
            case 0:
                count = 0;
            break;
        }
    }
}

//Function 6: Display's the update menu options for the user login until the user wishes to exit.
void updateUserLogin(struct UserLogin* loginUpdate){
    int update_option, count = 1;
    do{
        printf("User Login: %s - Update Options\n", loginUpdate->login);
        printf("----------------------------------------\n");
        printf("1) Password\n");
        printf("0) Done\n");
        printf("Selection: ");
        update_option = getIntFromRange(0, 2);
        printf("\n");
        switch (update_option){
            case 1:
                printf("Enter the password (must be %d chars in length): ", PASSWORD);
                getCString(loginUpdate->password, LOW_BOUND, PASSWORD);
                printf("\n");
            break;

            case 0:
                count = 0;
            break;
        }
    } 
    while (count);
}

