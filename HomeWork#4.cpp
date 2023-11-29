#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

void task1();
void task2();
void task3();
void task4();
void task5();
void task6();
void task7();
void task8();
void task9();

int main()
{
    setlocale(LC_ALL, "RU");
    task9();

}

//Task1
void task1() 
{
    ofstream file("Task1.txt", ios_base::out);
    for (int i = 0; i < 10; i++) 
    {
        int x;
        cin >> x;
        file << x << " ";
    }
    file.close();

    ifstream files("Task1.txt");
    int s = 0;
    for (int i = 0; i < 10; i++) 
    {
        int x;
        files >> x;
        s += x;

    }

    cout << s;
    files.close();
}

//Task2
int sign(float x) 
{
    if (x > 0) 
    {
        return 1;
    }
    else if (x == 0) 
    {
        return 0;
    }
    return -1;
}

void task2() 
{
    double x = 0;
    cin >> x;
    cout << sign(x) << endl;
}

//Task3

float a, b, h, r;
const float PI = 3.14;

float rectangle(float a, float b) 
{
    return a * b;
}

float triangle(float a, float h) 
{
    return a * h / 2;
}

float circle(float r) 
{
    return PI * r * r;
}

void task3()
{
    cout << "Выберите фигуру: Прямоугольник(1), Треугольник(2), Круг(3) \n";
    int choice;
    cin >> choice;
    switch (choice) {
    case 1:
        cout << "Вы выбрали прямоугольник. Задайте стороны! \n";
        cin >> a >> b;
        cout<<rectangle(a, b);
        break;
    case 2:
        cout << "Вы выбрали треугольник. Задайте сторону и высоту! \n";
        cin >> a >> h;
        cout<<triangle(a, h);
        break;
    case 3:
        cout << "Вы выбрали круг. Задайте радиус! \n";
        cin >> r;
        cout<<circle(r);
        break;
    default:
        cout << "Неправильно ввели номер! Попробуйте ещё раз! \n";
        main();


    }
}

//Task4

void task4() 
{
    for (int i = 0; i < 8; i++) 
    { 
        cout << " *  *  *  *  *  * ";
        cout << "----------------------------" << endl;
    }
    for (int i = 0; i < 5; i++) 
    { 
        cout << "----------------------------------------------" << endl;
    }
}

void task5()                    
{

        int size = 80, height = 21;

        vector<string> chart(height, string(size, ' '));
        chart[height / 2] = string(size, '-');

        for (int i = 0; i < size; i++) 
        {
            chart[static_cast<int>(round(10 * sin(i / 4.5) + 10))][i] = '*';
        }

        for (auto&& s : chart) 
        {
            cout << s << '\n';
        }
    
}

//Task 6
int romanToInt(string s) {
    int result = 0;
    int prevValue = 0;
    int count = 0;

    for (int i = s.length() - 1; i >= 0; i--) {
        int value = 0;
        switch (s[i]) {
        case 'I':
            value = 1;
            break;
        case 'V':
            value = 5;
            break;
        case 'X':
            value = 10;
            break;
        case 'L':
            value = 50;
            break;
        case 'C':
            value = 100;
            break;
        case 'D':
            value = 500;
            break;
        case 'M':
            value = 1000;
            break;
        default:
            cout << "Ошибка: Недопустимый символ - " << s[i] << endl;
            return -1;
        }

        if (value < prevValue) {
            result -= value;
            count = 0;
        }
        else {
            result += value;
            if (value == prevValue) {
                count++;
                if (count > 3) {
                    cout << "Ошибка: Слишком много повторяющихся символов - " << s[i] << endl;
                    return -1;
                }
            }
            else {
                count = 1;
            }
        }

        prevValue = value;
    }

    return result;
}

void task6() {
    string romanNumber;
    cout << "Введите римское число: ";
    cin >> romanNumber;

    int decimalNumber = romanToInt(romanNumber);

    if (decimalNumber == -1) {
        cout << "Ошибка в римской записи." << endl;
    }
    else {
        cout << "Десятичное число: " << decimalNumber << endl;
    }
}

//Task 7

class RandomNumberGenerator {
private:
    int m, i, c;
    int current;

public:
    RandomNumberGenerator(int m, int i, int c, int seed) : m(m), i(i), c(c), current(seed) {}

    int getNextRandom() {
        current = (m * current + i) % c;
        return current;
    }
};

void task7() {
    int m1 = 37;
    int i1 = 3;
    int c1 = 64;
    int seed1 = 0;

    RandomNumberGenerator rng1(m1, i1, c1, seed1);

    cout << "Вариант I:" << std::endl;
    for (int j = 0; j < 10; j++) {
        int randomNum = rng1.getNextRandom();
        cout << randomNum << std::endl;
    }

    int m2 = 25173;
    int i2 = 13849;
    int c2 = 65537;
    int seed2 = 0;

    RandomNumberGenerator rng2(m2, i2, c2, seed2);

    cout << "Вариант II:" << std::endl;
    for (int j = 0; j < 10; j++) {
        int randomNum = rng2.getNextRandom();
        cout << randomNum << std::endl;
    }

    
}

//Task 9

void task9() {
    string inputNumber;
    int oldBase, newBase;

    cout << "Введите число: ";
    cin >> inputNumber;

    cout << "Введите старое основание: ";
    cin >> oldBase;

    cout << "Введите новое основание: ";
    cin >> newBase;

    int decimalNumber = 0;
    int power = 0;
    for (int i = inputNumber.length() - 1; i >= 0; i--) {
        char digit = inputNumber[i];
        int value;
        if (isdigit(digit)) {
            value = digit - '0';
        }
        else {
            value = toupper(digit) - 'A' + 10;
        }
        decimalNumber += value * pow(oldBase, power);
        power++;
    }

    string result = "";
    while (decimalNumber > 0) {
        int remainder = decimalNumber % newBase;
        char digit;
        if (remainder < 10) {
            digit = remainder + '0';
        }
        else {
            digit = 'A' + (remainder - 10);
        }
        result = digit + result;
        decimalNumber /= newBase;
    }

    cout << "Результат: " << result << endl;

    
}

//Task 8

void task8() {
        float A[3][4]{ {5,  2, 0, 10},
                      {3,  5, 2, 5},
                      {20, 0, 0, 0} };

        float B[4][2]{ {1.2, 0.5},
                      {2.8, 0.4},
                      {5,   1},
                      {2,   1.5} };

        float C[3][2]{ {0, 0},
                      {0, 0},
                      {0, 0} };
        
        for (int row = 0; row < 3; row++) {
            for (int col = 0; col < 2; col++) {
                for (int res = 0; res < 4; res++) {
                    C[row][col] += A[row][res] * B[res][col];
                }
            }
        }

        float sumMax = 0, sumMin = 38;
        float comMax = 0, comMin = 19;
        float sumMoney = 0, sumCom = 0;
        float sum = 0;
        for (int i = 0; i < 3; i++) {
            sumMoney += C[i][0];
            sumCom += C[i][1];
            sumMax = max(sumMax, C[i][0]);
            sumMin = min(sumMin, C[i][0]);
            comMax = max(comMax, C[i][1]);
            comMin = min(comMin, C[i][1]);
        }

        // Затем выведите матрицу C
        for (int row = 0; row < 3; row++) {
            for (int col = 0; col < 2; col++) {
                cout << C[row][col] << " ";
            }
            cout << "\n";
        }
        cout << "sumMax: " << sumMax << endl;
        cout << "sumMin: " << sumMin << endl;
        cout << "comMax: " << comMax << endl;
        cout << "comMin: " << comMin << endl;
        cout << "sumMoney: " << sumMoney << endl;
        cout << "sumCom: " << sumCom << endl;
        cout << "sum: " << sumMoney + sumCom << endl;
    
}
