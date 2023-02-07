#include <iostream>
#include <random>

using namespace std;
random_device Rand;

void end()
{
	cout << endl << endl;
}

void InitMass(int* mas, int size)
{
	for (int i = 0; i < size; ++i)
	{
		*(mas + i) = Rand() % 99;
	}
}
void ShowMass(int* mas, int size)
{
	for (int i = 0; i < size; ++i)
	{
		cout << *(mas + i) << " ";
	}
}
void CopyMass(int* mas, int* mas2, int size)
{
	for (int i = 0; i < size; ++i)
	{
		*(mas2 + i) = *(mas + i);
	}
}
void ReversMass(int* mas, int size)
{
	int* massRev = new int[size];

	for (int i = 0, j = size - 1; i < size; ++i, --j)
	{
		*(massRev + i) = *(mas + j);
	}
	CopyMass(massRev, mas, size);
}

int calc(int* x, int* y, char* z)
{

	if (*z == '+')
	{
		*x = *x + *y;
	}
	else if (*z == '-')
	{
		*x = *x - *y;
	}
	else if (*z == '*')
	{
		*x = *x * *y;
	}
	else if (*z == '/')
	{
		*x = *x / *y;
	}
	return *x;
}
int SumMass(int* mas, int size)
{
	int sum = 0;
	for (int i = 0; i < size; ++i)
	{
		sum += *(mas + i);
	}
	return sum;
}

int main()
{
	setlocale(LC_ALL, "ru");

	//Задание 1:

	system("Pause");
	cout << "\n\tЗадание 1.\n\n \tИспользуя два указателя на массив целых чисел, скопировать один массив в другой.\n"
			"Использовать в программе арифметику указателей для продвижения по массиву, а также\n"
			"оператор разыменования.\n\n";

	system("Pause");
	cout << "\n\tРешение:\n\n";


	const int size1 = 10;
	int* mass1 = new int[size1];
	int* mass2 = new int[size1];
	if (mass1 == nullptr || mass2 == nullptr)
	{
		cout << "memory take error!\n";
		return 0;
	}
	InitMass(mass1, size1);

	/*mass2 = mass1; */    //копируем указатель

	CopyMass(mass1, mass2, size1); //копируем значения

	cout << "первый массив: ";
	ShowMass(mass1, size1);
	cout << endl;
	cout << "второй массив: ";
	ShowMass(mass2, size1);
	delete[] mass1;
	delete[] mass2;

	end();





	//Задание 2:
	system("Pause");

	cout << "\n\tЗадание 2.\n\n \tИспользуя указатель на массив целых чисел, изменить порядок следования элементов массива\n"
			"на противоположный. Использовать в программе арифметику указателей для продвижения по массиву, а также\n"
			"оператор разыменования\n\n";

	system("Pause");
	cout << "\n\tРешение:\n\n";

	const int size2 = 20;
	int* mass3 = new int[size2];
	if (mass3 == nullptr)
	{
		cout << "memory take error!\n";
		return 0;
	}
	InitMass(mass3, size2);
	cout << "начальный массив: ";
	ShowMass(mass3, size2);
	cout << endl;
	ReversMass(mass3, size2);
	cout << "перевернутый массив: ";
	ShowMass(mass3, size2);
	delete[] mass3;
	end();

	//Задание 3:

	system("Pause");
	cout << "\n\tЗадание 3.\n\n \tИспользуя два указателя на массивы целых чисел, скопировать один массив в другой так, чтобы\n"
		"во втором массиве элементы находились в обратном порядке.\n"
		"Использовать в программе арифметику указателей для продвижения по массиву, а также\n"
		"оператор разыменования.\n\n";

	system("Pause");
	cout << "\n\tРешение:\n\n";


	const int size3 = 25;
	int* mass5 = new int[size3];
	int* mass6 = new int[size3];
	if (mass5 == nullptr || mass6 == nullptr)
	{
		cout << "memory take error!\n";
		return 0;
	}
	InitMass(mass5, size3);
	CopyMass(mass5, mass6, size3);
	ReversMass(mass6, size3);
	cout << "начальный массив: ";
	ShowMass(mass5, size3);
	cout << endl;
	cout << "перевернутый массив: ";
	ShowMass(mass6, size3);
	delete[] mass5;
	delete[] mass6;
	end();



	//Задание 4:
	//Используя указатели и оператор разыменования, определить наибольшее из двух чисел.
	system("Pause");

	cout << "\n\tЗадание 4.\n\n \tИспользуя указатели и оператор разыменования, определить наибольшее из двух чисел.\n\n";

	system("Pause");
	cout << "\n\tРешение:\n\n";

	int a;
	int b;
	cout << "введите число А: ";
	cin >> a;
	cout << endl;
	cout << "введите число B: ";
	cin >> b;
	int max = 0;
	int* pa = &a;
	int* pb = &b;
	cout << endl;
	*pa > * pb ? max = a : max = b;
	cout <<"наибольшее число: "<< max;

	end();

	//Задание 5:
	system("Pause");

	cout << "\n\tЗадание 5.\n\n\tИспользуя указатели и оператор разыменования,определить знак числа, введённого с клавиатуры.\n\n";

	system("Pause");
	cout << "\n\tРешение:\n\n";

	int a1;
	cout << "Введите число : ";
	cin >> a1;
	cout << endl;

	int* pa1 = &a1;

	if (*pa1 > 0)
		cout << "число положительное." << endl;
	else if (*pa1 < 0)
		cout << "число отрицательное." << endl;
	else
		cout << "Вы ввели ноль." << endl;

	end();


	//Задание 6:	
	system("Pause");

	cout << "\n\tЗадание 6.\n\n \tИспользуя указатели и оператор разыменования, обменять местами значения двух переменных.\n\n";

	system("Pause");
	cout << "\n\tРешение:\n\n";

	int x;
	int y;
	cout << "Введите число X: ";
	cin >> x;
	cout << endl;
	cout << "Введите число Y: ";
	cin >> y;
	cout << "X = " << x << endl;
	cout << "Y = " << y << endl;
	int* px = &x;
	int* py = &y;
	int tmp;
	tmp = *py;
	y = *px;
	x = tmp;
	cout << "Значения переменных поменяны местами: ";
	cout << endl;
	cout << "X = " << x << endl;
	cout << "Y = " << y << endl;
	end();
	//Задание 7:
	system("Pause");
	cout << "\n\tЗадание 7.\n\n \tНаписать примитивный калькулятор, пользуясь только указателями\n\n";

	system("Pause");
	cout << "\n\tРешение:\n\n";

	int x1, y1;
	char z1;
	cout << "введите первое число: ";
	cin >> x1;
	cout << endl;
	cout << "введите второе число: ";
	cin >> y1;
	cout << endl;
	cout << "Введите арифметический знак: ";
	cin >> z1;
	end();
	int* px1 = &x1;
	int* py1 = &y1;
	char* pz1 = &z1;
	cout << "ответ: " << calc(px1, py1, pz1);
	end();

	//Задание 8:
	system("Pause");
	cout << "\n\tЗадание 8.\n\n \tИспользуя указатель на массив целых чисел, посчитать сумму элементов массива.\n"
			"Использовать в программе арифметику указателей для продвижения по массиву, а также оператор разыменования.\n\n";

	system("Pause");
	cout << "\n\tРешение:\n\n";

	const int size = 15;
	int* mass8 = new int[size];
	InitMass(mass8, size);
	cout << "элементы массива: ";
	ShowMass(mass8, size);
	cout << endl;
	cout << "сумма всех элементов массива равна: " << SumMass(mass8, size);

	end();

}
