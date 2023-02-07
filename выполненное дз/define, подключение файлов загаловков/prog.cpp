#define INTEGER 1
#define DOUBLE 2
#define CHAR 3

#define COMPILED DOUBLE





#include <iostream>
#include "function.h"

using namespace std;

int main() 
{
	
 #if COMPILED==INTEGER

	int size1 = 10;
	int* mass1 = new int[size1];
	int index1 = 5;
	int number1 = 0;

	Init_Int(mass1,size1);
	Show_Int(mass1,size1);
	cout << Min_Int(mass1, size1);
	cout << Max_Int(mass1, size1);
	Sort_Int(mass1,size1);
	Redactor_Int(mass1,size1,index1,number1);
	Show_Int(mass1, size1);

	delete[] mass1;


#elif COMPILED==DOUBLE

	int size2 = 10;
	double* mass2 = new double[size2];
	int index2 = 5;
	double number2 = 0;

	Init_Double(mass2, size2);
	Show_Double(mass2, size2);
	cout << Min_Double(mass2, size2);
	cout << Max_Double(mass2, size2);
	Sort_Double(mass2, size2);
	Redactor_Double(mass2, size2, index2, number2);
	Show_Double(mass2, size2);

	delete[] mass2;


#elif COMPILED==CHAR


	int size3 = 10;
	char* mass3 = new char[size3];
	int index3 = 5;
	char number3 = 'a';

	Init_Char(mass3, size3);
	Show_Char(mass3, size3);
	cout << Min_Char(mass3, size3);
	cout << Max_Char(mass3, size3);
	Sort_Char(mass3, size3);
	Redactor_Char(mass3, size3, index3, number3);
	Show_Char(mass3, size3);

	delete[] mass3;

#endif


}