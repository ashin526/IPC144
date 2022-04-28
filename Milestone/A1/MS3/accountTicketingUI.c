#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "account.h"
#include "commonHelpers.h"
#include "accountTicketingUI.h"

//Function 1: Displays a formatted table header with seven (7) column
void displayAccountDetailHeader(){
    printf("Acct# Acct.Type Full Name       Birth Income      Country    Login      Password\n");
    printf("----- --------- --------------- ----- ----------- ---------- ---------- --------\n");
}

//Function 2: Displays a formatted record that aligns to the respective header as defined in function "displayAccountDetailHeader" described earlier
void displayAccountDetailRecord(struct Account* accountData){
    int i, j;
    int count = 0;
    char star = '*';
    for (i = 0; accountData->Ulogin.password[i] != '\0'; i++){
        count++;
    }
    for (j = 0; j < count + 1; j++){
        if ((j + 1) % 2 == 0){
            accountData->Ulogin.password[j] = star;
        }
    }
    printf("%05d %-9s %-15s %5d %11.2lf %-10s %-10s %8s", 
    accountData->account_no, accountData->account_type == 'A' ? "AGENT" : "CUSTOMER", 
    accountData->person.fullname, accountData->person.birth, accountData->person.income, accountData->person.country, 
    accountData->Ulogin.login, accountData->Ulogin.password);
    printf("\n");
    printf("Account, Person, and User Login test completed!");
}