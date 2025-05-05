#include <iostream>
#include <list>
#include <string>
#include <windows.h>
using namespace std;

struct Student {
    string name;
    int age;
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    // Створюємо список студентів
    list<Student> students = {
        {"Аня", 18},
        {"Богдан", 19},
        {"Катя", 17}
    };

    // Виводимо список
    cout << "Початковий список:\n";
    for (auto s : students) {
        cout << s.name << " - " << s.age << " років\n";
    }

    // Видаляємо першого і міняємо вік другого
    students.pop_front();
    students.front().age = 20;

    cout << "\nПісля змін:\n";
    for (list<Student>::iterator it = students.begin(); it != students.end(); ++it) {
        cout << it->name << " - " << it->age << " років\n";
    }

    // Другий список
    list<Student> moreStudents = {
        {"Максим", 18},
        {"Олена", 21}
    };

    // Видаляємо елементи після першого і додаємо нових
    list<Student>::iterator it = students.begin();
    ++it;
    students.erase(it, students.end());
    students.insert(students.end(), moreStudents.begin(), moreStudents.end());

    cout << "\nПерший список:\n";
    for (auto s : students) {
        cout << s.name << " - " << s.age << " років\n";
    }

    cout << "\nДругий список:\n";
    for (auto s : moreStudents) {
        cout << s.name << " - " << s.age << " років\n";
    }

    return 0;
}
