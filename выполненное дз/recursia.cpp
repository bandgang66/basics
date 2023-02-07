#include <iostream>
#include <random>
#include "recursia.h"

using namespace std;

random_device Rand;
void end() 
{
	cout << endl << endl;
}
int del(int a, int b)
{
	if (a == 0)
		return b;
	else if (b == 0)
		return a;
	else if (a > b)
		return del(b, a % b);
	else
		return del(a, b % a);
}
template<typename T>
T step(T a, T st)
{

	if (st < 1)
	{
		return 1;
	}

	return a * step(a, st - 1);

}
int star(int a)
{
	if (a < 1)
	{
		return 0;
	}
	cout << " * ";
	return star(a - 1);
}
int summa(int a, int b)
{
	if (b < a)
	{
		return 0;
	}

	return  b + summa(a, b - 1);
}
void InitMass(int* mas, int size)
{
	if(size>=0)
	{
		*(mas + size) = Rand() % ((9 - (1)) + 1);
		InitMass(mas, size - 1);
	}
}
void ShowMass(int* mas, int size,int i=0)
{

	if (i < size)
	{
		cout << *(mas + i) << " ";
		ShowMass(mas, size, ++i);
	}
	else 
		return;

}
int minSumMass(int* mas, int size)
{
	//Здесь не смог сделать рекурсию, потому что сложно дался сам алгоритм =(
	int sum = 0;
	int min = 0;
	for (int i = 0; i < 10; ++i)
	{
		sum += *(mas + i);
	}
	min = sum;
	for (int j = 0; j < size; ++j)
	{
		sum = 0;
		if (j == size - 9)
		{
			return min;
		}
		for (int i = j; i < j + 10; ++i)
		{
			sum += *(mas + i);
		}
		if (sum < min)
		{
			min = sum;
		}
	}
	return min;
}
int transMassNum(int* mas, int size,int number=0, int i = 0,int  del = 1000)
{

	if (i < size) 
	{
		number = number + (*(mas + i) * del);
		i++;
		del /= 10;
		
		transMassNum(mas, size, number, i, del);
	}
	else
		return number;
}
void transNumMass(int number, int* mass, int size,int i=3)
{

	if (i >= 0) 
	{
		*(mass + i) = number % 10;
		number /= 10;
		i--;
		transNumMass(number, mass, size, i);
	}

}
int bulls(int* mas1, int* mas2, int size)
{
	//Здесь тоже сложно было сделать рекурсию =(
	
	int counter = 0;
	int i = 0;

	for (int i = 0; i < size; ++i)                 
	{											   
		for (int j = 0; j < size; ++j)
		{
			if (*(mas1 + j) == *(mas2 + i))
			{
				counter++;
				j = size;

			}
		}
	}


	return counter;
}
int cows(int* mas1, int* mas2, int size8,int counter = 0, int i=0)
{

	if (i <= size8) 
	{
		if (*(mas1 + i) == *(mas2 + i))
		{
			counter++;
			
		}
		i++;
		cows(mas1, mas2, size8, counter, i);
	}else
		return counter;
}

int main()
{
	setlocale(LC_ALL, "ru");

	//задание 1.
	system("Pause");
	cout << "\tЗадание № 1 :\n Написать рекурсивную функцию нахождения наибольшего общего делителя двух целых чисел.\n\n";
	system("Pause");
	cout << "\nРешение: \n\n";

	int a1;
	cout << "введите число А: ";
	cin >> a1;
	cout << endl;
	int b1;
	cout << "введите число В: ";
	cin >> b1;
	cout << endl;
	cout << "Наибольший общий делитель чисел А и В: " << del(a1, b1);
	cout << endl;
	end();

	//задание 2.
	system("Pause");
	cout << "\tЗадание № 2 :\nНаписать игру быки и коровы, программа загадывает  четырехзначное число\n"
			"и играющий должен угадать его, после ввода пользователем  числа программа сообщает, сколько цифр числа угадано(быки)\n"
			"и сколько цифр угадано и стоит на своем месте (коровы). После отгадывания\n"
			"числа на экран необходимо вывести количество сделаных пользователем попыток.\n"
			"Использовать рекурсию\n\n";
	system("Pause");
	cout << "\nРешение: \n\n";

	int number;
	const int size2 = 4;
	int* mass2 = new int[size2];
	int* mass2_2 = new int[size2];

	InitMass(mass2, size2);
	transMassNum(mass2, size2);
	cout << "введите четырехзначное число: ";
	cin >> number;
	transNumMass(number, mass2_2, size2);
	cout << endl;
	cout << endl;
	cout <<"загаданое машиной число: " << transMassNum(mass2, size2);
	cout << endl;
	cout <<"ваше число: " <<number;
	cout << endl;
	cout <<"количество быков(одинаковых чисел):        " << bulls(mass2_2, mass2, size2);
	cout << endl;
	cout <<"количество коров(числа на своих местах):   "<<cows(mass2, mass2_2, size2);
	end();

	//задание 4.
	system("Pause");
	cout << "\tЗадание № 4 :\n Написать рекурсивную функцию нахождения степени числа.\n\n";
	system("Pause");
	cout << "\nРешение: \n\n";
	long long a4;
	cout << "введите число : ";
	cin >> a4;
	cout << endl;
	long long b4;
	cout << "введите степень числа: ";
	cin >> b4;
	cout << endl;
	cout << "число: " << a4 << " в степени: " << b4 << " равно: " << step(a4, b4);
	cout << endl;
	end();

	//задание 5.
	system("Pause");
	cout << "\tЗадание № 5 :\nНаписать рекурсивную функцию, которая выводит N звезд в ряд, число N задает пользователь.\n"
			"Проиллюстрируйте работу функции примером.\n\n";
	system("Pause");
	cout << "\nРешение: \n\n";
	int a5;
	cout << "введите количество звёздочек: ";
	cin >> a5;
	cout << endl;
	star(a5);
	cout << endl;
	end();

	//задание 6.
	system("Pause");
	cout << "\tЗадание № 6 :\nНаписать рекурсивную функцию, которая вычисляет сумму всех чисел в диапазоне от a до b.\n"
			"Пользователь вводит a и b.Проиллюстрируйте работу функции примером.\n\n";
	system("Pause");
	cout << "\nРешение: \n\n";
	int a6;
	cout << "введите число А: ";
	cin >> a6;
	cout << endl;
	int b6;
	cout << "введите число В: ";
	cin >> b6;
	cout << endl;
	cout << "сумма чисел в диапозоне от: " << a6 << " до: " << b6 << " равно: " << summa(a6, b6);
	cout << endl;
	end();

	//задание 7.
	system("Pause");
	cout << "\tЗадание № 7 :\nНапишите рекурсивную функцию, которая принимает одномерный массив из 100 целых чисел,\n"
			"заполненных случайным образом, и находит позицию, с которой начинается\n"
			"последовательность из 10 чисел, сумма которых минимальна\n\n";
	const int size = 100;
	int* mass = new int[size];
	InitMass(mass, size);
	cout << "массив из 100 элементов: \n";
	ShowMass(mass, size);
	end();
	cout << "из  кобинаций \"10\" подряд , сумма наименьшей равна : " << minSumMass(mass, size);
	end();



}
