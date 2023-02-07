#include <iostream>
#include <random>
using namespace std;

random_device Rand;


//int
void mass_Init_Int(int* mass, int size) 
{
	for (int i = 0; i < size; ++i) 
	{
		*(mass + i) = Rand() % 100;
	}
}
void mass_Show_Int(int* mass, int size)
{
	for (int i = 0; i < size; ++i)
	{
		cout << *(mass + i)<<" ";
	}
}
int mass_Min_Element_Int(int* mass, int size)
{
	int min = *mass;
	for (int i = 0; i < size; ++i)
	{
		if (min < *(mass + i))
		{
			min = *(mass + i);
		}
	}
	return min;
}
int mass_Max_Element_Int(int* mass, int size)
{
	int max = *mass;
	for (int i = 0; i < size; ++i)
	{
		if (max > *(mass + i))
		{
			max = *(mass + i);
		}
	}
	return max;
}
void mass_Sort_Int(int* mass, int size)
{
	for (int i = 0; i < size - 1; ++i)
	{
		for (int j = i + 1; j < size; ++j)
		{
			if (*(mass + i) > *(mass + j))
			{
				int tmp = *(mass + i);
				*(mass + i) = *(mass + j);
				*(mass + j) = tmp;

			}
		}
	}
}
void mass_Redactor_Int(int* mass, int size, int index, int number)
{
	*(mass + index) = number;

}


//double
void mass_Init_Double(double* mass, int size)
{
	for (int i = 0; i < size; ++i)
	{
		if (i % 2 == 0) 
		{
			*(mass + i) = Rand() % 1000/10.0;	
		}
		else
		{
			*(mass + i) = Rand() % 100 - 50;
		}
		
	}
}
void mass_Show_Double(double* mass, int size)
{
	for (int i = 0; i < size; ++i)
	{
		cout << *(mass + i) << " ";
	}
}
double mass_Min_Element_Double(double* mass, int size)
{
	double min = *mass;
	for (int i = 0; i < size; ++i)
	{
		if (min < *(mass + i))
		{
			min = *(mass + i);
		}
	}
	return min;
}
double mass_Max_Element_Double(double* mass, int size)
{
	double max = *mass;
	for (int i = 0; i < size; ++i)
	{
		if (max > *(mass + i))
		{
			max = *(mass + i);
		}
	}
	return max;
}
void mass_Sort_Double(double* mass, int size)
{
	for (int i = 0; i < size - 1; ++i)
	{
		for (int j = i + 1; j < size; ++j)
		{
			if (*(mass + i) > *(mass + j))
			{
				double tmp = *(mass + i);
				*(mass + i) = *(mass + j);
				*(mass + j) = tmp;

			}
		}
	}
}
void mass_Redactor_Double(double* mass, int size, int index, double number)
{
	*(mass + index) = number;

}


//char
void mass_Init_Char(char* mass, int size)
{
	for (int i = 0; i < size; ++i)
	{
		*(mass + i) = Rand() % 100;
	}
}
void mass_Show_Char(char* mass, int size)
{
	for (int i = 0; i < size; ++i)
	{
		cout << *(mass + i)<<" ";
	}
}
char mass_Min_Element_Char(char* mass, int size)
{
	char min = *mass;
	for (int i = 0; i < size; ++i)
	{
		if (min < *(mass + i))
		{
			min = *(mass + i);
		}
	}
	return min;
}
char mass_Max_Element_Char(char* mass, int size)
{
	char max = *mass;
	for (int i = 0; i < size; ++i)
	{
		if (max > *(mass + i))
		{
			max = *(mass + i);
		}
	}
	return max;
}
void mass_Sort_Char(char* mass, int size)
{
	for (int i = 0; i < size - 1; ++i)
	{
		for (int j = i + 1; j < size; ++j)
		{
			if (*(mass + i) > *(mass + j))
			{
				char tmp = *(mass + i);
				*(mass + i) = *(mass + j);
				*(mass + j) = tmp;

			}
		}
	}
}
void mass_Redactor_Char(char* mass, int size, int index, char number)
{
	*(mass + index) = number;

}

