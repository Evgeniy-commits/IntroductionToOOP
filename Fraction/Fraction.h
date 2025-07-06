#pragma once
#include<iostream>
#include<conio.h>

using namespace std;

class Fraction
	{
		int integer;		//целая часть
		int numerator;		//числитель
		int denominator;	//знаменатель
	public:
		int get_integer() const
		{
			return integer;
		}
		int get_numerator() const
		{
			return numerator;
		}
		int get_denominator() const
		{
			return denominator;
		}
		void set_integer(int integer)
		{
			this -> integer = integer;
		}
		void set_numerator(int numerator)
		{
			this -> numerator = numerator;
		}
		void set_denominator(int denominator)
		{
			if (denominator == 0) denominator = 1;
			this -> denominator = denominator;
		}
	
		// Constructor
		Fraction();
		Fraction(int integer);
		Fraction(int numerator, int denominator);
		Fraction(int integer, int numerator, int denominator);
		Fraction(const Fraction& other);
		~Fraction();
		
		//Operators
		const Fraction& operator=(const Fraction& other);
		const Fraction& operator+=(Fraction& right);
		const Fraction& operator-=(Fraction& right);
		const Fraction& operator*=(Fraction& right);
		const Fraction& operator/=(Fraction& right);
		Fraction operator++(int);
		Fraction operator--(int);
		const Fraction& operator+(Fraction& right);
		const Fraction& operator-(Fraction& right);
		const Fraction& operator*(Fraction& right);
		const Fraction& operator/(Fraction& right);
		bool operator==(Fraction& right);
		bool operator!=(Fraction& right);
		bool operator>(Fraction& right);
		bool operator<(Fraction& right);
		bool operator>=(Fraction& right);
		bool operator<=(Fraction& right);
		
		//Methods
		Fraction& to_improper();
		Fraction& to_proper();
		
		void print() const;
	};

