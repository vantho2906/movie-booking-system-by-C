#pragma once
#include"library.h"
#include"login_register.h"
void removing(int number) {
    int day,month,year;
    char filepath[100];
    sprintf(filepath,"./ticketShow/%s.txt",username);
    FILE* file = fopen(filepath,"r");
    int count=0,i=0;
    char takeData[100][100];
    char one[100],copy[100];
    while(fgets(buffer,1000,file)) {
        count++;
        if(count!=number) {
            i++;
            strcpy(takeData[i],buffer);
        } else {
            strcpy(one,buffer);
            strcpy(copy,buffer);
        }
    }
    fclose(file);
    file=fopen(filepath,"w");
    for(j=1;j<=i;j++) {
        fprintf(file,"%s",takeData[j]);
    }
    fclose(file);
    char * a;
    a=strtok(one,",");
    a=strtok(NULL,","); // lấy ra tên phim
    char movieName[100];
    strcpy(movieName,a);
    a=strtok(NULL,","); // lay ra duoc ngay thang nam
    char * data;
    data= strtok(a,"-");
    day = atoi(data);
    data= strtok(NULL,"-");
    month= atoi(data);
    data= strtok(NULL,"-");
    year= atoi(data);
    a=strtok(copy,",");
    for(i=1;i<=3;i++) a=strtok(NULL,",");
    char timer[100];
    strcpy(timer,a);
    a=strtok(NULL,",");// lay ra hội trường
    a=strtok(NULL,",");// lấy ra vị trí ngồi
    char seat[100];
    strcpy(seat,a);
    a=strtok(NULL,",");// lấy ra giá vé
    int tickerPrice = atoi(a);
    int checkout=0;
    if(year>=yearCur) {
        if(month>=monCur) {
            if(day>dayCur) {
                checkout=1;
            }
        }
    }
    if(!checkout) {
        printf("Remove successfully!!\n");
        printf("The ticket was used so there will be no Refund\n");
    }
    else {
        printf("Remove successfully!!\n");
        printf("you receive a refund of 50%% ticket price(%d) which is %d\n",tickerPrice,tickerPrice/2);
        balance+= tickerPrice/2;
        printf("Your balance now is %d\n",balance);
        saveToFile();
        sprintf(filepath,"./movieName/%s/%d-%d-%d/",movieName,day,month,year);
        if(!strcmp(timer,"7:30")) strcat(filepath,"1.txt");
        else if(!strcmp(timer,"10:30")) strcat(filepath,"2.txt");
        else if(!strcmp(timer,"15:30")) strcat(filepath,"3.txt");
        else if(!strcmp(timer,"20:30")) strcat(filepath,"4.txt");
        file=fopen(filepath,"r");
        count=0;i=0;
        strcat(seat,"\n");
        while(fgets(buffer,1000,file)) {
            if(strcmp(seat,buffer)) {
                count++;
                strcpy(takeData[count],buffer);
            }
        }
        fclose(file);
        file=fopen(filepath,"w");
        for(i=1;i<=count;i++) {
            fprintf(file,"%s",takeData[i]);
        }
        fclose(file);
    }

}
void removeTicket() {
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
        fclose(file);
        if(!checkk) printf("No data.\n");
        else {
            int number;
            do {
                int check1=0;
                printf("Remove the ticket No.: ");
                gets(choice);
                fflush(stdin);
                for(i=1;i<=countTickets;i++) {
                    char a[100];
                    sprintf(a,"%d",i);
                    if(!strcmp(choice,a)) {
                        check1=1;
                        number=i;
                        removing(number);
                        break;
                    }
                }
                if(check1) break;
                printf("Invalid input.Please enter again!!\n");
            }while(1);
        }
        
    } 
    printf("1-continue to remove ticket\n");
    printf("2-back to last menu\n");
    do {
        gets(choice);
        fflush(stdin);
        if(!strcmp(choice,"1")) {
            removeTicket();
            break;
        }
        else if(!strcmp(choice,"2")) {
            main1Menu();
            break;
        }
        else printf("Invalid input. Please enter again!\n");
    }while(1);
    
}