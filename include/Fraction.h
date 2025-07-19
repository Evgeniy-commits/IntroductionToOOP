#pragma once

#include<iostream>
#include<cmath>
#include<string>
#include<conio.h>
#include<iomanip>

//#pragma GCC diagnostic push  
//#pragma GCC diagnostic ignored "4944"  
//#pragma GCC diagnostic pop 
using namespace std;
using std::cout;
#define delimiter  "\n_____________________________________\n"

class Fraction;
Fraction operator*(Fraction left, Fraction right);
Fraction operator/(const Fraction& left, const Fraction& right);
Fraction operator+(Fraction left, Fraction right);
Fraction operator-(Fraction left, Fraction right);
bool operator==(Fraction left, Fraction right);
bool operator!=(const Fraction& left, const Fraction& right);
bool operator>(Fraction left, Fraction right);
bool operator<(Fraction left, Fraction right);
bool operator>=(const Fraction& left, const Fraction& right);
bool operator<=(const Fraction& left, const Fraction& right);

class Fraction
{
	int integer;		//целая часть
	int numerator;		//числитель
	int denominator;	//знаменатель
public:
	int get_integer() const;
	int get_numerator() const;
	int get_denominator() const;
	void set_integer(int integer);
	void set_numerator(int numerator);
	void set_denominator(int denominator);

	// Constructor
	Fraction();
	explicit Fraction(int integer);
	Fraction(int numerator, int denominator);
	Fraction(int integer, int numerator, int denominator);
	Fraction(double number);
	Fraction(const Fraction& other);
	~Fraction();

	//Operators
	Fraction& operator=(const Fraction& other);
	Fraction& operator+=(Fraction& right);
	Fraction& operator-=(Fraction& right);
	Fraction& operator*=(const Fraction& right);
	Fraction& operator/=(const Fraction& right);
	Fraction& operator++(); // Prefix increment
	Fraction& operator--(); // Prefix Decrement
	const Fraction operator++(int); //Postfix increment
	const Fraction operator--(int); //Postfix Decrement

	//Operators stream
	friend std::ostream& operator<<(std::ostream& os, const Fraction& obj);
	friend istream& operator>>(istream& is, Fraction& obj);

	// Type-cast operators
	explicit operator int()const;
	explicit operator double()const;
	explicit operator Fraction() const;

	//Methods
	Fraction& to_improper();
	Fraction& to_proper();
	Fraction inverted() const;
	Fraction& reduce();
	void print()const;
};
