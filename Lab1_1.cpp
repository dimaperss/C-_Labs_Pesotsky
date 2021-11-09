#include <iostream>
#include <iomanip>
#include <list>
#include <vector>
#include <string>
#include <clocale>
using namespace std;

class Stock{
    string company_name;
    int stock_num;
    vector<float> stock_cost_array;
    float stock_cost;
    double all_stock_cost;

    void SetTotal(){
    all_stock_cost = 0;
    for (int i = 0; i < stock_num; i++){
        all_stock_cost += stock_cost_array[i];
        }
    }

    public:

    void Acquire(){
        cout << "Введите название компании: " << endl;
        cin >> company_name;

        cout << "Количество акций в пакете первоначального вклада: " << endl;
        cin >> stock_num;

        cout << "Введите стоимость каждой акции: " << endl;
        for (int i = 0; i < stock_num; i++){
            int s_cost;
            cout << "Акция номер " << i + 1 << ": ";
            cin >> s_cost;
            stock_cost_array.push_back(s_cost);
        }

        SetTotal();
    }

    int Buy(int s_num){
        if (s_num > 0){
            float s_cost;
            for (int i = 0; i < s_num; i++){
                cout << "Цена приобретённой акции №" << i + 1 << ": ";
                cin >> s_cost;
                stock_cost_array.push_back(s_cost);
                stock_num++;
            }
            SetTotal();
        } else{
            return 1;
        }
        return 0;
    }

    int Sell(int s_num){
        if (s_num > 0){
            int ndx;
            for (int i = 0; i < s_num; i++){
                cout << "Номер проданной акции: ";
                cin >> ndx;
                for (int i = ndx; i < stock_num - 1; i++){
                    stock_cost_array[i] = stock_cost_array[i + 1];
                }
                stock_cost_array.pop_back();
                stock_num--;
            }
            SetTotal();
        } else {
            return 1;
        }
        return 0;
    }

    void Update(int ndx, float cost){
        stock_cost_array[ndx] = cost;
        SetTotal();
    }

    void Show(){
        cout << "Название компании: " << setw(1) << company_name << endl;
        cout << "Общее количество акций: " << setw(1) << stock_num << endl;
        cout << "Общая стоимость всех акций: " << setw(1) << all_stock_cost << endl;
    }
};


int main(){
    setlocale(LC_ALL,"Russian");
    Stock a;
    a.Acquire();
    a.Show();
    a.Buy(2);
    a.Sell(1);
    a.Show();
    a.Update(0, 500);
    a.Show();

    return 0;
}
