#pragma once
#include"library.h"
#include"login_register.h"
void showTicket() {
    char usernameFile[100];
    sprintf(usernameFile,"./ticketShow/%s.txt",username);
    FILE*file;
    if(!(file=fopen(usernameFile,"r"))) {
        printf("No data.\n");
    }
    else {
        int checkk=0;
        char *line;
        countTickets=0;
        while(fgets(buffer,1000,file)) {
            checkk=1;
            countTickets++;
            line = strtok(buffer, ",");
            strcpy(ID,line);
            line = strtok(NULL,",");
            strcpy(showName,line);
            line = strtok(NULL,",");
            strcpy(showwDate,line);
            line = strtok(NULL,",");
            strcpy(timee,line);
            line = strtok(NULL,",");
            strcpy(hall,line);
            line = strtok(NULL,",");
            strcpy(seats,line);
            line = strtok(NULL,",");
            strcpy(price,line);
            printf("Number %d:\n",countTickets);
            printf("****************************\n");
            printf("\tBooking ID:%s\t\t\tShow name:%s\n",ID,showName);
            printf("\tCustomer:%s\n",fullname);
            printf("\t\t\t\t\tDate: %s\n",showwDate);
            printf("\t\t\t\t\tTime: %s\n",timee);
            printf("\t\t\t\t\tHall: %s\n",hall);
            printf("\t\t\t\t\tSeat: %s\n",seats);
            printf("\t\t\t\t\tPrice: %s\n",price);
        }
        if(!checkk) printf("No data.\n");
    }   
    fclose(file);
}
void showTicketandBack() {
    showTicket();
    system("pause");
    fflush(stdin);
    main1Menu();
}