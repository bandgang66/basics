#define _CRT_SECURE_NO_WARNINGS


#include <iostream>
#include <cstdio>
#include <cstring>
#include <fstream>

using namespace std;



class Abonent 
{
    char FIO[30]{};
    int nomer{};
    int homePhone{};
    int workPhone{};
    int mobilPhone{};
    char info[100]{};
    int SIZE_GRUPPA{};
    int SIZE_OBSHIY{};
    Abonent* massAbon=nullptr;

public:
   
    //конструкторы
    
    Abonent() {  };

    Abonent(Abonent *buff) 
    {
        cout << "\nКонструктор группы абоентов\n";

        buff = new Abonent[100];                                    
        massAbon = buff;
        
    } 

    //сеттеры
    void set_FIO(char name[30]);
    void set_nomer(int num);        
    void set_home_Ph(int num);
    void set_work_Ph(int num);
    void set_mobil_Ph(int num);
    void set_info(char inf[100]);

    //геттеры
    char* get_FIO();                
    int get_nomer();                
    int get_home_Ph();
    int get_work_Ph();
    int get_mobil_Ph();
    char* get_info();

    //Функции                      
    void Abon_init();       //инициализация абонента
    void Abon_show();           //показ абонента
    void mass_Abon_init(int s);      //инициализация группы абонентов
    void mass_Abon_show();      //показ группы абонентов
    void poisk_Abon();          //поиск абонента
    void delete_Abon();             //удаление абонента
    void file_Write();          //запись в файл
    void file_Read();               //чтение из файла
    ~Abonent()
    {
        delete[] massAbon;
    }

};  
//сеттеры
void Abonent::set_FIO(char name[30])
{
    strcpy(FIO, name);
}
void Abonent::set_nomer(int num)
{
    nomer = num;
}           
void Abonent::set_home_Ph(int num)
{
    homePhone = num;
}
void Abonent::set_work_Ph(int num)
{
    workPhone = num;
}
void Abonent::set_mobil_Ph(int num)
{
    mobilPhone = num;
}
void Abonent::set_info(char inf[100])
{
    strcpy(info, inf);
}

//геттеры
char* Abonent::get_FIO()
{
    return FIO;
}
int Abonent::get_nomer()
{
    return nomer;
}               
int Abonent::get_home_Ph()
{
    return homePhone;
}
int Abonent::get_work_Ph()
{
    return workPhone;
}
int Abonent::get_mobil_Ph()
{
    return mobilPhone;
}
char* Abonent::get_info()
{
    return info;
}

//функции-члены
void Abonent::Abon_init()
{
    char name[30]{};
    char inform[100]{};
    int home{};
    int work{};
    int mobil{};

    cout << "\nВведите ФИО: ";
    gets_s(name);
    cout << "\nВведите домашний телефон: ";
    cin >> home;
    cout << "\nВведите рабочий телефон: ";
    cin >> work;
    cout << "\nВведите мобильный телефон: ";
    cin >> mobil;
    cin.clear();
    cin.ignore(cin.rdbuf()->in_avail());
    cout << "\nВведите дополнительную информацию: ";
    gets_s(inform);
    
    set_FIO(name);
    set_home_Ph(home);
    set_work_Ph(work);
    set_mobil_Ph(mobil);
    set_info(inform);
    
}
void Abonent::Abon_show()
{
    cout <<endl<<get_nomer() << endl;
    cout << get_FIO() << endl;
    cout << get_home_Ph() << endl;
    cout << get_work_Ph() << endl;
    cout << get_mobil_Ph() << endl;
    cout << get_info() << endl;
}
void Abonent::mass_Abon_init(int s)
{
    SIZE_GRUPPA += s;
    
    for (; SIZE_OBSHIY < SIZE_GRUPPA; ++SIZE_OBSHIY)
    {
        massAbon[SIZE_OBSHIY].nomer = SIZE_OBSHIY +1;
        massAbon[SIZE_OBSHIY].Abon_init();
    }
    cout << "общий = " << SIZE_OBSHIY << endl;
    cout << "группа= " << SIZE_GRUPPA << endl;
}
void Abonent::mass_Abon_show()
{
    for (int i = 0; i < SIZE_OBSHIY; ++i)
    {
        massAbon[i].Abon_show();
    }
}
void Abonent::poisk_Abon()
{
    char name[30]{};
    cout << "\nВведите ФИО для поиска: \n";
    gets_s(name);
    for (int i = 0; i < SIZE_OBSHIY; ++i)
    {
        if (!strcmp(massAbon[i].FIO, name))
        {
            massAbon[i].Abon_show();
        }
    }

}
void Abonent::delete_Abon()
{
    char name[30]{};
    cout << "\nВведите ФИО для поиска: \n";
    gets_s(name);
    for (int i = 0; i < SIZE_OBSHIY; ++i)
    {
        if (!strcmp(massAbon[i].FIO, name))
        {
            for (int j = i; j < SIZE_OBSHIY; ++j)
            {
                massAbon[i].nomer = i + 1;
                massAbon[j] = massAbon[j + 1];
            }
        }
    }
  
    --SIZE_OBSHIY;
}
void Abonent::file_Write()
{
   
    fstream file;
    file.open("abonent.txt", ios::out);

    if (!file.is_open())
    {
        cout << "Файл не открылся" << endl;
    }
    else
    {
        char* buff = nullptr;
        buff = new char[1000];
        char* word = nullptr;
        word = new char[100];
        cin.clear();
        cin.ignore(cin.rdbuf()->in_avail());

        for (int i = 0; i < SIZE_OBSHIY; ++i)
        {
                word = _itoa(massAbon[i].nomer,word,10);
                strcpy(buff,word );
                file << buff << endl;
                
                strcpy(buff, massAbon[i].FIO);
                file << buff << endl;

                word = _itoa(massAbon[i].homePhone, word, 10);
                strcpy(buff, word);
                file << buff << endl;

                word = _itoa(massAbon[i].workPhone, word, 10);
                strcpy(buff, word);
                file << buff << endl;

                word = _itoa(massAbon[i].mobilPhone, word, 10);
                strcpy(buff, word);
                file << buff << endl;

                strcpy(buff, massAbon[i].info);
                file << buff << endl;

                file << endl;

            
        }
        delete[] word;
        delete[] buff;
    }
    file.close();
}
void Abonent::file_Read()
{
    fstream file;
    file.open("abonent.txt");

    if (!file.is_open())
    {
        cout << "Файл не открылся" << endl;
    }
    else
    {
        char* buff1 = nullptr;
        buff1 = new char[1000];

        while (!file.eof())
        {

            file.getline(buff1, 1000);
            cout << buff1 << endl;

        }

        delete[] buff1;
    }

    file.close();

}




int main()
{
    setlocale(LC_ALL, "ru");

    
    Abonent* newAbon = nullptr;
   
    Abonent abon(newAbon);
    cout << "\n==========================НАЧАЛО РАБОТЫ====================================\n";
    cout << "\n=======================ЗАПОЛНЯЕМ ПЕРВЫЙ РАЗ================================\n";
    cout << "\nВведите количество добавляемых Абонентов: \n";
    int size_Abon;
    cin >> size_Abon;
    cin.clear();
    cin.ignore(cin.rdbuf()->in_avail());
    abon.mass_Abon_init(size_Abon);      
    abon.mass_Abon_show();

    cout << "\n========================ЗАПИСАЛОСЬ В ФАЙЛ===================================\n";
    abon.file_Write();

    cout << "\n=========================ЧТЕНИЕ ИЗ ФАЙЛА====================================\n";
    abon.file_Read();

    cout << "\n=======================ЗАПОЛНЯЕМ ВТОРОЙ РАЗ=================================\n";
    cout << "\nВведите количество добавляемых Абонентов: \n";
    cin >> size_Abon;
    cin.clear();
    cin.ignore(cin.rdbuf()->in_avail());
    abon.mass_Abon_init(size_Abon);          
    abon.mass_Abon_show();

    cout << "\n=========================ЗАПИСАЛОСЬ В ФАЙЛ==================================\n";
    abon.file_Write();

    cout << "\n==========================ЧТЕНИЕ ИЗ ФАЙЛА===================================\n";
    abon.file_Read();

    cout << "\n========================ВЫПОЛНЯЕМ ПОИСК ПО ФИО==============================\n";
    abon.poisk_Abon();

    cout << "\n===========================УДАЛЯЕМ ПО ФИО===================================\n";
    abon.delete_Abon();
    abon.mass_Abon_show();

    cout << "\n==========================ЗАПИСАЛОСЬ В ФАЙЛ=================================\n";
    abon.file_Write();

    cout << "\n===========================ЧТЕНИЕ ИЗ ФАЙЛА==================================\n";
    abon.file_Read();

    delete[] newAbon;
    
   

}

//Задание 1.
//Создайте приложение "Телефонная книга".
//Необходимо:
//
//1)хранить данные об абоненте:
// + 1)ФИО
// + 2)домашний телефон
// + 3)рабочий телефон
// + 4)мобильный телефон
// + 5)дополнительная информация о контакте внутри соответствующего класса
// 
//2)Наполните класс: 
// + 1)переменными - членами
// + 2)функциями - членами,
// + 3)конструкторами
// - 4)inline - функциями - членами
//
// + 5)используйте инициализаторы,
// + 6)реализуйте деструктор.
//
//-3)Обязательно необходимо выделять динамически память под ФИО.
//
//4)Предоставьте пользователю возможность: 
// + 1)добавлять новых абонентов,
// + 2)удалять абонентов,
// + 3)искать абонентов по ФИО,
// + 4)показывать всех абонентов,
// + 5)сохранять информацию в файл и загружать из файла.

