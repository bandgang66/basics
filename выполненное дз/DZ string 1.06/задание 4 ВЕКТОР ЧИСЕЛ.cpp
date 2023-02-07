#include <iostream>
#include <random>
#include <vector>
#include <string>

using namespace std;

random_device Rand;


class massNum 
{
	vector<int> mass;
public:
	massNum(int size) : mass(size) {};
	massNum() :massNum(0) {};

	
	void set_add_once_mass();//добавление одного элемента
	void set_add_many_mass(int size_m);//добавление нескольких элементов
	void get_min_mass();	//поиск минимального значения
	void get_max_mass();	//поиск максимального значения
	void sort_mass_minus();	//сортировка по убыванию
	void sort_mass_plus();	//сортировка по выростанию
	void plus_const_mass(const int x);	//Увеличение значений в контейнере на заданную константу;
	void minus_const_mass(const int y);	//Уменьшение значений в контейнере на заданную константу;
	void del_val_mass(int x);	//Удаление элементов из контейнера равных искомому значению.
	void get_all_mass();	//показ всех элементов


};
void massNum::set_add_once_mass()
{
	mass.push_back(Rand() % 9);
}
void massNum::set_add_many_mass(int size_m)
{
	for (int i = 0; i < size_m; ++i)
	{
		set_add_once_mass();
	}
}
void massNum::get_min_mass()
{
	int min = mass[0];
	for (int i = 0; i < mass.size(); ++i)
	{
		if (min > mass[i])
		{
			min = mass[i];
		}
	}
	cout << min << endl;
}
void massNum::get_max_mass()
{
	int max = mass[0];
	for (int i = 0; i < mass.size(); ++i)
	{
		if (max < mass[i])
		{
			max = mass[i];
		}
	}
	cout << max << endl;
}
void massNum::sort_mass_minus()
{
	if (mass.size() > 1)
	{
		int tmp = 0;
		for (size_t i = 0; i < mass.size(); i++)
		{
			for (size_t j = (mass.size() - 1); j >= (i + 1); j--)
			{
				if (mass[j] > mass[j - 1])
				{
					tmp = mass[j];
					mass[j] = mass[j - 1];
					mass[j - 1] = tmp;
				}
			}
		}
	}
	else
	{
		cout << "\nВв векторе менее 2х элементов, сортировка не нужна\n";
	}

}
void massNum::sort_mass_plus()
{
	if (mass.size() > 1)
	{
		int tmp = 0;
		for (size_t i = 0; i < mass.size(); i++)
		{
			for (size_t j = (mass.size() - 1); j >= (i + 1); j--)
			{
				if (mass[j] < mass[j - 1])
				{
					tmp = mass[j];
					mass[j] = mass[j - 1];
					mass[j - 1] = tmp;
				}
			}
		}
	}
	else
	{
		cout << "\nВв векторе менее 2х элементов, сортировка не нужна\n";
	}
}
void massNum::plus_const_mass(const int x)
{
	for (int i = 0; i < mass.size(); ++i)
	{
		mass[i] += x;
	}
}
void massNum::minus_const_mass(const int y)
{
	for (int i = 0; i < mass.size(); ++i)
	{
		mass[i] -= y;
	}
}
void massNum::del_val_mass(int x)
{
	auto iter = mass.begin();
	for (int i = 0; i < mass.size(); ++i)
	{
		if (mass[i] == x)
		{
			mass.erase(iter + i);
		}
	}
	mass.shrink_to_fit();

}
void massNum::get_all_mass()
{
	for (int i = 0; i < mass.size(); ++i)
	{
		cout << mass[i] << " ";
	}
	cout << endl;
}



int main()
{
	setlocale(LC_ALL, "ru");

	const int y = 1;
	const int x = 5;
	int del = 5;
	massNum newMass;
	cout << "=================================ДОБАВЛЕНИЕ 1 ЭЛЕМЕНТА===========================\n";
	newMass.set_add_once_mass();
	newMass.get_all_mass();
	cout << "=============================ДОБАВЛЕНИЕ НЕСКОЛЬКИХ ЭЛЕМЕНТОВ===========================\n";
	newMass.set_add_many_mass(9);
	newMass.get_all_mass();
	cout << "==============================ПОКАЗАТЬ МИНИМАЛЬНОЕ ЗНАЧЕНИЕ=========================\n";
	newMass.get_min_mass();
	cout << "=============================ПОКАЗАТЬ МАКСИМАЛЬНОЕ ЗНАЧЕНИЕ=================\n";
	newMass.get_max_mass();
	cout << "=================================СОРТИРОВАТЬ ПО УБЫВАНИЮ========================\n";
	newMass.sort_mass_minus();
	newMass.get_all_mass();
	cout << "================================СОРТИРОВАТЬ ПО ВОЗРАСТАНИЮ========================\n";
	newMass.sort_mass_plus();
	newMass.get_all_mass();
	cout << "==================================УВИЛИЧИТЬ НА ЗНАЧЕНИЕ==< "<< x <<" >========================\n";
	newMass.plus_const_mass(x);
	newMass.get_all_mass();
	cout << "===================================УМЕНИШИТЬ НА ЗНАЧЕНИЕ========< " << y << " >================\n";
	newMass.minus_const_mass(y);
	newMass.get_all_mass();
	cout << "===============================УДАЛЕНИЕ ЭЛЕМЕНТОВ РАВНЫХ ЗНАЧЕНИЮ===========< " << del << " >=================\n";
	newMass.del_val_mass(del);
	newMass.get_all_mass();
	cout << "============================================КОНЕЦ=========================\n";

}

//Задание №4.
//В контейнере типа vector хранится набор целых чисел.Создайте решения для следующих задач :
//
//
//■ Поиск минимального значения;
//■ Поиск максимального значения;
//■ Сортировка данных по убыванию;
//■ Сортировка данных по возрастанию;
//■ Увеличение значений в контейнере на заданную константу;
//■ Уменьшение значений в контейнере на заданную константу;
//■ Удаление элементов из контейнера равных искомому значению.

