// Lab5_IndivV14.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <map>
#include <windows.h>
#include <string>
using namespace std;

int main() {
    SetConsoleCP(1251); 
    SetConsoleOutputCP(1251);
    // Створюємо контейнер map для збереження цілих чисел і рядків
    map<int, string> MyMap;

    // Заповнюємо контейнер
    MyMap[1] = "First";
    MyMap[2] = "Second";
    MyMap[3] = "Third";

    // Виводимо map
    cout << "Початковий map:\n";
    for (auto el : MyMap) {
        cout << el.first << ": " << el.second << endl;
    }

    // Видаляємо елемент з ключем 2 і змінюємо значення при ключі 3
    MyMap.erase(2);
    MyMap[3] = "Other";

    // Перегляд з ітераторами
    cout << "\nПісля змін (ітератори):\n";
    for (map<int, string>::iterator it = MyMap.begin(); it != MyMap.end(); ++it) {
        cout << it->first << ": " << it->second << endl;
    }

    // Створюємо другий map
    map<int, string> secondMap;
    secondMap[4] = "FOUR";
    secondMap[5] = "FIVE";

    // Видаляємо перший елемент і додаємо всі з другого
    MyMap.erase(1);
    MyMap.insert(secondMap.begin(), secondMap.end());

    // Перегляд обох контейнерів
    cout << "\nПерший map після змін:\n";
    for (auto el : MyMap) {
        cout << el.first << ": " << el.second << endl;
    }

    cout << "\nДругий map:\n";
    for (auto el : secondMap) {
        cout << el.first << ": " << el.second << endl;
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
