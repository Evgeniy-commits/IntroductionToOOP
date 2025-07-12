#include<iostream>
#include<cmath>
#include<string>
#include<conio.h>
#include<iomanip>

using namespace std;

#define delimiter  "\n_____________________________________\n"

class String
{
private:
	char* str;
	
	char* createstr(const char* str);
public:
	String();
	String(const char* str);
	String(const String& other);
	~String();
	
	char* get_string() const;
	void  set_string(char* str);

	//Operators
	String& operator=(const String& other);
	friend String operator+(const String& left, const String& right);
	friend std::ostream& operator<<(std::ostream& os, const String& other);
	friend istream& operator>>(istream& is, String& str);
};


void main()
{
	setlocale(LC_ALL, "");
	
	String Str_1{};
	String Str_2{};
	String Str_3{};
	cout << "Введите сроку: " << endl; cin >> Str_1 ;
	cout << "Больше срок: " << endl; cin >> Str_2 ;
	cout << "Еще Больше срок: " << endl; cin >> Str_3 ;
	cout << Str_1 + Str_2 + Str_3 << endl;
	
}

String::String()
{
	str = nullptr;
 	cout << "Отработал конструктор 1: " << this << endl;
	system("pause");
}

String::String(const char* str)
{
	createstr(str);
	cout << "Отработал конструктор 2: " << str << endl;
 	system("pause");
}

String::String(const String& other)
{
	int length = strlen(other.str);
	for (int i = 0; i < length; i++) str[i] = other.str[i];
	str[length] = '\0';
	cout << "CopyConstructor:\t\t" << str << endl;
}

String::~String()
{
	cout << "Отработал деструктор" << str << endl;
	if (str != nullptr) delete[] str;
	system("pause");
}

char* String::get_string() const
{
	return str;
}

void String::set_string(char* str)
{
	delete[] str;
	str = nullptr;
	createstr(str);
}

char* String::createstr(const char* enterstr)
{
	int strLength = strlen(enterstr);
	str = new char[strLength + 1];
	for (int i = 0; i <= strLength; i++) str[i] = enterstr[i];
	return str;
}

//Operators
String& String::operator=(const String& other)
{   
	int length = strlen(other.str);
	str = new char[length + 1];
	for (int i = 0; i < length; i++) str[i] = other.str[i];
	str[length] = '\0';
	cout << "CopyAssignment:\t\t" << this << endl;
	return *this;
}

String operator+(const String& left, const String& right)
{
	int length = strlen(left.str) + strlen(right.str);
	char* buffer = new char[length + 1];
	for (int i = 0; i < strlen(left.str); i++)
		buffer[i] = left.str[i];
	for (int i = 0; i < length; i++)
		buffer[i + strlen(left.str)] = right.str[i];
	return buffer;
}

std::ostream& operator<<(std::ostream& os, const String& other) 
{
	os << other.str;
	return os;
}

std::istream& operator>>(std::istream& is, String& other)
{
	const int n = 256;
	char buffer[n] = {};
	is.getline(buffer, n);
	int length = strlen(buffer);
	other.str = new char[length + 1] {};
	for (int i = 0; i < length; i++) other.str[i] = buffer[i];
	other.str[length] = '\0';
	return is;
}
	

//bool operator==(String& left, String& right)
//{
//	return strcmp(left.get_string(), right.get_string()) == 0;
//}

