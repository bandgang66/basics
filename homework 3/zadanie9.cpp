#include <iostream>

using namespace std;

int main()
{
	system("Pause");

	setlocale(LC_ALL, "rus");

	//задание 9

	cout << "\n\tЗадание 9.\n\n \tПользователь вводит число. Определить количество цифр в этом числе, \n"
            "посчитать их сумму и среднее арифметическое.Определить количество нулей в этом числе. \n"
            "Общение с пользователем организовать через меню..\n\n";

	system("Pause");

	cout << "\n\tРешение:\n\n";

    int number, kolvo0, number1, ostatok;
    float sum, kolvo, srednee;
  
    kolvo0 = 0;
    kolvo = 0;
    sum = 0;
    char S = *"U";

    cout << "\t\tВведите необходимый пункт меню для выбранного действия: \n\n"
        "\tОпределить количество цифр в этом числе:..........введите \"A\".\n"
        "\tПосчитать сумму цифр числа:.......................введите \"B\".\n"
        "\tПосчитать среднее арифметическое цифр числа:......введите \"C\".\n"
        "\tОпределить количество нулей в этом числе:.........введите \"D\".\n"
        "\tДля ввода нового числа:...........................введите \"N\".\n"
        "\tДля остановки программы:..........................введите \"X\".\n\n";
    cout << "\n\tВведите число:\n\n";
    cin >> number;
    number1 = number;

    while (S != *"X")
    {
        cout << "\nВведите пункт меню: \n";
        cin >> S;

        switch (S)
        {
        case * "A":
            for (number; number > 0; number /= 10)
            {
                kolvo++;
            }
            cout << "\nВ введеном числе: " << kolvo << " цифр." << endl;
            number = number1;
            kolvo = 0;
            break;
        case * "B":
            for (number; number > 0; number /= 10)
            {
                ostatok = number % 10;
                sum += ostatok;
            }
            cout << "\nСумма цифр введеного числа равна: " << sum << endl;
            number = number1;
            ostatok = 0;
            sum = 0;
            break;
        case * "C":
            for (number; number > 0; number /= 10)
            {
                kolvo++;
                ostatok = number % 10;
                sum += ostatok;
            }
            srednee = sum / kolvo;
            cout << "\nСреднее арифметическое цифр введеного числа равно: " << srednee << endl;
            number = number1;
            kolvo = 0;
            ostatok = 0;
            sum = 0;
            srednee = 0;
            break;
        case * "D":
            for (number; number > 0; number /= 10)
            {
                if (number % 10 == 0)
                {
                    kolvo0++;
                }
            }
            cout << "\nВ введеном числе: " << kolvo0 << " нулей." << endl;
            number = number1;
            kolvo0 = 0;
            break;

        case *"N":
            cout << "\nВведите новое число: \n";
            cin >> number1;
            number = number1;
            break;
        }

    }
}