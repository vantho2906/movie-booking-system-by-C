#pragma once
#include"library.h"
#include"login_register.h"

void saveToFile() {
    FILE*file = fopen("../txtFiles/user.txt","r");
    char buffer[1000];
    char *line;
    char save[100][1000];
    int count=-1;
    char temp[1000];
    while(fgets(buffer,1000,file)) {
        strcpy(temp,buffer);
        line = strtok(buffer,",");
        if(strcmp(line,username)!=0) {
            strcpy(save[++count],temp);
        }
    }
    fclose(file);
    file = fopen("../txtFiles/user.txt","w");
    for(i=0;i<=count;i++) {
        fprintf(file,"%s",save[i]);
    }
    fprintf(file,"%s,%s,%s,%d\n",username,password,fullname,balance);
    fclose(file);
}
void deposit() {
    int moneyAdd;
    do {
        printf("Enter money you want to add(multiple of 50000): ");
        scanf("%d",&moneyAdd);
        fflush(stdin);
        if(moneyAdd%50000!=0) {
            printf("the money added has to be the multiple of 50000.Please enter again!\n");
        }
        else {
            balance+=moneyAdd;
            saveToFile();
            break;
        }
    }while(1);
    printf("deposit successfully!\n");
    printf("Your balance now is %d\n",balance);
}
void seeBalance() {
    printf("Your balance is %d\n",balance);
    printf("1-Deposit money\n");
    printf("2-Back to last menu\n");
    char choice[100];
    do {
        printf("Enter your choice: ");
        gets(choice);
        fflush(stdin);
        if(!strcmp(choice,"1")|| !strcmp(choice,"2")) {
            break;
        }
        else {
            printf("Invalid input. Please enter again!\n");
        }
    }while(1);
    if(!strcmp(choice,"1")) {
        deposit();
        printf("----------\n");
        printf("1-To continue to deposit\n");
        printf("2-Back to last menu\n");
        do {
            printf("Enter your choice: ");
            gets(choice);
            fflush(stdin);
            if(!strcmp(choice,"1")|| !strcmp(choice,"2")) {
                break;
            }
            else {
                printf("Invalid input. Please enter again!\n");
            }
        }while(1);
        if(!strcmp(choice,"1")) deposit();
        else main1Menu();
    }
    else if(!strcmp(choice,"2")) {
        main1Menu();
    }
}