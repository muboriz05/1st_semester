#include <iostream>
#include <cmath>

using namespace std;

void task1() {
    float r1, r2, h, l;
    const float PI = 3.14;
    cin >> r1 >> r2 >> h >> l;

    if (r1 == r2 == h) {
        cout << "Это не конус!";
    }
    else {
        cout << "V: " << PI / 3 * h * (pow(r1, 2) + r1 * r2 + pow(r2, 2)) << endl;
        cout << "S: " << PI * (pow(r1, 2) + r1 * r2 + pow(r2, 2)) << endl;
    }
}

void task2() {
    float x, a;
    cin >> x >> a;
    if (abs(x) < 1) {
        cout << "w = " << a * log(abs(x));
    }
    else if (x = 0)
        cout << "х не может быть равен 0";
    else if (a - pow(x, 2) < 0)
        cout << "Корень не должен быть отрицательным";
    else
        cout << "w = " << sqrt(a - pow(x, 2));
}

void task3() {
    float x, y, b;
    cin >> x >> y >> b;
    if ((b - y < 1) || (b - x < 0))
        cout << "Решения нет!";
    else
        cout << "z = " << log(b - y) * sqrt(b - x);
}

void task4() {
    int n;
    cin >> n;
    for (int i = 0; i <= 10; i++) {
        cout << n + i << ", ";
    }
    
}

void task5() {
    /*
    int k = 1;
    for (float i = -4; i <= 4; i += 0.5) {
        if (i == 1)
            continue;
        cout << "y" << k++ <<"= " << (pow(i, 2) - 2 * i + 2) / (i - 1) << endl;
    }*/
    int k = 1;
    float x = -4;
    while (x <= 4) {
        if (x == 1)
            continue;
        cout << "y" << k++ << "= " << (pow(x, 2) - 2 * x + 2) / (x - 1) << endl;
        x += 0.5;
    }
}

int main()
{
    setlocale(LC_ALL, "RU");
    task5();
}

