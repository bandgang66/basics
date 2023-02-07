#include <iostream>
#include <string>

using namespace std;


class Employer 
{
protected:
	
	string name{};
	string charge{};
	int age{};
	int salary{};
public:
	Employer() {}
	Employer(string NAME, string CHARGE, int AGE, int SALARY) :name(NAME), charge(CHARGE), age(AGE), salary(SALARY) {}

	virtual	void print() = 0;
};

class President :public Employer 
{
public:
	President() :Employer() {}
	President(string Name, string Charge, int Age, int Salary) :Employer(Name,Charge,Age,Salary) {}

	void print() override 
	{
		cout << "ФИО: " << name << endl;
		cout << "Возраст: " << age << endl;
		cout << "Обязанности: " << charge << endl;
		cout << "Зарплата: " << salary << endl;
	}

	
};

class Manager :public Employer 
{
public:
	Manager() :Employer() {}
	Manager(string Name, string Charge, int Age, int Salary) :Employer(Name, Charge, Age, Salary) {}

	void print() override
	{
		cout << "ФИО: " << name << endl;
		cout << "Возраст: " << age << endl;
		cout << "Обязанности: " << charge << endl;
		cout << "Зарплата: " << salary << endl;
	}
};

class Worker :public Employer 
{
public:
	Worker() :Employer() {}
	Worker(string Name, string Charge, int Age, int Salary) :Employer(Name, Charge, Age, Salary) {}

	void print() override
	{
		cout << "ФИО: " << name << endl;
		cout << "Возраст: " << age << endl;
		cout << "Обязанности: " << charge << endl;
		cout << "Зарплата: " << salary << endl;
	}
};

int main()
{
	setlocale(LC_ALL, "ru");


	string namePresident = "Романов Дмитрий Евгеньевич";
	string nameManager = "Иванов Иван Степанович";
	string nameWorker = "Сидоров Сидр Сидорович";

	string charge_President = "Повеливать";
	string charge_Manager = "Промышлять";
	string charge_Worker = "Вкалывать";

	int age_president = 32;
	int age_manager = 30;
	int age_worker = 25;

	int salary_president = 100000;
	int salary_manager = 75000;
	int salary_worker = 50000;




	//President
	President newPresident(namePresident, charge_President, age_president, salary_president);
	newPresident.print();
	cout << endl;

	//Manager
	Manager newManager(nameManager, charge_Manager, age_manager, salary_manager);
	newManager.print();
	cout << endl;

	//Worker
	Worker newWorker(nameWorker, charge_Worker, age_worker, salary_worker);
	newWorker.print();
	cout << endl;
	





}
//Задание 3
//Создать абстрактный базовый класс Employer(служащий) с чисто виртуальной функцией Print().
// 
//Создайте три производных класса :
// 
//President
//Manager
//Worker
// 
//Переопределите функцию Print() для вывода информации, соответствующей каждому типу служащего.