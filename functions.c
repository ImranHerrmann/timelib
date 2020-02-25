/**
* Funktionsbibliothek zur Berechnung der bereits vergangenen Tage des Jahres anhand eines
* eingegebenen Datums.
*
* Autor: Imran Yassir Herrmann
* Klasse: IFA92
*
* 2020-02-25
**/

#include "functions.h"

/**
* Checks if year is leapyear
*
* return 0 if no, 1 if yes, -1 if wrong year
**/
int is_leapyear(int year)
{

//declaration of variables
    int isLeapyear = 0;

    if (1582 > year && year > 2400)
    {
        return -1;
    }


//calculation
    if (year % 4 == 0)
    {
        if (year % 100 == 0)
        {
            if (year % 400 == 0)
            {
                isLeapyear = 1;
            }

            else
            {
                isLeapyear = 0;
            }
        }

        else
        {
            isLeapyear = 1;
        }
    }
    else
    {
        isLeapyear = 0;
    }

    return isLeapyear;

}

/**
* calculates days of month
*
* return days of month, -1 when wrong month/year
**/
int get_days_for_month(int month, int year)
{
    int daysOfMonths[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

    //Überprüfung auf Schaltjahr
    if (is_leapyear(year) == 1)
    {
        daysOfMonths[1] = 29;
    }
    //Überprüfung ob Übergabeparameter gültig sind
    else if (is_leapyear(year) == -1 || month < 1 || month > 12)
    {
        return -1;
    }

    return daysOfMonths[month - 1];
}

/**
* checks if date exists
*
* return 0 if date exists, -1 if not
**/
int exists_date(int day, int month, int year)
{
    if (month > 12 || month < 1 || year < 1582 || year > 2399 || day < 1 || get_days_for_month(month, year) < day)
    {
        return -1;
    }

    return 0;
}

/**
 * calculates days of year
 *
 * return count of days, -1 if wrong date
 **/
int day_of_the_year(int day, int month, int year)
{
    //declaration of variables
    int i = 0, ergebnis = 0;
    int tage[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

    //check leapyear
    if (is_leapyear(year) == 1)
    {
        tage[1] = 29;
    }

    //check if valid date
    if (exists_date(day, month, year) == -1)
    {
        return -1;
    }

    //calculation of days
    for (i = 0; i < month - 1; i++)
    {
        ergebnis += tage[i];
    }

    ergebnis += day;

    return ergebnis;
}

/**
* Lets user enter a date
*
* return 0 if date is valid
**/
int input_date(int *day, int *month, int *year)
{
    do
    {
        printf("Please enter day: ");
        scanf("%d", day);
        printf("Please enter month: ");
        scanf("%d", month);
        printf("Please enter day: ");
        scanf("%d", year);
    }
    while(exists_date(*day, *month, *year) == -1);

    return 0;
}
