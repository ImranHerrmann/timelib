/**
* Programm zur Berechnung der bereits vergangenen Tage des Jahres anhand eines
* eingegebenen Datums.
*
* Autor: Imran Yassir Herrmann
* Klasse: IFA92
*
* 2020-01-28
**/

#include <stdio.h>
#include <stdlib.h>

/**
* Funktion berechnet ob Jahr ein Schaltjahr ist
*
* return 0 if no, 1 if yes, -1 if wrong year
**/
int is_leapyear(int year)
{

//Deklaration der Variablen
    int jahr = year;
    int isLeapyear = 0;

    if (1582 > jahr && jahr > 2400)
    {
        return -1;
    }


//Rechnung / Jahr mit Modulo, weil es erst ohne einen Rest, ein Schaltjahr ist
    if (jahr % 4 == 0)
    {
        if (jahr % 100 == 0)
        {
            if (jahr % 400 == 0)
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
* Gibt Anzahl der Tage des abgefragten Monats aus
*
* return Tage des Monats, -1 wenn ungültige Daten übergeben wurden
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
* Überprüft ob Datum existiert
*
**/
int exists_date(int day, int month, int year)
{
    int isValid = 1;
    if (month > 12 || month < 1 || year < 1582 || year > 2399 || day < 0 || get_days_for_month(month, year) < day)
    {
        return isValid = 0;
    }

    return 1;
}

/**
 * Funktion zur Berechnung des Tags des Jahres
 *
 * return -1 wenn Datum nicht existiert
 **/
int day_of_the_year(int day, int month, int year)
{
    //Deklaration der Variablen und des Monatsarray
    int i = 0, ergebnis = 0;
    int tage[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

    //Überprüfung ob es ein Schaltjahr ist
    if (is_leapyear(year) == 1)
    {
        //Änderung des Februars in 29 Tage
        tage[1] = 29;
    }

    //Überprüfung ob Datum existiert
    if (month < 0 || month > 12 || year < 0 || day < 1 || day > tage[month - 1])
    {
        return -1;
    }

    //Berechnung der Tage durch Addition der vergangenen Monate
    for (i = 0; i < month - 1; i++)
    {
        ergebnis += tage[i];
    }

    //Addition des aktuellen Monats
    ergebnis += day;

    return ergebnis;
}

int input_date(int day, int month, int year)
{
    return 0;
}

int main()
{
    int tag_des_jahres = day_of_the_year(30, 5, 2020);

    //Überprüfung ob Funktion einen Fehler zurückgibt
    if (tag_des_jahres == -1)
    {
        //Ausgabe des Fehlers
        printf("Datum existiert nicht. Fehlercode: %i\n", tag_des_jahres);
        return -1;
    }

    //Ausgabe falls Datum korrekt
    printf("Tag des Jahres: %i\n", tag_des_jahres);
    return 0;
}
