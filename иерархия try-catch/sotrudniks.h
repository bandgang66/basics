#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "tryCatchClass.h"

using namespace std;

class Sotrudniks	//базовый класс сотрудники(шаблон для профессий)
{
protected:
	string name;	//ФИО
	int ZP;			//ЗП
	double staj;	//трудовой стаж
	const string path = "sotrudniks.txt"; //путь для файла

public:
	//конструкторы
	Sotrudniks(string n, int zp, double s) :name(n), ZP(zp), staj(s) { cout << "[сборка базы сотрудника]" << endl; } //конструктор все данные
	Sotrudniks() :Sotrudniks{ " ",0,0.0 } { cout << "[сборка базы сотрудника default]" << endl; }	//делигировнаие (констр по умолчанию )

	//мутатор
	virtual void setBase(string n, int zp, double st)		//метод заполнение данных базы
	{
		ZP = zp;
		name = n;
		staj = st;

		if (st<1.5) 
		{
			throw exDOUB(st);
		}
	}


	//вирт функции
	virtual void set(string obyz) {} //вирт метод для наследников, будет добавлять обязанности
	virtual void get() {}		//вывод на экран (в наследниках будет добавлены поля, поэтому виртуальный)

	//сохранение в файл и загрузка из файла
	virtual void saveFile(string path2) {};
	virtual void LoadFile(string path2) {};



	//диструктор
	virtual ~Sotrudniks() { cout << "[~Завершение сборки базы сотрудника]" << endl; };

};

//класс наследник Электрик
class Electric :public Sotrudniks
{
	const string doljnost = "Electric";	//должность
	string obyzanosti{};	//обязанности
	static int countObyz;	//счетчик обязанностей
	string flag = "+";	//для определения в файле
public:
	Electric(string n, int zp, double s) :Sotrudniks{ n,zp,s } { cout << "[сборка Электрика]" << endl; }
	Electric() :Electric{ "",0,0.0 } { cout << "[сборка Электрика default]" << endl; }



	virtual void set(string obyz)	//назначение обязанностей макс-3
	{
		if (countObyz >= 3)
		{		
			throw exSTR(obyz);				//throw excep STRING
		}

		if (obyzanosti.size() < 1)
		{
			obyzanosti.append(obyz);
			countObyz = 1;
		}
		else
		{
			countObyz++;
			obyzanosti.append(" " + obyz);
		}
	}

	virtual void get()	//вывод на экран
	{
		cout << endl;
		cout << "Должность: " << doljnost << endl;
		cout << "ФИО: " << name << endl;
		cout << "Обязанности: " << obyzanosti << endl;
		cout << "Трудовой стаж: " << staj << endl;
		cout << "Зарпалата: " << ZP << endl;
	}

	//сохранение в файл и загрузка из файла
		//сохранение
	virtual void saveFile(string path2)
	{
		ofstream file;

		if (path2 != path)
		{
			throw exINT(0);
		}

		file.open(path2, ios::app);

		if (!file.is_open())
		{
			cout << "файл не открылся" << endl;
		}
		else
		{
			file << endl;
			file << flag << endl;
			file << "Должность: " << doljnost << endl;
			file << "ФИО: " << name << endl;
			file << "Обязанности: " << obyzanosti << endl;
			file << "Трудовой стаж: " << staj << endl;
			file << "Зарпалата: " << ZP << endl;
			file << "*" << endl;
			file << endl;
		}

		file.close();

	};
	//выгрузка из файла
	virtual void LoadFile(string path2)
	{
		ifstream file;

		if (path2 != path)
		{
			throw exINT(0);
		}

		file.open(path2, ios::in);

		if (!file.is_open())
		{
			cout << "файл не открылся" << endl;
		}
		else
		{
			string buff1 = "";
			string buff2 = "";
			int poz = 0;
			int i = 0;


			while (!file.eof())
			{
				getline(file, buff1);
				if (buff1 == flag)
				{
					while (buff2.find("*") == string::npos)
					{
						getline(file, buff2);

						if (buff2.find("*") != string::npos)
							break;

						cout << buff2 << "\n";
					}
				}
			}
		}
		file.close();


	};
	~Electric()
	{
		cout << "[~завершение сборки электрика]" << endl;
	}
};
int Electric::countObyz{ 0 };


//класс наследник ПОВАР
class Povar :public Sotrudniks
{
	const string doljnost = "Povar";
	string obyzanosti{};
	static int countObyz;
	string flag = "$";
public:
	Povar(string n, int zp, double s) :Sotrudniks{ n,zp,s } { cout << "[сборка Повара]" << endl; }
	Povar() :Povar{ "",0,0.0 } { cout << "[сборка Повара default]" << endl; }

	virtual void set(string obyz)
	{
		if (countObyz >= 3)
		{
			throw exSTR(obyz);									//throw excep STRING
		}

		if (obyzanosti.size() < 1)
		{
			obyzanosti.append(obyz);
			countObyz = 1;
		}
		else
		{
			countObyz++;
			obyzanosti.append(" " + obyz);
		}
	}

	virtual void get()
	{
		cout << endl;
		cout << "Должность: " << doljnost << endl;
		cout << "ФИО: " << name << endl;
		cout << "Обязанности: " << obyzanosti << endl;
		cout << "Трудовой стаж: " << staj << endl;
		cout << "Зарпалата: " << ZP << endl;
	}

	//сохранение в файл и загрузка из файла
		//сохранение
	virtual void saveFile(string path2)
	{
		ofstream file;

		if (path2 != path)
		{
			throw exINT(0);
		}

		file.open(path2, ios::app);
		if (!file.is_open())
		{
			cout << "Файл не открылся" << endl;
		}
		else
		{
			file << endl;
			file << flag << endl;
			file << "Должность: " << doljnost << endl;
			file << "ФИО: " << name << endl;
			file << "Обязанности: " << obyzanosti << endl;
			file << "Трудовой стаж: " << staj << endl;
			file << "Зарпалата: " << ZP << endl;
			file << "*" << endl;
			file << endl;
		}

		file.close();

	};
	//выгрузка из файла
	virtual void LoadFile(string path2)
	{
		ifstream file;

		if (path2 != path)
		{
			throw exINT(0);
		}

		file.open(path, ios::in);

		if (!file.is_open())
		{
			cout << "Файл не открылся" << endl;
		}
		else
		{
			string buff1 = "";
			string buff2 = "";
			int poz = 0;
			int i = 0;


			while (!file.eof())
			{
				getline(file, buff1);
				if (buff1 == flag)
				{
					while (buff2.find("*") == string::npos)
					{
						getline(file, buff2);

						if (buff2.find("*") != string::npos)
							break;

						cout << buff2 << "\n";
					}
				}
			}
		}
		file.close();


	};
	~Povar()
	{
		cout << "[~завершение сборки Повара]" << endl;
	}
};
int Povar::countObyz{ 0 };

//класс-наследник БУХГАЛТЕР
class buhgalter :public Sotrudniks
{
	const string doljnost = "Buhgalter";
	string obyzanosti{};
	static int countObyz;
	string flag = "/";
public:
	buhgalter(string n, int zp, double s) :Sotrudniks{ n,zp,s } { cout << "[сборка Бухгалтера]" << endl; }
	buhgalter() :buhgalter{ "",0,0.0 } { cout << "[сборка Бухгалтера default]" << endl; }

	virtual void set(string obyz)
	{
		if (countObyz >= 3)
		{
			throw exSTR(obyz);										//throw excep STRING
		}

		if (obyzanosti.size() < 1)
		{
			obyzanosti.append(obyz);
			countObyz = 1;
		}
		else
		{
			countObyz++;
			obyzanosti.append(" " + obyz);
		}
	}

	virtual void get()
	{
		cout << endl;
		cout << "Должность: " << doljnost << endl;
		cout << "ФИО: " << name << endl;
		cout << "Обязанности: " << obyzanosti << endl;
		cout << "Трудовой стаж: " << staj << endl;
		cout << "Зарпалата: " << ZP << endl;
	}

	//сохранение в файл и загрузка из файла
		//сохранение
	virtual void saveFile(string path2)
	{
		ofstream file;

		if (path2 != path)
		{
			throw exINT(0);
		}

		file.open(path2, ios::app);
		if (!file.is_open())
		{
			cout << "файл не открылся" << endl;
		}
		else
		{
			file << endl;
			file << flag << endl;
			file << "Должность: " << doljnost << endl;
			file << "ФИО: " << name << endl;
			file << "Обязанности: " << obyzanosti << endl;
			file << "Трудовой стаж: " << staj << endl;
			file << "Зарпалата: " << ZP << endl;
			file << "*" << endl;
			file << endl;
		}

		file.close();

	};
	//выгрузка из файла
	virtual void LoadFile(string path2)
	{
		ifstream file;


		if (path2 != path)
		{
			throw exINT(0);
		}


		file.open(path2, ios::in);

		if (!file.is_open())
		{
			cout << "файл не открылся" << endl;
		}
		else
		{
			string buff1 = "";
			string buff2 = "";
			int poz = 0;
			int i = 0;


			while (!file.eof())
			{
				getline(file, buff1);
				if (buff1 == flag)
				{
					while (buff2.find("*") == string::npos)
					{
						getline(file, buff2);

						if (buff2.find("*") != string::npos)
							break;

						cout << buff2 << "\n";
					}
				}
			}
		}
		file.close();


	};
	~buhgalter()
	{
		cout << "[~завершение сборки Бухгалтера]" << endl;
	}
};
int buhgalter::countObyz{ 0 };

Sotrudniks* creatSotrud(string dolj)	
{
	if (dolj == "Electric")
	{
		return new Electric;
	}
	else if (dolj == "Povar")
	{
		return new Povar;
	}
	else if (dolj == "Buhgalter")
	{
		return new buhgalter;
	}
	else
	{
		return nullptr;
	}
}

void addObyz(Sotrudniks* sotr)					//TRY для THROW EXCEP STRING
{
	int vihod = 1;
	string obyz;
	do
	{
		try
		{
			
			cout << "Введите обязанность: " << endl;
			getline(cin, obyz);
			sotr->set(obyz);
			cout << "Для выхода введите  0, ДЛЯ ПРОДОЛЖЕНИЯ  1" << endl;
			cin >> vihod;

			cin.clear();
			cin.ignore(cin.rdbuf()->in_avail());
		}
		catch (excep& msg)
		{
			msg.what();
			
			break;
		}
	} while (vihod);

}

void zapolnen(Sotrudniks* sotr)							//TRY для THROW EXCEP DOUB
{
	string name;
	int zp;
	double staj;

	cout << "\nвведите ФИО: " << endl;
	getline(cin, name);
	cout << "\nвведите Зарплату: " << endl;
	cin >> zp;
	cout << "\nвведите стаж: " << endl;
	cin >> staj;
	
	cin.clear();
	cin.ignore(cin.rdbuf()->in_avail());

	try
	{
		sotr->setBase(name, zp, staj);
	}
	catch (excep& msg)
	{
		msg.what();
		
	}
	


}

