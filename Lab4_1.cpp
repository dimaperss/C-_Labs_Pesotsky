#include <iostream>;
#include <math.h>;
#include <clocale>
using namespace std;

double pointDiff(double x1, double y1, double x2, double y2);
double pointDiff(double x1, double y1, double z1, double x2, double y2, double z2);

int main() {
	setlocale(LC_ALL, "Russian");
	cout << "1)Двумерное пространство: " << endl;
	double a = pointDiff(-1.0,4.0,-1.0, 2.0);
	double b = pointDiff(-7.0,3.0,-1.0, 2.0);
	double c = pointDiff(-1.0,4.0,-7.0, 3.0);
	double P = a + b + c;
	cout << "Периметр треугольника равен: " << P << endl << "2)Трёхмерное пространство: " << endl;
	a = pointDiff(2.0, 1.0, 3.0, 2.0, 0.0,5.0);
	b = pointDiff(2.0, 1.0, 3.0, 5.0, -1.0, 10.0);
	c = pointDiff(5.0, -1.0, 10.0, 2.0, 0.0, 5.0);
	P = a + b + c;
	cout << "Периметр треугольника равен: " << P << endl;
	return 0;
}
double pointDiff(double x1, double y1, double x2, double y2) {
	return sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
}

double pointDiff(double x1, double y1, double z1, double x2, double y2, double z2) {
	return sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2) + pow((z2 - z1), 2));
}
