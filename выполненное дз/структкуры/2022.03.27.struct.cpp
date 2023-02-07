#include <iostream>
#include <random>
#include <conio.h>
#include <cstring>// <string.h>
#include <string>
#include <fstream>
using namespace std;
random_device Rand;

struct table {
	int l;//4 б
	int w;//4
	int h;//4
	char color[20];//20
	char material[20];//20
	double weight;//8
};
//60
struct A {
	char y;
	int x;
	short z;
};

struct sklad {
	table Alltable[100];
	int count_now;

};
table create() {
	table Test;
	cout << "Enter color & material:";
	cin >> Test.color >> Test.material;
	cout << " Enter lxwxh:";
	cin >> Test.l >> Test.w >> Test.h;
	cout << "Enter weght:";
	cin >> Test.weight;
	return Test;
}

void printTable(table& t) {
	cout << "size:" << t.l << "x" << t.w << "x" << t.h << " weight:"
		<< t.weight << " color:" << t.color << " mat:" << t.material << endl;
}
struct man {
	char FIO[20] = "Ivanov Ivan";
	int height = 185;
	double weight = 70;
	bool sex = true;
	man* mother = nullptr;
	man* father = nullptr;
};

struct Data {
	int d, m, y;
};

struct book {
	char genre[20];
	char name[50];
	char author[30];
	int counter_lib;
	int counter_reader;
	Data* getter;
};

void print(const book& Tmp) {
	cout << Tmp.name << " auth:" << Tmp.author << " genre:" << Tmp.genre << endl;
}
void load(book& CurrentBook) {
	CurrentBook.getter = NULL;
	CurrentBook.counter_reader = 0;
	strcpy_s(CurrentBook.genre, 20, "Roman");
	string Names[] = { "Peace & War","Master & Margarita","Anna Karenina","We", "Tihij Don" };
	strcpy_s(CurrentBook.name, 50, Names[Rand() % 5].c_str());
	strcpy_s(CurrentBook.author, 30, "Bulgakov Michail");
	CurrentBook.counter_lib = Rand() % 10;
}

struct goods {
	char name[20];
	unsigned int price;
	unsigned short count;
};

void print(const goods& cur_g) {
	cout << "name:" << cur_g.name << " price:" << cur_g.price << " count:" 
		<< cur_g.count << endl;
}
void load(goods& next_val) {
	cin >> next_val.name >> next_val.count >> next_val.price;
}

int main() {
	/*char Str[] = "Hello! World!";
	cout << strlen(Str) << endl;
	strcpy_s(Str,14, "Goodbye");
	if (strcmp(Str, "Hello"))
		cout << "not equal\n";
	else
		cout << "=====";
	if (strchr(Str, ' '))
		cout << "find space\n";*/
		//table PCtable;
		//cout << sizeof(table) << endl;
		//cout << sizeof(A) << endl;
		//PCtable.weight = 5.14;
		//PCtable.l = 100, PCtable.w = 50, PCtable.h = 70;
		//strcpy_s(PCtable.color, 20, "blue");
		//strcpy_s(PCtable.material, 20, "wood");
		////cout << PCtable;
		//table KitchenTable{90,30,50,"black","metal",10.35};
		//printTable(PCtable);
		//printTable(KitchenTable);
		//string STR;
		//STR = "Hello!";//strcpy_s()
		//if (STR == "Goodbye") //strcmp()
		//	cout << "ravny";
		/*man Im;
		man MyFather{ "Ivanov Maxim",170,75,true,nullptr,
			new man{"Ivanov Daria",167,55,false,NULL,NULL}};
		Im.father = &MyFather;
		cout << Im.father->FIO << endl;
		man* MyMother = new man{ "Ivanova Marina",178,55,false,nullptr,nullptr };
		Im.mother = MyMother;*/
		//создать структуру Data содержаща€ день, мес€ц и год.
		//создать 2 функции: 1. «аполн€юща€ дату, 2 вывод€ща€ дату на экран

			//struct A {
			//	char y;
			//	int x;
			//	short z;
			//};
			//A value;
			//value.x = 1;
			//A* ptr = new A;
			//ptr->x = 1;
			//table NewT = create();

		//book* Library = new book[20];//
		//if (!Library) {
		//	return 0;
		//}
		//for (int i = 0; i < 20; ++i)
		//	load(Library[i]);
		//for (int i = 0; i < 20; ++i)
		//	print(Library[i]);
		////поиск книги макмимально вз€той на руки
		//cout << "max on reader:\n";
		//book maxReader = Library[0];
		//for (int i = 0; i < 20; ++i)
		//	if(maxReader.counter_reader<Library[i].counter_reader)
		//		maxReader = Library[i];
		//print(maxReader);
		////поиск по количеству книг в библиотеке
		//cout << "findeng book from count in library\b";
		//int counter = 5;
		//int i = 0;
		//for (  ; i < 20; ++i)
		//	if (Library[i].counter_lib == counter)
		//	{
		//		break;
		//	}
		//if (i < 20)
		//	print(Library[i]);
		//else
		//	cout << "not find\n";
		////сортировка по названию
		//cout << "after sorting\n";
		//for (int i = 0; i < 20; ++i) {
		//	for (int j = 0; j < 20 - 1 - i; ++j) {
		//		if (strcmp(Library[j].name, Library[j + 1].name) > 0)
		//			swap(Library[j], Library[j + 1]);
		//	}
		//}
		//for (int i = 0; i < 20; ++i)
		//	print(Library[i]);
		//FILE* file;

		//ofstream out_file("1.txt");//создание переменной св€занной с файлом и открытие этого файла
		////ofstream out_file;
		////out_file.open("C:/dir/1.txt");
		//if (!out_file.is_open()) {
		//	cout << "file not open\n";
		//}
		//else {
		//	out_file << "Hello! World!\nSomeText!";
		//	out_file.close();
		//}
		//out_file.open("1.html");
		//if (!out_file.is_open())
		//	return 0;
		//out_file << "<html><head/><body>Some Text. Hello!</body></html>";
		//out_file.close();
		//out_file.open("1.xls");
		//out_file << "1\t2\t3";
		//out_file.close();
	//int size;
	//int* arr = nullptr;
	//cout << "Enter size:";
	//cin >> size;
	//arr = new int[size] {};
	//for (int i = 0; i < size; ++i) {
	//	arr[i] = Rand() % 100;
	//	cout << arr[i] << endl;
	//}
	//char file_name[50];
	//cout << "Enter filename:";
	//cin >> file_name;
	//ofstream file(file_name);
	//if (file.is_open() == 0)
	//	return 0;
	//for (int i = 0; i < size; ++i) {
	//	file << arr[i] << " ";
	//}
	//file.close();
	//delete[]arr;
	//записать в файл, кроме всех чисел массива, размер и сумму всех чисел массива
	//чтение из файла
	//char file_name2[50];
	//cout << "Enter filename:";
	//cin >> file_name2;
	//ifstream from_file(file_name2);
	//if (!from_file.is_open())
	//{
	//	cout << "file " << file_name2 << " not open\n";
	//	return 0;
	//}
	////int x;
	////from_file >> x;
	////cout << "Read val:" << x << endl;
	////char buff[250] = {};
	////from_file.getline(buff, 250);
	////cout << "line: " << buff << endl;
	//for (;;) {
	//	int x;
	//	from_file >> x;
	//	if (from_file.eof() == true)
	//		break;
	//	cout << x << " ";
	//}
	//from_file.seekg(-1, ios::cur);
	////ios::end, ios::beg,ios::cur
	//from_file.seekg(0);//вернутьс€ в начало файла
	//from_file.close();
	//from_file.open(R"(C:\Users\t.student1\source\repos\ConsoleApplication5\ConsoleApplication5\2022.03.27.struct.cpp)");
	//if (from_file.is_open() == 0)
	//	return 0;
	//int counter_line = 0;
	//while (!from_file.eof()) {
	//	char buff[550] = {};
	//	from_file.getline(buff, 550);
	//	int len = strlen(buff);
	//	counter_line++;
	//	if (strstr(buff, "main") != nullptr) {
	//		cout << "find main on " << counter_line << " line\n";
	//	}
	//}
	//cout << "line in file:" << counter_line << endl;

	char DB_name[20] = "1.txt";
	goods* Sklad = nullptr;
	unsigned int size = 0;
	ifstream from(DB_name);
	if (!from.is_open())
		return 0;
	//по количеству строк определ€ем количество наименований на складе
	while (!from.eof()) {
		char tmp[200]{};
		from.getline(tmp, 200);
		size++;
	}
	from.seekg(0);//вернулись в начало
	Sklad = new goods[size];
	for (int i = 0; i < size; ++i)
		from >> Sklad[i].name >> Sklad[i].count >> Sklad[i].price;
	from.close();
	for (int i = 0; i < size; ++i)
		print(Sklad[i]);
	//1.найти товар с наибольшей стоимостью

	//2. отсортировать по количеству
	/*
	* for (int i = 0; i < size; ++i) {
	* for (int j = 0; j < size-1-i; ++j) {
	*  if(mas[j]<mas[j+1])
	*    swap(mas[j],mas[j+1]);
	* }
	*}
	*/
	//3. увеличить цену всех товаров на 30%

	//сохран€ем обратно в файл
	ofstream to(DB_name);
	for (int i = 0; i < size; ++i) {
		to << Sklad[i].name << " " << Sklad[i].count << " " << Sklad[i].price;
		if (i != size - 1)
			to << endl;
	}
}