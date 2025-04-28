// Lab5_Indiv14.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <windows.h> 
#include <cstdlib> // для abs()

using namespace std;
const int MAX_SIZE = 100; // максимальний розмір матриці

template <typename T>
class Matrix {
private:
    T data[MAX_SIZE][MAX_SIZE];
    int rows, cols;
public:
    Matrix(int r, int c) {
        rows = r;
        cols = c;
    }

    void input() {
        cout << "Введіть елементи матриці:\n";
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                cin >> data[i][j];
    }

    void output() {
        cout << "Матриця:\n";
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j)
                cout << data[i][j] << "\t";
            cout << endl;
        }
    }

    void DobOfRows() {
        for (int i = 0; i < rows; ++i) {
            bool hasNegative = false;
            for (int j = 0; j < cols; ++j) {
                if (data[i][j] < 0) {
                    hasNegative = true;
                    break;
                }
            }
            if (!hasNegative) {
                T product = 1;
                for (int j = 0; j < cols; ++j)
                    product *= data[i][j];
                cout << "Добуток елементів у рядку " << i + 1 << ": " << product << endl;
            }
        }
    }

    void maxDiagonalSum() {
        T maxSum = data[0][0];

        // Діагоналі, що починаються в першому рядку
        for (int k = 0; k < cols; ++k) {
            T sum = 0;
            for (int i = 0, j = k; i < rows && j < cols; ++i, ++j)
                sum += data[i][j];
            if (sum > maxSum) maxSum = sum;
        }

        // Діагоналі, що починаються в першому стовпці
        for (int k = 1; k < rows; ++k) {
            T sum = 0;
            for (int i = k, j = 0; i < rows && j < cols; ++i, ++j)
                sum += data[i][j];
            if (sum > maxSum) maxSum = sum;
        }

        cout << "Максимальна сума на діагоналях: " << maxSum << endl;
    }

    void SmallElements(T delete_el) {
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                if (abs(data[i][j]) <= delete_el)
                    data[i][j] = 0;
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int rows, cols;
    cout << "Введіть кількість рядків і стовпців матриці: ";
    cin >> rows >> cols;

    Matrix<int> mat(rows, cols);

    mat.input();
    mat.output();

    mat.DobOfRows();
    mat.maxDiagonalSum();

    int delete_el;
    cout << "Введіть число для видалення елементів (по модулю <=): ";
    cin >> delete_el;

    mat.SmallElements(delete_el);

    cout << "Матриця після видалення елементів:\n";
    mat.output();

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
