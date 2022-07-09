#pragma once
#include"library.h"
#include"login_register.h"
void movieProcess(char movie[],int pricee,int hallNum) {
    int i,j;
    int check[1000]= {0};
    char fileName[100];
    char folderName[100];
    char hour[100];
    char usernameFile[100];
    sprintf(folderName,"./movieName/%s",movie);
    mkdir(folderName);
    sprintf(folderName,"./movieName/%s/%d-%d-%d",movie,day,month,year);
    sprintf(fileName,"./movieName/%s/%d-%d-%d/",movie,day,month,year);
    mkdir(folderName);
    FILE *file;
    printf("1-7:30\n");
    printf("2-10:30\n");
    printf("3-15:30\n");
    printf("4-20:30\n");
    int chosen;
    do {
        printf("Choose the time: ");
        scanf("%d",&chosen);
        fflush(stdin);
        if(chosen<1||chosen>4) printf("Invalid input. Please choose again!!\n");
        else break;
    }while(1);
    if(chosen==1) {strcat(fileName,"1.txt"); strcpy(hour,"7:30");}
    else if(chosen==2) {strcat(fileName,"2.txt"); strcpy(hour,"10:30");}
    else if(chosen==3) {strcat(fileName,"3.txt"); strcpy(hour,"15:30");}
    else if(chosen==4) {strcat(fileName,"4.txt"); strcpy(hour,"20:30");}
    if(file = fopen(fileName,"r")) {
        while(fgets(buffer,1000,file)) {
        int index = (buffer[0]-'A')*10+buffer[1]-'0';
        if(strlen(buffer)==4) index+=9;
        check[index]=1;
        }
        fclose(file);
    }
    else {
        fclose(file);
        file = fopen(fileName,"w");
        fclose(file);
    }
    printf("\t\t\t\t\t\t\tSCREEN\n\n\n");
    for(i=0;i<=9;i++) {
        for(j=1;j<=10;j++) {
            char add[100];
            if(j==3||j==9) printf("\t\t");
            if(check[i*10+j]) {strcpy(add,"X");}
            else {
                sprintf(add,"%c%d",i+65,j);
            }
            if(j==10) printf("%11s",add);
            else printf("%10s",add);
        }
        printf("\n");
    }
    int numberOfTickets;
    char option[100];
    do {
        int checkSyntax=0;
        printf("\nPlease select the number of tickets you want(maximum 5): ");
        gets(option);
        fflush(stdin);
        int i;
        for(i=0;i<strlen(option);i++) {
            if(option[i]-'0'<0||option[i]-'0'>9) {
                checkSyntax=1;
                break;
            }
        }
        if(checkSyntax) printf("Invalid input.Please enter again!!\n");
        else {
            numberOfTickets=atoi(option);
            if(numberOfTickets>=1&&numberOfTickets<=5) {
                if(numberOfTickets*pricee>balance) {
                    printf("The total price of these tickets is %d while your balance is %d\n",numberOfTickets*pricee,balance);
                    printf("You dont have enough money!\n");
                    printf("1-Deposit money\n");
                    printf("2-Select again the number of tickets\n");
                    char decide[100];
                    do {
                        printf("Enter your choice: ");
                        gets(decide);
                        if(!strcmp(decide,"1")|| !strcmp(decide,"2")) break;
                        else printf("Invalid input.Please enter again!\n");
                    }while(1);
                    if(!strcmp(decide,"1")) deposit();
                }
                else break;
            }
            else printf("The number tickets you can buy can not exceed 5.Please enter a number <=5!!\n");
        }
        
        
    }while(1);
    fflush(stdin);
    file = fopen(fileName,"a");
    char date[100];
    int num;
    FILE* file2;
    sprintf(usernameFile,"./ticketShow/%s.txt",username);
    file2 =fopen(usernameFile,"a");
    int IDlist[6],demm=0;
    for(i=1;i<=numberOfTickets;i++) {
        char th[10];
        int index;
        char choose[100];
        if(i==1) {
            if(numberOfTickets==1) strcpy(th,"");
            else strcpy(th,"first ");
        }
        else if(i==2) strcpy(th,"second ");
        else if(i==3) strcpy(th,"third ");
        else sprintf(th,"%dth ",i);
        do {
                printf("Please select your %sseat: ",th);
                scanf("%s",&choose);
                index = (choose[0]-'A')*10+choose[1]-'0';
                if(strlen(choose)==3) index+=9;
                if(strlen(choose)>3) printf("Unavailable seat.Please select again!!\n");
                else if(choose[0]!='A'&&choose[0]!='B'&&choose[0]!='C'&&choose[0]!='D'&&choose[0]!='E'
                    &&choose[0]!='F'&&choose[0]!='G'&&choose[0]!='H'&&choose[0]!='I'&&choose[0]!='J')
                    printf("Unavailable seat.Please select again!!\n");
                else if(0>=choose[1]-'0'||10<=choose[1]-'0') printf("Unavailable seat.Please select again!!\n");
                else if(strlen(choose)==3 &&choose[2]!='0') printf("Unavailable seat.Please select again!!\n");
                else if(check[index]) printf("Unavailable seat.Please select again!!\n");
                else break;
        } while(1);
        check[index]=1;
        fprintf(file,"%s\n",choose);
        srand( (int)time(NULL) );
        num = rand()%100000+100000;
        demm++; IDlist[demm]=num;
        sprintf(date,"%d-%d-%d",day,month,year);
        fprintf(file2,"%d,%s,%s,%s,%d,%s,%d\n",num,movie,date,hour,hallNum,choose,pricee);
    }
    fclose(file);
    fclose(file2);
    file=fopen(usernameFile,"r");
    char *line;
    char buffer[1000];
    demm=1;
    while(fgets(buffer,1000,file)) {
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
        char a[100];
        sprintf(a,"%d",IDlist[demm]);
        if(!strcmp(a,ID)) {
            demm++;
            printf("****************************\n");
            printf("\tBooking ID:%s\t\t\tShow name:%s\n",ID,showName);
            printf("\tCustomer:%s\n",fullname);
            printf("\t\t\t\t\tDate: %s\n",showwDate);
            printf("\t\t\t\t\tTime: %s\n",timee);
            printf("\t\t\t\t\tHall: %s\n",hall);
            printf("\t\t\t\t\tSeat: %s\n",seats);
            printf("\t\t\t\t\tPrice: %s\n",price);
        }
    }
    fclose(file);
    printf("The total price is %d\n",numberOfTickets*pricee);
    balance-=numberOfTickets*pricee;
    saveToFile();
    printf("Your balance is %d left\n",balance);
    printf("Thank you for booking!!!\n");


}
void takeMovie() {
    FILE* file=fopen("./listOfMovie/movie.txt","r");
    countMovie=0;
    while(fgets(buffer,1000,file)) {
        countMovie++;
        char *a;
        a=strtok(buffer,",");
        strcpy(content[countMovie],a);
        a=strtok(NULL,",");
        priceOfTicket[countMovie]= atoi(a);
        a=strtok(NULL,",");
        hallNumber[countMovie] = atoi(a);
    }
    fclose(file);
}
void showMovie() {
    takeMovie();
    printf("----------Movie name----------\n");
    for(i=1;i<=countMovie;i++) {
        char printName[100];
        sprintf(printName,"%d-%s\n",i,content[i]);
        printf("%s",printName);
    }
    char choice[100];
    do {
        int checkkk=0;
        printf("Enter your choice: ");
        gets(choice);
        fflush(stdin);
        for(i=1;i<=countMovie;i++) {
            char a[100];
            sprintf(a,"%d",i);
            if(!strcmp(choice,a)){
                checkkk=1;
                movieProcess(content[i],priceOfTicket[i],hallNumber[i]);
                break;
            } 
        }
        if(checkkk)break;
        else printf("Invalid input. Please enter again!\n");
    } while(1);
    system("pause");
    fflush(stdin);
    main1Menu();
}