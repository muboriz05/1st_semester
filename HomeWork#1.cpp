#include <iostream>

using namespace std;

void task1() {
    cout << "Мубориз"<<endl;
}

void task2() {
    float a, b;
    cin >> a >> b;
    cout << "Сумма: " << a + b << endl;
    cout << "Разность: " << a - b << endl;
    cout << "Произвездение: " << a * b << endl;
    if (b != 0)
        cout << "Частное: " << a / b << endl;
    else
        cout << "Делить на ноль нельзя!";

}

void task3() {
    float b, c;
    cin >> b >> c;
    cout << "Результат: " << -c / b<<endl;
}

void task4() {
    float a, b, c, d;
    cin >> a >> b >> c;
    d = b * b - 4 * a * c;
    if (d < 0)
        cout << "Корней этого уравнения нет!";
    else if (d == 0)
        cout << "x = " << (-b + sqrt(d)) / (2 * a);
    else {
        cout << "x1 = " << (-b + sqrt(d)) / (2 * a) << endl;
        cout << "x2 = " << (-b - sqrt(d)) / (2 * a) << endl;
    }

}

void task5() {
    bool day, curtains, lamp;
    cin >> day >> curtains >> lamp;
    if ((day && curtains) || lamp)
        cout << "В комнате светло!";
    else
        cout << "В комнате темно!";

}

int main()
{
    setlocale(LC_ALL, "RU");
    
    task5();
    
}

