#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

void task1();
void task2();
void task3();
void task4();
void task5();
void task6();

int main() {
	setlocale(LC_ALL, "RU");
	task6();
}

//TASK1

int gcdByDivision(int a, int b) {
    if (b == 0) {
        return a;
    }
    else {
        return gcdByDivision(b, a % b);
    }
}

int gcdBySubtraction(int a, int b) {
    while (a != b) {
        if (a > b) {
            a -= b;
        }
        else {
            b -= a;
        }
    }
    return a;
}

void task1(){
    int num1, num2;
    cout << "Введите два числа: ";
    cin >> num1 >> num2;

    
    int resultByDivision = gcdByDivision(num1, num2);
    cout << "НОД методом деления: " << resultByDivision << endl;

    int resultBySubtraction = gcdBySubtraction(num1, num2);
    cout << "НОД методом вычитания: " << resultBySubtraction << endl;

}

//TASK 2
void task2() {
    cout<<("Введите натуральное число: ");
    int n;
    cin>>n;

    cout<<"Простые числа от 2 до "<< n<<": ";

    for (int i = 2; i <= n; ++i) {
        bool is_prime = true;

        for (int j = 2; j * j <= i; ++j) {
            if (i % j == 0) {
                is_prime = false;
                break;
            }
        }

        if (is_prime) {
            cout<<i<< " ";
        }
    }

 
}

void task3() {
    int t;
    cout << "Введите натуральное число t < 27: ";
    cin >> t;

    if (t >= 27) {
        cerr << "Ошибка: введенное число больше или равно 27." << endl;
    }
    else {
        cout << "Трехзначные числа, сумма цифр которых равна " << t << ": ";

        for (int i = 100; i <= 999; ++i) {
            int digit_sum = 0;
            int num = i;

            while (num > 0) {
                digit_sum += num % 10;
                num /= 10;
            }

            if (digit_sum == t) {
                cout << i << " ";
            }
        }
    }
}

void task4() {
    for (int i = 1000; i <= 9999; ++i) {
        int num = i;
        bool has_duplicate = false;

        int digits[10] = { 0 };

        while (num > 0) {
            int digit = num % 10;

            if (digits[digit] > 0) {
                has_duplicate = true;
                break;
            }

            digits[digit]++;
            num /= 10;
        }

        if (!has_duplicate) {
            cout << i << " ";
        }
    }
}

void task5() {
        ifstream ifile("53.txt");
        string str, w, strLen, d = " ";
        string letter = "";
        while (ifile.peek() >= 0) { 
            ifile >> letter;
            str = str + letter + " ";
        }
        ifile.close();

        int b, e = 0;
        while ((b = str.find_first_not_of(d, e)) != str.npos) {
            e = str.find_first_of(d, b);
            w = str.substr(b, e - b);
            if (w.size() > strLen.size())
                strLen = w;
        }
        cout << strLen << endl;

    }
    

void task6() {
    ifstream ifile("53.txt");
    string word = "";
    string result = "";
    char letter = ' ';

    cout << "Enter a word: ";
    cin >> word;

    while (ifile.peek() >= 0) { 
        ifile >> letter;
        result += letter;
    }
    ifile.close();

    int pos = result.find(word, 0);

    if (pos != -1) {
        cout << "Position word: " << pos << endl;
    }
    else {
        cout << "word not found...\n";
    }
}