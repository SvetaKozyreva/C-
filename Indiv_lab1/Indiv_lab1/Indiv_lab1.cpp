// Indiv_lab1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <windows.h>
#include <conio.h>
#include <math.h>
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	const float pi = 3.14159;
	const float e = 2.71828;
	float x, y, z;
	float a1, a2, a3, a4, a5, a;
	float b1, b2, b3, b4, b5, b;
	// Ввiд заданих величин:
	std::cout << " Введiть значення трьох дiйсних змiнних:\n ";
	std::cin >> x >> y >> z;
	// Обчислення виразу a:
	a1 = x + 1.3 * y + 4.8 * z * z - 1 / 5;
	a2 = x * x + 2 * y * y + pi + 5 * z * z;
	a3 = a1 / a2;
	a4 = pow(e, -(x - y)) * log(4.2 + atan(z));
	a5 = pow(cos(x), 2) + pow(sin(y), 2) + 0.614;
	a = a3+(a4 / a5);
	// Обчислення виразу b:
	b1 = sin(x) + 0.2 * z * z + pow(e, -x * x / 2);
	b2 = fabs(3 * x - 4 * y + 5 * z);
	b3 = 2 + b2;
	b4 = x + b1 / b3;
	b5 = log(b4);
	b = sqrt(b5);
	// Друк результатiв у виглядi таблицi:
	std::cout << std::fixed << std::setprecision(3) << "\n Вхiднi величини та результати обчислень:";
	std::cout << "\nI-------------------------------------------I";
	std::cout << "\nI		Вхiднi величини:			I";
	std::cout << "\nI-------------------------------------------I";
	std::cout << "\nI		x =	I" << "	" << x << "		I";
	std::cout << "\nI-------------------------------------------I";
	std::cout << "\nI		y =	I" << "	" << y << "		I";
	std::cout << "\nI-------------------------------------------I";
	std::cout << "\nI		z =	I" << "	" << z << "		I";
	std::cout << "\nI-------------------------------------------I";
	std::cout << "\nI		Результати обчислень:		I";
	std::cout << "\nI-------------------------------------------I";
	std::cout << "\nI a1 = I	" << a1 << " I	b1 = " << b1 << "		I";
	std::cout << "\nI-------------------------------------------I";
	std::cout << "\nI a2 = I	" << a2 << " I  b2 = " << b2 << "		I";
	std::cout << "\nI-------------------------------------------I";
	std::cout << "\nI a3 = I	" << a3 << " I  b3 = " << b3 << "		I";
	std::cout << "\nI-------------------------------------------I";
	std::cout << "\nI a4 = I	" << a4 << " I  b4 = " << b4 << "		I";
	std::cout << "\nI-------------------------------------------I";
	std::cout << "\nI a5 = I	" << a5 << " I  b5 = " << b5 << "		I";
	std::cout << "\nI-------------------------------------------I";
	std::cout << "\nI a = I		" << a << "  I  b = " << b << "			I";
	std::cout << "\nI-------------------------------------------I";
	std::cin.get();
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
