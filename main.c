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
* return 0 if no, 1 if yes
**/
int istSchaltjahr(int jahrTest)
{

//Deklaration der Variablen
    int jahr = jahrTest;
    int istSchaltjahr = 0;


//Rechnung / Jahr mit Modulo, weil es erst ohne einen Rest, ein Schaltjahr ist
    if (jahr % 4 == 0)
    {
        if (jahr % 100 == 0)
        {
            if (jahr % 400 == 0)
            {
                istSchaltjahr = 1;
            }

            else
            {
                istSchaltjahr = 0;
            }
        }

        else
        {
            istSchaltjahr = 1;
        }
    }
    else
    {
        istSchaltjahr = 0;
    }
    return istSchaltjahr;

}

/**
 * Funktion zur Berechnung des Tags des Jahres
 *
 * return -1 wenn Datum nicht existiert
 **/
int day_of_the_year(int day, int month, int year)
{
    //Deklaration der Variablen und des Monatsarray
    int tag = day, monat = month, jahr = year, i = 0, ergebnis = 0;
    int tage[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

    //Überprüfung ob es ein Schaltjahr ist
    if (istSchaltjahr(jahr) == 1)
    {
        //Änderung des Februars in 29 Tage
        tage[1] = 29;
    }

    //Überprüfung ob Datum existiert
    if (monat < 0 || monat > 12 || jahr < 0 || tag < 1 || tag > tage[monat - 1])
    {
        printf("Datum existiert nicht");
        return -1;
    }

    //Berechnung der Tage durch Addition der vergangenen Monate
    for (i = 0; i < monat - 1; i++)
    {
        ergebnis += tage[i];
    }

    //Addition des aktuellen Monats
    ergebnis += tag;

    return ergebnis;
}

int main()
{
    int tag_des_jahres = day_of_the_year(25, 4, 1992);

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
