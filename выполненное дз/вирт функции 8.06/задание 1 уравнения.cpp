#include <iostream>
#include <string>

using namespace std;


class uravnenie 
{

public:
    float A{};
    float B{};
    float C{};
    float X{};
    uravnenie() {}
    uravnenie(float a, float b, float c) :A(a), B(b), C(c) {}




    virtual void korni() 
    {
        cout << "\nНахождение корней уравнения: \n";
        cout << X << endl;
    }




    void set(float a, float b,float c) 
    {
        A = a;
        B = b;
        C = c;
    }
    void get() 
    {
        cout << "a= " << A << endl;
        cout << "b= " << B << endl;
        cout << "c= " << C << endl;
    }

    

};

class line_urav :public uravnenie 
{
 public:
     line_urav() :uravnenie() {}
     line_urav(float q,float w,float e) :uravnenie(q,w,e) {}

   void  korni()override
   {
         cout << "\nНахождение корней линейного уравнения: \n";
         cout << "\na*x+b=c\n";
         cout << "\nx=(c-b)/a\n";
         X = (C - B) / A;
         cout <<"X = " << X << endl;
         
   }
    
};

class kvad_urav :public uravnenie 
{
    float Dis{};
public:
    kvad_urav() :uravnenie() {}
    kvad_urav(float q, float w, float e) :uravnenie(q, w, e) {}

    void  korni()override
    {
        cout << "\nНахождение корней квадратного уравнения: \n";
        cout << "\na*(x*х)+b*х+с=0\n";
        cout << "\nдискриминант = (b*b)-4*a*c\n";
        Dis = (B * B) - 4 * A * C;
        cout << "\nдискриминант = "<<Dis<<"\n";

        if (Dis < 0)
        {
            cout << "\nкорней нет\n";
        }
        else if (Dis == 0)
        {
            X = (B * -1) / (2 * A);
            cout << "X = " << X << endl;
        }
        else if (Dis > 0)
        {
            X = ((B * -1) + sqrt(Dis)) / (2 * A);
            cout << "X1 = " << X << endl;
            X = ((B * -1) - sqrt(Dis)) / (2 * A);
            cout << "X2 = " << X << endl;

        }




    }
    
};

int main()
{
    setlocale(LC_ALL, "ru");

    cout << "\n-=КЛАСС uravnenie=-\n";
    uravnenie newUrav(1, 2, 3);
    newUrav.get();
    cout << endl;
    cout << "\n-=КЛАСС uravnenie set=-\n";
    newUrav.set(4, 5, 6);
    newUrav.get();
    cout << "\n-=КЛАСС uravnenie korni=-\n";
    newUrav.korni();


    cout << "\n-=КЛАСС line_urav=-\n";
    line_urav newUrav2(1, 2, 3);
    newUrav2.get();
    cout << endl;
    cout << "\n-=КЛАСС line_urav set=-\n";
    newUrav2.set(4, 5, 6);
    newUrav2.get();
    cout << "\n-=КЛАСС line_urav korni=-\n";
    newUrav2.korni();
    

    cout << "\n-=КЛАСС kvad_urav=-\n";
    kvad_urav newUrav3(1, 2, 3);
    newUrav3.get();
    cout << endl;
    cout << "\n-=КЛАСС kvad_urav set=-\n";
    newUrav3.set(1, 10, 1);
    newUrav3.get();
    cout << "\n-=КЛАСС kvad_urav korni=-\n";
    newUrav3.korni();
    

    
}

//Задание 1
//Создать абстрактный базовый класс с виртуальной функ -
//цией — корни уравнения.Создать производные классы :
//класс линейных уравнений и класс квадратных уравнений.
//Определить функцию вычисления корней уравнений