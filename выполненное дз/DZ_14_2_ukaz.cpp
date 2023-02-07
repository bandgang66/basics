#include <iostream>
#include <random>

using namespace std;

random_device Rand;

void end()
{
	cout << endl << endl;
}

//Задание 1
void dincreat(int*& mas, int& size);		//Функция распределения динамической памяти.
void InitMass(int*& mas, int& size);		//Функция инициализации динамического массива.
void ShowMass(int* mas, int& size);			//Функция печати динамического массива.
void dindelete(int*& mas, int& size);		//Функция удаления динамического массива.
void addLastElMass(int*& mas, int& size);	//Функция добавления элемента в конец массива.
void addIndElMass(int*& mas, int& size);	//Функция вставки элемента по указанному индексу.
void delElMass(int*& mas, int& size, int x);		//Функция удаления элемента по указанному индексу.

//задание 2
//простое число: 
bool prostoNum(int n);
void delProstNum(int*& mas, int& size);

//задание 3
void InitStatMass(int mas[], const int size);
void ShowStatMass(int mas[], const int size);

void rasp3Mass(int* mas, int size, int*& mass0, int*& massPlus, int*& massMinus, int& sizeP, int& sizeM, int& size0);

int main()
{
	setlocale(LC_ALL, "ru");


	//задание 1.

	cout << "\tЗадание № 1 :\n Написать следующие функции для работы с динамическим массивом :\n"
			"Функция распределения динамической памяти.\n"
			"Функция инициализации динамического массива.\n"
			"Функция печати динамического массива.\n"
			"Функция удаления динамического массива.\n"
			"Функция добавления элемента в конец массива.\n"
			"Функция вставки элемента по указанному индексу.\n"
			"Функция удаления элемента по указанному индексу.\n\n";
	system("Pause");
	cout << "\nРешение: \n\n";


	int size = 5;
	int* mass = new int[size];

	dincreat(mass, size);		//размер массива
	InitMass(mass, size);		//инициализация массива
	ShowMass(mass, size);		//вывод массива на экран
	end();

	addLastElMass(mass, size);	//добавление элементов в конец массива
	ShowMass(mass, size);		//вывод массива на экран
	end();

	addIndElMass(mass, size);	//замена элемента по индексу
	ShowMass(mass, size);
	end();

	int n;
	cout << "Введите номер  элемента массива  который хотите удалить: ";
	cin >> n;
	

	delElMass(mass, size, n);	    //удаление элемента по индесу
	ShowMass(mass, size);
	end();

	dindelete(mass, size);		//очистка памяти под массив
	if (mass == nullptr)
	{
		cout << "динамический массив удален";
	}
	else
		cout << "динамический массив не удален";
	system("Pause");

	//Задание 2: 
	cout << "\tЗадание № 2 :\n Написать функцию, которая получает указатель на динамичесий массив и его размер.\n" 
			"Функция должна удалить из массива все простые числа и вернуть указатель на новый динамический массив.\n\n";
	system("Pause");
	cout << "\nРешение: \n\n";

	int size2 = 5;
	int* mass2 = new int[size2];

	dincreat(mass2, size2);		//размер массива
	InitMass(mass2, size2);		//инициализация массива
	ShowMass(mass2, size2);		//вывод массива на экран
	end();

	delProstNum(mass2, size2);
	ShowMass(mass2, size2);
	end();
	dindelete(mass2, size2);		
		if (mass2 == nullptr)
		{
			cout << "динамический массив удален";
		}
		else
			cout << "динамический массив не удален";
	end();
	system("Pause");

	//задание 3: 
	cout << "\tЗадание № 3 :\n Написать функцию, которая получает указатьель на статический массив и его размер,"
			"функция распределяет, положительные, отрицательные и нулевые элементы в разные динамические массивы.\n\n";
	system("Pause");
	cout << "\nРешение: \n\n";

	const int size3 = 20;
	int mass3[size3];

	InitStatMass(mass3, size3);
	ShowStatMass(mass3, size3);
	end();
	int sizeP = 3;
	int sizeM = 3;
	int size0 = 3;
	int* mass0 = new int[size0];
	int* massPlus = new int[sizeP];
	int* massMinus = new int[sizeM];
	rasp3Mass(mass3, size3, mass0, massPlus, massMinus, sizeP, sizeM, size0);
	end();
	cout << "выявленые 0 в массиве: \n\n";
	ShowMass(mass0, size0);
	end();
	cout << "выявленые отрицательные числа в массиве: \n\n";
	ShowMass(massPlus, sizeP);
	end();
	cout << "выявленые положительные числа в массиве: \n\n";
	ShowMass(massMinus, sizeM);
	end();





}

void dincreat(int*& mas, int& size)
{
	cout << "введите размер массива: ";
	cin >> size;
	mas = new int[size];



}

void InitMass(int*& mas, int& size)
{

	for (int i = 0; i < size; ++i)
	{
		*(mas + i) = Rand() % 9;

	}

}

void ShowMass(int* mas, int& size)
{
	for (int i = 0; i < size; ++i)
	{
		cout << i + 1 << "-й элемент массива " << *(mas + i) << endl;
	}

}

void dindelete(int*& mas, int& size)
{
	mas = nullptr;
	delete[] mas;
}

void addLastElMass(int*& mas, int& size)
{
	int n = 0;
	cout << "Введите сколько элементов добавить в конец массива: ";
	cin >> n;
	size += n;

	for (int i = size - n; i < size; ++i)
	{
		*(mas + i) = Rand() % 9;
	}
}

void addIndElMass(int*& mas, int& size)
{
	int n;
	int a;
	cout << "Введите номер  элемента массива  который хотите поменять: ";
	cin >> n;
	cout << "\nВведите число которое хотите вставить: ";
	cin >> a;
	*(mas + (n - 1)) = a;



}

void delElMass(int*& mas, int& size, int x)
{

	--x;

	for (int i = 0; i < size; ++i)
	{
		if (i == x)
		{
			for (; x < size; ++x)
			{
				*(mas + x) = *(mas + (x + 1));
			}
			break;
		}
	}

	--size;
}

bool prostoNum(int n)
{
	if (n == 1)
		return true;
	if (n == 0)
		return false;
	int count = 0;
	for (int del = n; del >= 1; --del)
	{

		if (n % del == 0)
			++count;

	}

	if (count == 2)
	{
		int prosto = 0;
		prosto = n;
		return true;
	}
	else
		return false;
}

void delProstNum(int*& mas, int& size)
{


	int n = 0;
	int counter = 0;
	for (int i = 0; i < size; ++i)
	{
		if ((prostoNum(*(mas + i))) == true)
		{
			++counter;					//считаем сколько простых чисел

		}
	}

	for (int j = 0; j < counter; ++j)
	{
		for (int i = 0; i < size; ++i) //проходим по массиву до первого простого числа
		{
			if ((prostoNum(*(mas + i))) == true) //нашли первое простое число
			{
				n = i + 1;    //задали n индекс простого числа
				break;

			}
		}
		delElMass(mas, size, n);

	}


}

void InitStatMass(int mas[], const int size)
{
	for (int i = 0; i < size; ++i)
	{
		*(mas + i) = Rand() % 18 - 9;

	}
}

void ShowStatMass(int mas[], const int size)
{
	for (int i = 0; i < size; ++i)
	{
		cout << *(mas + i) << " ";

	}
}

void rasp3Mass(int* mas, int size, int*& mass0, int*& massPlus, int*& massMinus, int& sizeP, int& sizeM, int& size0)
{

	int size00 = 0;
	int sizePlus = 0;
	int sizeMinus = 0;

	for (int i = 0; i < size; ++i)
	{
		if (*(mas + i) > 0)
			++sizePlus;
		else if (*(mas + i) == 0)
			++size00;
		else if (*(mas + i) < 0)
			++sizeMinus;
	}

	size0 = size00;
	sizeP = sizePlus;
	sizeM = sizeMinus;
	mass0 = new int[size0];
	massPlus = new int[sizeP];
	massMinus = new int[sizeM];
	for (int i = 0, O = 0, P = 0, M = 0; i < size; ++i)
	{
		if (*(mas + i) > 0)
		{
			*(massPlus + P) = *(mas + i);
			++P;
		}
		else if (*(mas + i) == 0)
		{
			*(mass0 + O) = *(mas + i);
			++O;
		}
		else if (*(mas + i) < 0)
		{
			*(massMinus + M) = *(mas + i);
			++M;
		}
	}
}

