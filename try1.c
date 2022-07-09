#include "library.h"
char buffer[1000];
char fullname[100];


    /* Program to print %*/
int main()
{
    int i;
    int day,month,year;
    char one[100]="1235,Jurassic Park,7-7-2022,20:30,1,J6,90000\n";
    char omg[100];
    strcpy(omg,one);
    char * a;
    a=strtok(one,",");
    a=strtok(NULL,",");
    printf("%s",a);
    char movieName[100];
    strcpy(movieName,a);
    a=strtok(NULL,","); // lay ra duoc ngay thang nam
    char temp[100];
    strcpy(temp,a);
    printf("%s",a);
    char * data;
    data= strtok(temp,"-");
    day = atoi(data);
    printf("%d",day);
    data= strtok(NULL,"-");
    month= atoi(data);
    printf("%d",month);
    data= strtok(NULL,"-");
    year= atoi(data);
    printf("%d",year);
    a=strtok(omg,",");
    for(i=1;i<=3;i++) a=strtok(NULL,",");
    printf("%s",a);
    char timer[100];
    strcpy(timer,a);
    a=strtok(NULL,",");// lay ra hội trường
    printf("%s",a);
    a=strtok(NULL,",");// lấy ra vị trí ngồi
    printf("%s",a);
    char seat[100];
    strcpy(seat,a);
    a=strtok(NULL,",");// lấy ra giá vé
    printf("%s",a);
    int tickerPrice = atoi(a);
}

