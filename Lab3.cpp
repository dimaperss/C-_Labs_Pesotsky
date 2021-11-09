 #include <iostream>;
using namespace std;

class Goods {
	string name;
	string date;
	int cost;
	int num;
	int id;
public:
	Goods(string _name, string _date, int _cost, int _num, int _id) {
		name = _name;
		date = _date;
		cost = _cost;
		num = _num;
		id = _id;
		cout << "Counstructor" << endl;
	}
	Goods() {
		name = "Unkown";
		date = "0000-00-00";
		cost = 0;
		num = 0;
		id = 0;
		cout << "Default constructor" << endl;
	}
	Goods(Goods& _ob) {
		name = _ob.name;
		date = _ob.date;
		cost = _ob.cost;
		num = _ob.num;
		id = _ob.id;
		cout << "CopyCounstructor" << endl;
	}
	~Goods() {
		cout << "Destructor"<< endl;
	};

public:
	void Show() {
		cout<< endl << "Наименование: " << name << endl;
		cout << "Дата поступления: " << date << endl;
		cout << "Стоимость: " << cost << endl;
		cout << "Количество: " << num << endl;
		cout << "Идентификатор: " << id << endl<<endl;
	}

	Goods operator=(Goods& _ob);

};

Goods tovar(Goods& _s) {
    cout<<"_s"<<endl;
	return _s;
}



Goods Goods::operator=(Goods& _ob) {
	name = _ob.name;
	date = _ob.date;
	cost = _ob.cost;
	num = _ob.num;
	id = _ob.id;
	cout << "Operator" << endl;
	return *this;
}


int main() {
	setlocale(LC_ALL, "Russian");
	cout<<"Вход в функцию main()"<<endl;
	cout<<"a"<<endl;
	Goods a("Knight", "03.03.2002", 1000, 15, 626);
	cout<<"b"<<endl;
	Goods b(a);
	cout<<"c"<<endl;
	Goods c;
	cout<<"tovar"<<endl;
	tovar(b);
	cout<<"a"<<endl;
	a = c;
	cout<<"a"<<endl;
	a.Show();
	cout<<"b"<<endl;
	b.Show();
	cout<<"c"<<endl;
	c.Show();
	cout<<"Выход из функции main()"<<endl;
	return 0;
}

