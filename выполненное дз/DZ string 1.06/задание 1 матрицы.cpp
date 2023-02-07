#include <iostream>
#include <random>

using namespace std;
random_device Rand;


//Задание 1.
//Создайте шаблонный класс матрица.Необходимо реали -
//зовать динамическое выделение памяти, очистку памяти,
//заполнение матрицы с клавиатуры, заполнение случайны -
//ми значениями, отображение матрицы, арифметические
//операции с помощью перегруженных операторов(+, –,
//	*, / ), поиск максимального и минимального элемента.


class matrix
{
	double** mass;
	int size_stroki{};	//празмер частей
	int size_gruppa{};	//размер групп частей

	//закрытая функция выделения памяти
	void new_memory(int gr, int st)
	{
		size_gruppa = gr;
		size_stroki = st;
		mass = new double* [size_gruppa];
		for (int i = 0; i < size_gruppa; ++i)
		{
			mass[i] = new double[size_stroki];
		}
	}

public:

	//КОНСТРУКТОРЫ
	//конструктор выделения динамической памяти
	matrix(int g, int s)
	{
		new_memory(g, s);
	}

	//контсруктор копирования
	matrix(const matrix& C)
	{
		new_memory(C.size_gruppa, C.size_stroki);
		for (int i = 0; i < size_gruppa; i++)
		{
			for (int j = 0; j < size_stroki; j++)
			{
				mass[i][j] = C.mass[i][j];
			}
		}
	}

	//ПЕРЕОПРЕДЕЛЕНИЕ ОПЕРТАОРОВ / * - + =
	//+
	matrix operator+(matrix& MAT_B)
	{
		matrix MAT_A(MAT_B);

		for (int i = 0; i < size_gruppa; ++i)
		{
			for (int j = 0; j < size_stroki; ++j)
			{
				MAT_A.mass[i][j] = mass[i][j];
			}
		}

		for (int i = 0; i < size_gruppa; ++i)
		{
			for (int j = 0; j < size_stroki; ++j)
			{
				MAT_A.mass[i][j] += MAT_B.mass[i][j];
			}
		}

		return MAT_A;
	}
	//-
	matrix operator-(matrix& MAT_B)
	{
		matrix MAT_A(MAT_B);

		for (int i = 0; i < size_gruppa; ++i)
		{
			for (int j = 0; j < size_stroki; ++j)
			{
				MAT_A.mass[i][j] = mass[i][j];
			}
		}

		for (int i = 0; i < size_gruppa; ++i)
		{
			for (int j = 0; j < size_stroki; ++j)
			{
				MAT_A.mass[i][j] -= MAT_B.mass[i][j];
			}
		}

		return MAT_A;
	}
	//  /
	matrix operator/(matrix& MAT_B)
	{
		matrix MAT_A(MAT_B);

		for (int i = 0; i < size_gruppa; ++i)
		{
			for (int j = 0; j < size_stroki; ++j)
			{
				MAT_A.mass[i][j] = mass[i][j];
			}
		}

		for (int i = 0; i < size_gruppa; ++i)
		{
			for (int j = 0; j < size_stroki; ++j)
			{
				MAT_A.mass[i][j] /= MAT_B.mass[i][j];
			}
		}

		return MAT_A;
	}
	// *
	matrix operator*(matrix& MAT_B)
	{
		matrix MAT_A(MAT_B);

		for (int i = 0; i < size_gruppa; ++i)
		{
			for (int j = 0; j < size_stroki; ++j)
			{
				MAT_A.mass[i][j] = mass[i][j];
			}
		}

		for (int i = 0; i < size_gruppa; ++i)
		{
			for (int j = 0; j < size_stroki; ++j)
			{
				MAT_A.mass[i][j] *= MAT_B.mass[i][j];
			}
		}

		return MAT_A;
	}

	// =
	matrix& operator= (matrix MAT_B)
	{
		for (int i = 0; i < size_gruppa; ++i)
		{
			for (int j = 0; j < size_stroki; ++j)
			{
				mass[i][j] = MAT_B.mass[i][j];
			}

		}

		return *this;
	}

	

	//ФУНКЦИИ

	//заполнение  случайными числами
	void set_random_matrix()
	{
		for (int i = 0; i < size_gruppa; ++i)
		{
			for (int j = 0; j < size_stroki; ++j)
			{
				mass[i][j] = Rand() % 9;
			}
		}
	}

	//заполнение с клавиатуры
	void set_user_matrix()
	{
		for (int i = 0; i < size_gruppa; ++i)
		{
			cout << "\nВведите числа для " << i + 1 << " группы: \n";
			for (int j = 0; j < size_stroki; ++j)
			{
				cout << "Введите " << j + 1 << " число : \n";
				cin >> mass[i][j];
			}
		}
	}

	//вывод на экран
	void get_matrix()
	{
		for (int i = 0; i < size_gruppa; ++i)
		{
			for (int j = 0; j < size_stroki; ++j)
			{
				cout << mass[i][j] << " ";
			}
			cout << endl;
		}
	}

	//нахождение наибольшего числа
	void get_matrix_Max() 
	{
		double MAX = mass[0][0];

		for (int i = 0; i < size_gruppa;++i) 
		{
			for (int j = 0; j < size_stroki; ++j)
			{
				if (MAX < mass[i][j]) 
				{
					MAX = mass[i][j];
				}
			}
		}
		cout << "\nНаибольшее число массива: " << MAX << endl;

	};

	//нахождение наименьшего числа
	void get_matrix_Min() 
	{
		double MIN = mass[0][0];

		for (int i = 0; i < size_gruppa; ++i)
		{
			for (int j = 0; j < size_stroki; ++j)
			{
				if (MIN > mass[i][j])
				{
					MIN = mass[i][j];
				}
			}
		}
		cout << "\nНаименьшее число массива: " << MIN << endl;
	};

	// диструктор удаление памяти
	~matrix()
	{
		delete[] mass;
	}
};


int main()
{
	setlocale(LC_ALL, "ru");

	matrix newMat(2, 3);
	matrix newMat_2(2, 3);
	matrix newMat_3(2, 3);



	cout << "\n========matrix 1 INIT================\n";
	newMat.set_random_matrix();
	newMat.get_matrix();

	cout << "\n========matrix 2 INIT================\n";
	newMat_2.set_user_matrix();
	newMat_2.get_matrix();

	cout << "\n======== matrix 3 = matrix 1 + matrix 2 ================\n";
	newMat_3 = (newMat + newMat_2);
	newMat_3.get_matrix();

	cout << "\n======== matrix 3 = matrix 1 - matrix 2 ================\n";
	newMat_3 = (newMat - newMat_2);
	newMat_3.get_matrix();

	cout << "\n======== matrix 3 = matrix 1 / matrix 2 ================\n";
	newMat_3 = (newMat / newMat_2);
	newMat_3.get_matrix();

	cout << "\n======== matrix 3 = matrix 1 * matrix 2 ================\n";
	newMat_3 = (newMat * newMat_2);
	newMat_3.get_matrix();

	cout << "\n======== Максимальные значения матриц: ================\n";
	newMat.get_matrix_Max();
	newMat_2.get_matrix_Max();
	newMat_3.get_matrix_Max();
	

	cout << "\n======== Минимальные значения матриц: ================\n";

	newMat.get_matrix_Min();
	newMat_2.get_matrix_Min();
	newMat_3.get_matrix_Min();



	return 0;

}
