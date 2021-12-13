#include <iostream>;
#include <string>;

using namespace std;

class Base1 {

private:
	int i;

public:
	Base1() {
		i = 0;
		cout << "Конструктор Base1 без параметров \n";
	}
	Base1(int _i) {
		i = _i;
		cout << "Конструктор Base1 c параметром \n";
	}

	void PutInt(int value) {
		i = value;
	}

	int GetInt() {
		return i;
	}

};

class Base2 {
private:
	string name;

public:
	Base2() {
		name = "void";
		cout << "Конструктор Base2 без параметров \n";
	}

	Base2(string _name) {
		name = _name;
		cout << "Конструктор Base2 с параметром \n";
	}

	void PutString(string value) {
		name = value;
	}

	string GetString() {
		return name;
	}


};

class Derived :  public Base2, public Base1 {
private:
	char ch;
public:
	Derived() {
		ch = 'V';
		cout << "Конструктор Derived без параметров \n";
	}
	Derived(char _ch, string _name, int _i): Base2(_name), Base1(_i){
		ch = _ch;
		cout << "Конструктор Derived с параметрами \n";
	}
	void PutChar(char value) {
		ch = value;
	}
	char GetChar() {
		return ch;
	}

	friend ostream& operator<<(ostream& out, Derived& ob);
};

ostream& operator<<(ostream& out, Derived& ob) {
	return out << ob.GetInt() << "\n" << ob.GetString() << "\n" << ob.GetChar() << "\n";
}

int main() {
	setlocale(LC_ALL, "Russian");
	Derived ob, ob2('A',"bubble",3);
	cout << ob << ob2;

	return 0;
}