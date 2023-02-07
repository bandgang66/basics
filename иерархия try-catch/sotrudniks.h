#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "tryCatchClass.h"

using namespace std;

class Sotrudniks	//������� ����� ����������(������ ��� ���������)
{
protected:
	string name;	//���
	int ZP;			//��
	double staj;	//�������� ����
	const string path = "sotrudniks.txt"; //���� ��� �����

public:
	//������������
	Sotrudniks(string n, int zp, double s) :name(n), ZP(zp), staj(s) { cout << "[������ ���� ����������]" << endl; } //����������� ��� ������
	Sotrudniks() :Sotrudniks{ " ",0,0.0 } { cout << "[������ ���� ���������� default]" << endl; }	//������������� (������ �� ��������� )

	//�������
	virtual void setBase(string n, int zp, double st)		//����� ���������� ������ ����
	{
		ZP = zp;
		name = n;
		staj = st;

		if (st<1.5) 
		{
			throw exDOUB(st);
		}
	}


	//���� �������
	virtual void set(string obyz) {} //���� ����� ��� �����������, ����� ��������� �����������
	virtual void get() {}		//����� �� ����� (� ����������� ����� ��������� ����, ������� �����������)

	//���������� � ���� � �������� �� �����
	virtual void saveFile(string path2) {};
	virtual void LoadFile(string path2) {};



	//����������
	virtual ~Sotrudniks() { cout << "[~���������� ������ ���� ����������]" << endl; };

};

//����� ��������� ��������
class Electric :public Sotrudniks
{
	const string doljnost = "Electric";	//���������
	string obyzanosti{};	//�����������
	static int countObyz;	//������� ������������
	string flag = "+";	//��� ����������� � �����
public:
	Electric(string n, int zp, double s) :Sotrudniks{ n,zp,s } { cout << "[������ ���������]" << endl; }
	Electric() :Electric{ "",0,0.0 } { cout << "[������ ��������� default]" << endl; }



	virtual void set(string obyz)	//���������� ������������ ����-3
	{
		if (countObyz >= 3)
		{		
			throw exSTR(obyz);				//throw excep STRING
		}

		if (obyzanosti.size() < 1)
		{
			obyzanosti.append(obyz);
			countObyz = 1;
		}
		else
		{
			countObyz++;
			obyzanosti.append(" " + obyz);
		}
	}

	virtual void get()	//����� �� �����
	{
		cout << endl;
		cout << "���������: " << doljnost << endl;
		cout << "���: " << name << endl;
		cout << "�����������: " << obyzanosti << endl;
		cout << "�������� ����: " << staj << endl;
		cout << "���������: " << ZP << endl;
	}

	//���������� � ���� � �������� �� �����
		//����������
	virtual void saveFile(string path2)
	{
		ofstream file;

		if (path2 != path)
		{
			throw exINT(0);
		}

		file.open(path2, ios::app);

		if (!file.is_open())
		{
			cout << "���� �� ��������" << endl;
		}
		else
		{
			file << endl;
			file << flag << endl;
			file << "���������: " << doljnost << endl;
			file << "���: " << name << endl;
			file << "�����������: " << obyzanosti << endl;
			file << "�������� ����: " << staj << endl;
			file << "���������: " << ZP << endl;
			file << "*" << endl;
			file << endl;
		}

		file.close();

	};
	//�������� �� �����
	virtual void LoadFile(string path2)
	{
		ifstream file;

		if (path2 != path)
		{
			throw exINT(0);
		}

		file.open(path2, ios::in);

		if (!file.is_open())
		{
			cout << "���� �� ��������" << endl;
		}
		else
		{
			string buff1 = "";
			string buff2 = "";
			int poz = 0;
			int i = 0;


			while (!file.eof())
			{
				getline(file, buff1);
				if (buff1 == flag)
				{
					while (buff2.find("*") == string::npos)
					{
						getline(file, buff2);

						if (buff2.find("*") != string::npos)
							break;

						cout << buff2 << "\n";
					}
				}
			}
		}
		file.close();


	};
	~Electric()
	{
		cout << "[~���������� ������ ���������]" << endl;
	}
};
int Electric::countObyz{ 0 };


//����� ��������� �����
class Povar :public Sotrudniks
{
	const string doljnost = "Povar";
	string obyzanosti{};
	static int countObyz;
	string flag = "$";
public:
	Povar(string n, int zp, double s) :Sotrudniks{ n,zp,s } { cout << "[������ ������]" << endl; }
	Povar() :Povar{ "",0,0.0 } { cout << "[������ ������ default]" << endl; }

	virtual void set(string obyz)
	{
		if (countObyz >= 3)
		{
			throw exSTR(obyz);									//throw excep STRING
		}

		if (obyzanosti.size() < 1)
		{
			obyzanosti.append(obyz);
			countObyz = 1;
		}
		else
		{
			countObyz++;
			obyzanosti.append(" " + obyz);
		}
	}

	virtual void get()
	{
		cout << endl;
		cout << "���������: " << doljnost << endl;
		cout << "���: " << name << endl;
		cout << "�����������: " << obyzanosti << endl;
		cout << "�������� ����: " << staj << endl;
		cout << "���������: " << ZP << endl;
	}

	//���������� � ���� � �������� �� �����
		//����������
	virtual void saveFile(string path2)
	{
		ofstream file;

		if (path2 != path)
		{
			throw exINT(0);
		}

		file.open(path2, ios::app);
		if (!file.is_open())
		{
			cout << "���� �� ��������" << endl;
		}
		else
		{
			file << endl;
			file << flag << endl;
			file << "���������: " << doljnost << endl;
			file << "���: " << name << endl;
			file << "�����������: " << obyzanosti << endl;
			file << "�������� ����: " << staj << endl;
			file << "���������: " << ZP << endl;
			file << "*" << endl;
			file << endl;
		}

		file.close();

	};
	//�������� �� �����
	virtual void LoadFile(string path2)
	{
		ifstream file;

		if (path2 != path)
		{
			throw exINT(0);
		}

		file.open(path, ios::in);

		if (!file.is_open())
		{
			cout << "���� �� ��������" << endl;
		}
		else
		{
			string buff1 = "";
			string buff2 = "";
			int poz = 0;
			int i = 0;


			while (!file.eof())
			{
				getline(file, buff1);
				if (buff1 == flag)
				{
					while (buff2.find("*") == string::npos)
					{
						getline(file, buff2);

						if (buff2.find("*") != string::npos)
							break;

						cout << buff2 << "\n";
					}
				}
			}
		}
		file.close();


	};
	~Povar()
	{
		cout << "[~���������� ������ ������]" << endl;
	}
};
int Povar::countObyz{ 0 };

//�����-��������� ���������
class buhgalter :public Sotrudniks
{
	const string doljnost = "Buhgalter";
	string obyzanosti{};
	static int countObyz;
	string flag = "/";
public:
	buhgalter(string n, int zp, double s) :Sotrudniks{ n,zp,s } { cout << "[������ ����������]" << endl; }
	buhgalter() :buhgalter{ "",0,0.0 } { cout << "[������ ���������� default]" << endl; }

	virtual void set(string obyz)
	{
		if (countObyz >= 3)
		{
			throw exSTR(obyz);										//throw excep STRING
		}

		if (obyzanosti.size() < 1)
		{
			obyzanosti.append(obyz);
			countObyz = 1;
		}
		else
		{
			countObyz++;
			obyzanosti.append(" " + obyz);
		}
	}

	virtual void get()
	{
		cout << endl;
		cout << "���������: " << doljnost << endl;
		cout << "���: " << name << endl;
		cout << "�����������: " << obyzanosti << endl;
		cout << "�������� ����: " << staj << endl;
		cout << "���������: " << ZP << endl;
	}

	//���������� � ���� � �������� �� �����
		//����������
	virtual void saveFile(string path2)
	{
		ofstream file;

		if (path2 != path)
		{
			throw exINT(0);
		}

		file.open(path2, ios::app);
		if (!file.is_open())
		{
			cout << "���� �� ��������" << endl;
		}
		else
		{
			file << endl;
			file << flag << endl;
			file << "���������: " << doljnost << endl;
			file << "���: " << name << endl;
			file << "�����������: " << obyzanosti << endl;
			file << "�������� ����: " << staj << endl;
			file << "���������: " << ZP << endl;
			file << "*" << endl;
			file << endl;
		}

		file.close();

	};
	//�������� �� �����
	virtual void LoadFile(string path2)
	{
		ifstream file;


		if (path2 != path)
		{
			throw exINT(0);
		}


		file.open(path2, ios::in);

		if (!file.is_open())
		{
			cout << "���� �� ��������" << endl;
		}
		else
		{
			string buff1 = "";
			string buff2 = "";
			int poz = 0;
			int i = 0;


			while (!file.eof())
			{
				getline(file, buff1);
				if (buff1 == flag)
				{
					while (buff2.find("*") == string::npos)
					{
						getline(file, buff2);

						if (buff2.find("*") != string::npos)
							break;

						cout << buff2 << "\n";
					}
				}
			}
		}
		file.close();


	};
	~buhgalter()
	{
		cout << "[~���������� ������ ����������]" << endl;
	}
};
int buhgalter::countObyz{ 0 };

Sotrudniks* creatSotrud(string dolj)	
{
	if (dolj == "Electric")
	{
		return new Electric;
	}
	else if (dolj == "Povar")
	{
		return new Povar;
	}
	else if (dolj == "Buhgalter")
	{
		return new buhgalter;
	}
	else
	{
		return nullptr;
	}
}

void addObyz(Sotrudniks* sotr)					//TRY ��� THROW EXCEP STRING
{
	int vihod = 1;
	string obyz;
	do
	{
		try
		{
			
			cout << "������� �����������: " << endl;
			getline(cin, obyz);
			sotr->set(obyz);
			cout << "��� ������ �������  0, ��� �����������  1" << endl;
			cin >> vihod;

			cin.clear();
			cin.ignore(cin.rdbuf()->in_avail());
		}
		catch (excep& msg)
		{
			msg.what();
			
			break;
		}
	} while (vihod);

}

void zapolnen(Sotrudniks* sotr)							//TRY ��� THROW EXCEP DOUB
{
	string name;
	int zp;
	double staj;

	cout << "\n������� ���: " << endl;
	getline(cin, name);
	cout << "\n������� ��������: " << endl;
	cin >> zp;
	cout << "\n������� ����: " << endl;
	cin >> staj;
	
	cin.clear();
	cin.ignore(cin.rdbuf()->in_avail());

	try
	{
		sotr->setBase(name, zp, staj);
	}
	catch (excep& msg)
	{
		msg.what();
		
	}
	


}

