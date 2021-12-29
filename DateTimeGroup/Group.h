#include "Libery.h"
#include "Students.h"


using namespace std;

class Group
{
private:

	Students* students = new Students[100];
		
	char* NameGroup;
	char* Specializationgroup;
	
	unsigned int numbercouse = 1;
	unsigned int studsquantity = 1;


public:

	Group()
	{
		
		NameGroup = new char[100];
		strcpy_s(NameGroup, 99, "Zero");
		Specializationgroup = new char[100];
		strcpy_s(Specializationgroup, 99, "Unknows");
		

		
		unsigned int numbercouse = 0;
		unsigned int studsquantity = 0;
	}
	Group(const char* nNameGroup, const char* sSpecializationgroup)
	{
		
		NameGroup = new char[100];
		strcpy_s(NameGroup, 99, nNameGroup);
		Specializationgroup = new char[100];
		strcpy_s(Specializationgroup, 99, sSpecializationgroup);
		numbercouse = 1;
		studsquantity = 1;
	}
	Group(const Group& original)
	{

	}

	Group(unsigned int kol)
	{
		students[0].SetName(" ", " ");
		NameGroup = new char[100];
		strcpy_s(NameGroup, 99, "First");
		Specializationgroup = new char[100];
		strcpy_s(Specializationgroup, 99, "Programs");
		numbercouse = 1;

		char* first = new char[100];
		char* last = new char[100];
		if (kol > 100) kol = 100;
		
		for (int i = 1; i <= kol; i++)
		{
			int j = rand() % 5;
			if (j == 1)
			{
				strcpy_s(first, 99, "Alex1");
				strcpy_s(last, 99, "Alex1");

				
			}
			else if (j==2)
			{
				strcpy_s(first, 99, "Alex2");
				strcpy_s(last, 99, "Alex2");
				
			}
			else if (j == 3)
			{
				strcpy_s(first, 99, "Alex3");
				strcpy_s(last, 99, "Alex3");
			
			}
			else if (j == 4)
			{
				strcpy_s(first, 99, "Alex4");
				strcpy_s(last, 99, "Alex4");
				
			}
			else
			{
				strcpy_s(first, 99, "Alex5");
				strcpy_s(last, 99, "Alex5");				
			}
			students[i].SetName(first, last);
			studsquantity++;

		}
		
	}
	//Group(Group& original)
	//{

	//}

	~Group()
	{
		if (students != nullptr)delete[]students;
		if (NameGroup != nullptr) delete[] NameGroup;
		if (Specializationgroup != nullptr) delete[] Specializationgroup;	
	}

	void Newstud(const char* first,const char* last)
	{	 
		 students[studsquantity].SetName(first, last);
		 studsquantity++;		
	}

	void ShowAll()
	{
		for (int i = 0; i < studsquantity; i++)
		{
			 students[i].GetShowAll();
			 cout << "NameGroup : " << NameGroup << " Specializationgroup : " << Specializationgroup  << " numbercouse : " << numbercouse<<"\n\n";
		}
	}

};