﻿#include<iostream>
//#include<cmath>
//#include<string>
//#include<conio.h>
//#include<Windows.h>

using namespace std;

#define delimiter  "\n_____________________________________\n"
class String;
std::ostream& operator<<(std::ostream& os, const String& obj);


class String
{
private:
	int size;	// размер строки в байтах(с учетом нуля)
	char* str; // адрес строки в динамич памяти

public:

	int get_size() const
	{
		return size;
	}

	const char* get_str() const
	{
		return str;
	}

	char* get_str()
	{
		return str;
	}

    explicit String(int size = 80)
	{
		this->size = size;
		this->str = new char[size] {};
		cout << "DefaultConstruktor:\t" << this << endl;
	}

	void print() const
	{
		cout << "Size:\t" << size << endl;
		cout << "Str:\t" << str << endl;
	}

	String(const char* str)
	{
		this->size = strlen(str) + 1;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++) this->str[i]	= str[i];
		cout << "SingleArgumentConstructor:\t" << this << endl;
	}

	String(const String& obj)
	{
		size = obj.size;
		//this->str = obj.str; //Shallow copy
		str = new char[size];
		for (int i = 0; i < size; i++) str[i] = obj.str[i];
		cout << "CopyConstructor:\t\t" << this << endl;
	}

	String& operator=(const String& obj)
	{
		if (this == &obj) return *this;
		this->~String();
		size = obj.size;
		//this->str = obj.str; //Shallow copy
		str = new char[size];
		for (int i = 0; i < size; i++) str[i] = obj.str[i];
		cout << "CopyAssignment:\t\t" << this << endl;
		return *this;
	}

	String& operator=(String&& other) noexcept
	{
		//проверяем, что this != other
		if (this == &other) return *this;
		//удаляем старую динамич память
		delete[] str;
		//shallow copy
		this->size = other.size;
		this->str = other.str;
		//обнуляем принимаемый объект
		other.size = 0;
		other.str = nullptr;
		cout << "MoveAssignment:\t\t" << this << endl;
		return *this;
	}
	//            MOVE_METHODS
	String (String&& other) noexcept
	{
		this->size = other.size;
		this->str = other.str;
		//обнуляем принимаемый объект, д/т/ч предотвратить его удаление деструктором
		other.size = 0;
		other.str = nullptr;
		cout << "MoveConstructor:\t\t" << this << endl;
	}

	~String()
	{
		delete[] str;
		str = nullptr;
		size = 0;
		cout << "Destruktor:\t\t" << this << endl;
	}

	char operator[](int i) const
	{
		return str[i];
	}

	char& operator[](int i)
	{
		return str[i];
	}

	


};

String operator+(const String& left, const String& right)
{
	String result(left.get_size() + right.get_size() - 1);
	for (int i = 0; i < left.get_size(); i++)
		result[i] = left[i];
		//result.get_str()[i] = left.get_str()[i];
	for (int i = 0; i < right.get_size(); i++)
		result[i + left.get_size() - 1] = right[i];
		//result[i + left.get_size() - 1] = right[i];
	return result;
}

std::ostream& operator<<(std::ostream& os, const String& obj)
{
	return os << obj.get_str();
}


//#define CONSTRACTORS_CHECK 
//#define COPY_SEMANTIC 
#define MOVE_METHODS
void main()
{
	setlocale(LC_ALL, "");
#ifdef CONSTRACTORS_CHECK
	String str1;
	str1.print();

	String str2{ 5 };
	str2.print();

	String str3 = "Hello";
	cout << str3 << endl;

	String str4{ "World" };
	cout << str4 << endl;
	String str5 = str3 + str4;
	cout << str5 << endl;
	cout << delimiter << endl;
#endif // CONSTRACTORS_CHECK

#ifdef COPY_SEMANTIC
	cout << delimiter << endl;
	String str1 = "Hello";
	cout << str1 << endl;
	cout << delimiter << endl;
	String str2 = str1;
	cout << str2 << endl;
	cout << delimiter << endl;
	String str3;
	str1 = str1;
	str3 = str1;
	cout << str3 << endl;
	cout << delimiter << endl;
#endif // COPY_SEMANTIC

#ifdef MOVE_METHODS
	String str3 = "Hello";
	cout << str3 << endl;
	cout << delimiter << endl;
	String str4{ "World" };
	cout << str4 << endl;
	cout << delimiter << endl;
	String str5;
	str5 = str3 + str4;
	cout << delimiter << endl;
	cout << str5 << endl;
#endif // MOVE_METHODS


}
