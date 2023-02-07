//#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include <cstdio>


using namespace std;
//Задание 1
union zadanie_1
{
	int num;
	unsigned char bytes[4];
};
//показать число засунуть его в обьядинение
void showNum(zadanie_1& poko, int a)
{
	poko.num = a;
	cout << "ваше число a1: " << a << ", В обьединении poko.num: " << poko.num << endl;

}
//разбить на байты и показать
void showbytes(zadanie_1& poko)
{
	for (int i = 3; i >= 0; --i) {
		cout << (int)poko.bytes[i] << " " << i + 1 << " - байт " << endl;
	}
}
//посмотреть выбранный байт числа
void showViborbyte(zadanie_1& poko)
{
	unsigned int a;
	cout << "\nВведите номер байта который хотите посмотреть: ";
	cin >> a;

	unsigned int nums = 1;

	cout << (int)poko.bytes[a - 1] << " , " << a << " - байт " << endl;

	if (a == 1)
	{
		cout << "В " << a << "-байте, хранится число: " << ((int)poko.bytes[a - 1]) << endl;
	}
	else
	{
		for (unsigned int i = 0; i < a - 1; ++i)
		{
			nums *= 256;
		}
		cout << "В " << a << "-байте, хранится число: " << nums * ((int)poko.bytes[a - 1]) << endl;
	}
}
//просмотр в 8-ричной СС
void showbytes_okt(zadanie_1& poko)
{
	for (int i = 3; i >= 0; --i) {
		cout << oct << (int)poko.bytes[i];
		cout << " " << i + 1 << " - байт " << endl;
	}
}
//просмотр в 16-ричной СС
void showbytes_hex(zadanie_1& poko)
{
	for (int i = 3; i >= 0; --i) {
		cout << hex << (int)poko.bytes[i];
		cout << " " << i + 1 << " - байт " << endl;
	}
}


//Задание 2
union zadanie_2
{
	bool znak;
	int num;
	unsigned char bytes[4];

};

//показать число засунуть его в обьединение
void showNum_2(zadanie_2& poko, int a)
{
	if (a < 0)
	{
		a *= -1;
		poko.znak = 0;
	}
	else
		poko.znak = 1;

	poko.num = a;
	cout << "ваше число a1: " << a << ", В обьединении poko.num: " << poko.num << endl;
}

//разбить на байты и показать
void showbytes_2(zadanie_2& polo)
{

	for (int i = 3; i >= 0; --i) {
		cout << (int)polo.bytes[i] << " " << i + 1 << " - байт " << endl;
	}
}

//Задание 3
union zadanie_3
{
	int nums;
	bool logic[4];
};
//показать число засунуть его в обьединение
void showNum_3(zadanie_3& poko, int a)
{


	poko.nums = a;
	cout << "ваше число a1: " << a << ", В обьединении poko.num: " << poko.nums << endl;
}
//показать по байтово
void showbytes_3(zadanie_3& poko, int a)
{
	int count = 0;
	for (int i = 3; i >= 0; --i)
	{
		if ((bool)poko.logic[i] == 0)
		{
			cout << i + 1 << " -байт нулевой" << endl;
			count++;
		}
		else
		{
			cout << i + 1 << " -байт НЕ нулевой" << endl;
		}
		cout << (int)poko.logic[i] << " " << i + 1 << " - байт " << endl;
	}
	cout << count << " - нулевых байтов в числе:" << a << endl;
}

int main()
{
	setlocale(LC_ALL, "ru");
	//Задание 1. Создайте объединение, состоящее из целого
	//	числа и массива символов.
	//	Напишите следующие функции :
	//■ Ввести целое число;
	//■ Просмотреть все байты числа;
	//■ Просмотреть выбранный байт числа;
	//■ Вывод байтов числа в двоичном и шестнадцатеричном виде.

	//задание 1

	zadanie_1 poko;
	int a1;
	cout << "введите число, оно будет передано в обьект poko обьединения zadanie_1: \n";
	cin >> a1;

	showNum(poko,a1);

	showbytes(poko);

	showViborbyte(poko);
	cout << "=======16-ая СС=========" << endl;
	showbytes_hex(poko);
	cout << "========8-ая СС========" << endl;
	showbytes_okt(poko);

	//задание 2


		//	Задание 2. Реализовать 4 - х байтовую целую переменную,
	//	к которой можно обращаться и как к знаковому целому,
	//	и как беззнаковому целому, без явного преобразования
	//	типов.Для этого используйте объединение.


	zadanie_2 polo;
	int a2;
	cout << "введите ОТРИЦАТЕЛЬНОЕ  число, оно будет передано в обьект poko обьединения zadanie_2: \n";
	cin >> a2;

	showNum_2(polo, a2);

	showbytes_2(polo);



	//Задание 3. 
	//	Задание 3. Создайте объединение, состоящее из целого
	//	числа и массива логических переменных.Напишите следующие функции :
	//■ Ввести целое число;
	//■ Посчитать сколько нулевых байтов у числа;
	//■ Вывод информации о байтах числа(нулевой, не нулевой)

	zadanie_3 poro;
	int a3;
	cout << "введите число, оно будет передано в обьект poro обьединения zadanie_3: \n";
	cin >> a3;

	showNum_3(poro, a3);

	showbytes_3(poro, a3);





}