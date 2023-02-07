//#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include <cstdio>


using namespace std;

union charge
{
	char Director[15];
	int object;
	double time;
	bool job;
};

struct Sotrudniks 
{
	char FIO[30];
	char Doljnost[10];
	int exp;
	int ZP;
	charge obyaz;

};



void zapolSotr(Sotrudniks& newSort) 
{
	char name[80];//ФИО

	char dir[10]="Директор";
	char eng[10] = "Инженер";
	char sles[10] = "Слесарь";		
	char kadr[10] = "Кадровик";			//ДОЛЖНОСТИ
	
	char dir_obyaz_G[15] = "Главный";
	char dir_obyaz2_K[15] = "Коммерческий";
	char dir_obyaz3_F[15] = "Финансовый";			//ОБЯЗАННОСТИ ДИРЕКТОРА

	//ФИО
	cin.clear();
	cin.ignore(cin.rdbuf()->in_avail());
	cout << "\nВведите ФИО: " << endl;
	gets_s(name,80);

	if (strlen(name) <= 30) 
	{

		strcpy_s(newSort.FIO, name);
	}
	else
	{
		cout << "Не правильынй ввод ФИО ";
		return;
	}
	
	
	//ДОЛЖНОСТЬ И ОБЯЗАННОСТИ
	int vibor_D = 0;
	int vibor_O = 0;

	cout << "\nВыбирите должность: \n"
			"\nДиректор, введите......1\n"
			"\nИнженер, введите.......2\n"
			"\nСлесарь, введите.......3\n"
			"\nКадровик, введите......4\n";

	cin >> vibor_D;

	

	switch (vibor_D)
	{
	case 1:
		strcpy_s(newSort.Doljnost, dir);
		cout << "\nВыбирите Обязанности Директора: \n"
			"\nГлавный, введите............1\n"
			"\nКоммерческий, введите.......2\n"
			"\nФинансовый, введите.........3\n";

		cin >> vibor_O;

		switch (vibor_O)
		{
		case 1:
			strcpy_s(newSort.obyaz.Director, dir_obyaz_G);
			break;
		case 2:
			strcpy_s(newSort.obyaz.Director, dir_obyaz2_K);
			break;
		case 3:
			strcpy_s(newSort.obyaz.Director, dir_obyaz3_F);
			break;
		}
		break;
	case 2:
		strcpy_s(newSort.Doljnost, eng);
		cout << "\nВведите количество сданных проектов: \n";
		cin >> newSort.obyaz.object;
		break;
	case 3:
		strcpy_s(newSort.Doljnost, sles);
		cout << "\nВведите обьём работы в часах: \n";
		cin >> newSort.obyaz.time;
		break;
	case 4:
		strcpy_s(newSort.Doljnost, kadr);
		cout << "\nВыбирете тип занятости: \n"
				"\nЕсли полная занятость, введите......1\n"
				"\nЕсли частичная занятость, введите...0\n";
		cin >> newSort.obyaz.job;
		break;

	}

	//СТАЖ
	cout << "\nВведите стаж работы: \n";
	cin >> newSort.exp;
	//ЗАРПЛАТА
	cout << "\nВведите уровень зарплаты: \n";
	cin >> newSort.ZP;


}

void vivodSotr(Sotrudniks& newSotr) 
{

	char dir[10] = "Директор";
	char eng[10] = "Инженер";
	char sles[10] = "Слесарь";
	char kadr[10] = "Кадровик";			//ДОЛЖНОСТИ


	//ФИО
	cout <<"\nФИО сотрудника: " << newSotr.FIO << endl;
	//ДОЛЖНОСТЬ
	cout <<"\nДолжность: " << newSotr.Doljnost << endl;
	//ОБЯЗАННОСТИ
	if (!strcmp(newSotr.Doljnost, dir)) 
	{
		cout << "\nОбязанности Директора: ";
		cout << newSotr.obyaz.Director << endl;
	}
	else if (!strcmp(newSotr.Doljnost, eng))
	{
		cout << "\nКоличество сданных обьектов: ";
		cout << newSotr.obyaz.object << endl;
	}
	else if (!strcmp(newSotr.Doljnost, sles))
	{
		cout << "\nКоличество отработанных часов: ";
		cout << newSotr.obyaz.time << endl;
	}
	else if (!strcmp(newSotr.Doljnost, kadr))
	{
		if (newSotr.obyaz.job == 1) 
		{
			cout << "\nПолная занятость\n";
		}
		else
		{
			cout << "\nЧастичная занятость\n";
		}
		
	}
	//СТАЖ
	cout << "\nСтаж сотрудника: " << newSotr.exp << endl;
	//ЗП
	cout << "\nЗарплата: " << newSotr.ZP << endl;
}

void zapolAddSotrs(Sotrudniks* addSotrs, int& size_start, int& size_end, int sizeAdd)
{
	size_end += sizeAdd;
	for (; size_start < size_end; ++size_start) 
	{
		zapolSotr(*(addSotrs + size_start));
	}
	
}



void vivodShtat(Sotrudniks* shtatSotr, int sizeShtat) 
{
	for (int i = 0; i < sizeShtat; ++i) 
	{
		cout << endl;
		vivodSotr(*(shtatSotr + i));
	}
}

void uvol(Sotrudniks* shtatSotr, int& sizeShtat_end) 
{
	char name[30];
	cin.clear();
	cin.ignore(cin.rdbuf()->in_avail());
	cout << "\nВведите ФИО сотрудника которого хотите уволить: ";
	gets_s(name,30);

	for (int i = 0; i < sizeShtat_end; ++i)
	{
		if (!strcmp(shtatSotr[i].FIO, name)) 
		{
			for (int j = i; j < sizeShtat_end; ++j) 
			{
				shtatSotr[j] = shtatSotr[j + 1];
			}
		}
		
	}
	
	--sizeShtat_end;
}

int main()
{
	setlocale(LC_ALL, "ru");
	//Задание 2:
	cout << "Задание 2: \n"
		"Реализовать структуру \"Сотрудники\" (ФИО, стаж, должность(директор, инженер, слесарь, кадровик),зарплата, обязанности).\n\n"
		"Обязанности реализовать как объединение:\n\n"
		"для директора : главный, комерческий или финасовый;\n"
		"для инженера - количество сданных проектов;\n"
		"для слесаря - объем работы в часах;\n"
		"для кадровика : постоянная занятость или нет).\n\n"
		"Реализовать следующие функции :\n\n"
		"Заполнение объекта\n"
		"Вывод на экран данных об объекте\n"
		"Зачисление сотрудника в штат\n"
		"Увольнение\n";
	
	system("PAUSE");



	cout << "\n============выбираем и заполняем группу сотрудников.============= \n";

	int sizeAdd;
	
	int size_start = 0;
	int size_end = 0;
	cout << "\n===========введите число добавляемых сотрудников в  штат сотрудников======1 раз======\n";
	cin >> sizeAdd;
	cin.clear();
	cin.ignore(cin.rdbuf()->in_avail());

	Sotrudniks addSotrs[100] = {};

	cout << "\n===========заполнение штата 1 раз===============\n";
	zapolAddSotrs(addSotrs,size_start,size_end, sizeAdd);
	cout << "\n===========вывод штата 1 раз===============\n";
	vivodShtat(addSotrs, size_end);

	cout << "\n=======введите число добавляемых сотрудников в  штат сотрудников=====2 раз======\n";
	cin >> sizeAdd;
	cin.clear();
	cin.ignore(cin.rdbuf()->in_avail());

	cout << "\n==============заполнение штата 2 раз=====================\n";
	zapolAddSotrs(addSotrs, size_start, size_end, sizeAdd);
	cout << "\n==============вывод штата 2 раз=====================\n";
	vivodShtat(addSotrs, size_end);
	cout << "\n==============увольнение сотрудника=====================\n";
	
	uvol(addSotrs, size_end);
	cout << "\n==============вывод штата после увольнения =====================\n";
	vivodShtat(addSotrs, size_end);

	return 0;
}