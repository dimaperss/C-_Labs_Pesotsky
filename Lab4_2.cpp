#include <iostream>;
#include <clocale>
using namespace std;

class Date {
protected:
	int day, month, year;
	int days[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
public:
	Date() {
		day = 0;
		month = 0;
		year = 0;
	}
	Date(int _day, int _month, int _year) {
		day = _day;
		month = _month;
		year = _year;
	}

	~Date() {};


	friend ostream& operator<<(ostream& out,Date& ob);
	Date operator+(Date& ob);
	Date operator-(Date& ob);
	Date operator++(int _day);
	Date operator--(int _day);
	Date operator+(int day);
	Date operator-(int day);

};

Date Date::operator--(int _day) {
	Date temp;
	temp.day = day-1;
	temp.month = month;
	temp.year = year;

    if (temp.day < 1) {
        temp.month--;
        temp.day = temp.days[temp.month];
    }
	while (temp.month < 1) {
		temp.year--;
		temp.month + 12;
	}
	return temp;
}

Date Date::operator++(int _day) {

	Date temp;
	temp.day = day+1;
	temp.month = month;
	temp.year = year;
	if (temp.day>temp.days[temp.month]){
        temp.day = 1;
        temp.month++;
	}
	while (temp.month > 12) {
		temp.month - 12;
		temp.year++;
	}
	return temp;
}

Date Date::operator+(int _day) {
	Date temp;
	temp.day = day + _day;
	temp.month = month;
	temp.year = year;

	if (temp.day>temp.days[temp.month]){
        temp.day -= temp.days[temp.month];
        temp.month++;
	}
	while (temp.month > 12) {
		temp.month -= 12;
		temp.year++;
	}
	return temp;
}

Date Date::operator-(int _day) {
	Date temp;
	temp.day = day - _day;
	temp.month = month;
	temp.year = year;
    if (temp.day < 1) {
                temp.month--;
                temp.day += temp.days[temp.month];
            }

	while (temp.month < 1) {
		temp.year--;
		temp.month += 12;
	}
	return temp;
}

Date Date::operator+(Date& ob) {
	Date temp;
	temp.month = month + ob.month;
	temp.day = day + ob.day;
    if (temp.day < 1) {
	if (temp.day>temp.days[temp.month]){

        temp.month++;
        temp.day += temp.days[temp.month];
	}
    }
	while (temp.month > 12) {
		temp.month -= 12;
		temp.year++;
	}
	temp.year += year + ob.year;
	return temp;
}

Date Date::operator-(Date& ob) {
	Date temp;
	temp.month = month - ob.month;
	temp.day = day - ob.day;
	while (temp.day > 31 or temp.day < 1) {
	    if (temp.day < 1) {
            temp.month--;
            temp.day += temp.days[temp.month];
	    }
    }
	while (temp.month < 1) {
		temp.year--;
		temp.month += 12;
	}
	temp.year = year - ob.year;
	return temp;
}

ostream& operator<<(ostream& out, Date& ob){

	return out << ob.day << "." << ob.month<<"."<< ob.year;
}

int main() {
	setlocale(LC_ALL, "Russian");
	Date	start(1, 2, 2010), constructing(29, 0, 0);
	Date enda = start + constructing;
    cout << "���� ������ �������������: " << start << endl;
	cout << "����� �������������: " << constructing << endl;
	cout << "����+����: " << enda << endl;
	enda = start - constructing;
	cout << "����-����: " << enda << endl;
    enda = start + 29;
    cout << "����+Int: " << enda << endl;
    enda = start++;
    cout << "����++: " << enda << endl;
    enda = start--;
    cout << "����--: " << enda << endl;
	return 0;
}
