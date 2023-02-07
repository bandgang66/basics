#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	// Задание №1
	cout << "\tЗадание 1.\n\n \tВывести на экран фигуры заполненные звездочками.\n Диалог с пользователем"
		"реализовать при помощи меню.\n\n";
	cout << "\tРешение:\n\n";
	int razmer;
	char menu;
	char exit = *"y";
	while (exit == *"y") 
	{
		cout << "Выберите вид фигуры:\n\n"
				"фигура а .введите: a \n"
				"фигура б .введите: b \n"
				"фигура в .введите: c \n"
				"фигура г .введите: d \n"
				"фигура д .введите: e \n"
				"фигура е .введите: f \n"
				"фигура ж .введите: g \n"
				"фигура з .введите: h \n"
				"фигура и .введите: i \n"
				"фигура к .введите: j \n\n";
		cout << "Введите свой выбор : \n";
		
		cin >> menu;
		cout << " \n";
		cout << "Введите размер квадрата\n";
		cin >> razmer;
		

		switch (menu)
		{
		case * "a":
			for (int y = 0; y < razmer; y++)
			{
				for (int x = 0; x < razmer; x++)
				{
					if (x==y||x>y)
					{
						cout << " * ";
					}
					else
						cout << "   ";
				}
				cout << endl;
			}
			break;

		case * "b":
			for (int y = 0; y < razmer; y++)
			{
				for (int x = 0; x < razmer; x++)
				{
					if (x == y||x < y)
					{
						cout << " * ";
					}
					else
						cout << "   ";
				}
				cout << endl;
			}
			break;
		case * "c":
			for (int y = 0; y < razmer; y++)
			{
				for (int x = 0; x < razmer; x++)
				{
					if (!((x + y> razmer - 1)||(x<y)))
					{
						cout << " * ";
					}
					else
						cout << "   ";
				}
				cout << endl;
			}
			break;
		case * "d":
			for (int y = 0; y < razmer; y++)
			{
				for (int x = 0; x < razmer; x++)
				{
					if (!((x>y)||(x+y< razmer -1)))
					{
						cout << " * ";
					}
					else
						cout << "   ";
				}
				cout << endl;
			}
			break;
		case * "e":
			for (int y = 0; y < razmer; y++)
			{
				for (int x = 0; x < razmer; x++)
				{
					if ((!((x > y) || (x + y < razmer - 1)))|| (!((x + y > razmer - 1) || (x < y))))
					{
						cout << " * ";
					}
					else
						cout << "   ";
				}
				cout << endl;
			}
			break;
		case * "f":
			for (int y = 0; y < razmer; y++)
			{
				for (int x = 0; x < razmer; x++)
				{
					if ((!((x + y > razmer - 1) || (x > y))) ||(!((x < y) || (x + y < razmer - 1))))
					{
						cout << " * ";
					}
					else
						cout << "   ";
				}
				cout << endl;
			}
			break;
		case * "g":
			for (int y = 0; y < razmer; y++)
			{
				for (int x = 0; x < razmer; x++)
				{
					if (!((x + y> razmer - 1 )|| (x>y)))
					{
						cout << " * ";
					}
					else
						cout << "   ";
				}
				cout << endl;
			}
			break;
		case * "h":
			for (int y = 0; y < razmer; y++)
			{
				for (int x = 0; x < razmer; x++)
				{
					if (!((x <y) || (x + y< razmer - 1)))
					{
						cout << " * ";
					}
					else
						cout << "   ";
				}
				cout << endl;
			}
			break;
		case * "i":
			for (int y = 0; y < razmer; y++)
			{
				for (int x = 0; x < razmer; x++)
				{
					if ((x+y< razmer -1)||(x== razmer -y-1))
					{
						cout << " * ";
					}
					else
						cout << "   ";
				}
				cout << endl;
			}
			break;
		case * "j":
			for (int y = 0; y < razmer; y++)
			{
				for (int x = 0; x < razmer; x++)
				{
					if ((x == razmer - y - 1)||x+y> razmer -1)
					{
						cout << " * ";
					}
					else
						cout << "   ";
				}
				cout << endl;
			}
			break;

		}
		cout << "Для повтора введите строчную английскую букву \"y\", для выхода введите любой символ\n";
		cin >> exit;
	}



 return 0;
}