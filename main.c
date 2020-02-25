#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

/**
* Programm zur Berechnung der bereits vergangenen Tage des Jahres anhand eines
* eingegebenen Datums.
*
* Autor: Imran Yassir Herrmann
* Klasse: IFA92
*
* 2020-01-28
**/
int main()
{
    int day = 0, month = 0, year = 0;
    input_date(&day, &month, &year);

    int tag_des_jahres = day_of_the_year(day, month, year);

    //check for error
    if (tag_des_jahres == -1)
    {
        printf("Datum existiert nicht. Fehlercode: %i\n", tag_des_jahres);
        return -1;
    }

    printf("Tag des Jahres: %i\n", tag_des_jahres);
    return 0;
}
