#include <iostream>;
#include <string>;

using namespace std;

class DomesticAnimal {
protected:
	int price;
	int weight;
	string color;
public:
	DomesticAnimal() {
		price = 0;
		weight = 0;
		color = "brown";
	}

	DomesticAnimal(int _price, int _weight, string _color) {
		price = _price;
		weight = _weight;
		color = _color;
	}
	
	void Print(){
		cout << price+"  " << weight+"  " << color+"  ";
		cout << "Êëàññ domestic ";
	}

};

class Cow: public DomesticAnimal {
public:
	Cow(int _price, int _weight, string _color) : DomesticAnimal(_price, _weight, _color) {}
	void Print() {
		cout << price + "  " << weight + "  " << color + "  ";
		cout << "Êëàññ Cow ";
	}
};

class Buffalo : public DomesticAnimal {
public:
	Buffalo(int _price, int _weight, string _color) : DomesticAnimal(_price, _weight, _color) {}
	void Print() {
		cout << price + "  " << weight + "  " << color + "  ";
		cout << "Êëàññ Buffalo ";
	}
};

class Beefalo : public DomesticAnimal {
public:
	Beefalo(int _price, int _weight, string _color): DomesticAnimal(_price, _weight, _color) {}
	void Print() {
		cout << price + "  " << weight + "  " << color + "  ";
		cout << "Êëàññ Beefalo ";
	}
};

int main() {
	setlocale(LC_ALL, "Russian");
	Cow a(1, 1, "red");
	Beefalo b(2, 2, "blue");
	a.Print();
	b.Print();

	return 0;
}