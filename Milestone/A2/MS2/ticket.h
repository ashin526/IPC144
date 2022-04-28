// #############################################################################################
//  Assignment: 2 
//  Milestone : 2
// #############################################################################################
//  Student Name  : Anna Shin
//  Student ID    : 131283210
//  Student Email : ashin8@myseneca.ca 
//  Course Section: NHH
// #############################################################################################

#ifndef TICKET_H
#define TICKET_H
#define MAX_NUMBER_MESSAGE 20

struct Ticket{
	int unique_no;
	int account_no;
	int ticket_indicator;
	char subject[31];
	int counter;
	struct Message{
		char account_type;
		char display_name[31];
		char message[151];
	}msg[MAX_NUMBER_MESSAGE];
};

void displayOneTicketRecord(const struct Ticket* ticket);
void displayMessageHeader();
void displayMessage(const struct Ticket* ticket);
void updateTicket(struct Ticket *ticket, const struct Account account);

#endif
