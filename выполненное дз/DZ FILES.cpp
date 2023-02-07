//#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <cstring>


using namespace std;

void fileWrite(fstream &file)
{
	char name[20];
	cout << "Введите имя файла: " << endl;
	cin >> name;

	cin.clear();
	cin.ignore(cin.rdbuf()->in_avail());

	file.open(name,ios::out);

	if (!file.is_open())
	{
		cout << "Файл не открылся" << endl;
	}
	else
	{
		cout << "Введите количество строк: " << endl;
		int stroki;
		cin >> stroki;

		char* buff = nullptr;
		buff = new char[1000];
		
		

		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());

		for (int i = 1; i <= stroki; ++i)
		{
			
			
			cout << "Введите " << i << " строку: ";
			gets_s(buff, 1000);
			file << buff;
			
			if (i != stroki)
				file << "\n";
			
			
		}

		delete[] buff;
	}
	file.close();
}


void fileRead(fstream &file) 
{
	char name[20];
	cout << "Введите имя файла: " << endl;
	cin >> name;

	cin.clear();
	cin.ignore(cin.rdbuf()->in_avail());

	file.open(name);

	if (!file.is_open())
	{
		cout << "Файл не открылся" << endl;
	}
	else
	{
		char* buff1 = nullptr;
		buff1 = new char[1000];

		while (!file.eof())
		{

			file.getline(buff1, 1000);
			cout << buff1 << endl;

		}

		delete[] buff1;
	}

	file.close();
}

int fileRows(fstream& file) 
{
	int counter = 0;

	char name[20];
	cout << "Введите имя файла: " << endl;
	cin >> name;

	cin.clear();
	cin.ignore(cin.rdbuf()->in_avail());

	file.open(name);

	if (!file.is_open())
	{
		cout << "Файл не открылся " << endl;
	}
	else
	{
		char* buff = nullptr;
		buff = new char[1000];

		while (!file.eof())
		{

			file.getline(buff, 1000);

			counter++;

		}

		delete[] buff;
	}

	

	file.close();
	return counter;
}

void deleteLastRow(fstream& file1, fstream& file2, int counter) 
{

	char name1[20];
	cout << "Введите имя первого файла: " << endl;
	cin >> name1;

	cin.clear();
	cin.ignore(cin.rdbuf()->in_avail());

	char name2[20];
	cout << "Введите имя второго файла: " << endl;
	cin >> name2;

	cin.clear();
	cin.ignore(cin.rdbuf()->in_avail());



	file1.open(name1, ios::in);
	file2.open(name2, ios::out);

	if (!(file1.is_open() || file2.is_open()))
	{
		cout << "Файл1 или файл2 не открылся" << endl;
	}
	else
	{
		char* buff = nullptr;
		buff = new char[1000];

		for (int i = 0; i < counter-1; ++i)
		{

			file1.getline(buff, 1000);
			file2 << buff << endl;

		}

		delete[] buff;

	}
	file1.close();
	file2.close();
}

void fileLenRow(fstream& file,int countRow) 
{
	char name[20];
	cout << "Введите имя файла: " << endl;
	cin >> name;
	cin.clear();
	cin.ignore(cin.rdbuf()->in_avail());
	size_t lenRow = 0;
	size_t tmp = 0;
	int Row = 0;
	file.open(name, ios::in);
	if (!file.is_open())
	{
		cout << "Файл не открылся" << endl;
	}
	else
	{
		char* buff = nullptr;
		buff = new char[1000];

		for (int i = 1; i <= countRow; ++i)
		{
			file.getline(buff, 1000);
			lenRow = strlen(buff);
			if (lenRow > tmp)
			{
				tmp = lenRow;
				Row = i;
			}
		}
		delete[] buff;
	}

	file.close();
	cout << "длинна строки: " << Row << " имеет " << tmp << " символов(считая пробелы) " << endl;
}

void fileFindWord(fstream& file) 
{
	int counter = 0;

	char name[20];
	cout << "Введите имя файла: " << endl;
	cin >> name;

	cin.clear();
	cin.ignore(cin.rdbuf()->in_avail());

	char word[20];
	cout << "введите слово которое будем искать: ";
	cin >> word;

	cin.clear();
	cin.ignore(cin.rdbuf()->in_avail());

	file.open(name);

	if (!file.is_open())
	{
		cout << "Файл не открылся " << endl;
	}
	else
	{
		char* buff = nullptr;
		buff = new char[1000];

		while (!file.eof())
		{

			file.getline(buff, 1000);
			if (strstr(buff, word))
				counter++;
			

		}

		delete[] buff;
	}
	cout << "В файле " << name << " слово " << word << " встречается " << counter << " раз" << endl;
	file.close();
	
}

void fileChangeWord(fstream& file,int rows) 
{
	char name[20];
	cout << "Введите имя файла: " << endl;
	cin >> name;

	cin.clear();
	cin.ignore(cin.rdbuf()->in_avail());

	char wordfind[20];
	cout << "введите слово которое будем искать: ";
	cin >> wordfind;

	cin.clear();
	cin.ignore(cin.rdbuf()->in_avail());

	char wordPaste[20];
	cout << "введите слово которое будем вставлять: ";
	cin >> wordPaste;

	cin.clear();
	cin.ignore(cin.rdbuf()->in_avail());

	fstream tmpFile;

	file.open(name);
	tmpFile.open("tmpFile.txt");

	if (!(file.is_open()||tmpFile.is_open()))
	{
		cout << "Файл не открылся " << endl;
	}
	else
	{
		char* buff = nullptr;
		buff = new char[1000];
		char* C = new char[1000];
		

		
		
		for (int i = 0; i < rows; ++i)	//rows это количество строк в файле(второй аргумент функции)
		{
			file.getline(buff, 1000); //1) получили строку
			// 2) нужно перенести в 2-ой массив по словам
			// 3) идти по массиву и искать wordFind
			// 4) нашли и с помощью swap поменяли элемент массива на wordPaste
			// 5) преобразовать этот массив обратно в строку
			// 6) записать строку в tmpFile

			if (char* F = strstr(buff, wordfind)) 
			{
				strncpy_s(C, 1000, buff, F - buff);
				strcat_s(C, 1000, wordPaste);						//ну либо так, но тот вариант тоже интересный
				strcat_s(C, 1000, F + strlen(wordfind));

			}
			tmpFile << C << endl;
		}

		// 7) скопировать tmpFile в file
		
		for (int i = 0; i < rows; ++i) 
		{
			tmpFile.getline(buff, 1000);
			file << buff << endl;
		}

		delete[] buff;
	}
	
	file.close();
	tmpFile.close();


	file.open(name);
	tmpFile.open("tmpFile.txt");

	if (!(file.is_open() || tmpFile.is_open()))
	{
		cout << "Файл не открылся " << endl;
	}
	else
	{
		char* buff = nullptr;
		buff = new char[1000];

		// 7) скопировать tmpFile в file

		for (int i = 0; i < rows; ++i)
		{
			tmpFile.getline(buff, 1000);
			file << buff << endl;
		}


		delete[] buff;
	}

	file.close();
	tmpFile.close();

}

int main()
{
	setlocale(LC_ALL, "ru");

	fstream newfile;

	cout << "\n==========================ОТКРЫТИЯ И ЗАПИСЬ В ФАЙЛ===================\n";

	
	fileWrite(newfile);

	cout << "\n==========================ОТКРЫТИЕ И ЧТЕНИЕ ИЗ ФАЙЛА=================\n";

	fileRead(newfile);


	// Задание 1

	cout << "\n============================ЗАДАНИЕ 1===================================\n\n";
	cout << "Задание 1. Дан текстовый файл.Удалить из него последнюю строку.Результат записать в другой файл.\n\n";
	system("PAUSE");
	cout << "\n======================УЗНАЁМ КОЛИЧЕСТВО СТРОК===========================\n\n";

	int counteRows = 0;
	counteRows = fileRows(newfile);
	cout << "В файле следующее количество строк: " << counteRows << endl;
	cout << "\n================УДАЛИТЬ ПОСЛЕДНЮЮ СТРОКУ В ФАЙЛЕ========================\n\n";
	 
	fstream newfile2;
	deleteLastRow(newfile, newfile2, counteRows);
	 
	cout << "\n==================ОТКРЫТИЕ И ЧТЕНИЕ ИЗ ФАЙЛА============================\n\n";
	fileRead(newfile2);
	system("PAUSE");
	//Задание 2. 
	cout << "\n============================ЗАДАНИЕ 2===================================\n\n";
	cout << "Дан текстовый файл.Найти длину самой длинной строки.\n\n";
	system("PAUSE");
	cout << "\n========================ОТКРЫТИЕ НОВОГО ФАЙЛА===========================\n\n";

	fstream newfile3;
	fileWrite(newfile3);	

	cout << "\n====================УЗНАЁМ КОЛИЧЕСТВО СТРОК=============================\n\n";

	int counteRows1 = 0;
	counteRows1 = fileRows(newfile3);
	cout << "В файле следующее количество строк: " << counteRows1 << endl;
	
	cout << "\n===================УЗНАЁМ САМУЮ ДЛИННУЮ СТРОКУ==========================\n\n";

	fileLenRow(newfile3, counteRows1);
	system("PAUSE");
	//Задание 3. 
	cout << "\n============================ЗАДАНИЕ 3===================================\n\n";
	cout << "Дан текстовый файл.Посчитать сколько раз в нем встречается заданное пользователем слово.\n\n";
	system("PAUSE");
	cout << "\n=====================ОТКРЫТИЕ НОВОГО ФАЙЛА==============================\n\n";
	fstream newfile4;
	fileWrite(newfile4);
	cout << "\n================ПОИСК И ПОДСЧЁТ ЗАДАННОГО СЛОВА=========================\n\n";
	fileFindWord(newfile4);

	system("PAUSE");
	//Задание 4. 
	cout << "\n============================ЗАДАНИЕ 4===================================\n\n";
	cout << "Дан текстовый файл.Найти и заменить в нем заданное слово.\nЧто искать и на что заменять определяется пользователем.\n\n";
	system("PAUSE");
	cout << "\n======================ОТКРЫТИЕ НОВОГО ФАЙЛА=============================\n\n";
	fstream newfile5;
	fileWrite(newfile5);

	
	cout << "\n====================УЗНАЁМ КОЛИЧЕСТВО СТРОК=============================\n\n";
	int counteRows2 = 0;
	counteRows2 = fileRows(newfile5);

	cout << "\n================ПОИСК И ЗАМЕНА ЗАДАННОГО СЛОВА==========================\n\n";

	fileChangeWord(newfile5,counteRows2);
	cout << "\n======================ЧТЕНИЕ ИЗ ФАЙЛА=============================\n\n";
	fileRead(newfile5);
	system("PAUSE");
	
}
