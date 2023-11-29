#include <iostream>
#include <cmath>
#include <fstream>
#include <algorithm>
#include <string>

using namespace std;

void task1() {
    float s, n, p,  r;
    cin >> s >> n >> p;
    r = p / 100;
    cout << "m = " << (s * r * (pow(1 + r, n))) / (12 * (pow(1 + r, n) - 1))<<endl;
}

void task2() {
    float s, m, n, p = 100, r, mTest;
    cin >> s >> n >> mTest;
    r = p / 100;
    m = (s * r * (pow(1 + r, n))) / (12 * (pow(1 + r, n) - 1));
    while (m - mTest > 0.0001) {
        p--;
        r = p / 100;
        m = (s * r * (pow(1 + r, n))) / (12 * (pow(1 + r, n) - 1));
        
    }
    cout << p << "%" << endl;
}

void task3() {
    ofstream file("Task3.txt", ios_base::out);
    file << "Hello World!";
    file.close();

    char text[100];
    ifstream files("Task3.txt");
    files.getline(text, 100);
    cout << text;
    files.close();

}

void task4() {
    ofstream in("Task4.txt", ios_base::out);
    in << "Muboriz05C++JavaPH1P";
    in.close();

    char numbers;
    ifstream ins("Task4.txt");
    while (ins >> numbers) {
        if (isdigit(numbers))
            cout << numbers;
    }
    ins.close();
}

void task5() {
    string word;
    cin >> word;
    sort(word.begin(), word.end());
    cout << word;

}

int main()
{
    task5();
}
