#include<iostream>
using namespace std;

class Date {
	
	int _day, _month, _year;

public:
	Date(int = 0, int = 0, int = 0);
	Date operator+(int days);
	friend ostream & operator<<(ostream&, const Date&);
};



    // Konstruktor, der die Daten intialisiert:
    Date::Date(int day, int month, int year) {
        _day = day;
        _month = month;
        _year = year;
        }

// Methode, die zur Klasse eine bestimmte Anzahl von Tagen addiert:
// Zur Vereinfachung 1 Jahr = 360 Tage mit 30 Tagen im Monat
Date Date::operator+(int days) {
    // Datum als einzelne Zahl ausdrücken
    int total_days = _year * 360 + (_month - 1) * 30 + (_day - 1);
    total_days += days; // Anzahl der Tage addieren

    // Umrechnungen in Jahren, Monaten und Tagen
    int year = total_days / 360;
    total_days %= 360;

    int month = total_days / 30 + 1;
    int day = total_days % 30 + 1;

    return Date(day, month, year);
}



// Jetzt: Datum formattieren
ostream& operator<<(ostream &os, const Date &date) {
        os << date._day << "." << date._month << "." << date._year;

        return os;
}


int main(int argc, char *argv[])
{
    Date begin_task = Date(26,10,2023);
    cout << "Die Aufgabe beginnt am " << begin_task << endl;
    Date end_task = begin_task + 6;
    cout << "Die Aufgabe endet am " << end_task << endl;
    Date one_year_and_one_month_later = begin_task + 390;
    cout << "Ein Jahr und ein Monat nach Aufgabenbeginn ist der " << one_year_and_one_month_later << endl;
    Date three_years_and_eleven_months_later = begin_task + 1410;
    cout << "Drei Jahre und 11 Monate nach Aufgabenbeginn ist der " << three_years_and_eleven_months_later << endl;
}

