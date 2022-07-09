#include"library.h"
#include"login_register.h"
#include"showTicket.h"
#include"accountBalance.h"
#include"showDate.h"
#include"removeTicket.h"
#include"admin.h"
void mainMenu() {
    printf("------------Welcome to CGV cinema------------\n");
    printf("1-User\n");
    printf("2-Admin\n");
    printf("3-Exit\n");
    printf("---------------------------------------------\n");
    do {
        printf("Enter your choice: ");
        gets(choice);
        fflush(stdin);
        if(!strcmp(choice,"1")|| !strcmp(choice,"2") || !strcmp(choice,"3")) {
            break;
        }
        else {
            printf("Invalid input. Please enter again!\n");
        }
    }while(1);
    if(!strcmp(choice,"1")) User();
    else if(!strcmp(choice,"2")) admin();
    else if(!strcmp(choice,"3")) {
        printf("Have a nice day!");
        return;
    }
}

void main1Menu() {
    printf("User login:\n");
    printf("1-Show tickets bought\n");
    printf("2-Remove the ticket\n");
    printf("3-Purchase tickets\n");
    printf("4-See your account balance\n");
    printf("5-Log out\n");
    do {
        printf("Enter your choice: ");
        gets(choice);
        fflush(stdin);
        if(!strcmp(choice,"1")|| !strcmp(choice,"2")|| !strcmp(choice,"3")|| !strcmp(choice,"4")|| !strcmp(choice,"5")) {
            break;
        }
        else {
            printf("Invalid input. Please enter again!\n");
        }
    }while(1);
    if(!strcmp(choice,"1")) showTicketandBack();
    else if(!strcmp(choice,"2")) removeTicket();
    else if(!strcmp(choice,"3")) showDate();
    else if(!strcmp(choice,"4")) seeBalance();
    else if(!strcmp(choice,"5")) mainMenu();
}
int main() {
    time_t rawtime;
    time(&rawtime);
    timeinfo= localtime (&rawtime);
    yearCur = timeinfo->tm_year+1900;
    monCur = timeinfo->tm_mon+1;
    dayCur = timeinfo->tm_mday;
    mainMenu();
}