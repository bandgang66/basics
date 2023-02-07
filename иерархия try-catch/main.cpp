#include <iostream>
#include <string>
#include <fstream>
#include "sotrudniks.h"
#include "tryCatchClass.h"

const string path1 = "sotrudniks.txt";


using namespace std;



void OpenFile(fstream& file,string path)  //открытие файла
{
	if (path != path1) 
	{
		throw exINT(0);
	}

	file.open(path,ios::out);
	file.close();
}

void saveFile(Sotrudniks* sotr) //сохранение в файл
{
	string path;
	do
	{
		try
		{
			cout << "введите путь к файлу: " << endl;
			getline(cin, path);
			sotr->saveFile(path);
			cout << "ФАЙЛ ОТКРЫТ!!!" << endl;
		}
		catch (excep& msg)
		{
			msg.what();
		}
	} while (path != path1);

}

void LoadFile(Sotrudniks* sotr) //загрузка из файла
{
	string path;
	do
	{
		try
		{
			cout << "введите путь к файлу: " << endl;
			getline(cin, path);
			sotr->LoadFile(path);
			cout << "ФАЙЛ ОТКРЫТ!!!" << endl;
		}
		catch (excep& msg)
		{
			msg.what();
		}
	} while (path != path1);

}

int main()
{
	setlocale(LC_ALL, "ru");

	//очистка файла перед работой				//try  except INT

	fstream file;
	string path;
	do
	{
		try
		{
			cout << "введите путь к файлу: " << endl;
			getline(cin, path);
			OpenFile(file, path);
			cout << "ФАЙЛ ОТКРЫТ!!!" << endl;
		}
		catch (excep& msg)
		{
			msg.what();
		}
	} while (path!=path1);
	

	//создание обьектов

	Sotrudniks* newSotr = creatSotrud("Electric");
	Sotrudniks* newSotr2 = creatSotrud("Povar");
	Sotrudniks* newSotr3 = creatSotrud("Buhgalter");

	//заполнение базовых полей		
	
	zapolnen(newSotr);
	zapolnen(newSotr2);
	zapolnen(newSotr3);

	//заполнение обязанностей: 	
	cout << "ДЛЯ ЭЛЕКТРИКА" << endl;
	addObyz(newSotr);
	cout << "ДЛЯ ПОВАРА" << endl;
	addObyz(newSotr2);
	cout << "ДЛЯ БУХГАЛТЕРА" << endl;
	addObyz(newSotr3);

	//вывод на экран
	cout << "ДЛЯ ЭЛЕКТРИКА" << endl;
	newSotr->get();

	cout << "ДЛЯ ПОВАРА" << endl;
	newSotr2->get();

	cout << "ДЛЯ БУХГАЛТЕРА" << endl;
	newSotr3->get();

	//сохранение в файл
	cout << "\n\n-=-=-=-=-=-=-=-=-=  сохранение в файл  -=-=-=-=--=-=-=-  newSort  =-=-=-=-===-=-=-=-=-=- \n\n";
	saveFile(newSotr);
	cout << "\n\n-=-=-=-=-=-=-=-=-=  сохранение в файл  -=-=-=-=--=-=-=-  newSort2  =-=-=-=-===-=-=-=-=-=- \n\n";
	saveFile(newSotr2);
	cout << "\n\n-=-=-=-=-=-=-=-=-=  сохранение в файл  -=-=-=-=--=-=-=-  newSort3  =-=-=-=-===-=-=-=-=-=- \n\n";
	saveFile(newSotr3);


	////загрузка из файла
	cout << "\n\n-=-=-=-=-=-=-=-=-=  загрузка из файла -=-=-=-=--=-=-=-  newSort  =-=-=-=-===-=-=-=-=-=- \n\n";
	LoadFile(newSotr);
	cout << "\n\n-=-=-=-=-=-=-=-=-=  загрузка из файла -=-=-=-=--=-=-=-  newSort2  =-=-=-=-===-=-=-=-=-=- \n\n";
	LoadFile(newSotr2);
	cout << "\n\n-=-=-=-=-=-=-=-=-=  загрузка из файла -=-=-=-=--=-=-=-  newSort3  =-=-=-=-===-=-=-=-=-=- \n\n";
	LoadFile(newSotr3);



	//удаление обьектов
	delete[] newSotr;
	delete[] newSotr2;
	delete[] newSotr3;
}