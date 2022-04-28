// #############################################################################################
//  Assignment: 2 
//  Milestone : 1
// #############################################################################################
//  Student Name  : Anna Shin
//  Student ID    : 131283210
//  Student Email : ashin8@myseneca.ca 
//  Course Section: NHH
// #############################################################################################

#ifndef accountTicketingUI_H
#define accountTicketingUI_H

#include "account.h"
#include "ticket.h"

struct AccountTicketingData
{
    struct Account* accounts;   // array of accounts 
    const int ACCOUNT_MAX_SIZE; // maximum elements for account array 

    struct Ticket* tickets;     // array of tickets 
    const int TICKET_MAX_SIZE;  // maximum elements for ticket array 
};

void displayAccountDetailHeader(void);
void displayAccountDetailRecord(struct Account* accountData);
void applicationStartup(struct AccountTicketingData* data);
int menuLogin(const struct Account accountUpdate[], int maxAccount);
void menuAgent(struct AccountTicketingData* data, const struct Account* info);
int findAccountIndexByAcctNum(int accountNo, const struct Account accountData[], int maxAccount, int promptNo);
void displayAllAccountDetailRecords(struct Account accountUpdate[], int maxAccount);
void pauseExecution(void);
int getNextAccountNumber(const struct Account* accounts, int size);

#endif
