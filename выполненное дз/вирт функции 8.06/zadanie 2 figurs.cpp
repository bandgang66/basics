#include <iostream>
#include <random>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

random_device Rand;

string name_file1 = "figures.txt";
string name_file2 = "figures2.txt";

class coords
{
public:
	float coord_x{};
	float coord_y{};

	void set_coords_rand()
	{
		coord_x = Rand() % 9;
		coord_y = Rand() % 9;
	}
	void set_coords_val(float x, float y) { coord_x = x, coord_y = y; }
	void get_coords()
	{
		cout << "(" << coord_x << "," << coord_y << ")" << endl;
	}
};

class shape
{
protected:
	coords center{};
	coords* arr_coords = nullptr; //массив координат
	int size{};	//для квадрата или для прямоугольник 4 кординаты, для круга 1(центр)
	float len_a{};	//сторона А или радиус
	float len_b{};	//сторона Б для прямоугольника
public:
	//конструкторы
	shape() {};
	shape(coords A, float a, int SIZE)		//квадрат
	{
		size = SIZE;
		arr_coords = new coords[size];
		arr_coords[0] = A;
		len_a = a;
	}
	shape(coords A, float a, float b, int SIZE)	//прямоугольник
	{
		size = SIZE;
		arr_coords = new coords[4];
		arr_coords[0] = A;
		len_a = a;
		len_b = b;
	}
	shape(coords A, float a) //круг
	{
		center = A;
		len_a = a;
	}


	//виртуальные функции
	virtual void data() { cout << "DATA абстрактный класс\n"; }

	virtual void show()
	{
		cout << "абстрактный обьект: \n";
		cout << "координаты точки А: ";
		arr_coords[0].get_coords();
		cout << "длинна стороны a : " << len_a << endl;

	}
	virtual void save(string name)
	{
		
		fstream file;


		file.open(name, ios::app);

		if (!file.is_open())
		{
			cout << "Файл не открылся" << endl;
		}
		else
		{

			file << "+\n";
			file << "абстрактный  обьект: \n";
			file << "координаты точки А: ";
			file << "(" << arr_coords[0].coord_x << "," << arr_coords[0].coord_y << ")\n";
			file << "длинна стороны a : " << len_a << endl;
			file << "." << endl;
			file << endl;

		}

		file.close();
	};

	virtual void load(string name)
	{
		fstream file;

		file.open(name, ios::in | ios::out);

		if (!file.is_open())
		{
			cout << "Файл не открылся" << endl;
		}
		else
		{
			string buff1 = "";
			string buff2 = "";
			string simb = "+";
			int poz = 0;
			int i = 0;


			while (!file.eof())
			{
				getline(file, buff1);
				if (buff1 == simb)
				{
					while (buff2.find(".") == string::npos)
					{
						getline(file, buff2);

						if (buff2.find(".") != string::npos)
							break;

						cout << buff2<<"\n";
					}
				}
			}
		}
		file.close();
	}
};

class Square :public shape
{
public:
	Square() :shape() {}
	Square(coords A, float a, float s = 4) :shape(A, a, s) {}

	void data() override
	{
		//точка B
		//ось x
		arr_coords[1].coord_x = arr_coords[0].coord_x + len_a;
		//оcь y
		arr_coords[1].coord_y = arr_coords[0].coord_y;

		//точка C
		//ось x
		arr_coords[2].coord_x = arr_coords[0].coord_x + len_a;
		//оcь y
		arr_coords[2].coord_y = arr_coords[0].coord_y - len_a;

		//точка D
		//ось x
		arr_coords[3].coord_x = arr_coords[0].coord_x;
		//оcь y
		arr_coords[3].coord_y = arr_coords[0].coord_y - len_a;
	}

	void show() override
	{
		cout << "данные квадрата: " << endl;
		cout << "координаты точки А: ";
		arr_coords[0].get_coords();
		cout << "координаты точки B: ";
		arr_coords[1].get_coords();
		cout << "координаты точки C: ";
		arr_coords[2].get_coords();
		cout << "координаты точки D: ";
		arr_coords[3].get_coords();
		cout << "длинна стороны a : " << len_a << endl;
	}
	void save(string name) override
	{
		fstream file;


		file.open(name, ios::app);

		if (!file.is_open())
		{
			cout << "Файл не открылся" << endl;
		}
		else
		{
			file << "-\n";
			file << "данные квадрата: " << endl;
			file << "координаты точки А: ";
			file << "(" << arr_coords[0].coord_x << "," << arr_coords[0].coord_y << ")\n";
			file << "координаты точки B: ";
			file << "(" << arr_coords[1].coord_x << "," << arr_coords[1].coord_y << ")\n";
			file << "координаты точки C: ";
			file << "(" << arr_coords[2].coord_x << "," << arr_coords[2].coord_y << ")\n";
			file << "координаты точки D: ";
			file << "(" << arr_coords[3].coord_x << "," << arr_coords[3].coord_y << ")\n";
			file << "длинна стороны a : " << len_a << endl;
			file << "." << endl;
			file << endl;

		}

		file.close();
	};

	void load(string name) override
	{
		fstream file;

		file.open(name, ios::in | ios::out);

		if (!file.is_open())
		{
			cout << "Файл не открылся" << endl;
		}
		else
		{
			string buff1 = "";
			string buff2 = "";
			string simb = "-";
			int poz = 0;
			int i = 0;


			while (!file.eof())
			{
				getline(file, buff1);
				if (buff1 == simb)
				{
					while (buff2.find(".") == string::npos)
					{
						getline(file, buff2);

						if (buff2.find(".") != string::npos)
							break;

						cout << buff2 << "\n";
					}
				}
			}
		}
		file.close();
	}
};

class Rectangle :public shape
{
public:
	Rectangle() :shape() {}
	Rectangle(coords A, float a, float b, float s = 4) :shape(A, a, b, s) {}

	void data()
	{
		//точка B
		//ось x
		arr_coords[1].coord_x = arr_coords[0].coord_x + len_a;
		//оcь y
		arr_coords[1].coord_y = arr_coords[0].coord_y;

		//точка C
		//ось x
		arr_coords[2].coord_x = arr_coords[0].coord_x + len_a;
		//оcь y
		arr_coords[2].coord_y = arr_coords[0].coord_y - len_b;

		//точка D
		//ось x
		arr_coords[3].coord_x = arr_coords[0].coord_x;
		//оcь y
		arr_coords[3].coord_y = arr_coords[0].coord_y - len_b;
	}

	void show() override
	{
		cout << "данные прямоугольника: " << endl;
		cout << "координаты точки А: ";
		arr_coords[0].get_coords();
		cout << "координаты точки B: ";
		arr_coords[1].get_coords();
		cout << "координаты точки C: ";
		arr_coords[2].get_coords();
		cout << "координаты точки D: ";
		arr_coords[3].get_coords();
		cout << "длинна стороны a : " << len_a << endl;
		cout << "длинаа стороны b : " << len_b << endl;
	}
	void save(string name) override
	{
		fstream file;


		file.open(name, ios::app);

		if (!file.is_open())
		{
			cout << "Файл не открылся" << endl;
		}
		else
		{
			file << "*\n";
			file << "данные прямоугольника: " << endl;
			file << "координаты точки А: ";
			file << "(" << arr_coords[0].coord_x << "," << arr_coords[0].coord_y << ")\n";
			file << "координаты точки B: ";
			file << "(" << arr_coords[1].coord_x << "," << arr_coords[1].coord_y << ")\n";
			file << "координаты точки C: ";
			file << "(" << arr_coords[2].coord_x << "," << arr_coords[2].coord_y << ")\n";
			file << "координаты точки D: ";
			file << "(" << arr_coords[3].coord_x << "," << arr_coords[3].coord_y << ")\n";
			file << "длинна стороны a : " << len_a << endl;
			file << "длинна стороны b : " << len_b << endl;
			file << "." << endl;
			file << endl;

		}

		file.close();
	};

	void load(string name) override
	{
		fstream file;

		file.open(name, ios::in | ios::out);

		if (!file.is_open())
		{
			cout << "Файл не открылся" << endl;
		}
		else
		{
			string buff1 = "";
			string buff2 = "";
			string simb = "*";
			int poz = 0;
			int i = 0;


			while (!file.eof())
			{
				getline(file, buff1);
				if (buff1 == simb)
				{
					while (buff2.find(".") == string::npos)
					{
						getline(file, buff2);

						if (buff2.find(".") != string::npos)
							break;

						cout << buff2 << "\n";
					}
				}
			}
		}
		file.close();
	}

};

class Circle :public shape
{
private:
	coords point{};

public:
	Circle() :shape() {}
	Circle(coords A, float r) :shape(A, r) {}

	void data()
	{
		point.coord_x = center.coord_x + len_a * 2;
		point.coord_y = center.coord_y + len_a * 0.7;
	}

	void show() override
	{
		cout << "данные круга: " << endl;
		cout << "координаты точки центра окружности: ";
		center.get_coords();
		cout << "координаты точки на окружности учитывая угол 45 градусов, равны: ";
		point.get_coords();

		cout << "радиус равен : " << len_a << endl;
	}

	void save(string name) override
	{
		fstream file;


		file.open(name, ios::app);

		if (!file.is_open())
		{
			cout << "Файл не открылся" << endl;
		}
		else
		{
			file << "/\n";
			file << "данные круга: " << endl;
			file << "координаты точки центра окружности: ";
			file << "(" << center.coord_x << "," << center.coord_y << ")\n";
			file << "радиус равен : " << len_a << endl;
			file << "координаты точки на окружности учитывая угол 45 градусов, равны:  ";
			file << "(" << point.coord_x << "," << point.coord_y << ")\n";
			file << "." << endl;
			file << endl;

		}

		file.close();
	};


	void load(string name) override
	{
		fstream file;

		file.open(name, ios::in | ios::out);

		if (!file.is_open())
		{
			cout << "Файл не открылся" << endl;
		}
		else
		{
			string buff1 = "";
			string buff2 = "";
			string simb = "/";
			int poz = 0;
			int i = 0;


			while (!file.eof())
			{
				getline(file, buff1);
				if (buff1 == simb)
				{
					while (buff2.find(".") == string::npos)
					{
						getline(file, buff2);

						if (buff2.find(".") != string::npos)
							break;

						cout << buff2 << "\n";
					}
				}
			}
		}
		file.close();
	}



};






int main()
{
	setlocale(LC_ALL, "ru");

	//===========================ОЧИСТКА ФАЙЛОВ================================
	
		fstream file1;
		file1.open(name_file1, ios::out);
		if (!file1.is_open())
		{
			cout << "Файл не открылся" << endl;
		}
		else
		{
			cout << "Файл открылся" << endl;
		}
		file1.close();

		fstream file2;
		file1.open(name_file2, ios::out);
		if (!file1.is_open())
		{
			cout << "Файл не открылся" << endl;
		}
		else
		{
			cout << "Файл открылся" << endl;
		}
		file2.close();


	//===============================СОЗДАНИЕ ФИГУР============================
	
	//координата левого верхнего угла
	coords myCoord;
	myCoord.set_coords_val(1, 1);


	//абстактный обьект фигур
	shape myshape(myCoord, 4, 2);
	myshape.show();
	myshape.save(name_file1);
	cout << endl;

	//описание квадрата
	Square mySquare(myCoord, 4);
	mySquare.data();
	mySquare.show();
	mySquare.save(name_file1);
	cout << endl;

	//описание прямоугльника
	Rectangle myRectangle(myCoord, 4, 5);
	myRectangle.data();
	myRectangle.show();
	myRectangle.save(name_file1);
	cout << endl;

	//описание круга
	Circle myCircle(myCoord, 4);
	myCircle.data();
	myCircle.show();
	myCircle.save(name_file1);
	cout << endl;



	//=================================LOAD================================
		//абстарктный класс
	cout << "\n-=-=-=-=-=-=-\n";
	myshape.load(name_file1);
	cout << "\n-=-=-=-=-=-=-\n";
		// квадрат
	cout << "\n-=-=-=-=-=-=-\n";
	mySquare.load(name_file1);
	cout << "\n-=-=-=-=-=-=-\n";
		// прямоугольник
	cout << "\n-=-=-=-=-=-=-\n";
	myRectangle.load(name_file1);
	cout << "\n-=-=-=-=-=-=-\n";
		// круг
	cout << "\n-=-=-=-=-=-=-\n";
	myCircle.load(name_file1);
	cout << "\n-=-=-=-=-=-=-\n";
	cout << endl;


	//========================МАССИВ ФИГУР====================================
	//координата левого верхнего угла
	coords myCoord2;
	myCoord2.set_coords_val(2, 2);
	cout << "\n=_=_=_=_=_=_=_=_=_=_\n";
	const int size_mass = 3;
	vector<shape*> figures;

	figures.push_back(new Square(myCoord2, 4));
	figures[0]->data();
	figures[0]->show();
	cout << endl;
	cout << "\n=_=_=_=_=_=_=_=_=_=_\n";

	figures.push_back(new Rectangle(myCoord2, 4,2));
	figures[1]->data();
	figures[1]->show();
	cout << endl;
	cout << "\n=_=_=_=_=_=_=_=_=_=_\n";

	figures.push_back(new Circle(myCoord2, 4));
	figures[2]->data();
	figures[2]->show();
	cout << endl;
	cout << "\n=_=_=_=_=_=_=_=_=_=_\n";
	//SAVE

	figures[0]->save(name_file2);
	figures[1]->save(name_file2);
	figures[2]->save(name_file2);
	cout << "\n=-=-=-=-LOAD FILE2-=-=-=-=\n";
	//LOAD
	figures[0]->load(name_file2);
	figures[1]->load(name_file2);
	figures[2]->load(name_file2);

	cout << "\n=-=-=-=-СОЗДАНИЕ И ЗАГРУЗКА В ДРУГОЙ МАССИВ-=-=-=-=\n";

	vector<shape*> figures_2;

	figures_2.push_back(figures[0]);
	figures_2.push_back(figures[1]);
	figures_2.push_back(figures[2]);

	figures_2[0]->show();
	figures_2[1]->show();
	figures_2[2]->show();
	


}
//Создайте абстрактный класс Shape для рисования плоских
//фигур.Определите виртуальные методы :
//• Show() — вывод на экран информации о фигуре,
//• Save() — сохранение фигуры в файл,
//• Load() — считывание фигуры из файла.
//Определите производные классы :
//• Square — квадрат, который характеризуется коорди -
//натами левого верхнего угла и длиной стороны;
//• Rectangle — прямоугольник с заданными координатами
//верхнего левого угла и размерами;
//• Circle — окружность с заданными координатами цен -
//тра и радиусом;
//• Ellipse — эллипс с заданными координатами верхнего
//угла описанного вокруг него прямоугольника со сто -
//ронами, параллельными осям координат, и размерами
//этого прямоугольника.
// 
//  Создайте массив фигур,
//  сохраните фигуры в файл, 
//  загрузите в другой массив и отобразите информацию о каждой из фигур.