// Lab2_indiv_V14.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <windows.h> 
#include <conio.h>

using namespace std;

class Person {

public:
    string name;
    int age;
    bool gender;

    Person() {
        name = "Невідомий";
        age = 0;
        gender = 0;
    }

    Person(string n, int a, bool g) {
        name = n;
        age = a;
        gender = g;
    }

    Person(const Person& person2) {
        name = person2.name;
        age = person2.age;
        gender = person2.gender;
    }

    void Input() {
        cout << "Введіть ім'я: " << endl;
        cin >> name;
        cout << "Введіть вік: " << endl;
        cin >> age;
        cout << "Введіть стать (0 - ж, 1 - ч): " << endl;
        cin >> gender;
    }

    void Print() {
        cout << "Ім'я: " << name << endl;
        cout << "Вік: " << age << endl;
        if (gender == 0) {
            cout << "Стать: Жінка\n" << endl;
        }
        else {
            cout << "Стать: Чоловік\n" << endl;
        }
    }
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    // За замовчуванням
    Person p1;
    p1.Print();

    // З параметрами
    Person p2;
    p2.Input();
    p2.Print();

    // Конструтор копіювання
    Person p3(p2);
    p3.Print();

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
