// #############################################################################################
//  Assignment: 2 
//  Milestone : 4
// #############################################################################################
//  Student Name  : Anna Shin
//  Student ID    : 131283210
//  Student Email : ashin8@myseneca.ca 
//  Course Section: NHH
// #############################################################################################

#ifndef ACCOUNT_H
#define ACCOUNT_H

# define FULLNAME 30
# define COUN_SIZE 30
# define LOGIN 10
# define PASSWORD 8
# define MIN_AGE 18
# define MAX_AGE 110
# define LOW_BOUND 1

struct Person{
    char fullname[FULLNAME+1];
    int birth;
    double income;
    char country[COUN_SIZE+1];
};

struct UserLogin{
    char login[LOGIN+1];
    char password[PASSWORD+1];
};

struct Account{
    int account_no;
    char account_type;
    struct Person Person;
    struct UserLogin Login;
};

void getAccount(struct Account* accountData, int highno);
void getPerson(struct Person* accountPerson);
void getUserLogin(struct UserLogin* accountLogin);
void updateAccount(struct Account* accountUpdate);
void updatePerson(struct Person* personUpdate);
void updateUserLogin(struct UserLogin* loginUpdate);
void getPaswordCriteria(struct UserLogin* accountLogin);
int loadAccounts(struct Account accounts[], int size);
int saveAccounts(struct Account accounts[], int sizeAccount);

#endif