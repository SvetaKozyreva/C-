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
        cout << "������ �����\n(0 - ����, 1 - ���, 2 - ���, 3 - �����, 4 - ����): ";
        cin >> brand;
        cout << "������ ��: ";
        cin >> year;
        cout << "������ ��� (0 - ���������, 1 - ������������): ";
        cin >> type;
        cout << "������ ����� (� ���. ��): ";
        cin >> mileage;
        cout << "������ ������� ��������: ";
        cin >> owner;
    }

    void Print() const {
        cout << "�����: ";
        switch (brand) {
        case 0: cout << "����"; break;
        case 1: cout << "���"; break;
        case 2: cout << "BMW"; break;
        case 3: cout << "�����"; break;
        case 4: cout << "����"; break;
        default: cout << "�������"; break;
        }
        cout << "\nг� �������: " << year;
        cout << "\n���: " << (type == 0 ? "���������" : "������������");
        cout << "\n�����: " << mileage << " ���. ��";
        cout << "\n�������: " << owner << "\n";
    }

    // ����� �������� ������ 
    void InputArray(Car* arr, int size) {
        for (int i = 0; i < size; ++i) {
            cout << "\n�������� ������ #" << i + 1 << endl;
            arr[i].Input();
        }
    }
};

class Derived : public Car {
public:
    // ����� ���������� ������
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

    // �������� ������ ����� ������� ����
    d.InputArray(cars, 1);

    // ������ ��'���� ����� ����������� ��������� �� ��� ���������
    Car carDefault;       // ������ � ������������� ��� ���������
    cars[1] = carDefault; // ������ �� �� ������

    Car carCopy(cars[0]); // ���� ����� ������
    cars[2] = carCopy;    // ������ �� �� ������

    cout << "\n--- �� ����������� �� ����� ������� ---\n";
    for (int i = 0; i < N; ++i) {
        cout << "\n������ #" << i + 1 << endl;
        cars[i].Print();
    }

    // ���������� ����� �������� ����
    d.SortByYear(cars, N);

    cout << "\n--- ³���������� �� ����� ������� ---\n";
    for (int i = 0; i < N; ++i) {
        cout << "\n������ #" << i + 1 << endl;
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
