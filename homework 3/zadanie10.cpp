#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    system("Pause");

    //задание 10

    cout << "\n\tЗадание 10.\n\n \tНаписать программу, которая выводит на экран\n" 
            "шахматную доску с заданным размером клеточки.\n\n";

    system("Pause");

    cout << "\n\tРешение:\n\n";
    int shirina, visota, kletka;
    cout << "Введите ширину шахматной доски:\n";
    cin >> shirina;
    cout << "Введите высоту шахматной доски:\n";
    cin >> visota;
    cout << "Введите размер клеточки:\n";
    cin >> kletka;
    for (int visotadoska = 0; visotadoska < visota; visotadoska++) //здесь задается высота доски. т.е количество горизонитльных чередований
    {
        if (visotadoska % 2 == 0) //проверка горизонтальных чередований,  четное будет " * - * "
        {
            for (int visotakletok = 0; visotakletok < kletka; visotakletok++) //здесь задается высота клеток
            {
                for (int shirdoska = 0; shirdoska < shirina; shirdoska++) // количество клеток в ширину
                {
                    if (shirdoska % 2 == 0) // проверка условия на цвет клетки, четное будет " * "
                    {
                        for (int shirklet = 0; shirklet < kletka; shirklet++) //заполнение по ширене клетке " * "
                        {
                            cout << " * ";
                        }
                    }
                    else if (shirdoska % 2 != 0) // проверка условия на цвет клетки, нечетное будет " - "
                    {
                        for (int shirklet = 0; shirklet < kletka; shirklet++) //заполнение по ширене клетке " - "
                        {
                            cout << " - ";
                        }
                    }
                }
                cout << endl; // здесь исполняется высота клеток
            }
        }
            else if (visotadoska % 2 != 0) //проверка горизонтальных чередований, не четное будет " - * - "
            {
                for (int visotakletok = 0; visotakletok < kletka; visotakletok++) //здесь задается высота клеток
                {
                    for (int shirdoska = 0; shirdoska < shirina; shirdoska++) // количество клеток в ширину
                    {
                        if (shirdoska % 2 == 0) // проверка условия на цвет клетки, четное будет " - "
                        {
                            for (int shirklet = 0; shirklet < kletka; shirklet++) //заполнение по ширене клетке " - "
                            {
                                cout << " - ";
                            }
                        }
                        else if (shirdoska % 2 != 0) // проверка условия на цвет клетки, нечетное будет " * "
                        {
                            for (int shirklet = 0; shirklet < kletka; shirklet++) //заполнение по ширене клетке " * "
                            {
                                cout << " * ";
                            }
                        }
                    }
                    cout << endl; // здесь исполняется высота клеток
                }
            }
    }
    return 0;
}

