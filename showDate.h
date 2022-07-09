#pragma once
#include"library.h"
#include"login_register.h"
#include"showMovie.h"

char monthList[][100]={"January","February","March","April","May","June","July","August","September","October","November","December"};
char shortmonthList[][100]={"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
int mDays[12]={31,28,31,30,31,30,31,31,30,31,30,31};
struct tm * timeinfo;

int checkValidDate(int day,int month,int year) {
    if((year%4==0&&year%100!=0)||year%400==0) mDays[1]=29;
        else mDays[1]=28;
    if(month<1||month>12) return 0;
    if(mDays[month-1]<day||day<1) return 0;
    return 1;
}
void enterDate() {
    do {
        printf("Enter the date(d/m/y): ");
        gets(choice);
        fflush(stdin);
        int false=0;
        int dem=0;
        if(choice[0]=='/') false=1;
        if(choice[strlen(choice)-1]=='/') false=1;
        if(!false) {
            for(i=0;i<strlen(choice);i++) {
                if(choice[i]=='/') {
                    dem++;
                    if(choice[i+1]=='/') {
                        false=1; break;
                    }
                }
                else {
                    if(choice[i]-'0'<0||choice[i]-'0'>9) {
                        false=1;break;
                    }
                }
            }
        }
        if(dem!=2) false=1;
        if(false) {
            printf("Invalid input.Please enter again!\n");
        } else {
            char *a;
            a= strtok(choice,"/");
            day = atoi(a);
            a= strtok(NULL,"/");
            month = atoi(a);
            a= strtok(NULL,"/");
            year = atoi(a);
            if(!checkValidDate(day,month,year)) {
                printf("Invalid date.Please enter again!\n");
            } else {
                int checker=0;
                if(year>=yearCur) {
                    if(month>=monCur) {
                        if(day>=dayCur) {
                            checker=1;
                        }
                    }
                }
                if(checker) {
                    sprintf(showwDate,"%d/%d/%d",day,month,year);
                    break;
                } else {
                    printf("Can not enter date in the past.Please enter another date!!\n");
                }
                
            }
        }
    } while(1);
}
void showDate() {
    int yearCurrent=timeinfo->tm_year+1900;
    if((yearCurrent%4==0&&yearCurrent%100!=0)||yearCurrent%400==0) mDays[1]=29;
    else mDays[1]=28;
    printf("Today is %s %d %d\n",monthList[timeinfo->tm_mon],mDays[timeinfo->tm_mon],timeinfo->tm_year+1900);
    int k=timeinfo->tm_mday%7;
    int startDayof1 = timeinfo->tm_wday-k+1;
    if(startDayof1<0)startDayof1+=7;
    int j;
    printf("%10s%10s%10s%10s%10s%10s%10s\n","Sunday","Monday","Tuesday","Wednesday","Thurday","Friday","Saturday");
    for(j=0;j<startDayof1;j++) {
        printf("%10s","");
    }
    j=startDayof1-1;
    for(int i=1;i<=mDays[timeinfo->tm_mon];i++) {
        j++;
        if(j>6){j=0;printf("\n");}
        printf("%10d",i);
    }
    printf("\n");
    enterDate();
    showMovie();
}
