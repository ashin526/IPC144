// #############################################################################################
//  Assignment: 1 
//  Milestone : 4
// #############################################################################################
//  Student Name  : Anna Shin
//  Student ID    : 131283210
//  Student Email : ashin8@myseneca.ca 
//  Course Section: NHH
// #############################################################################################

#ifndef accountTicketingUI_H
#define accountTicketingUI_H

void displayAccountDetailHeader(void);
void displayAccountDetailRecord(struct Account* accountData);
void applicationStartup(struct Account accountUpdate[], int maxAccount);
int menuLogin(const struct Account accountUpdate[], int maxAccount);
void menuAgent(struct Account accountData[], int maxAccount, const struct Account* info);
int findAccountIndexByAcctNum(int accountNo, const struct Account accountData[], int maxAccount, int promptNo);
void displayAllAccountDetailRecords(struct Account accountUpdate[], int maxAccount);
void pauseExecution(void);

#endif
