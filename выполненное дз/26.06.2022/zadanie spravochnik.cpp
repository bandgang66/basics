#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>


using namespace std;




class Spravochnik_DATA 
{
protected:
    
    string NAME_FIRM{};
    string NAME_DIRECTOR{};
    string ADRESS{};
    string DEYATEL{};
    string TELEPH{};

public:
    Spravochnik_DATA() {}
    Spravochnik_DATA(string name_F,string name_D,string adress,string deyatel,string teleph):
        NAME_FIRM{ name_F }, NAME_DIRECTOR{ name_D }, ADRESS{ adress }, DEYATEL{ deyatel }, TELEPH{teleph} {}
    virtual ~Spravochnik_DATA() {}

    virtual void setDATA(); 
    virtual void getDATA();
};

class Spravochnik : public Spravochnik_DATA
{
    vector<Spravochnik_DATA*> mySprav;
    static int counter; //общий счетчик фирм

public:
    Spravochnik() : Spravochnik_DATA() { }
    ~Spravochnik() {}

    //добавление фирмы в вектор
    void setDATA() override;
    //вывод на экран всех фирм
    void getDATA() override;

    //функции поиска
    void poisk_nameFirm();
    void poisk_nameDir();
    void poisk_telephon();
    void poisk_deyatel(); 


    //функции с файлом
    void save_to_file();    //запись в файл
    void load_from_file();    //чтение из файла


};
int Spravochnik::counter = 0;
//базовые функции 
void Spravochnik_DATA::setDATA()
{
    cout << "\nВведите название фирмы: ";
    getline(cin,NAME_FIRM);

    cout << "\nВведите ФИО владельца: ";
    getline(cin, NAME_DIRECTOR);

    cout << "\nВведите Адрес: ";
    getline(cin, ADRESS);

    cout << "\nВведите род деятельности: ";
    getline(cin, DEYATEL);

    cout << "\nВведите номер телефона: ";
    getline(cin, TELEPH);

}
void Spravochnik_DATA::getDATA()
{
    cout << "\n=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
    cout << "\nНазвание фирмы: " << NAME_FIRM << endl;
    cout << "ФИО Владельца: " << NAME_DIRECTOR << endl;
    cout << "Адрес: " << ADRESS << endl;
    cout << "Род деятельности: " << DEYATEL << endl;
    cout << "Телефон: " << TELEPH << endl;
    cout << "\n=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
}

//функции наследника
        //данные
void Spravochnik::setDATA()
{
        mySprav.push_back(new Spravochnik_DATA);
        mySprav[counter]->setDATA();
        counter++;
}
void Spravochnik::getDATA()
{
    for (auto x : mySprav)
    {
        x->getDATA();
    }
}

        //поиски
void Spravochnik::poisk_nameFirm()
{
    int vopros{};       //переменная вывода если поиск не дал результатов
    string buff{};      //ввод от поьзователья
    string buff2{};         //будем копировать для сравнения
    Spravochnik* pop;  //для доступа к метожу потомка

    cout << "\nВведите название фирмы: \n";
    getline(cin, buff);

    buff.erase(remove(buff.begin(), buff.end(), ' '), buff.end()); //удаляем все пробелы
    transform(buff.begin(), buff.end(), buff.begin(), tolower);         //делаем все буквы мелкими

    for (int i = 0; i < counter; ++i) 
    {

      pop = (Spravochnik*)mySprav[i];               //делаем доступ к методу потомка 
      buff2 = pop->NAME_FIRM;
      buff2.erase(remove(buff2.begin(), buff2.end(), ' '), buff2.end()); 
      transform(buff2.begin(), buff2.end(), buff2.begin(), tolower);
            if (buff2 == buff) 
            {
                cout << "\nМы нашли : \n";
                pop->getDATA();
                vopros = 1;
                break;
            }
     
    }

    if (vopros == 0) 
    {
        cout << "\nТакой фирмы нет!\n";
    }

}
void Spravochnik::poisk_nameDir()
{
    int vopros{};       //переменная вывода если поиск не дал результатов
    string buff{};      //ввод от поьзователья
    string buff2{};         //будем копировать для сравнения
    Spravochnik* pop;  //для доступа к метожу потомка

    cout << "\nВведите ФИО владельца: \n";
    getline(cin, buff);

    buff.erase(remove(buff.begin(), buff.end(), ' '), buff.end()); //удаляем все пробелы
    transform(buff.begin(), buff.end(), buff.begin(), tolower);         //делаем все буквы мелкими

    for (int i = 0; i < counter; ++i)
    {

        pop = (Spravochnik*)mySprav[i];               //делаем доступ к методу потомка 
        buff2 = pop->NAME_DIRECTOR;
        buff2.erase(remove(buff2.begin(), buff2.end(), ' '), buff2.end());
        transform(buff2.begin(), buff2.end(), buff2.begin(), tolower);
        if (buff2 == buff)
        {
            cout << "\nМы нашли : \n";
            pop->getDATA();
            vopros = 1;
            break;
        }

    }

    if (vopros == 0)
    {
        cout << "\nТакой фирмы нет!\n";
    }
}
void Spravochnik::poisk_telephon()
{
    int vopros{};       //переменная вывода если поиск не дал результатов
    string buff{};      //ввод от поьзователья
    string buff2{};         //будем копировать для сравнения
    Spravochnik* pop;  //для доступа к метожу потомка

    cout << "\nВведите номер телефона: \n";
    getline(cin, buff);

    buff.erase(remove(buff.begin(), buff.end(), ' '), buff.end()); //удаляем все пробелы
    transform(buff.begin(), buff.end(), buff.begin(), tolower);         //делаем все буквы мелкими

    for (int i = 0; i < counter; ++i)
    {

        pop = (Spravochnik*)mySprav[i];               //делаем доступ к методу потомка 
        buff2 = pop->TELEPH;
        buff2.erase(remove(buff2.begin(), buff2.end(), ' '), buff2.end());
        transform(buff2.begin(), buff2.end(), buff2.begin(), tolower);
        if (buff2 == buff)
        {
            cout << "\nМы нашли : \n";
            pop->getDATA();
            vopros = 1;
            break;
        }

    }

    if (vopros == 0)
    {
        cout << "\nТакой фирмы нет!\n";
    }
}
void Spravochnik::poisk_deyatel()
{
    int vopros{};       //переменная вывода если поиск не дал результатов
    string buff{};      //ввод от поьзователья
    string buff2{};         //будем копировать для сравнения
    Spravochnik* pop;  //для доступа к метожу потомка

    cout << "\nВведите род деятельности: \n";
    getline(cin, buff);

    buff.erase(remove(buff.begin(), buff.end(), ' '), buff.end()); //удаляем все пробелы
    transform(buff.begin(), buff.end(), buff.begin(), tolower);         //делаем все буквы мелкими

    for (int i = 0; i < counter; ++i)
    {

        pop = (Spravochnik*)mySprav[i];               //делаем доступ к методу потомка 
        buff2 = pop->DEYATEL;
        buff2.erase(remove(buff2.begin(), buff2.end(), ' '), buff2.end());
        transform(buff2.begin(), buff2.end(), buff2.begin(), tolower);
        if (buff2 == buff)
        {
            cout << "\nМы нашли : \n";
            pop->getDATA();
            vopros = 1;
            break;
        }

    }

    if (vopros == 0)
    {
        cout << "\nТакой фирмы нет!\n";
    }
}
    //файл
void Spravochnik::save_to_file()
{
    fstream file;
    Spravochnik* pop;

    file.open("spravochnik.txt", ios::app);

    if (!file.is_open()) 
    {
        cout << "\nфайл не открылся\n";
    }
    else
    {
        for (int i = 0; i < counter; ++i)
        {
            pop = (Spravochnik*)mySprav[i];

            file << pop->NAME_FIRM << "\n";
            file << pop->NAME_DIRECTOR << "\n";
            file << pop->ADRESS << "\n";
            file << pop->DEYATEL << "\n";
            file << pop->TELEPH << "\n\n";
        }
    }
    file.close();

}
void Spravochnik::load_from_file()
{

    fstream file;

    string buff{};

    file.open("spravochnik.txt", ios::in | ios::out);

    if (!file.is_open())
    {
        cout << "\nфайл не открылся\n";
    }
    else
    {
        while (!file.eof())
        {
            getline(file, buff);
            cout << buff << endl;
        }
    }
    file.close();



}


int main()
{
    setlocale(LC_ALL, "ru");

    fstream file1;
    file1.open("spravochnik.txt", ios::out);
    if (!file1.is_open())
    {
        cout << "Файл не открылся" << endl;
    }
    else
    {
        cout << "Файл открылся" << endl;
    }
    file1.close();


    cout << "\n=-=-=-=-=-=-=-=- ТЕСТ 1 ЭКЗЕМПЛЯР =-=-=-=-=-=-=-\n";
    Spravochnik_DATA mySprav1;
    Spravochnik_DATA mySprav2("mySprav2", "mySprav2", "mySprav2", "mySprav2", "mySprav2");

    mySprav1.setDATA();
    cout << "\n=-=-=-=- mySprav1  =-=-=-\n";
    mySprav1.getDATA();
    cout << "\n=-=-=-=- mySprav2  =-=-=-\n";
    mySprav2.getDATA();

    cout << "\n=-=-=-=-=-=-=-=- ТЕСТ 2 ВЕКТОР =-=-=-=-=-=-=-\n";
    Spravochnik newSprav3;
    
    newSprav3.setDATA();
    newSprav3.setDATA();
    newSprav3.setDATA();
    cout << "\n=-=-=-=- newSprav3  =-=-=-\n";
    newSprav3.getDATA();
    cout << "\n=-=-=-=-=-=-=-=- ТЕСТ  3 ПОИСКИ =-=-=-=-=-=-=-\n";

    int ror = 3;
    while (ror>0)
    {
        newSprav3.poisk_nameFirm();
        newSprav3.poisk_nameDir();
        newSprav3.poisk_deyatel();
        newSprav3.poisk_telephon();
        --ror;
    }
    cout << "\n=-=-=-=-=-=-=-=- ТЕСТ  4 ФАЙЛ =-=-=-=-=-=-=-\n";

    newSprav3.save_to_file();

    newSprav3.load_from_file();


    

    
}
//Задание 1.
//Создать класс СПРАВОЧНИК со следующими полями :
//1 Название фирмы;
//2 Владелец;
//3 Телефон;
//4 Адрес;
//5 Род деятельности.
//Реализовать следующие возможности :
//1 Поиск по названию;
//2 Поиск по владельцу;
//3 Поиск по номеру телефона;
//4 Поиск по роду деятельности;
//5 Показ всех записей и добавление.
//Вся информация, должна сохранятся в файле, должна
//быть реализована возможность добавления новых данных.

