#pragma once
#include"library.h"
#include"login_register.h"
void admin();
void checkPass() {
    char pass[100];
    FILE*file = fopen("./adminPassword.txt","r");
    fgets(adminPassword,100,file);
    do {
        printf("Enter the password to continue: ");
        gets(pass);
        fflush(stdin);
        if(!strcmp(pass,adminPassword)) break;
        else printf("Wrong password.Please enter again!!\n");
    }while(1);
    fclose(file);
}
void addMovie() {
    checkPass();
    char nameMovie[100];
    char prices[100];
    printf("Enter a movie name: ");
    gets(nameMovie);
    fflush(stdin);
    do {
        printf("Enter the price of ticket: ");
        gets(prices);
        fflush(stdin);
        int check=0;
        for(i=0;i<prices[strlen(prices)];i++) {
            if(prices[i]-'0'<0||prices[i]-'0'>9) {
                check=1;
                break;
            }
        }
        if(check) printf("Invalid input.Please enter again!!\n");
        else break;
    }while(1);
    FILE* file=fopen("./listOfMovie/movie.txt","r");
    i=0;
    char save[100][100];
    while(fgets(buffer,1000,file)) {
        i++;
        strcpy(save[i],buffer);
    }
    fclose(file);
    file=fopen("./listOfMovie/movie.txt","w");
    for(j=1;j<=i;j++) {
        fprintf(file,"%s",save[j]);
    }
    fprintf(file,"%s,%s\n",nameMovie,prices);
    fclose(file);
    printf("Add successfully!!\n");
    printf("1-Continue to add\n");
    printf("2-Back to last menu\n");
    do {
        printf("Enter your choice:");
        gets(choice);
        fflush(stdin);
        if(!strcmp(choice,"1")) {
            addMovie();
            break;
        }
        else if(!strcmp(choice,"2")) {
            admin();
            break;
        }
        else printf("Invalid input.Please enter again!!\n");
    }while(1);
}
void deleteMovie() {
    checkPass();
    char prices[100];
    FILE* file=fopen("./listOfMovie/movie.txt","r");
    char save[100][100];
    char line[100][100];
    i=0;
    int index;
    while(fgets(buffer,1000,file)) {
        i++;
        strcpy(line[i],buffer);
        char *a=strtok(buffer,",");
        strcpy(save[i],a);
    }
    fclose(file);
    for(j=1;j<=i;j++) {
        char printName[100];
        sprintf(printName,"%d-%s\n",j,save[j]);
        printf("%s",printName);
    }
    do {
        int checkkk=0;
        printf("Enter your choice of one movie to delete it: ");
        gets(choice);
        fflush(stdin);
        char a[100];
        for(j=1;j<=i;j++) {
            sprintf(a,"%d",j);
            if(!strcmp(choice,a)){
                index=j;
                checkkk=1;
                break;
            } 
        }
        if(checkkk)break;
        else printf("Invalid input. Please enter again!\n");
    } while(1);
    file=fopen("./listOfMovie/movie.txt","w");
    for(j=1;j<=i;j++) {
        if(index!=j) {
            fprintf(file,"%s",line[j]);
        }
    }
    fclose(file);
    printf("Delete successfully!!\n");
    printf("1-Continue to delete\n");
    printf("2-Back to last menu\n");
    do {
        printf("Enter your choice:");
        gets(choice);
        fflush(stdin);
        if(!strcmp(choice,"1")) {
            deleteMovie();
            break;
        }
        else if(!strcmp(choice,"2")) {
            admin();
            break;
        }
        else printf("Invalid input.Please enter again!!\n");
    }while(1);
}
void editPrice() {
    checkPass();
    char prices[100];
    FILE* file=fopen("./listOfMovie/movie.txt","r");
    char save[100][100];
    char line[100][100];
    i=0;
    int index;
    while(fgets(buffer,1000,file)) {
        i++;
        strcpy(line[i],buffer);
        char *a=strtok(buffer,",");
        strcpy(save[i],a);
    }
    fclose(file);
    for(j=1;j<=i;j++) {
        char printName[100];
        sprintf(printName,"%d-%s\n",j,save[j]);
        printf("%s",printName);
    }
    do {
        int checkkk=0;
        printf("Enter your choice of one movie to edit its price: ");
        gets(choice);
        fflush(stdin);
        char a[100];
        for(j=1;j<=i;j++) {
            sprintf(a,"%d",j);
            if(!strcmp(choice,a)){
                index=j;
                checkkk=1;
                break;
            } 
        }
        if(checkkk)break;
        else printf("Invalid input. Please enter again!\n");
    } while(1);
    do {
        printf("Enter new price of ticket: ");
        gets(prices);
        fflush(stdin);
        printf("strlen is %d\n",strlen(prices));
        int check=0;
        for(j=0;j<prices[strlen(prices)];j++) {
            if(prices[j]-'0'<0||prices[j]-'0'>9) {
                printf("ahihi\n");
                check=1;
                break;
            }
        }
        if(check) printf("Invalid input.Please enter again!!\n");
        else break;
    }while(1);
    file=fopen("./listOfMovie/movie.txt","w");
    printf("i is %d\n",i);
    for(j=1;j<=i;j++) {
        if(index!=j) {
            fprintf(file,"%s",line[j]);
        }
    }
    fprintf(file,"%s,%s\n",save[index],prices);
    fclose(file);
    printf("Edit successfully!!\n");
    printf("1-Continue to edit price of ticket\n");
    printf("2-Back to last menu\n");
    do {
        printf("Enter your choice:");
        gets(choice);
        fflush(stdin);
        if(!strcmp(choice,"1")) {
            editPrice();
            break;
        }
        else if(!strcmp(choice,"2")) {
            admin();
            break;
        }
        else printf("Invalid input.Please enter again!!\n");
    }while(1);
}
void changePassword() {
    checkPass();
    printf("Enter new password: ");
    gets(adminPassword);
    FILE*file = fopen("./adminPassword.txt","w");
    fprintf(file,"%s",adminPassword);
    fclose(file);
    printf("Change successfully!!\n");
    printf("1-Continue to change password\n");
    printf("2-Back to last menu\n");
    do {
        printf("Enter your choice:");
        gets(choice);
        fflush(stdin);
        if(!strcmp(choice,"1")) {
            changePassword();
            break;
        }
        else if(!strcmp(choice,"2")) {
            admin();
            break;
        }
        else printf("Invalid input.Please enter again!!\n");
    }while(1);
}
void admin() {
    printf("1-Add movie\n");
    printf("2-Delete movie\n");
    printf("3-Edit price of ticket\n");
    printf("4-Change admin password\n");
    printf("5-Back to last menu\n");
    do {
        printf("Enter your choice: ");
        gets(choice);
        fflush(stdin);
        if(!strcmp(choice,"1")) {
            addMovie();
            break;
        }
        else if(!strcmp(choice,"2")) {
            deleteMovie();
            break;
        }
        else if(!strcmp(choice,"3")) {
            editPrice();
            break;
        }
        else if(!strcmp(choice,"4")) {
            changePassword();
            break;
        }
        else if(!strcmp(choice,"5")) {
            mainMenu();
            break;
        }
    }while(1);
}