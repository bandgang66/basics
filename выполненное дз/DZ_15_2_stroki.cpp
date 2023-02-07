#include <iostream>
#include <cstring> //или <string.h>   файл где описаны функция для работы с си строками
#include <conio.h>
#include <string>

using namespace std;



void delIndSimb(char* str, int num);
void delManySimb(char* str, char simb);
void vstavkaIndSimb(char* str, int num, char simb);
void obmenTochVoskl(char* str, char simb);
int podschetSimbs(char* str, char simb);
void podschetVsego(char* str);


int main()
{
	setlocale(LC_ALL, "ru");

	//Задание 1
	cout << "\tЗадание № 1 :\n Написать функцию, которая удаляет из строки символ с заданным номером.\n\n";
	system("Pause");
	cout << "\nРешение: \n\n";

	char stroka1[7] = { "строка" };
	char* pstroka1 = stroka1;
	
	puts(stroka1);
	delIndSimb(pstroka1, 3);
	puts(stroka1);

	system("Pause");

	//Задание 2. 

	cout << "\tЗадание № 2 :\n Написать функцию, которая удаляет из строки все вхождения в нее заданного символа.\n\n";
	system("Pause");
	cout << "\nРешение: \n\n";
	char stroka2[25] = { "строка строки строчечки" };
	char* pstroka2 = stroka2;
	puts(stroka2);
	delManySimb(pstroka2, 'о');
	puts(stroka2);

	system("Pause");

	//Задание 3. 
	cout << "\tЗадание № 3 :\n Написать функцию, которая вставляет в строку в указанную позицию заданный символ.\n\n";
	system("Pause");
	cout << "\nРешение: \n\n";
	char stroka3[17] = { "что-то написанно" };
	char* pstroka3 = stroka3;
	puts(stroka3);
	vstavkaIndSimb(pstroka3, 4, '*');
	puts(stroka3);

	system("Pause");

	//Задание 4. 
	cout << "\tЗадание № 4 :\n Написать программу, которая заменяет все символы точки «.» в строке,\n"
			"введенной пользователем, на символы восклицательного знака «!».\n\n";
	system("Pause");
	cout << "\nРешение: \n\n";
	char stroka4[25] = { "точка.точки..точечки..." };
	char* pstroka4 = stroka4;
	puts(stroka4);
	obmenTochVoskl(pstroka4, '!');
	puts(stroka4);

	system("Pause");

	//Задание 5. 

	cout << "\tЗадание № 5 :\n Пользователь вводит строку символов и исокомый символ, посчитать сколько раз он встречается в строке.\n\n";
	system("Pause");

	char stroka5[100];
	gets_s(stroka5);

	puts(stroka5);

	cout << podschetSimbs(stroka5, 'j');

	system("Pause");

	//задание 6. 
	cout << "\tЗадание № 6 :\n Пользователь вводит строку. Определить количество букв,\n"
			"количество цифр и количество остальных  символов, присутствующих в строке.\n\n";
	system("Pause");

	char stroka6[100];

	gets_s(stroka6);

	puts(stroka6);

	podschetVsego(stroka6);



}

void delIndSimb(char* str, int num)
{
	--num;	//понижаем под работу с массивом

	int size = strlen(str) + 1;	// выясняем ддлину строки
	for (int i = 0, j = 0; i < size; ++i, ++j)	//идем по массиву 
	{
		if (i == num)	//пока не дойдем до нужного индекса
			++j;

		*(str + i) = *(str + j);	//сдвигаем
	}


}

void delManySimb(char* str, char simb)
{
	int size = strlen(str) + 1;	//длинна строки
	int counter = 0;		//сколкьо встретиться символов для удаления

	for (int i = 0; i < size; ++i)
	{
		if (*(str + i) == simb)
			++counter;				//сколкьо встретиться символов для удаления
	}

	for (int k = 0; k < counter; ++k)	//сколько раз удвалять
	{
		for (int poz = 0; poz < size; ++poz)		//идем пока не найдем символ
		{
			if (*(str + poz) == simb)				//находим символ
			{
				for (int i = 0, j = 0; i < size; ++i, ++j)  // сдвигаем 
				{
					if (i == poz)
						++j;

					*(str + i) = *(str + j);
				}
			}
		}
	}


}

void vstavkaIndSimb(char* str, int num, char simb)
{

	--num;

	int size = strlen(str) + 1;
	for (int i = 0; i < size; ++i)
	{
		if (i == num)
			*(str + i) = simb;
	}


}

void obmenTochVoskl(char* str, char simb)
{


	int size = strlen(str) + 1;
	for (int i = 0; i < size; ++i)
	{
		if (*(str + i) == '.')
			*(str + i) = simb;
	}

}

int podschetSimbs(char* str, char simb)
{
	int size = strlen(str) + 1;
	int counter = 0;

	for (int i = 0; i < size; ++i)
	{
		if (*(str + i) == simb)
			++counter;
	}
	return counter;
}

void podschetVsego(char* str)
{
	int numbers = 0;
	int engword = 0;
	int ENGword = 0;
	int rusword = 0;
	int RUSword = 0;
	int znak = 0;

	int size = strlen(str) + 1;

	for (int i = 0; i < size; ++i)
	{
		if (*(str + i) >= 33 && *(str + i) <= 47 || *(str + i) >= 58 && *(str + i) <= 64 || *(str + i) >= 91 && *(str + i) <= 96 || *(str + i) >= 123 && *(str + i) <= 127)
			++znak;
		else if (*(str + i) >= 48 && *(str + i) <= 57)
			++numbers;
		else if (*(str + i) >= 65 && *(str + i) <= 90)
			++ENGword;
		else if (*(str + i) >= 97 && *(str + i) <= 122)
			++engword;
		else if (*(str + i) >= 128 && *(str + i) <= 159 || *(str + i) == 240)
			++RUSword;
		else if (*(str + i) >= 160 && *(str + i) <= 175 || *(str + i) == 241)
			++RUSword;

	}

	cout << "Знаков:.................." << znak << endl;
	cout << "Английских заглавных:...." << ENGword << endl;
	cout << "Английских строчных:....." << engword << endl;
	cout << "Русских заглавных:......." << RUSword << endl;
	cout << "Русских строчных:........" << rusword << endl;
	cout << "Цифр:...................." << numbers << endl;

}
