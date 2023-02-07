
#ifdef  INTEGER
#define Init_Int mass_Init_Int
#define Show_Int mass_Show_Int
#define Min_Int mass_Min_Element_Int
#define Max_Int mass_Max_Element_Int
#define Sort_Int mass_Sort_Int
#define Redactor_Int mass_Redactor_Int
//int
void mass_Init_Int(int* mass, int size);
void mass_Show_Int(int* mass, int size);
int mass_Min_Element_Int(int* mass, int size);
int mass_Max_Element_Int(int* mass, int size);
void mass_Sort_Int(int* mass, int size);
void mass_Redactor_Int(int* mass, int size, int index, int number);

#endif //  INTEGER

#ifdef  DOUBLE
#define Init_Double mass_Init_Double
#define Show_Double mass_Show_Double
#define Min_Double mass_Min_Element_Double
#define Max_Double mass_Max_Element_Double
#define Sort_Double mass_Sort_Double
#define Redactor_Double mass_Redactor_Double
//double
void mass_Init_Double(double* mass, int size);
void mass_Show_Double(double* mass, int size);
double mass_Min_Element_Double(double* mass, int size);
double mass_Max_Element_Double(double* mass, int size);
void mass_Sort_Double(double* mass, int size);
void mass_Redactor_Double(double* mass, int size, int index, double number);

#endif 


#ifdef CHAR
#define Init_Char mass_Init_Char
#define Show_Char mass_Show_Char
#define Min_Char mass_Min_Element_Char
#define Max_Char mass_Max_Element_Char
#define Sort_Char mass_Sort_Char
#define Redactor_Char mass_Redactor_Char
//char
void mass_Init_Char(char* mass, int size);
void mass_Show_Char(char* mass, int size);
char mass_Min_Element_Char(char* mass, int size);
char mass_Max_Element_Char(char* mass, int size);
void mass_Sort_Char(char* mass, int size);
void mass_Redactor_Char(char* mass, int size, int index, char number);

#endif 
