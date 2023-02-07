#pragma once

#include <iostream>
#include <string>
#include <fstream>


using namespace std;



class excep //сам класс 
{
	int intmsg{};
	string strmsg{};
	double doubmsg{};
public:
	excep(int i) :intmsg{i} {};
	excep(string s) :strmsg{ s } {};
	excep(double  d) :doubmsg{ d } {};
	excep() {};
	virtual void what() {};
};

//наследник для стринг
class exSTR:public excep
{
	string strMSG{};

public:
	exSTR(string msg) :excep(msg) { this->strMSG = msg; }
	exSTR() :exSTR{ "" } {}

	virtual void what() { cout << "ошибка ПРИВЫШЕН ЛИМИТ ОБЯЗАННОСТЕЙ -=-=- " <<strMSG << " НЕ БУДЕТ ДОБАВЛЕНА " << endl; }

};

//наследник для int
class exINT:public excep
{
	int intMSG{};
public:
	exINT(int msg) :excep(msg) { this->intMSG = msg; }
	exINT() :exINT{ 0 } {}

	virtual void what() { cout << "ошибка ОТКРЫТИЯ ФАЙЛА -=-=- file.is_open() = " << intMSG << endl; }
};

//наследник для double
class exDOUB :public excep
{
	double doubMSG{};
public:
	exDOUB(double msg) :excep(msg) { this->doubMSG = msg; }
	exDOUB() :exDOUB{ 0 } {}

	virtual void what() { cout << "СТАЖ МЕНЬШЕ 1.5 лет, = " << doubMSG << ", ТРЕБУЕТСЯ ПРОВЕСТИ СТАЖИРОВКУ" << endl; }
};