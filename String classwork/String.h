#pragma once

#include<iostream>
//#include<cmath>
//#include<string>
//#include<conio.h>
//#include<Windows.h>

using namespace std;

#define delimiter  "\n_____________________________________\n"


//������ ����������
class String
{
private:
	int size;	// ������ ������ � ������(� ������ ����)
	char* str;  // ����� ������ � ������� ������

public:

	int get_size() const;
	const char* get_str() const;
	char* get_str();
	//Constructors
	explicit String(int size = 80); //int size ������ � ���������
	String(const char* str);
	String(const String& other);
	String(String&& other) noexcept;
	~String();
	//Operators
	String& operator=(const String& obj);
	String& operator=(String&& other) noexcept;
	char operator[](int i) const;
	char& operator[](int i);
	//Methods
	void print() const;
}; 

String operator+(const String& left, const String& right);
std::ostream& operator<<(std::ostream& os, const String& obj);
//����� ����������