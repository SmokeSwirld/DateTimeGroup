#include "Libery.h"
using namespace std;


struct Birthday
{
	unsigned int day;
	unsigned int month;
	unsigned int year;
}; 

class Students
{
private:
	
	char* first_name;
	char* last_name;
	Birthday birthday;
	char* numbertelefone;
	int sizezachet = 0;
	int* p_zachet = new int[100];
	int sizekurswork = 0;
	int* p_kurswork = new int[100];
	int sizeekz = 0;
	int* p_ekzamen = new int[100];

public:
	
	Students();
	Students(const char* first_name, const char* last_name, const char* numbertelefone);
	Students(const Students& original);
	~Students();
	void SetTelefone(const char* numbertelefone);
	void SetName(const char* first_name, const char* last_name);
	void SetBirthday(int day, int month, int year);
	void Setzachet(int zachet);
	void Setkursowa(int kursowa);
	void SetEkz(int ekz);
	void GetShowAll() const;

};