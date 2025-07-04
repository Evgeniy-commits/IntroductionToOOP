#include<iostream>
#include<conio.h>
#include<iomanip>

using namespace std;

struct Point
{
	int x;
	int y;
};

void main()
{
	setlocale(LC_ALL, "");

	int answer{ 42 };						//Простая переменная
	const float goodTemp{ 36.6 };			//константа
	int grades[4]{ 3, 5, 4, 4 };			//одномерный массив
	int matrix[2][2]{ {1, 2}, {3, 4} };		//двумерный массив
	int* dataPtr{ nullptr };				//указатель
	char* str{ new char[14] {"Hello, world!"} };	//c-style строка, по-сути указатель
	int& reference{ answer };               //ссылка
	Point point{ 10, -6 };                  //экземпляр (объект) структуры
}