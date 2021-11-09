#include <iostream>
#include <clocale>
using namespace std;

class Test {
protected:
	int W;
	void Z(){
		cout << "Это закрытая функция Test" << endl;
	}
public:
	Test() {
		W = 1;
	}
	~Test() {};

	friend void Fun(Test ob);
};

void Fun(Test ob) {
	cout << ob.W << endl;
	ob.Z();
}

int main() {
    setlocale(LC_ALL,"Russian");
	Test ob;
	Fun(ob);

    return 0;
}
