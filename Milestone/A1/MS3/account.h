// #############################################################################################
//  Assignment: 1 
//  Milestone : 3
// #############################################################################################
//  Student Name  : Anna Shin
//  Student ID    : 131283210
//  Student Email : ashin8@myseneca.ca 
//  Course Section: NHH
// #############################################################################################

#ifndef ACCOUNT_H
#define ACCOUNT_H

// Define a Macro
# define FULLNAME 30
# define COUN_SIZE 30
# define LOGIN 10
# define PASSWORD 8
# define MIN_AGE 18
# define MAX_AGE 110
# define LOW_BOUND 1



// STRUCTURES
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
    struct Person person;
    struct UserLogin Ulogin;
};

#endif

void getAccount(struct Account* accountData);

void getUserLogin(struct Account* accountData);

void getPerson(struct Account* accountData);