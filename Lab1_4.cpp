#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <clocale>
using namespace std;

class Train {
	string PN;
	int TrainNumber;
	int StartNumber;
	int	CountOM;
	int	Kupe;
	int Platskart;

    public:
        Train() {
            PN = "Unkown";
            TrainNumber = 0;
            StartNumber = 0;
            CountOM = 0;
            Kupe = 0;
            Platskart = 0;
        }
        Train( string	a, int c, int d, int e, int f, int g) {
            PN = a;
            TrainNumber = c;
            StartNumber = d;
            CountOM = e;
            Kupe = f;
            Platskart = g;
        }
        ~Train() {}

        void SetDriverName(string s) {
            PN = s;
        }
        void SetPlatskart(int a) {
            Platskart = a;
        }
        void SetTrainNumber(int a) {
            TrainNumber = a;
        }
        void SetStartNumber(int a) {
            StartNumber = a;
        }
        void SetCountOM(int a) {
            CountOM = a;

        }
        void SetKupe(int a) {
            Kupe = a;
        }

        string GetPN(){
            return PN;
        }
        int GetPlatskart() {
            return Platskart;
        }
        int GetTrainNumber() {
            return TrainNumber;
        }
        int GetStartNumber() {
            return StartNumber;
        }
        int GetCountOM() {
            return CountOM;
        }
        int GetKupe() {
            return Kupe;
        }

        void Show(){
            cout << "Пункт назначения: " << setw(1) << PN << endl;
            cout << "Номер поезда: " << setw(1) << TrainNumber << endl;
            cout << "Время отправления: " << setw(1) << StartNumber << endl;
            cout << "Число общих мест: " << setw(1) << CountOM << endl;
            cout << "Купейных: " << setw(1) << Kupe << endl;
            cout << "Плацкартных: " << setw(1) << Platskart << endl;
        }
};

int main() {
    setlocale(LC_ALL,"Russian");
	vector<Train> TrainArr;

	Train a("Москва", 585, 10*60+10, 20, 585, 15);
	Train	b("Питер", 228, 13*60+5, 22, 228, 122);
	Train	c("Ростов", 982, 8*60+0, 0, 982, 18);
	Train	d("Ростов-на-Дону", 100, 1*60+55, 1, 100, 0);

	TrainArr.push_back(a);
	TrainArr.push_back(b);
	TrainArr.push_back(c);
	TrainArr.push_back(d);
	for (int i = 0; i < TrainArr.size(); i++){
        if (TrainArr[i].GetPN() == "Ростов-на-Дону") {
			TrainArr[i].Show();
			cout << endl;
		}
		if ((TrainArr[i].GetPN() == "Питер")&&(TrainArr[i].GetStartNumber()>7*60)) {
			TrainArr[i].Show();
			cout << endl;
		}
		if ((TrainArr[i].GetPN() == "Москва")&&(TrainArr[i].GetCountOM()>0)) {
			TrainArr[i].Show();
			cout << endl;
		}
	}

	return 0;
}
