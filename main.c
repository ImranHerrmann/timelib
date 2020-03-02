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
    struct date inputDate = input_date();


    int tag_des_jahres = day_of_the_year(inputDate);

    //check for error
    if (tag_des_jahres == -1)
    {
        printf("Datum existiert nicht. Fehlercode: %i\n", tag_des_jahres);
        return -1;
    }

    printf("Tag des Jahres: %i\n", tag_des_jahres);
    return 0;
}
