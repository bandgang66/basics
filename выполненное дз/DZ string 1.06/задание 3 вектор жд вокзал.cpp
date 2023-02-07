#include <iostream>
#include <random>
#include <vector>
#include <string>

using namespace std;

random_device Rand;



class trains
{
	int NUM;
	class TIME 
	{
	public:
		int hour;
		int minute;
		TIME(int h, int m) :hour{ h }, minute{ m }{};
		TIME() :TIME(0, 0) {};

		void get_time() 
		{
			if (hour < 10 && minute < 10) 
			{
				cout << "0" << hour << ":" << "0" << minute;
			}
			else if (hour < 10 && minute >= 10)
			{
				cout << "0" << hour << ":" << minute;
			}
			else if (hour >= 10 && minute < 10) 
			{
				cout  << hour << ":" << "0" << minute;
			}
		}

	}time_otp;
	string STATION;
public:
	trains(int num, TIME time, string station) :NUM(num), time_otp(time), STATION(station) {};
	trains() :trains(0, { 0,0 }, "") {};

	void set_train() 
	{
		cout << "\nВведите номер поезда: \n";
		cin >> NUM;
		cout << "\nВведите время отправления поезда: \n";
		cout << "\nВведите часы: \n";
		cin >> time_otp.hour;
		cout << "\nВведите минуты: \n";
		cin >> time_otp.minute;
		cout << "\nВведите название станции назначения поезда: \n";
		cin >> STATION;
		
	}
	void get_train() 
	{
		cout << "\nномер поезда: " << NUM << "\n";
		cout << "\nвремя отправления поезда: "; 
		time_otp.get_time();
		cout << "\nСтанция назначения поезда: " << STATION << "\n";
	}

	int get_NUM() { return NUM; };
	TIME get_TIME() { return time_otp; };
	string get_Station() { return STATION; }
};



void add_trains(vector<trains>& masstrains) 
{
	int nums{};
	cout << "\nВведите сколько поездов добавить: \n";
	cin >> nums;

	for (int i = 0; i < nums; ++i) 
	{
		masstrains[i].set_train();
	}
}

void show_train(vector<trains> masstrains) 
{
	cout << "\nВведите номер поезда: \n";
	int num{};
	cin >> num;

	for (int i = 0; i < masstrains.size(); ++i)
	{
		if (masstrains[i].get_NUM() == num) 
		{
			masstrains[i].get_train();
		}
	}


}

void show_all_trains(vector<trains> masstrains) 
{
	for (int i = 0; i < masstrains.size(); ++i) 
	{
		masstrains[i].get_train();
	}
}


int main()
{
	setlocale(LC_ALL, "ru");

	
	trains newtrain;
	cout << "\n=================================================================\n";
	newtrain.set_train();
	newtrain.get_train();
	cout << "\n=================================================================\n";
	trains newtrain2(2, {4,14}, "asd");
	newtrain2.get_train();
	cout << "\n=================================================================\n";

	vector<trains> masstrains(2);
	

	add_trains(masstrains);
	show_all_trains(masstrains);
	show_train(masstrains);




}

//
//Задание №3
//Написать программу «Автоматизированная информационная
//система ЖД вокзала».
 
// Система содержит : сведения об отправлении поездов дальнего следования.

//Для каждого поезда указываем : 
//номер,
//время отправления, 
//станцию назначения.

//Обеспечить :
//■ Ввод данных в систему;
//■ Вывод информации о всех поездах;
//■ Вывод информации о запрашиваемом поезде.

//Использовать контейнерный класс vector