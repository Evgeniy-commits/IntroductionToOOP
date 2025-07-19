#include"Strh.h"

//Ќачало определени€ класса
int String::get_size() const
{
	return size;
}

const char* String::get_str() const
{
	return str;
}

char* String::get_str()
{
	return str;
}

String::String(int size) : size(size), str(new char[size] {})
{
	//this->size = size;
	//this->str = new char[size] {};
	cout << "DefaultConstruktor:\t" << this << endl;
}

void String::print() const
{
	cout << "Size:\t" << size << endl;
	cout << "Str:\t" << str << endl;
}

String::String(const char* str) : String(strlen(str) + 1)
{
	//this->size = strlen(str) + 1;
	//this->str = new char[size] {};
	for (int i = 0; i < size; i++) this->str[i] = str[i];
	cout << "SingleArgumentConstructor:\t" << this << endl;
}

String::String(const String& other) : String(other.str)
{
	//size = obj.size;
	////this->str = obj.str; //Shallow copy
	//str = new char[size];
	//for (int i = 0; i < size; i++) str[i] = obj.str[i];
	cout << "CopyConstructor:\t\t" << this << endl;
}

String& String::operator=(const String& obj)
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

String& String::operator=(String&& other) noexcept
{
	//провер€ем, что this != other
	if (this == &other) return *this;
	//удал€ем старую динамич пам€ть
	delete[] str;
	//shallow copy
	this->size = other.size;
	this->str = other.str;
	//обнул€ем принимаемый объект
	other.size = 0;
	other.str = nullptr;
	cout << "MoveAssignment:\t\t" << this << endl;
	return *this;
}
//            MOVE_METHODS
String::String(String&& other) noexcept : size(other.size), str(other.str)
{
	//this->size = other.size;
	//this->str = other.str;
	//обнул€ем принимаемый объект, д/т/ч предотвратить его удаление деструктором
	other.size = 0;
	other.str = nullptr;
	cout << "MoveConstructor:\t\t" << this << endl;
}

String::~String()
{
	delete[] str;
	str = nullptr;
	size = 0;
	cout << "Destruktor:\t\t" << this << endl;
}

char String::operator[](int i) const
{
	return str[i];
}

char& String::operator[](int i)
{
	return str[i];
}


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
//конец определени€ класса