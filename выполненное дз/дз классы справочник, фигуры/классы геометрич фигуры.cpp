#include <iostream>
#include <cmath>

using namespace std;


class Square
{


    double sideA{};     //стороны
    double sideB{};
    double sideC{};
    double H{};         //треуголь равнобедр              
    double ostr_Ugol{}; //ромб
    double tup_Ugol{};



public:
    Square() {}
    Square(int ab, int bc) :sideA(ab), sideB(bc) {}                                          //квадрат, прямоугольник
    Square(double ab, double h) :sideA(ab), H(h) {}                                                //равнобедрянный треуг
    Square(int ab, int bc, int ca) :sideA(ab), sideB(bc), sideC(ca) {}                    //прямоугольный треуг
    Square(double a_r, double o_Ug, double t_Ug) :sideA(a_r), ostr_Ugol(o_Ug), tup_Ugol(t_Ug) {}    //ромб

    static int counter;

    double sqRavnBedrTreug();      //равнобедр треугл
    double sqPryamTreug();         //прфмоуголь треугол
    double sqKvadr_F();            //квадрат и прямоугльник
    double sqRomb_F();             //ромб




};

int Square::counter = 0;

//определение фунции площади pавнобедрянного треуголника
double Square::sqRavnBedrTreug()
{
    ++counter;
    double sqRavBedTr;
    return sqRavBedTr = 0.5 * (sideA * H);
}
//определение фунции площади прямоугольного треуголника
double Square::sqPryamTreug()
{
    ++counter;
    double sqTringle;
    return sqTringle = (0.5 * ((double)sideA * (double)sideB));
}
//определение фунции площади квадрата
double Square::sqKvadr_F()
{
    ++counter;
    double sqKvad = 0;
    if (sideB != sideA)
    {
        return (sqKvad = (double)sideA * (double)sideB);
    }
    else
    {
        return (sqKvad = 2 * (double)sideA);
    }
}
//определение фунции площади ромба
double Square::sqRomb_F()
{
    ++counter;
    double Big_Diag;
    double Small_Diag;
    double sq_Romb;

    Big_Diag = sideA * (sqrt(2 - (2 * cos(tup_Ugol) * 3.14 / 180)));
    Small_Diag = sideB * (sqrt(2 - (2 * cos(ostr_Ugol) * 3.14 / 180)));

    return sq_Romb = 0.5 * (Big_Diag * Small_Diag);
}

int main()
{
    setlocale(LC_ALL, "ru");

    int aPrUgTr = 0, bPrUgTr = 0, cPrUgTr = 0;  //прямуг треуг

    double aRavnUgTr = 0;
    double h = 0;               //равнобедр треуг

    double a_romb = 0;
    double o_ug = 0, t_ug = 0;      //ромб

    int a_kv = 0, b_kv = 0;   //квадрат и прямоугольник





    system("PAUSE");




    cout << "\nНайдем площадь прямоугольного треугольника : \n";
    cout << "\nВведите сторону А: ";
    cin >> aPrUgTr;
    cout << "\nВведите сторону B: ";
    cin >> bPrUgTr;
    cout << "\nВведите сторону C: ";
    cin >> cPrUgTr;
    Square pryamUg_treug(aPrUgTr, bPrUgTr, cPrUgTr);
    cout << "Площадь равна: " << pryamUg_treug.sqPryamTreug() << endl;



    cout << "\nНайдем площадь равнобедрянного  треугольника : \n";
    cout << "\nВведите сторону А: ";
    cin >> aRavnUgTr;
    cout << "\nВведите высоту Н: ";
    cin >> h;
    Square ravnoUg_treug(aRavnUgTr, h);
    cout << "Площадь равна: " << ravnoUg_treug.sqRavnBedrTreug() << endl;



    cout << "\nНайдем площадь квадрата либо прямоугольника: \n";
    cout << "\nВведите сторону А: ";
    cin >> a_kv;
    cout << "\nВведите сторону B: ";
    cin >> b_kv;
    Square Pryam_ugol(a_kv, b_kv);
    cout << "Площадь равна: " << Pryam_ugol.sqKvadr_F() << endl;



    cout << "\nНайдем площадь ромба: \n";
    cout << "\nВведите сторону А: ";
    cin >> a_romb;
    cout << "\nВведите острый угол ромба: ";
    cin >> o_ug;
    cout << "\nВведите тупой угол ромба: ";
    cin >> t_ug;
    Square Romb(a_romb, o_ug, t_ug);
    cout << "Площадь равна: " << Romb.sqRomb_F() << endl;


    cout << "Всего вызванно фунций: " << Square::counter << endl;

}

















//Задание 1.
//Создайте класс для подсчета площади геометрических фигур.
//Класс должен предоставлять функциональность для подсчета
// 
//площади треугольника по разным формулам, 
//площади прямоугольника,
//площади квадрата
//площади ромба.
// 
//Функции - члены
//для подсчета площади должны быть реализованы с помощью
//функций - членов.Также класс должен считать коли -
//чество подсчетов площади и возвращать это значение с помощью
//статической функции - члена.


