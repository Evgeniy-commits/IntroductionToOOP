#include<iostream>
#include<cmath>

using namespace std;

class String
{
	char* STR;
	const int SIZE = 80;

	//Constructions
	String()
	{
		STR = nullptr;
		cout << "Отработал конструктор 1: " << STR << endl;
		system("pause");
	}
};

void main()
{
	setlocale(LC_ALL, "");
	const int SIZE = 80;
	String* Null_STR = new String[SIZE];

}