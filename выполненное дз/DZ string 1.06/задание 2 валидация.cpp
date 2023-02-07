#include <iostream>
#include <fstream>
#include <string>

using namespace std;


class file
{
	string PATH{};
	string valid_file{ "<html>\n<body>To be or not to be</body>\n</html>" };
	string invalid_file{ "<html>\n<body To be or not to be</body>\n</html>" };
public:
	file() {};
	file(string path) :PATH(path) { };

	void file_Write();//функция-член создания файла

	void valid();

};


//функция-член создания файла

void file::file_Write()
{
	fstream newfile_valid;
	fstream newfile_invalid;

	newfile_valid.open("file_valid.txt", ios::out);
	newfile_invalid.open("file_invalid.txt", ios::out);

	if ((!newfile_valid.is_open()) && (!newfile_invalid.is_open()))
	{
		cout << "files is not open" << endl;
	}
	else
	{
		newfile_valid << valid_file;
		newfile_invalid << invalid_file;

	}
	newfile_valid.close();
	newfile_invalid.close();
}
void file::valid()
{
	cout << "Введите путь к файлу: ";
	getline(cin, PATH);

	char first = '<';
	char last = '>';
	string proverka;

	fstream newfile_valid;

	newfile_valid.open(PATH, ios::in);

	if (!newfile_valid.is_open())
	{
		cout << "files is not open" << endl;
	}
	else
	{
		char* buff1 = nullptr;
		buff1 = new char[1000];

		while (!newfile_valid.eof())
		{


			newfile_valid.getline(buff1, 1000);
			proverka.append(buff1);

		}

		cout << proverka << endl;
		cout << "Длинна строки : " << proverka.length() << endl << endl;

		int count_first = 0;
		int count_second = 0;

		for (size_t pos_first = 0, pos_second = 0; pos_first < proverka.length() || pos_second < proverka.length(); ++pos_first, ++pos_second)
		{
			if (proverka.find(first, pos_first) != string::npos)
			{
				pos_first = proverka.find(first, pos_first);
				count_first++;
			}
			if (proverka.find(last, pos_second) != string::npos)
			{
				pos_second = proverka.find(last, pos_second);
				count_second++;
			}
		}
		cout << endl;
		if (count_first != count_second)
		{
			cout << "файл не валидный" << endl;
		}
		else
		{
			cout << "файл валидный" << endl;
		}
		delete[] buff1;
	}
	newfile_valid.close();
}




int main()
{
	setlocale(LC_ALL, "ru");

	file X;
	X.file_Write();
	X.valid();
}

//Создайте приложение "валидатор HTML-файлов".
//Приложение запрашивает у пользователя путь к файлу, после чего проверяем файл на валидность.
//Критерием валидности для вашего проекта являются правила : все открытые теги(тегом будут назваться знаки < >) должны закрываться,
//если был знак < его должен закрыть > итогам валидации нужно отобразить результат проверки на экран.
//Используйте для рабоыт с файлами потоки, а для работы со строками класс string.
//Пример: 
//	Содержимое  валидного файла :
//	<html>
//	<body>To be or not to be</body>
//	</html>
//	Содержимое не валидного файла: 
//	<html>
//	<bodyTo be or not to be</body>
//	</html>
