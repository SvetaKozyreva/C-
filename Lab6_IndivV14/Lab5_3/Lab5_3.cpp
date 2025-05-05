#include <iostream>
#include <vector>
#include <algorithm>
#include <windows.h>
using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    // Створюємо вектор чисел
    vector<float> numbers = { 3.1, 5.4, 2.2, 5.0, 1.5 };

    // Сортуємо за спаданням вручну
    sort(numbers.begin(), numbers.end());
    reverse(numbers.begin(), numbers.end());  // Реверсуємо, щоб був спад
    cout << "Сортування за спаданням:\n";
    for (float x : numbers) {
        cout << x << " ";
    }

    // Пошук першого числа > 4
    for (float x : numbers) {
        if (x > 4) {
            cout << "\nПерше число більше 4: " << x << endl;
            break;
        }
    }

    // Створюємо другий вектор з числами > 4
    vector<float> second;
    for (float x : numbers) {
        if (x > 4) second.push_back(x); //додавання елементів у кінець контейнера
    }

    cout << "\nДругий вектор:\n";
    for (float x : second) {
        cout << x << " ";
    }

    // Злиття двох векторів
    numbers.insert(numbers.end(), second.begin(), second.end());

    // Сортуємо та виводимо злитий вектор (по зростанню)
    sort(numbers.begin(), numbers.end());
    cout << "\nЗлитий вектор (по зростанню):\n";
    for (float x : numbers) {
        cout << x << " ";
    }

    // Підраховуємо кількість чисел > 3
    int count = 0;
    for (float x : numbers) {
        if (x > 3) count++;
    }
    cout << "\nКількість чисел більше 3: " << count << endl;

    // Чи є число < 2
    bool found = false;
    for (float x : numbers) {
        if (x < 2) {
            found = true;
            break;
        }
    }
    cout << "Є число менше 2? " << (found ? "Так" : "Ні") << endl;

    return 0;
}
