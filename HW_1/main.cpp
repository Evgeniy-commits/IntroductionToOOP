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

	int answer{ 42 };						//������� ����������
	const float goodTemp{ 36.6 };			//���������
	int grades[4]{ 3, 5, 4, 4 };			//���������� ������
	int matrix[2][2]{ {1, 2}, {3, 4} };		//��������� ������
	int* dataPtr{ nullptr };				//���������
	char* str{ new char[14] {"Hello, world!"} };	//c-style ������, ��-���� ���������
	int& reference{ answer };               //������
	Point point{ 10, -6 };                  //��������� (������) ���������
}