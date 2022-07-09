#pragma once
#include"library.h"

int i,j;
char adminPassword[100];
int countTickets,hallNumber[100];
int priceOfTicket[100];
char fullname[100];
char username[100];
char password[100];
int balance;
char ID[10];
char showName[100];
char showwDate[100];
char timee[100];
char hall[5];
char seats[100];
char price[100];
int day=0,month=0,year=0;
char buffer[1000];
char choice[100];
int countMovie;
char content[100][100];
int yearCur,monCur,dayCur;
int accountCheck(char username[],char password[]) {
    FILE *file = fopen("user.txt","r");
    while(fgets(buffer,1000,file)) {
        char* usernameList = strtok(buffer, ",");
        if(!strcmp(usernameList,username)) {
            usernameList = strtok(NULL, ",");
            if(!strcmp(usernameList,password)) {
                usernameList = strtok(NULL, ",");
                strcpy(fullname,usernameList);
                usernameList = strtok(NULL, ",");
                balance = atoi(usernameList);
                fclose(file);
                return 1;
            }
        }
    }
    fclose(file);
    return 0;
}
int usernameCheckExist(char username[]) {
    char buffer[1000];
    FILE *file = fopen("user.txt","r");
    while(fgets(buffer,1000,file)) {
        char* usernameList = strtok(buffer, ",");
        if(!strcmp(usernameList,username)) {
            return 1;
        }
    }
    return 0;
}
void inputChoice(char choice[]) {
    do {
        printf("Enter your choice: ");
        gets(choice);
        fflush(stdin);
        if(!strcmp(choice,"1")|| !strcmp(choice,"2")|| !strcmp(choice,"3")) {
            break;
        }
        else {
            printf("Invalid input. Please enter again!\n");
        }
    }while(1);
}
void main1Menu();
void mainMenu();
void login();
void Register();
void User();
void showMovie();
void deposit();
void showTicket();
void saveToFile();
void login() {
    do {
        printf("\nEnter your username: ");
        scanf("%s",&username);
        fflush(stdin);
        printf("Enter your password: ");
        scanf("%s",&password);
        fflush(stdin);
        int check = accountCheck(username,password);
        if(check==0) {
            printf("Wrong username or password.\n");
            printf("1- Login again\n");
            printf("2- Go to Register\n");
            printf("3- Back to user menu\n");
            inputChoice(choice);
            if(!strcmp(choice,"2")) {
            Register();break;
            }
            else if(!strcmp(choice,"3")) {
            User();break;
            }
        }
        else {
            printf("Login successfully\n");
            printf("Hello %s!\n\n",fullname);
            main1Menu();
            break;
        }
    }while(1);
    
}
void Register() {
    char confirmPassword[100];
    printf("Enter your fullname: ");
    gets(fullname);
    fflush(stdin);
    do {
        printf("Enter your username: ");
        scanf("%s",&username);
        fflush(stdin);
        if(usernameCheckExist(username)) {
            printf("Username existed.Please enter another!\n");
        }
        else break;
    }while(1);
    printf("Enter your password: ");
    scanf("%s",&password);
    fflush(stdin);
    do {
        printf("Confirm your password: ");
        scanf("%s",&confirmPassword);
        fflush(stdin);
        if(strcmp(password,confirmPassword)) {
            printf("Confirm password not the same with password.Please type again!\n");
        }
        else break;
    }while(1);
    FILE *file;
    file = fopen("./user.txt","a");
    balance=0;
    fprintf(file,"%s,%s,%s,%d\n",username,password,fullname,balance);
    fclose(file);
    printf("Register successfully\n\n");
    printf("1-Continue to Register\n");
    printf("2-Go to Login\n");
    printf("3-Back to user menu\n");
    inputChoice(choice);
    if(!strcmp(choice,"1")) Register();
    else if(!strcmp(choice,"2")) login();
    else User();
}

void User() {
    printf("1-Login\n");
    printf("2-Register\n");
    printf("3-Back to main menu\n");
    do {
        printf("Enter your choice: ");
        gets(choice);
        fflush(stdin);
        if(!strcmp(choice,"1")|| !strcmp(choice,"2")|| !strcmp(choice,"3")) {
            break;
        }
        else {
            printf("Invalid input. Please enter again!\n");
        }
    }while(1);
    if(!strcmp(choice,"1")) {
        login();
    }
    else if(!strcmp(choice,"2")) {
        Register();
    }
    else {
        mainMenu();
    }
}