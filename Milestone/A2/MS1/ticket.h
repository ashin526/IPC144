// #############################################################################################
//  Assignment: 2 
//  Milestone : 1
// #############################################################################################
//  Student Name  : Anna Shin
//  Student ID    : 131283210
//  Student Email : ashin8@myseneca.ca 
//  Course Section: NHH
// #############################################################################################

#ifndef TICKET_H
#define TICKET_H

struct Message
{
	char account_type;
	char display_name[31];
	char message[151];
};
struct Ticket
{
	int unique_no;
	int account_no;
	int ticket_indicator;
	char subject[31];
	int counter;
	struct Message msg[20];
};

#endif
