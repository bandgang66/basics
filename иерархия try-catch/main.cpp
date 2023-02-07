#include <iostream>
#include <string>
#include <fstream>
#include "sotrudniks.h"
#include "tryCatchClass.h"

const string path1 = "sotrudniks.txt";


using namespace std;



void OpenFile(fstream& file,string path)  //�������� �����
{
	if (path != path1) 
	{
		throw exINT(0);
	}

	file.open(path,ios::out);
	file.close();
}

void saveFile(Sotrudniks* sotr) //���������� � ����
{
	string path;
	do
	{
		try
		{
			cout << "������� ���� � �����: " << endl;
			getline(cin, path);
			sotr->saveFile(path);
			cout << "���� ������!!!" << endl;
		}
		catch (excep& msg)
		{
			msg.what();
		}
	} while (path != path1);

}

void LoadFile(Sotrudniks* sotr) //�������� �� �����
{
	string path;
	do
	{
		try
		{
			cout << "������� ���� � �����: " << endl;
			getline(cin, path);
			sotr->LoadFile(path);
			cout << "���� ������!!!" << endl;
		}
		catch (excep& msg)
		{
			msg.what();
		}
	} while (path != path1);

}

int main()
{
	setlocale(LC_ALL, "ru");

	//������� ����� ����� �������				//try  except INT

	fstream file;
	string path;
	do
	{
		try
		{
			cout << "������� ���� � �����: " << endl;
			getline(cin, path);
			OpenFile(file, path);
			cout << "���� ������!!!" << endl;
		}
		catch (excep& msg)
		{
			msg.what();
		}
	} while (path!=path1);
	

	//�������� ��������

	Sotrudniks* newSotr = creatSotrud("Electric");
	Sotrudniks* newSotr2 = creatSotrud("Povar");
	Sotrudniks* newSotr3 = creatSotrud("Buhgalter");

	//���������� ������� �����		
	
	zapolnen(newSotr);
	zapolnen(newSotr2);
	zapolnen(newSotr3);

	//���������� ������������: 	
	cout << "��� ���������" << endl;
	addObyz(newSotr);
	cout << "��� ������" << endl;
	addObyz(newSotr2);
	cout << "��� ����������" << endl;
	addObyz(newSotr3);

	//����� �� �����
	cout << "��� ���������" << endl;
	newSotr->get();

	cout << "��� ������" << endl;
	newSotr2->get();

	cout << "��� ����������" << endl;
	newSotr3->get();

	//���������� � ����
	cout << "\n\n-=-=-=-=-=-=-=-=-=  ���������� � ����  -=-=-=-=--=-=-=-  newSort  =-=-=-=-===-=-=-=-=-=- \n\n";
	saveFile(newSotr);
	cout << "\n\n-=-=-=-=-=-=-=-=-=  ���������� � ����  -=-=-=-=--=-=-=-  newSort2  =-=-=-=-===-=-=-=-=-=- \n\n";
	saveFile(newSotr2);
	cout << "\n\n-=-=-=-=-=-=-=-=-=  ���������� � ����  -=-=-=-=--=-=-=-  newSort3  =-=-=-=-===-=-=-=-=-=- \n\n";
	saveFile(newSotr3);


	////�������� �� �����
	cout << "\n\n-=-=-=-=-=-=-=-=-=  �������� �� ����� -=-=-=-=--=-=-=-  newSort  =-=-=-=-===-=-=-=-=-=- \n\n";
	LoadFile(newSotr);
	cout << "\n\n-=-=-=-=-=-=-=-=-=  �������� �� ����� -=-=-=-=--=-=-=-  newSort2  =-=-=-=-===-=-=-=-=-=- \n\n";
	LoadFile(newSotr2);
	cout << "\n\n-=-=-=-=-=-=-=-=-=  �������� �� ����� -=-=-=-=--=-=-=-  newSort3  =-=-=-=-===-=-=-=-=-=- \n\n";
	LoadFile(newSotr3);



	//�������� ��������
	delete[] newSotr;
	delete[] newSotr2;
	delete[] newSotr3;
}