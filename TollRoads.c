/******************************************************************************

Esther Lee
ELET 1102
Project 3: Toll Roads
This code determines how much money you have on your quick pass based on the day
and how many exits you've passed. 

*******************************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    int militaryTime;
    int stdTime;
    char whichDay[5];
    double startExit;
    double endExit;
    double peopleInCar;
    double exitTotal;
    
    double startMoney = 33.33;
    double totalCharge;
    double remainingMoney;
    
    double weekday;
    double weekendOrHoliday;
    
    printf("You currently have $%lf in your Quick Pass.\n", startMoney);
    
    printf("Is it a holiday or a weekend?(y/n): ");
    scanf("%s", whichDay);
    
    printf("What time did you start driving?(24hr HHMM): ");
    scanf("%d", &militaryTime);
    
    printf("What exit number did you enter from?(1-25) ");
    scanf("%lf", &startExit);
    printf("What exit number did you exit from?(1-25) ");
    scanf("%lf", &endExit);
    exitTotal = ((abs(endExit - startExit)) * .10);
    
    printf("How many people were in the car? ");
    scanf("%lf", &peopleInCar);
    if(peopleInCar >= 3)
    {
        peopleInCar = .50;
        printf("\n\nYou get a $.50 discount");
    }else
    {
        peopleInCar = 0;
    }
    
    if(strcmp(whichDay, "n") == 0)
    {
        if(militaryTime >= 0000 && militaryTime <= 559)
        {
            weekday = 1.55;
            
        }else if(militaryTime >= 600 && militaryTime <= 959)
        {
            weekday = 2.65;
            
        }else if(militaryTime >= 1000 && militaryTime <= 1759)
        {
            weekday = 2.35;
            
        }else if(militaryTime >= 1800 && militaryTime <= 2459)
        {
            weekday = 1.25;
        }
        
        remainingMoney = startMoney - ((weekday + exitTotal) - peopleInCar);
        totalCharge = weekday + exitTotal;
        
    }else if(strcmp(whichDay, "y") == 0)
    {
        if(militaryTime >= 0000 && militaryTime <= 759)
        {
            weekendOrHoliday = 1;
            
        }else if(militaryTime >= 800 && militaryTime <= 959)
        {
            weekendOrHoliday = 2.05;
            
        }else if(militaryTime >= 1200 && militaryTime <= 1559)
        {
            weekendOrHoliday = 2.45;
            
        }else if(militaryTime >= 1600 && militaryTime <= 1859)
        {
            weekendOrHoliday = 2.60;
            
        }else if(militaryTime >= 1900 && militaryTime <= 2159)
        {
            weekendOrHoliday = 2.05;
            
        }else if(militaryTime >= 2200 && militaryTime <= 2459)
        {
            weekendOrHoliday = .55;
        }
        
        remainingMoney = startMoney - ((weekendOrHoliday + exitTotal) - peopleInCar);
        totalCharge = weekendOrHoliday + exitTotal;
    }
    
    printf("\nTotal amount charged is: $%lf\n", totalCharge);
    printf("You have $%lf left on your Carolinas Quick Pass\n", remainingMoney);
    
    if(militaryTime >= 1300)
    {
        stdTime = militaryTime - 1200;
    }else
    {
        stdTime = militaryTime;
    }
    printf("Your time in 24-hr format is: %d\n", stdTime);
    
    return 0;
}

