// Lab4_IndivV14.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <windows.h>
using namespace std;

class Car {
public:
    int brand = 4;
    string owner = "Unknown";
    int type = 0;
    int year = 0;
    int mileage = 0;

    Car() {}

    Car(const Car& other) {
        brand = other.brand;
        owner = other.owner;
        type = other.type;
        year = other.year;
        mileage = other.mileage;
    }

    void Input() {
        cout << "Введіть бренд\n(0 - Нива, 1 - Ауді, 2 - БМВ, 3 - Опель, 4 - інше): ";
        cin >> brand;
        cout << "Введіть рік: ";
        cin >> year;
        cout << "Введіть тип (0 - Дизельний, 1 - Карбюрований): ";
        cin >> type;
        cout << "Введіть пробіг (в тис. км): ";
        cin >> mileage;
        cout << "Введіть прізвище власника: ";
        cin >> owner;
    }

    void Print() const {
        cout << "Бренд: ";
        switch (brand) {
        case 0: cout << "Нива"; break;
        case 1: cout << "Ауді"; break;
        case 2: cout << "BMW"; break;
        case 3: cout << "Опель"; break;
        case 4: cout << "Інше"; break;
        default: cout << "Невідомо"; break;
        }
        cout << "\nРік випуску: " << year;
        cout << "\nТип: " << (type == 0 ? "Дизельний" : "Карбюрований");
        cout << "\nПробіг: " << mileage << " тис. км";
        cout << "\nВласник: " << owner << "\n";
    }

    // Метод введення масиву 
    void InputArray(Car* arr, int size) {
        for (int i = 0; i < size; ++i) {
            cout << "\nВведення машини #" << i + 1 << endl;
            arr[i].Input();
        }
    }
};

class Derived : public Car {
public:
    // Метод сортування масиву
    void SortByYear(Car* arr, int size) {
        for (int i = 0; i < size - 1; ++i) {
            for (int j = i + 1; j < size; ++j) {
                if (arr[i].year > arr[j].year) {
                    Car temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        }
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    const int N = 3;
    Car cars[N];
    Derived d;

    // Введення масиву через базовий клас
    d.InputArray(cars, 1);

    // Додаємо об'єкти через конструктор копіювання та без параметрів
    Car carDefault;       // Машина з конструктором без параметрів
    cars[1] = carDefault; // Додаємо її до масиву

    Car carCopy(cars[0]); // Копія першої машини
    cars[2] = carCopy;    // Додаємо її до масиву

    cout << "\n--- Не відсортовано за роком випуску ---\n";
    for (int i = 0; i < N; ++i) {
        cout << "\nМашина #" << i + 1 << endl;
        cars[i].Print();
    }

    // Сортування через похідний клас
    d.SortByYear(cars, N);

    cout << "\n--- Відсортовано за роком випуску ---\n";
    for (int i = 0; i < N; ++i) {
        cout << "\nМашина #" << i + 1 << endl;
        cars[i].Print();
    }

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
