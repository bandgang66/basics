#include <iostream>
#include <cstring>
#include <conio.h>
#include <string>



using namespace std;

//----------------------------ЗАДАНИЕ 1--------------------------------
struct complex1
{
	double a;
	double b;

};
struct complex2
{
	double c;
	double d;

};

double summa(complex1 z1, complex2 z2,double i);
double raznost(complex1 z1, complex2 z2, double i);
double umnojenie(complex1 z1, complex2 z2, double i);
double delenie(complex1 z1, complex2 z2, double i);

//----------------------------ЗАДАНИЕ 2--------------------------------
struct koleso {
	int shirina;
	int visota;
	int radius;
};
struct car {

	char name[20];
	double dlina;
	double klirens;
	double dvigVol;
	double dvigPow;
	koleso razmerColeso;
	char color[20];
	char korobka[20];

};

void newCar(car* mashina);
void showCar(car* show);
void poiskCar(car* poisk);


int main()
{
	setlocale(LC_ALL, "ru");


	system("Pause");

	////задание 1 
	cout << "\n\tЗадание 1.\n\n Создайте структуру, описывающую комплексное число.\n"
			"Реализуйте арифметические операции с комплексными числами : сумму, разность, умножение, деление\n\n";
	system("Pause");
	cout << "\n\tРешение:\n\n";

	cout << "Z=A+Bi\n"
			"z-комплексное число\n"
			"А и B действительные числа\n"
			"i - мнимая единица i=корень из -1\n"
			"сложение  (a+b*i)+(c+d*i)=(a+c)+(b+d)*i\n"
			"вычитание (a+b*i)-(c+d*i)=(a-c)+(b-d)*i\n"
			"умножение (a+b*i)*(c+d*i)=(a*c-b*d)+(a*d+b*c)*i\n"
			"деление   (a+b*i)/(c+d*i)=((a*c-b*d)/(c*c+d*d))+((b*c-a*d)/(c*c+d*d))*i   if((c*c+d*d)!=0)\n";

	double i = sqrt(-1);
	cout << i << endl;
	complex1 num1 = { 4,6 };
	complex2 num2 = { 2,4 };
	cout << summa(num1, num2, i) << endl;
	cout << raznost(num1, num2, i) << endl;
	cout << umnojenie(num1, num2, i) << endl;
	cout << delenie(num1, num2, i) << endl;

		system("Pause");

	////задание 2 

	cout << "\n\tЗадание 2.\n\n Реализовать структуру «Автомобиль»(длина,\n"
		"клиренс(высота посадки), объем двигателя, мощность\n"
		"двигателя, диаметр колес, цвет, тип коробки передач).\n"
		"Создайте функции для задания значений, отображения\n"
		"значений, поиска значений.\n\n";
	system("Pause");
	cout << "\n\tРешение:\n\n";
	car* massCar = new car[3];

	cout << "==============================ИНИЦИАЛИЗАЦИЯ АВТОМОБИЛЕЙ=============================\n";
	for (int i = 0; i < 3; ++i)			//инициализация обьектов массива структуры
	{
		cout << "Введите данные " << i + 1 << "-го автомобиля: " << endl;
		newCar(massCar + i);
		cout << endl;
	}


	cout << endl;

	cout << "==============================ПОКАЗ АВТОМОБИЛЕЙ=============================\n";
	for (int i = 0; i < 3; ++i)			//вывод на экран обьектов массива структуры
	{
		cout << "Данные " << i + 1 << "-го автомобиля: " << endl;
		showCar(massCar + i);
		cout << endl;
	}

	cout << "==============================ПОИСК АВТОМОБИЛЯ=============================\n";

	int exit = 1;
	while (exit)
	{
		poiskCar(massCar);

		cout << "\nДля выхода введите 0, для повтора введите 1: ";
		cin >> exit;
	}

}

double summa(complex1 z1, complex2 z2,double i)
{

	double otvet = (z1.a + z2.c) + (z1.b + z2.d) * i;
	return otvet;
}

double raznost(complex1 z1, complex2 z2, double i)
{
	double otvet = (z1.a - z2.c) + (z1.b - z2.d) * i;
	return otvet;
}

double umnojenie(complex1 z1, complex2 z2, double i)
{
	double otvet = (z1.a * z2.c - z1.b * z2.d) + (z1.a * z2.d + z1.b * z2.c) * i;
	return otvet;
}

double delenie(complex1 z1, complex2 z2, double i)
{
	double otvet = 0;
	if ((z2.c * z2.c + z2.d * z2.d) != 0) 
	{
		otvet = ((z1.a * z2.c - z1.b * z2.d) / (z2.c * z2.c + z2.d * z2.d)) + ((z1.b * z2.c - z1.a * z2.d) / (z2.c * z2.c + z2.d * z2.d)) * i;
		return otvet;
	}
	else
	{
		return 0;
	}
	
}

void newCar(car* mashina)
{

	cout << "\nВведите марку автомобиля: ";
	cin >> mashina->name;

	cout << "\nВведите длинну автомобиля в метрах: ";
	cin >> mashina->dlina;

	cout << "\nВведите клиренс в сантиметрах: ";
	cin >> mashina->klirens;

	cout << "\nВведите обьем двигателя (литров): ";
	cin >> mashina->dvigVol;

	cout << "\nВведите мощность двигателя(л.с.): ";
	cin >> mashina->dvigPow;

	cout << "\nВведите ширину протектора колес: ";
	cin >> mashina->razmerColeso.shirina;

	cout << "\nВведите высоту профиля колес: ";
	cin >> mashina->razmerColeso.visota;

	cout << "\nВведите посадочный диаметр покрышки: ";
	cin >> mashina->razmerColeso.radius;

	cout << "\nВведите цвет машины: ";
	cin >> mashina->color;

	cout << "\nВведиет тип коробки передач: ";
	cin >> mashina->korobka;


}

void showCar(car* show)
{
	cout << "Марка автомобиля: " << show->name << endl;
	cout << "Длинна автомобиля: " << show->dlina << " метра. " << endl;
	cout << "Клиренс автомобиля: " << show->klirens << " см. " << endl;
	cout << "Обьем двигателя автомобиля: " << show->dvigVol << " литра. " << endl;
	cout << "Обьем мощность автомобиля: " << show->dvigPow << " л.с. " << endl;
	cout << "Размерность колес: " << show->razmerColeso.shirina << "/" << show->razmerColeso.visota << "/" << show->razmerColeso.radius << endl;
	cout << "Цвет машины: " << show->color << endl;
	cout << "Тип коробки передач: " << show->korobka << endl;


}

void poiskCar(car* poisk)
{
	cout << "\nдля поска по названию, введите........................1\n";
	cout << "\nдля поска по цвету, введите...........................2\n";
	cout << "\nдля поска по типу коробки передач, введите............3\n";
	cout << "\nдля поска по мощности двигателя (л.с.), введите.......4\n";




	int vibor = 0;
	cout << "\nВведите свой выбор: ";
	cin >> vibor;
	char poisk1[20];
	int poisk2;




	switch (vibor)
	{

	case 1:

		cout << "Введите марку автомобиля: ";
		cin >> poisk1;
		for (int i = 0; i < 3; ++i)
		{
			if (strstr((poisk + i)->name, poisk1))
			{
				cout << "Ваш автомобиль под номером : " << i + 1 << endl;
			}
		}
		break;

	case 2:
		cout << "Введите цвет автомобиля: ";
		cin >> poisk1;
		for (int i = 0; i < 3; ++i)
		{
			if (strstr((poisk + i)->color, poisk1))
			{
				cout << "Ваш автомобиль под номером : " << i + 1 << endl;
			}
		}
		break;

	case 3:
		cout << "Введите тип каробки автомобиля: ";
		cin >> poisk1;
		for (int i = 0; i < 3; ++i)
		{
			if (strstr((poisk + i)->korobka, poisk1))
			{
				cout << "Ваш автомобиль под номером : " << i + 1 << endl;
			}
		}
		break;

	case 4:
		cout << "Введите мощность авто (л.с.) автомобиля: ";
		cin >> poisk2;
		for (int i = 0; i < 3; ++i)
		{
			if ((poisk + i)->dvigPow == poisk2)
			{
				cout << "Ваш автомобиль под номером : " << i + 1 << endl;

			}
		}
		break;

	}




}


