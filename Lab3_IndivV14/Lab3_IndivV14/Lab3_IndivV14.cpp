// Lab3_IndivV14.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream> 
#include <iomanip> 
#include <windows.h>  
#include <conio.h> 

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
        cout << "Введіть бренд\n(0 - Нива, 1- Ауді, 2 - БМВ, 3 - Опель, 4 - інше) " << endl;
        cin >> brand;
        cout << "Введіть рік: " << endl;
        cin >> year;
        cout << "Введіть тип (0 - Дизельний, 1 - Карбюрований): " << endl;
        cin >> type;
        cout << "Введіть пробіг (в тис. км.): " << endl;
        cin >> mileage;
        cout << "Введіть прізвище власника: " << endl;
        cin >> owner;
    }

    void Input(int b, int y, int t, int m, string o) {
        brand = b;
        year = y;
        type = t;
        mileage = m;
        owner = o;
    }

    void Print() {
        double m = (double)mileage;

        switch (brand) {
        case 0: cout << "Бренд: Нива" << endl; break;
        case 1: cout << "Бренд: Ауді" << endl; break;
        case 2: cout << "Бренд: BMW" << endl; break;
        case 3: cout << "Бренд: Опель" << endl; break;
        case 4: cout << "Бренд: Інша" << endl; break;
        }
        cout << "Рік випуску: " << year << endl;
        cout << "Тип: " << (type == 0 ? "Дизельний" : "Карбюрований") << endl;
        cout << "Пробіг: " << m << "км " << endl;
        cout << "Власник: " << owner << endl;
    }
};

void SortByYear(Car cars[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (cars[i].year > cars[j].year) {
                Car temp = cars[i];
                cars[i] = cars[j];
                cars[j] = temp;
            }
        }
    }
}


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    const int N = 3;
    Car cars[N];
    // Введення даних
    //for (int i = 0; i < N; i++) {
        //cout << "\nМашина #" << i + 1 << endl;
        //cars[i].Input();
    //}
    cars[0].Input();

    cars[1].Input(1,2000,1,12,"Хтось");

    cout << "\n--- Конструктор без параметрів ---\n";
    Car car2;
    car2.Print();
    cars[2] = car2;

    cout << "\n---Не відсортовано за роком випуску ---\n";
    for (int i = 0; i < N; i++) {
        cout << "\nМашина #" << i + 1 << endl;
        cars[i].Print();
    }
    // Сортування
    SortByYear(cars, N);

    // Вивід результату
    cout << "\n--- Відсортовано за роком випуску ---\n";
    for (int i = 0; i < N; i++) {
        cout << "\nМашина #" << i + 1 << endl;
        cars[i].Print();
    }

    cout << "\n--- Конструктор копіювання ---\n";
    Car car(cars[0]);
    car.Print();

    return 0;
}
