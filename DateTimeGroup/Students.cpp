#include "Students.h"

Students::Students() 
{		
	first_name = new char[100];
	strcpy_s(first_name, 99, "Alex");
	last_name = new char[100];
	strcpy_s(last_name, 99, "H");
	numbertelefone = new char[100];
	strcpy_s(numbertelefone, 99, "000-000-00-00");
	birthday.day = 1;
	birthday.month = 1;
	birthday.year = 1900;	
	p_zachet[0] = 0;
	p_kurswork[0] = 0;
	p_ekzamen[0] = 0;

	int sizezachet = 1;
	int sizekurswork = 1;
	int sizeekz = 1;
}

 Students:: Students(const char* first_name, const char* last_name, const char* numbertelefone )
 {
	 this->first_name = new char[100];
	 strcpy_s(this->first_name, 99, first_name);

	 this->last_name = new char[100];
	 strcpy_s(this->last_name, 99, last_name);

	 this->numbertelefone = new char[100];
	 strcpy_s(this->last_name, 99, numbertelefone);
	 birthday.day = 1;
	 birthday.month = 1;
	 birthday.year = 1900;
	 p_zachet[0] = 0;
	 p_kurswork[0] = 0;
	 p_ekzamen[0] = 0;

	 int sizezachet = 1;
	 int sizekurswork = 1;
	 int sizeekz = 1;
	  
 }
 Students::Students(const Students& original)
 {
	 this->first_name = new char[100];
	 strcpy_s(this->first_name, 99, original.first_name);

	 this->last_name = new char[100];
	 strcpy_s(this->last_name, 99, original.last_name);

	 this->numbertelefone = new char[100];
	 strcpy_s(this->numbertelefone, 99, original.numbertelefone);

	 sizezachet = original.sizezachet;
	 sizekurswork = original.sizekurswork;
	 sizeekz = original.sizeekz;
	 for (int i = 0; i <= sizezachet; i++)
	 {
		 p_zachet[i] = original.p_zachet[i];
	 }
	 for (int i = 0; i <= sizekurswork; i++)
	 {
		 p_kurswork[i] = original.p_kurswork[i];
	 }
	 for (int i = 0; i <= sizeekz; i++)
	 {
		 p_ekzamen[i] = original.p_ekzamen[i];
	 }
	birthday.day = original.birthday.day;
	birthday.month = original.birthday.month;
	birthday.year = original.birthday.year;


 }

Students::~Students()
{
	if (first_name != nullptr) delete[] first_name;
	if (last_name != nullptr) delete[] last_name;
	if (numbertelefone != nullptr) delete[] numbertelefone;
	if (p_zachet != nullptr) delete[] p_zachet;
	if (p_kurswork != nullptr) delete[] p_kurswork;
	if (p_ekzamen != nullptr) delete[] p_ekzamen;
}



void Students::SetName(const char* first_name, const char* last_name)
{
	this->first_name = new char[100];
	strcpy_s(this->first_name, 99, first_name);

	this->last_name = new char[100];
	strcpy_s(this->last_name, 99, last_name);
}

void Students::SetBirthday(int day, int month, int year)
{
	if (day < 1 || day > 32 || month < 1 || month > 13 || year < 1900 || year > 2022)
	{
		birthday.day = 1;
		birthday.month = 1;
		birthday.year = 1900;
		cout << "\n";
		HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(h, 4);
		cout << "auto birthday : 01.01.1922\n";
		SetConsoleTextAttribute(h, 7);
	}
	else
	{
		birthday.day = day;
		birthday.month = month;
		birthday.year = year;
	}
}

void Students::SetTelefone(const char* numbertelefone)
{
	this->numbertelefone = new char[100];
	strcpy_s(this->numbertelefone, 99, numbertelefone);
}
void Students::Setzachet(int zachet)
{
	sizezachet++;
	p_zachet[sizezachet] = zachet;
}
void Students :: Setkursowa(int kursowa)
{
	
	sizekurswork++;
	p_kurswork[sizekurswork]= kursowa;
}
void Students :: SetEkz(int ekz)
{
	sizeekz++;
	p_ekzamen[sizeekz] = ekz;
}
void Students::GetShowAll() const
{
	
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, 14);
	cout << "first_name : " << first_name << "    last_name  : " << last_name << "    Telefone : "<< numbertelefone;
	cout << "    Birthday : " << birthday.day << "." << birthday.month << "." << birthday.year << "\n";
	for (int i = 0; i <= sizezachet; i++)
	cout << "Zachet "<< i <<" - " << p_zachet[i] << "; ";
	cout << "\n";
	for (int i = 0; i <= sizekurswork; i++)
	cout << "Kursowa " << i << " - " << p_kurswork[i] << "; ";
	cout << "\n";
	for (int i = 0; i <= sizeekz; i++)
	cout << "Ekzamn " << i << " - " << p_ekzamen[i] << "; "; 
	cout << "\n"; 
	cout << (char)1;
	cout << "\n";
	SetConsoleTextAttribute(h, 7);
}