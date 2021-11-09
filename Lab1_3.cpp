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

    Stock(){
        cout << "Конструктор без параметров создан \n" << endl;
        company_name = "First company";
        stock_num = 1;
        all_stock_cost = 10;
    }

    Stock(string s, int i){
        cout << "Конструктор с параметрами создан" << endl;
        company_name = s;
        stock_num = i;
        cout << "Введите стоимость каждой акции:" << endl;
        for (int i = 0; i < stock_num; i++) {
            int s_cost;
            cout << "Акция номер " << i+1 << " : ";
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
                ndx++;
                for (int i = ndx; i < stock_num - 1; i++){
                    stock_cost_array[i] = stock_cost_array[i + 1];
                }
                stock_cost_array.pop_back();
                stock_num--;
            }
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



void stock_test() {
    vector<Stock> stocks_array;
    Stock a("a", 2), b("b", 2), c("c", 2), d("d", 2), e("e", 2);
    stocks_array.push_back(a);
    stocks_array.push_back(b);
    stocks_array.push_back(c);
    stocks_array.push_back(d);
    stocks_array.push_back(e);
    a.Buy(2);
    for (int i = 0; i < stocks_array.size(); i++){
        cout << endl;
        stocks_array[i].Show();
    }
}

int main(){
    setlocale(LC_ALL,"Russian");
    stock_test();

    return 0;
}
