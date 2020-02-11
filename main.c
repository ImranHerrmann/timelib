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
#include "functions.h"

int main()
{
    int tag_des_jahres = day_of_the_year(30, 9, 2800);

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
