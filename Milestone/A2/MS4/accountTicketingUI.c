// #############################################################################################
//  Assignment: 2 
//  Milestone : 5
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
#include "ticket.h"
#include <string.h>

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
    //memuLogin(data);
    int indexNo;
    do{
        indexNo = menuLogin(data);
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
int menuLogin(struct AccountTicketingData* data){
    int select, count = -1;
    char charValid = 0;
    int remaining, result; 
    do{
        count = -1;
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
            }  
            else{
                select = 1;
            }
        break;

        case 1:
            remaining = 0;
            result = 0;
            do{
                result = Attempt(data, &count); 
                if (result == 1){
                    remaining++;
                    printf("INVALID user login/password combination! [attempts remaining:%d]\n", 3 - remaining);
                    printf("\n");

                }
            } 
            while (result == 1 && remaining < 3);

            if (result == 1){
                printf("ERROR:  Access Denied.\n\n");
                pauseExecution();
                select = 1;
            }
            else{
                    printf("\n");
                    menuAgent(data, &data->accounts[count]);    
            }
        }             
    }
    while(select == 1);
    return count;
}

//Function 6: Display's the agent's main menu options until the user wishes to logout
void menuAgent(struct AccountTicketingData* data, const struct Account* info){
    int select = 0, i, count = 1;
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
            int searchIndex, highNo, full;
            char confirmDelete, remove;
            int ticketNo = 0;
            int j;
            int foundAccount = 0;
            char addTicket = 0;
            case 1:
                full = -1;
                for (i = 0; i < data->ACCOUNT_MAX_SIZE; i++){
                    if (data->accounts[i].account_no <= 0){
                        full = i;
                        break;
                    }   
                }
                
                if(i < data->ACCOUNT_MAX_SIZE){
                    highNo=0;
                    int k;
                    for (k=0; k < data->ACCOUNT_MAX_SIZE; k++){ 
                        if (highNo <= data->accounts[k].account_no){
                            highNo = data->accounts[k].account_no + 1;
                        }
                    }
                    getAccount(&data->accounts[i], highNo);
                    printf("*** New account added! ***\n\n");
                    pauseExecution();
                }
                if(full < 0) {
                    printf("ERROR: Account listing is FULL, call ITS Support!\n\n");
                    pauseExecution();
                }  
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
                if (data->accounts[searchIndex].account_no == info->account_no){
                    printf("\n");
                    printf("ERROR: You can't remove your own account!\n\n");
                    pauseExecution();
                }
                else {
                    printf("\n");
                    displayAccountDetailHeader();
                    displayAccountDetailRecord(&data->accounts[searchIndex]);
                    printf("\n");
                    printf("Are you sure you want to remove this record? ([Y]es|[N]o): ");
                    confirmDelete = getCharOption("yYnN");
                    printf("\n");
                    if (confirmDelete == 'y' || confirmDelete == 'Y'){
                        remove = 0;
                        for(i = 0; i<data->TICKET_MAX_SIZE; i++){
                            if(data->tickets[i].unique_no!=0 && data->tickets[i].account_no == data->accounts[searchIndex].account_no){
                                    data->tickets[i].account_no = 0;
                                    data->tickets[i].counter =0;
                                    data->tickets[i].unique_no=0;
                                    data->tickets[i].ticket_indicator=0;
                                    remove++;
                            }
                        }
                        data->accounts[searchIndex].account_no = 0;
                        printf("*** Account Removed! (%d ticket(s) removed) ***\n\n", remove);
                        pauseExecution();
                    }
                }
            break;

            case 4:
                displayAllAccountDetailRecords(data->accounts, data->ACCOUNT_MAX_SIZE);
                pauseExecution();
            break;

            case 5:
                do{
                    int foundTicket = 0;
                    displayMessageHeader();
                    for (i = 0; i < data->TICKET_MAX_SIZE; i++){
                        if (data->tickets[i].ticket_indicator == 1 && data->tickets[i].counter == 1){
                            displayOneTicketRecord(&data->tickets[i]);
                        }
                    }
                    printf("------ ----- --------------- ------ ------------------------------ --------\n");
                    printf("\n");
                    printf("Enter the ticket number to view the messages or\n");
                    printf("0 to return to previous menu: ");
                    scanf("%d", &ticketNo);
                    clearStandardInputBuffer();

                    for (i = 0; i < data->TICKET_MAX_SIZE; i++){
                        if (data->tickets[i].unique_no == ticketNo && ticketNo != 0){
                            displayMessage(&data->tickets[i]);
                            foundTicket = 1;
                            break;
                        }
                    }

                    if (foundTicket == 0 && ticketNo != 0){
                        printf("\n");
                        printf("ERROR: Invalid ticket number.\n");
                        pauseExecution();
                    }
                } 
                while (ticketNo != 0);
                printf("\n");
            break;

            case 6:
                do{
                    int foundTicket = 0;
                    displayMessageHeader();
                        for (i = 0; i < data->TICKET_MAX_SIZE; i++){
                            if (data->tickets[i].ticket_indicator == 1 && data->tickets[i].counter != 0){
                                displayOneTicketRecord(&data->tickets[i]);
                            }
                        }

                    printf("------ ----- --------------- ------ ------------------------------ --------\n");
                    printf("\n");
                    printf("Enter the ticket number to view the messages or\n");
                    printf("0 to return to previous menu: ");
                    scanf("%d", &ticketNo);
                    clearStandardInputBuffer();

                    for (i = 0; i < data->TICKET_MAX_SIZE; i++){
                        if (data->tickets[i].unique_no == ticketNo && (data->tickets[i].ticket_indicator == 1 && data->tickets[i].counter != 0)){
                            foundTicket = 1;
                            displayMessage(&data->tickets[i]);
                        }
                    }
                    if (!foundTicket && ticketNo){
                        printf("\n");
                        printf("ERROR: Invalid ticket number.\n\n");
                        pauseExecution();
                    }
                }
                while(ticketNo);
                printf("\n");
            break;

            case 7:
                do{
                    int foundTicket = 0;
                    displayMessageHeader();

                    for (i = 0; i < data->TICKET_MAX_SIZE; i++){
                        if (data->tickets[i].ticket_indicator == 0 && data->tickets[i].counter > 0){
                            displayOneTicketRecord(&data->tickets[i]);
                        }
                    }
                    printf("------ ----- --------------- ------ ------------------------------ --------\n");
                    printf("\n");

                    printf("Enter the ticket number to view the messages or\n");
                    printf("0 to return to previous menu: ");
                    scanf("%d", &ticketNo);
                    clearStandardInputBuffer();

                    for (i = 0; i < data->TICKET_MAX_SIZE; i++){
                        if (data->tickets[i].unique_no == ticketNo && (data->tickets[i].ticket_indicator == 0 && data->tickets[i].counter != 0)){
                            foundTicket = 1;
                            displayMessage(&data->tickets[i]);
                        }
                    }
                    if (!foundTicket && ticketNo){
                        printf("\n");
                        printf("ERROR: Invalid ticket number.\n\n");
                        pauseExecution();
                    }
                }
                while(ticketNo);
                printf("\n");
            break;

            case 8:
                for(i = 0; i< data->TICKET_MAX_SIZE; i++){
                    if (data->tickets[i].account_no == 0)
                        foundAccount = 1;
                }
                if (foundAccount == 1){
                    searchIndex = findAccountIndexByAcctNum(0, data->accounts, data->TICKET_MAX_SIZE, 1);
                    if(data->accounts[searchIndex].account_type == 'A')
                        printf("\nERROR: Agent accounts can't have tickets!\n\n");
                    else{
                        highNo = 0;
                        printf("\n");
                        displayAccountDetailHeader();
                        displayAccountDetailRecord(&data->accounts[searchIndex]);
                        printf("\nAdd a new ticket for this customer? ([Y]es|[N]o): ");
                        addTicket = getCharOption("yYNn");
                        if(addTicket == 'Y' || addTicket == 'y'){
                            for(i = 0; data->tickets[i].unique_no > 0; i++);
                            for(j = 0; j < data->TICKET_MAX_SIZE; j++){
                                if (highNo < data->tickets[j].unique_no)
                                    highNo = data->tickets[j].unique_no;
                            }
                            data->tickets[i].unique_no = highNo + 1;
                            data->tickets[i].counter =1; 
                            data->tickets[i].ticket_indicator = 1;
                            data->tickets[i].account_no = data->accounts[searchIndex].account_no;
                            data->tickets[i].msg->account_type = data->accounts[searchIndex].account_type;
                            strcpy(data->tickets[i].msg->display_name, data->accounts[searchIndex].Person.fullname);

                            printf("\nNew Ticket (Ticket#:%06d)\n", data->tickets[i].unique_no);
                            printf("----------------------------------------\n");
                            printf("Enter the ticket SUBJECT (30 chars. maximum): ");
                            getCString(data->tickets[i].subject, 1, 30);
                            printf("\n");
                            printf("Enter the ticket message details (150 chars. maximum). Press the ENTER key to submit:\n");
                            getCString(data->tickets[i].msg->message, 1, 150);
                            printf("\n");
                            printf("*** New ticket created! ***\n\n");
                        }
                    }
                }
                else 
                    printf("\nERROR: Ticket listing is FULL, call ITS Support!\n\n");
                    pauseExecution();
            break;
            
            case 9:
                printf("Enter ticket number: ");
                ticketNo = getPositiveInteger();
                printf("\n");
                for (i = 0; i < data->TICKET_MAX_SIZE; i++){
                    if(data->tickets[i].unique_no==ticketNo){
                        j = i;
                        foundAccount = 1 ;
                    }
                }
                if (foundAccount == 1){
                        updateTicket(&data->tickets[j], *info);
                }
                else {
                    printf("ERROR: Invalid ticket number.\n");
                }
                printf("\n");
            break;

            case 0:
                printf("Saving session modifications...\n");
                printf("   %d account(s) saved.\n", saveAccounts(data->accounts, data->ACCOUNT_MAX_SIZE));
                printf("   %d ticket(s) saved.\n", saveTickets(data->tickets, data->TICKET_MAX_SIZE));
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
    if (promptNo == 1){
        printf("Enter the account#: ");
        accountNo = getPositiveInteger();
    }
    for (i = 0; i < maxAccount; i++){
        if (accountData[i].account_no == accountNo){
            index = i;
        }
    }
    return index;
}

//Funtion 7 : Displays a detailed view of all the valid account records(where the account number is greater than zero(0)
void displayAllAccountDetailRecords(struct Account* accountUpdate, int maxAccount){
    int i;
        displayAccountDetailHeader();
        for (i = 0; i < maxAccount; i++){
            if (accountUpdate[i].account_no != 0){
                displayAccountDetailRecord(&accountUpdate[i]);
            }
        }
        printf("\n");
}

//Function 8: Give user up to 3 attemtps
int Attempt(const struct AccountTicketingData* data, int* index){
    int acct_no, attempt = 0;
    char ip[50];
    
    printf("Enter the account#: ");
    acct_no = getInteger();

    *index = findAccountIndexByAcctNum(acct_no, data->accounts, data->ACCOUNT_MAX_SIZE, 0);

    if (*index < 0){
        attempt = 1;
    }

    printf("User Login        : ");
    getCString(ip, 0, 49);
    if (*index >= 0){
        if (strcmp(ip, data->accounts[*index].Login.login)){
            attempt = 1;
        }
    }

    printf("Password          : ");
    getCString(ip, 0, 49);
    if (*index >= 0){
        if (strcmp(ip, data->accounts[*index].Login.password)){
            attempt = 1;
        }
    }
    return attempt;
}
