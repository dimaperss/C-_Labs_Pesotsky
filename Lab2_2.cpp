#include <iostream>
#include <time.h>
#include <vector>
#include <iomanip>
#include <string>
#include <clocale>
using namespace std;


class Abonent{
public:
	int id;
protected:
	string sName;
	string phoneNumber;
public:
	Abonent(int _id, string _sName, string _phoneNumber) {
		id = _id;
		sName = _sName;
		phoneNumber = _phoneNumber;
	}
	~Abonent() {};


	friend class Notebook;
};

class Notebook {

public:

	void change(Abonent& ob, string _newPhoneNumber) {
		ob.phoneNumber = _newPhoneNumber;
	}
	void show(Abonent& ob) {
		cout << ob.id <<' '<< ob.sName << ' '<< ob.phoneNumber << endl;
	}
};

int main() {
    setlocale(LC_ALL,"Russian");
	vector <Abonent> abonentArr;
	Notebook notebook;
	abonentArr.push_back(Abonent(1, "Ильин", "89184005916"));
	abonentArr.push_back(Abonent(2, "Иванов", "89184567181"));
	abonentArr.push_back(Abonent(3, "Каныгин", "89184514920"));
	abonentArr.push_back(Abonent(4, "Игрев", "89184514979"));
	abonentArr.push_back(Abonent(5, "Данилов", "89184515687"));
	for (int i = 0; i < abonentArr.size(); i++) {
		notebook.show(abonentArr[i]);
	}
	cout << "------------------------------------" << endl;
    //notebook.change(abonentArr[2],"89990548400");
	for (int i = 0; i < abonentArr.size(); i++) {
		if (abonentArr[i].id == 3) {
			notebook.change(abonentArr[i], "89990548400");
		}
		notebook.show(abonentArr[i]);
	}
	return 0;
}
