#включить <iostream>
#включить <iomanip>

использование пространства имен std;

 автомобиль класса {
 карнаме из струн;
	символ* Класс автомобиля = новый символ[16];
	int мощность;
	плавучий берег;

общественный:
	void SetCarSpec() {
 cout << "Čě˙ ŕâňîěîáčë˙: ";
 cin >>> карНаме;
 cout << "Ěîüüâî:::::: ";
 cin >>> Класс автомобилей;
 cout << "Ěîůíîńňü ŕâňîěîáčë˙: ";
 cin >>> мощность;
 cout << "Öíâîěîáčë:";
 cin >>> побережье;
	}
	аннулировать GetCarSpec() {
 cout << endl << setw(42) << карНейм <;
 cout << setw(32) < < "Класс автомобилей": "< < setw(10) << Класс автомобилей <;
 cout << setw(32) <<": < < setw(10) << мощность <;
 cout << setw(32) < < "Öĺí äííîăîâñîěîáčë:" << setw(10) << побережье <;
	}
};

int main() {
	setlocale(LC_ALL, "Русский");
 Автомобильная первая машина, вторая машина;
 firstCar.SetCarSpec();
 secondCar.SetCarSpec();
 firstCar.GetCarSpec();
 secondCar.GetCarSpec();
	возврат 0;
}