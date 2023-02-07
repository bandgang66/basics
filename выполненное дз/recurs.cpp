#include <iostream>
#include <random>

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
	for (int i = 0; i < size; ++i) 
	{
		*(mas + i) = Rand() % ((9-(1))+1);
	}
}
void ShowMass(int* mas, int size)
{
	for (int i = 0; i < size; ++i)
	{

		if (i==10|| i == 20 || i == 30 || i == 40 || i == 50 || i == 60 || i == 70 || i == 80 || i == 90 || i == 100) 
		{
			cout  << endl;

		}
		cout << *(mas + i) << " ";
	}
}
int minSumMass(int* mas, int size) 
{
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
		if (j == size-9) 
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
int transMassNum(int* mas, int size) 
{
	int number = 0;
	for (int i = 0, del = 1000; i < size; ++i, del /= 10)
	{
		number = number + (*(mas + i) * del);
	}
	return number;
}
void transNumMass(int number, int* mass, int size)
{

		//*(mass + 4) = number % del;
		//number /= 10;
		//del /= 10;
		//* (mass + 3) = number % del;
		//number /= 10;
		//del /= 10;
		//* (mass + 3) = number % del;
		//number /= 10;
		//del /= 10;
		//* (mass + 1) = number % del;
		//number /= 10;
		for (int i = size-1; i >=0; --i) 
		{
			*(mass + i) = number % 10;
			number /= 10;
		}

}
int bulls(int* mas1, int* mas2, int size) 
{
	int counter=0;

		for (int j = 0,i=0; j < size; ++j) 
		{
			if (*(mas1 + j) == *(mas2 + i)) 
			{
				counter++;
				++i;
			}
		}

	return counter;
}

int main()
{
	setlocale(LC_ALL, "ru");
	//Задание 1:
	//Написать рекурсивную функцию нахождения наибольшего общего делителя двух целых чисел.

	//int a1;
	//cout << "введите число А: ";
	//cin >> a1;
	//cout << endl;
	//int b1;
	//cout << "введите число В: ";
	//cin >> b1;
	//cout << endl;
	//cout << "Наибольший общий делитель чисел А и В: " << del(a1, b1);
	//cout << endl;
	//end();
	
	// задание 2:
	// Написать игру быки и коровы, программа загадывает  четырехзначное число
	// и играющий должен угадать его, после ввода пользователем  числа программа сообщает, сколько цифр числа угадано (быки)
	// и сколько цифр угадано и стоит на своем месте (коровы). После отгадывания
	// числа на экран необходимо вывести количество сделаных пользователем попыток.
	// Использовать рекурсию

	int number;
	const int size2 = 4;
	int* mass2 = new int[size2];
	int* mass2_2 = new int[size2];

	InitMass(mass2, size2);
	ShowMass(mass2, size2);
	cout << endl;
	cout << transMassNum(mass2, size2);
	cout << endl;
	cout << "введите четырехзначное число: ";
	cin >> number;
	transNumMass(number,mass2_2,size2);
	cout << endl;
	ShowMass(mass2_2, size2);
	cout << endl;
	cout << endl;
	ShowMass(mass2, size2);
	cout << endl;
	ShowMass(mass2_2, size2);
	cout << endl;
	cout << endl;
	cout << transMassNum(mass2, size2);
	cout << endl;
	cout << number;
	cout << endl;
	cout << bulls(mass2, mass2_2, size2);


	
	////Задание 4:
	////Написать рекурсивную функцию нахождения степени числа.
	//long long a4;
	//cout << "введите число : ";
	//cin >> a4;
	//cout << endl;
	//long long b4;
	//cout << "введите степень числа: ";
	//cin >> b4;
	//cout << endl;
	//cout << "число: " << a4 << " в степени: " << b4 << " равно: " << step(a4, b4);
	//cout << endl;
	//end();



	////Задание 5:
	////Написать рекурсивную функцию, которая выводит N звезд в ряд, число N задает пользователь.
	////Проиллюстрируйте работу функции примером.
	//int a5;
	//cout << "введите количество звёздочек: ";
	//cin >> a5;
	//cout << endl;
	//star(a5);
	//cout << endl;

	////Задание 6:
	////Написать рекурсивную функцию, которая вычисляет сумму всех чисел в диапазоне от a до b.
	////Пользователь вводит a и b.Проиллюстрируйте работу функции примером.
	//int a6;
	//cout << "введите число А: ";
	//cin >> a6;
	//cout << endl;
	//int b6;
	//cout << "введите число В: ";
	//cin >> b6;
	//cout << endl;

	//cout << "сумма чисел в диапозоне от: " << a6 << " до: " << b6 << " равно: " << summa(a6, b6);
	//cout << endl;

	//Задание 7:
	//Напишите рекурсивную функцию, которая принимает одномерный массив из 100 целых чисел,
	//заполненных случайным образом, и находит позицию, с которой начинается
	//последовательность из 10 чисел, сумма которых минимальна
	//const int size = 100;
	//int* mass = new int[size];
	//InitMass(mass, size);
	//ShowMassTabl(mass, size);
	//cout << endl;
	//cout << minSumMass(mass, size);

	

}
