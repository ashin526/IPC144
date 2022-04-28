// #############################################################################################
//  Assignment: 2 
//  Milestone : 3
// #############################################################################################
//  Student Name  : Anna Shin
//  Student ID    : 131283210
//  Student Email : ashin8@myseneca.ca 
//  Course Section: NHH
// #############################################################################################

#include <stdio.h>
#include "accountTicketingUI.h"
#include "ticket.h"
#include "account.h"
#include "commonHelpers.h"
#include <string.h>

//Funtion 1 : Displays a ticket record for new, active, closed ticket.
void displayOneTicketRecord(const struct Ticket *ticket){
    char status[7];
    if (ticket->ticket_indicator == 1){
        strcpy(status, "ACTIVE");
    }
    if (ticket->ticket_indicator == 0) {
        strcpy(status, "CLOSED");
    }

    printf("%06d %-5d %-15s %-6s %-30s %5d\n", ticket->unique_no, ticket->account_no, ticket->msg->display_name, status, ticket->subject, 
    ticket->counter);
}

//Funtion 2 : Displays a ticket message header
void displayMessageHeader(){
    printf("------ ----- --------------- ------ ------------------------------ --------\n");
    printf("Ticket Acct# Full Name       Status Subject                        Messages\n");
    printf("------ ----- --------------- ------ ------------------------------ --------\n");
}

//Funtion 3 : Displays a ticket message
void displayMessage(const struct Ticket *ticket){
    int true = 1;
    char status[7];
    if (ticket->ticket_indicator == 1){
        strcpy(status, "ACTIVE");
    }
    else{
        strcpy(status, "CLOSED");
    }
    printf("\n");

    printf("================================================================================\n");
    printf("%06d (%s) Re: %s\n", ticket->unique_no, status, ticket->subject);
    printf("================================================================================\n");
    int i;
    for (i = 0; i < ticket->counter; i++){
            printf("%s (%s):\n", ticket->msg[i].account_type == 'C' ? "CUSTOMER" : "AGENT", ticket->msg[i].display_name);
            printf("   %s\n\n", ticket->msg[i].message);
            true = 1;
        }
    if (true == 1){
        pauseExecution();
    }
}

//Funtion 4 : Displays a updataTicket menu until the user wishes to done.
void updateTicket(struct Ticket *ticket, const struct Account account){
    int select = 0, count = 1;
    do{
        printf("----------------------------------------\n");
        printf("Ticket %06d - Update Options\n", ticket->unique_no);
        printf("----------------------------------------\n");
        printf("Status  : %s\n", ticket->ticket_indicator == 1 ? "ACTIVE" : "CLOSED");
        printf("Subject : %s\n", ticket->subject);
        printf("Acct#   : %d\n", ticket->account_no);
        printf("Customer: %s\n", ticket->msg->display_name);
        printf("----------------------------------------\n");
        printf("1) Add CUSTOMER message\n");
        printf("2) Add AGENT message\n");
        printf("3) Close ticket\n");
        printf("4) Re-activate ticket\n");
        printf("0) Done\n");
        printf("Selection: ");
        select = getIntFromRange(0, 4);
        switch (select){
        case 1:
            if (ticket->counter + 1 > MAX_NUMBER_MESSAGE){
                printf("\n");
                printf("ERROR: Message limit has been reached, call ITS Support!\n");
                printf("\n");
            }
            if (ticket->ticket_indicator == 0){
                printf("\n");
                printf("ERROR: Ticket is closed - new messages are not permitted.\n");
                printf("\n");
            }
            else{
                printf("\n");
                int i;
                for (i = 0; i < MAX_NUMBER_MESSAGE; i++){
                    if (ticket->msg[i].message[0] == '\0'){
                        break;
                    }
                }
                printf("Enter the ticket message details (150 chars. maximum). Press the ENTER key to submit:\n");
                getCString(ticket->msg[i].message, 1, 150);
                putchar('\n');
                strncpy(ticket->msg[i].display_name, ticket->msg->display_name, 31);
                ticket->msg[i].account_type = ticket->msg->account_type;
                ticket->counter++;
            }
        break;

        case 2:
            if (ticket->counter + 1 > MAX_NUMBER_MESSAGE){
                printf("\n");
                printf("ERROR: Message limit has been reached, call ITS Support!\n");
                printf("\n");
            }
            if (ticket->ticket_indicator == 0){
                printf("\n");
                printf("ERROR: Ticket is closed - new messages are not permitted.\n");
                printf("\n");
            }
            else{
                printf("\n");
                int i;
                for (i = 0; i < MAX_NUMBER_MESSAGE; i++){
                    if (ticket->msg[i].message[0] == '\0'){
                        break;
                    }
                }
                printf("Enter the ticket message details (150 chars. maximum). Press the ENTER key to submit:\n");
                getCString(ticket->msg[i].message, 1, 150);
                putchar('\n');
                strncpy(ticket->msg[i].display_name, account.Person.fullname, 31);
                ticket->msg[i].account_type = account.account_type;
                ticket->counter++;
            }
        break;

        case 3:
            if (ticket->ticket_indicator == 0){
                printf("\n");
                printf("ERROR: Ticket is already closed!\n");
                printf("\n");
            }
            else{
                printf("\n");
                printf("Are you sure you CLOSE this ticket? ([Y]es|[N]o): ");
                if (getCharOption("YN") == 'Y'){
                    printf("\n");
                    ticket->ticket_indicator = 0;
                    printf("*** Ticket closed! ***\n\n");
                }
            }
            break;

        case 4:
            if (ticket->ticket_indicator == 1){
                printf("\n");
                printf("ERROR: Ticket is already active!\n");
                printf("\n");
            }
            else{
                printf("\n");
                printf("Are you sure you want to RE-ACTIVATE this closed ticket? ([Y]es|[N]o): ");
                if (getCharOption("YN") == 'Y'){
                    printf("\n");
                    ticket->ticket_indicator = 1;
                    printf("*** Ticket re-activated! ***\n");
                    printf("\n");
                }
            }
        break;

        case 0:
            count = 0;
        break;
        }

    } 
    while (count);
}

int loadTickets(struct Ticket ticket[], int ticketsize){
    int i=0, j=0;
    FILE *fp = NULL;
    fp = fopen("tickets.txt", "r");
    if (fp != NULL){
        while (fscanf(fp, "%d|%d|%d|%[^|]|%d|", 
        &ticket[i].unique_no, &ticket[i].account_no, &ticket[i].ticket_indicator, ticket[i].subject, &ticket[i].counter) != EOF){
            if (i == ticketsize - 1){
                i = ticketsize;
                break;
            }

            if (ticket[i].counter > MAX_NUMBER_MESSAGE){
                ticket[i].counter = MAX_NUMBER_MESSAGE;
                for (j = 0; j < ticket[i].counter; j++){
                    fscanf(fp, "%c|%[^|]|%[^|]|",
                           &ticket[i].msg[j].account_type, ticket[i].msg[j].display_name, ticket[i].msg[j].message);
                }
                fscanf(fp, "%*[^\n]");
            }
            else{
                for (j = 0; j < ticket[i].counter; j++){
                    fscanf(fp, "%c|%[^|]|%[^|]|",
                           &ticket[i].msg[j].account_type,
                           ticket[i].msg[j].display_name,
                           ticket[i].msg[j].message);
                }
            }
            i++;
        }
    }
    else{
        printf("ERROR: ticket.txt doesn't exist!\n");
    }
    return i;
}

