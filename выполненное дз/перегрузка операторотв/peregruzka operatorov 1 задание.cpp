#include <iostream>
#include <random>
		




using namespace std;

random_device Rand;
//===========задание 1=================
class Array
{
	int size{};
	int* mass = nullptr;

public:

	Array() { cout << "\n================конструктор по умолчанию=====================\n"; };
	Array(int s) :size(s), mass(new int[s]) { cout << "\n=========конструктор динамическая память массива========\n"; };


	//функции
	void mass_Init();
	void mass_Show();
	//[]
	int operator[] (int i) const
	{
		if ((i - 1) < size)
		{
			return *(mass + (i - 1));
		}
		else
		{
			return 0;
		}
	}
	//()
	void operator() (int n) const
	{
		for (int i = 0; i < size; ++i)
		{
			*(mass + i) += n;
		}
	}
	//int()
	explicit operator int() const
	{
		int sum = 0;
		for (int i = 0; i < size; ++i)
		{
			sum += *(mass + i);
		}

		return sum;
	}
	//char()
	
	explicit operator char() 
	{
		for (int i = 0; i < size; ++i)
		{
			cout << char(mass[i]) << "";
		}
		return 0;
	}

	//диструктор
	~Array()
	{
		cout << "\n===================диструктор=================\n";

		delete[] mass;

	}
};
//инициализация
void Array::mass_Init()
{
	for (int i = 0; i < size; ++i)
	{
		*(mass + i) = Rand() % 99;
	}

}
//вывод
void Array::mass_Show()
{
	for (int i = 0; i < size; ++i)
	{
		cout << *(mass + i) << " ";
	}
	cout << endl;
}




int main()
{
	setlocale(LC_ALL, "ru");


	Array newMass(6);
	newMass.mass_Init();
	newMass.mass_Show();
	cout << newMass[5] << endl;
	cout << newMass[90] << endl;
	newMass(2);
	newMass.mass_Show();
	cout << int(newMass) << endl;
	cout << char(newMass) << endl;

}
