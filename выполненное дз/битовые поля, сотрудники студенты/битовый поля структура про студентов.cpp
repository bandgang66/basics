#include <iostream>
#include <random>
#include <cstring>
#include <string>


using namespace std;

random_device Rand;
//структура студента
struct stud
{
	char FIO[20];

	unsigned int History : 1;
	unsigned int Math : 1;
	unsigned int Geography : 1;
	unsigned int Chemistry : 1;
	unsigned int Physics : 1;
	unsigned int Geometry : 1;
	unsigned int biology : 1;
	unsigned int drawing : 1;
	unsigned int sports : 1;
	unsigned int languages : 1;

};
//заполнение карточки студента
void Val(stud& newStud)
{
	newStud.History = 0;
	newStud.Math = 0;
	newStud.Geography = 0;
	newStud.Chemistry = 0;
	newStud.Physics = 0;
	newStud.Geometry = 0;
	newStud.biology = 0;
	newStud.drawing = 0;
	newStud.sports = 0;
	newStud.languages = 0;

	int tmp = 0;



	cout << "\nВведите фИО студента: ";

	getchar();

	cin.getline(newStud.FIO, 20);



	// 1
	cout << "Если получен зачёт по Истории то введите 1, если нет то 0: ";
	cin >> tmp;
	if (tmp == 1)
	{
		newStud.History = (~newStud.History);
	}
	//2
	cout << "Если получен зачёт по Математике то введите 1, если нет то 0: ";
	cin >> tmp;
	if (tmp == 1)
	{
		newStud.Math = (~newStud.Math);
	}
	//3
	cout << "Если получен зачёт по Географии то введите 1, если нет то 0: ";
	cin >> tmp;
	if (tmp == 1)
	{
		newStud.Geography = (~newStud.Geography);
	}
	//4
	cout << "Если получен зачёт по Химии то введите 1, если нет то 0: ";
	cin >> tmp;
	if (tmp == 1)
	{
		newStud.Chemistry = (~newStud.Chemistry);
	}
	//5
	cout << "Если получен зачёт по Физике то введите 1, если нет то 0: ";
	cin >> tmp;
	if (tmp == 1)
	{
		newStud.Physics = (~newStud.Physics);
	}
	//6
	cout << "Если получен зачёт по Геометрии то введите 1, если нет то 0: ";
	cin >> tmp;
	if (tmp == 1)
	{
		newStud.Geometry = (~newStud.Geometry);
	}
	//7
	cout << "Если получен зачёт по Биологии то введите 1, если нет то 0: ";
	cin >> tmp;
	if (tmp == 1)
	{
		newStud.biology = (~newStud.biology);
	}
	//8
	cout << "Если получен зачёт по Черчению то введите 1, если нет то 0: ";
	cin >> tmp;
	if (tmp == 1)
	{
		newStud.drawing = (~newStud.drawing);
	}
	//9
	cout << "Если получен зачёт по Физкультуре то введите 1, если нет то 0: ";
	cin >> tmp;
	if (tmp == 1)
	{
		newStud.sports = (~newStud.sports);
	}
	//10
	cout << "Если получен зачёт по Языкам то введите 1, если нет то 0: ";
	cin >> tmp;
	if (tmp == 1)
	{
		newStud.languages = (~newStud.languages);
	}

}
//вывод на экран карточки студента
void printVal(stud& newStud)
{
	cout << endl;
	cout << "ФИО студента: " << newStud.FIO << endl;

	//1
	if (newStud.History == 1)
		cout << "Зачет по Истории: Да " << endl;
	else
		cout << "Зачет по Истории: Нет " << endl;
	//2
	if (newStud.Math == 1)
		cout << "Зачет по Математике Да " << endl;
	else
		cout << "Зачет по Математике: Нет " << endl;
	//3
	if (newStud.Geography == 1)
		cout << "Зачет по Географии: Да " << endl;
	else
		cout << "Зачет по Географии: Нет " << endl;
	//4
	if (newStud.Physics == 1)
		cout << "Зачет по Физике: Да " << endl;
	else
		cout << "Зачет по Физике: Нет " << endl;
	//5
	if (newStud.Chemistry == 1)
		cout << "Зачет по Химии: Да " << endl;
	else
		cout << "Зачет по Химии: Нет " << endl;
	//6
	if (newStud.Geometry == 1)
		cout << "Зачет по Геометрии: Да " << endl;
	else
		cout << "Зачет по Геометрии: Нет " << endl;
	//7
	if (newStud.biology == 1)
		cout << "Зачет по Биологии: Да " << endl;
	else
		cout << "Зачет по Биологии: Нет " << endl;
	//8
	if (newStud.drawing == 1)
		cout << "Зачет по Черчению: Да " << endl;
	else
		cout << "Зачет по Черчению: Нет " << endl;
	//9
	if (newStud.sports == 1)
		cout << "Зачет по Физкультуре: Да " << endl;
	else
		cout << "Зачет по Физкультуре: Нет " << endl;
	//10
	if (newStud.languages == 1)
		cout << "Зачет по Языкам: Да " << endl;
	else
		cout << "Зачет по Языкам: Нет " << endl;

}
//расчет и вывод на экран среднего бала
double SredBal(stud& newStud)
{
	double srednee = 0;
	//1
	if (newStud.History > 0)
	{
		srednee++;
	}
	//2
	if (newStud.Math > 0)
	{
		srednee++;
	}
	//3
	if (newStud.Geography > 0)
	{
		srednee++;
	}
	//4
	if (newStud.Chemistry > 0)
	{
		srednee++;
	}
	//5
	if (newStud.Physics > 0)
	{
		srednee++;
	}
	//6
	if (newStud.Geometry > 0)
	{
		srednee++;
	}
	//7
	if (newStud.biology > 0)
	{
		srednee++;
	}
	//8
	if (newStud.drawing > 0)
	{
		srednee++;
	}
	//9
	if (newStud.sports > 0)
	{
		srednee++;
	}
	//10
	if (newStud.languages > 0)
	{
		srednee++;
	}






	return srednee / 10;




}
//добавить нового или внести изменения в список карточек студентов
void addStud(stud mass[], int pos)
{

	Val(mass[pos]);
}
//вывод на экран определенной карточки студента
void printStud(stud mass[], int pos)
{

	printVal(mass[pos]);
}
//заполнение всех карточек студентов
void valALLStud(stud mass[], int size)
{
	for (int i = 0; i < size; ++i)
	{
		cout << "\n=====" << i + 1 << "-ый Студент=====\n";
		Val(mass[i]);
	}
}
//вывод на экран всех карточек студентов
void printALLstud(stud mass[], int size)
{
	for (int i = 0; i < size; ++i)
	{
		cout << "\n=====" << i + 1 << "-ый Студент=====\n";
		printVal(mass[i]);
		cout << endl << endl;
	}
}
//вывод на экран должников (при условии 3х и более неуд'ов)
void doljniki(stud mass[],int size) 
{
	for (int i = 0; i < size; ++i) 
	{
		if (SredBal(mass[i]) < 0.8) 
		{
			cout << "\n=====" << i + 1 << "-ый Студент=====\n";
			cout << "\nДанный студент(ы) является должником:\n";
			printVal(mass[i]);
		}
		
	}
}
int main()
{
	setlocale(LC_ALL, "ru");

	// Задание 1 Реализуйте структуру, которая хранит ФИО студента и 10 битовых полей.
	// Каждое поле — это оценка (сдал / не сдал).
	// Создайте один экземпляр этой структуры и реализуйте для него следующие действия :
	// Заполнить структуру;
	// Вывод информации;
	// Печать среднего балла/

	// Создайте массив экземпляров этой структуры и реализуйте для него следующие действия :
	// Добавить студента;
	// Проставить оценки студенту;
	// Вывод списка студентов;
	// Печать оценок конкретного студента;
	// Печать должников.

	stud student;
	cout << "Размер структуры байт: ";
	cout << sizeof(student);
	cout << endl;
	cout << "\nЗаполните карточку студента: \n";
	Val(student);
	cout << "\n=======================Ведомость студента============================\n";
	printVal(student);

	cout << "\nСредний бал равен: " << SredBal(student) << endl;
	cout << "\n===================ЗАПОЛНИТЬ ВЕДОМОСТЬ СТУДЕНТОВ=======================\n";
	cout << "\nВведите количетсво студентов: ";

	int size;
	cin >> size;

	stud* mass = new stud[size];

	valALLStud(mass, size);

	cout << "\n=========================ВЕДОМОСТЬ СТУДЕНТОВ===========================\n";
	printALLstud(mass, size);


	cout << "\n==================КОРРЕКТИРОВКА ВЕДОМОСТИ СТУДЕНТОВ======================\n";

	int posit = 0;
	cout << "\nВведите порядковый номер  студента: ";
	cin >> posit;
	--posit;

	if (posit < size)
	{
		addStud(mass, posit);
		cout << endl << endl;
	}
	else
	{
		cout << "\nВведённая позиция выходит за рамки списка.\n";
	}

	cout << "\nИсправлено: \n";

	printStud(mass, posit);
	cout << "\n==================ВЫВОД СТУДЕНТОВ ДОЛЖНИКОВ(минимум 2 не сдачи)======================\n";
	doljniki(mass, size);


	delete[] mass;







}