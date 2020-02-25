/**
* Headerdatei zur Berechnung der bereits vergangenen Tage des Jahres anhand eines
* eingegebenen Datums.
*
* Autor: Imran Yassir Herrmann
* Klasse: IFA92
*
* 2020-02-25
**/

#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

int is_leapyear(int year);

int get_days_for_month(int month, int year);

int exists_date(int day, int month, int year);

int day_of_the_year(int day, int month, int year);

int input_date(int *day, int *month, int *year);
#endif // FUNCTIONS_H_INCLUDED
