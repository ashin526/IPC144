// #############################################################################################
//  Assignment: 2 
//  Milestone : 1
// #############################################################################################
//  Student Name  : Anna Shin
//  Student ID    : 131283210
//  Student Email : ashin8@myseneca.ca 
//  Course Section: NHH
// #############################################################################################
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

//Funtion 2 : Displays a record that aligns to the respective header
void displayAccountDetailRecord(struct Account* accountData){
    int i, j;
    int count = 0;
    char star = '*';
    for (i = 0; accountData->Login.password[i] != '\0'; i++){
        count++;
    }
    for (j = 0; j < count + 1; j++){
        if ((j + 1) % 2 == 0){
            accountData->Login.password[j] = star;
        }
    }
    printf("%05d %-9s %-15s %5d %11.2lf %-10s %-10s %8s", 
    accountData->account_no, accountData->account_type == 'A' ? "AGENT" : "CUSTOMER", 
    accountData->Person.fullname, accountData->Person.birth, accountData->Person.income, 
    accountData->Person.country, accountData->Login.login, accountData->Login.password);
    printf("\n");

}

//Function 3: Entry point to the application logic.
void applicationStartup(struct AccountTicketingData* data){
    int indexNo;
    do{
        indexNo = menuLogin(data->accounts, data->ACCOUNT_MAX_SIZE);
        if (indexNo != -1){
            if (data->accounts[indexNo].account_type == 'A'){
                menuAgent(data, &data->accounts[indexNo]);
            }
            else if (data->accounts[indexNo].account_type == 'C'){
                printf("ERROR:  Login failed!\n\n");
                pauseExecution();
            }
        }
    } 
    while (indexNo != -1);
}

//Function 4: Displays a login menu:
int menuLogin(const struct Account accountUpdate[], int maxAccount){
    int select;
    int accountNo;
    int count = -1, flag;
    char charValid = 0;
    while (flag==0){
        printf("==============================================\n");
        printf("Account Ticketing System - Login\n");
        printf("==============================================\n");
        printf("1) Login to the system\n");
        printf("0) Exit application\n");
        printf("----------------------------------------------\n\n");
        printf("Selection: ");
        select = getIntFromRange(0, 1);
        printf("\n");
        switch (select){
        case 0:
            printf("Are you sure you want to exit? ([Y]es|[N]o): ");
            charValid = getCharOption("yYnN");
            printf("\n");
            if (charValid == 'Y' || charValid == 'y'){
                printf("==============================================\n");
                printf("Account Ticketing System - Terminated\n");
                printf("==============================================\n");
                flag = 1;
            }  
            else{
                flag = 0;
            }
        break;

        case 1:
            printf("Enter your account#: ");
            accountNo = getPositiveInteger();
            count = findAccountIndexByAcctNum(accountNo, accountUpdate, maxAccount, 0);
            if (count<=0){
                printf("ERROR:  Login failed!\n\n");
                pauseExecution();
                flag = 0;
            }
            else{
                flag = 1;
                printf("\n");
            }
        break;
        }
    }
    return count;
}

//Function 6: Display's the agent's main menu options until the user wishes to logout
void menuAgent(struct AccountTicketingData* data, const struct Account* info){
    int select, i, count = 1;
    do{
        printf("AGENT: %s (%d)\n", info->Person.fullname, info->account_no);
        printf("==============================================\n");
        printf("Account Ticketing System - Agent Menu\n");
        printf("==============================================\n");
        printf("1) Add a new account\n");
        printf("2) Modify an existing account\n");
        printf("3) Remove an account\n");
        printf("4) List accounts: detailed view\n");
        printf("----------------------------------------------\n");
        printf("5) List new tickets\n");
        printf("6) List active tickets\n");
        printf("7) List closed tickets\n");
        printf("8) Add a new ticket\n");
        printf("9) Manage a ticket\n");
        printf("----------------------------------------------\n");
        printf("0) Logout\n\n");
        printf("Selection: ");
        select = getIntFromRange(0, 9);
        printf("\n");
        switch (select){ 
            int searchIndex, full, highNo;
            char confirmDelete;
            case 1:
                full = -1;
                for (i = 0; i < data->ACCOUNT_MAX_SIZE; i++){
                    if (data->accounts[i].account_no <= 0){
                        full = i;
                        break;
                    }   
                }
                if (full < 0){
                    printf("\nERROR: Account listing is FULL, call ITS Support!\n\n");
                    pauseExecution();
                } 
                else{
                    for (i=0; i < data->ACCOUNT_MAX_SIZE; i++){
                        if (highNo <= data->accounts[i].account_no){
                            highNo = data->accounts[i].account_no + 1;
                        }
                    }
                } 
                getAccount(&data->accounts[full], highNo);
                printf("*** New account added! ***\n\n");
                pauseExecution();
            break;

            case 2:
                searchIndex = findAccountIndexByAcctNum(0, data->accounts, data->ACCOUNT_MAX_SIZE, 1);
                if (searchIndex != -1){
                    printf("\n");
                    updateAccount(&data->accounts[searchIndex]);
                }
            break;

            case 3:
               searchIndex = findAccountIndexByAcctNum(0, data->accounts, data->ACCOUNT_MAX_SIZE, 1);
                if (data[searchIndex].accounts->account_no == info->account_no){
                    printf("\n");
                    printf("ERROR: You can't remove your own account!\n\n");
                }
                else {
                    displayAccountDetailHeader();
                    displayAccountDetailRecord(&data->accounts[searchIndex]);
                    printf("\n");
                    printf("Are you sure you want to remove this record? ([Y]es|[N]o): ");
                    confirmDelete = getCharOption("yYnN");
                    printf("\n");
                    if (confirmDelete == 'y' || confirmDelete == 'Y'){
                        data[searchIndex].accounts->account_no = 0;
                        printf("*** Account Removed! ***\n\n");
                    }
                }
                pauseExecution();
            break;

            case 4:
                displayAllAccountDetailRecords(data->accounts, data->ACCOUNT_MAX_SIZE);
                pauseExecution();
            break;

            case 5:
                printf("\nFeature #%d currently unavailable!\n\n", select);
                pauseExecution();
            break;

            case 6:
                printf("\nFeature #%d currently unavailable!\n\n", select);
                pauseExecution();
            break;

            case 7:
                printf("\nFeature #%d currently unavailable!\n\n", select);
                pauseExecution();
            break;

            case 8:
                printf("\nFeature #%d currently unavailable!\n\n", select);
                pauseExecution();
            break;
            
            case 9:
                printf("\nFeature #%d currently unavailable!\n\n", select);
                pauseExecution();
            break;

            case 0:
                printf("### LOGGED OUT ###\n\n");
                count = 0;
            break;
        }
    } 
    while (count);
}

//Function 7: Search the array received in argument 2 for a match on a desired account number.
int findAccountIndexByAcctNum(int accountNo, const struct Account accountData[], int maxAccount, int promptNo){

    int i, index = -1;
    if (promptNo == 1)
    {
        printf("Enter the account#: ");
        accountNo = getPositiveInteger();
    }
    for (i = 0; i < maxAccount; i++)
    {
        if (accountData[i].account_no == accountNo)
        {
            index = i;
        }
    }
    return index;
}

//Funtion 7 : Displays a detailed view of all the valid account records(where the account number is greater than zero(0)
void displayAllAccountDetailRecords(struct Account* accountUpdate, int maxAccount){
    int i;
    int count = 1;
        displayAccountDetailHeader();
        for (i = 0; i < maxAccount && count; i++){
            if (accountUpdate[i].account_no != 0){
                displayAccountDetailRecord(&accountUpdate[i]);
            }
        }
        printf("\n");
}

//Function 9: Pause execution until user enters the enter key
void pauseExecution(void){ 
    printf("<< ENTER key to Continue... >>"); 
    clearStandardInputBuffer(); 
    putchar('\n'); 
}

/*int getNextAccountNumber(const struct Account* accounts, int size){
    int i, acct_no = 0;
    for (i=0; i < size; i++){
        if(accounts[i].account_no > acct_no){
            acct_no = accounts[i].account_no;
        }
    }
    return acct_no + 1;
}*/









