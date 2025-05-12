// EXAMPLE.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <list>
#include <windows.h>
using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    list<int> myList = { 10, 20, 30, 40, 50 };

    cout << "Початковий список: ";
    for (int num : myList) {
        cout << num << " ";
    }
    cout << endl;

    myList.remove(20);
    myList.push_back(60);

    cout << "Список після змін: ";
    for (list<int> :: iterator it = myList.begin(); it != myList.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    list<int> secondList = { 100, 200, 300 };

    list<int> :: iterator it = myList.begin();
    advance(it, 2);
    myList.erase(it, myList.end());

    myList.insert(myList.end(), secondList.begin(), secondList.end());

    cout << "Фінальний список 1: ";
    for (int num : myList) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Фінальний список 2: ";
    for (int num : secondList) {
        cout << num << " ";
    }
    cout << endl;

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
