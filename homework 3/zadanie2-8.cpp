#include <iostream>

using namespace std;

int main()
{
	system("Pause");

	setlocale(LC_ALL, "rus");
	//задание 2
	cout << "\n\tЗадание 2.\n\n \tПодсчитать количество целых чисел в диапазоне от 100 до 999\n"
		"у которых есть две"
		"одинаковые цифры.\n\n";

	system("Pause");

	cout << "\n\tРешение:\n\n";

	int a = 100;
	int b = 999;
	int S100, S10, S1, sum, n;
	for (a; a <= b; a++)
	{
		n = a;
		S1 = n % 10;
		n = n / 10;
		S10 = n % 10;
		n = n / 10;
		S100 = n % 10;
		if ((S1 == S10 || S1 == S100 || S10 == S100) && (!(S1 == S10 && S10 == S100)))
		{
			sum = S100 * 100 + S10 * 10 + S1;
			cout << sum << endl;
		}
	}
	system("Pause");
	//задание 3
	cout << "\n\tЗадание 3.\n\n \tПодсчитать количество целых чисел в диапазоне от 100 до 999\n"
		"у которых все цифры разные \n\n";

	system("Pause");

	cout << "\n\tРешение:\n\n";

	int A = 100;
	int B = 999;
	int s100, s10, s1, newA, oper;
	for (A; A <= B; A++)
	{
		oper = A;
		s1 = oper % 10;
		oper = oper / 10;
		s10 = oper % 10;
		oper = oper / 10;
		s100 = oper % 10;
		if (s1 != s10 && s1 != s100 && s10 != s100)
		{
			newA = s100 * 100 + s10 * 10 + s1;
			cout << newA << endl;
		}
	}

	system("Pause");

	//задание 4

	cout << "\n\tЗадание 4.\n\n \tПользователь вводит любое целое число.\n"
		"Необходимо из этого целого числа удалить все цифры 3 и 6\n"
		"и вывести обратно на экран \n\n";

	system("Pause");

	cout << "\n\tРешение:\n\n";


	int chislo, cifra, razryad, sborka, mnojitel;
	cout << "Введите число, программа удалит из них цифры 3 и 6.\n";
	cin >> chislo;
	mnojitel = 1;
	sborka = 0;
	razryad = 0;

	while (chislo > 0)
	{
		cifra = chislo % 10;
		if (cifra != 3 && cifra != 6)
		{
			razryad = cifra * mnojitel;
			sborka += razryad;
			mnojitel *= 10;
		}

		chislo /= 10;


	}
	cout << sborka << endl;

	system("Pause");

	//Задание 5

	cout << "\n\tЗадание 5.\n\n \tПользователь вводит любое целое число А.\n"
		"Необходимо вывести все целые числа В, для которых А: \n"
		"делиться без остатка на В * В и не делиться без остатка на В * В * В \n\n";

	system("Pause");

	cout << "\n\tРешение:\n\n";



	int numberA, numberB;
	cout << "Введите число A: \n";
	cin >> numberA;
	numberB = 1;
	while (numberB < numberA)
	{
		if ((numberA % (numberB * numberB) == 0) && (numberA % (numberB * numberB * numberB) != 0))
		{
			cout << numberB << endl;
		}
		numberB++;
	}

	system("Pause");

	//задание № 6

	cout << "\n\tЗадание 6.\n\n \tПользователь вводит целое число А. \n"
		"Программа должна определить, что куб суммы цифр этого числа равен А * А \n\n";

	system("Pause");

	cout << "\n\tРешение:\n\n";

	int A1, a1, sum1, ost1;
	cout << "Введите число А\n\n";
	cin >> A1;
	sum1 = 0;
	a1 = A1;
	for (A1; A1 > 0; A1 /= 10)
	{
		ost1 = A1 % 10;
		sum1 += ost1;

	}
	if (sum1 * sum1 * sum1 == a1 * a1)
	{
		cout << "куб суммы цифр введеного числа равен квадрату этого числа " << sum1 * sum1 * sum1 << " = " << a1 * a1 << endl;
	}
	else
		cout << "Условия не выполняются\n";

	system("Pause");

	//Задание № 7 

	cout << "\n\tЗадание 7.\n\n \tПользователь вводит целое число.\n "
		"Необходимо вывести все целые числа, на которое заданное число делиться без остатка \n\n";

	system("Pause");

	cout << "\n\tРешение:\n\n";

	int A2, B2;
	cout << "Введите число: \n";
	cin >> A2;
	for (B2 = 1; B2 < A2; B2++)
	{
		if (A2 % B2 == 0)
		{
			cout << B2 << "\n\n";
		}
	}

	system("Pause");

	//Задание № 8

	cout << "\n\tЗадание 8.\n\n \tПользователь вводит два целых числа. \n "
		" Необходимо вывести все целые числа, на которые оба введенных числа делятся без остатка \n\n";

	system("Pause");

	cout << "\n\tРешение:\n\n";


	int A3, B3, C3;
	cout << "введите первое число: \n";
	cin >> A3;
	cout << "введите второе число: \n";
	cin >> B3;
	C3 = 1;

	for (C3; C3 < A3 && C3 < B3; C3++)
	{
		if (A3 % C3 == 0 && B3 % C3 == 0)
		{
			cout <<"\n" << C3 << endl;
		}
	}

	system("Pause");
}
    