#include "Fraction.h"


int Fraction::get_integer() const
{
	return integer;
}
int Fraction::get_numerator() const
{
	return numerator;
}
int Fraction::get_denominator() const
{
	return denominator;
}
void Fraction::set_integer(int integer)
{
	this->integer = integer;
}
void Fraction::set_numerator(int numerator)
{
	this->numerator = numerator;
}
void Fraction::set_denominator(int denominator)
{
	if (denominator == 0) denominator = 1;
	this->denominator = denominator;
}

// Constructor
Fraction::Fraction() : integer(0), numerator(0), denominator(1)
{
	cout << "DefaultConstructor:\t\t" << this << endl;
}
Fraction::Fraction(int integer) : integer(integer), numerator(0), denominator(1)
{
	cout << "SingleArgumentConstructor:\t\t" << this << endl;
}
Fraction::Fraction(int numerator, int denominator) : integer(0), numerator(numerator), denominator(denominator)
{
	this->set_denominator(denominator);
	cout << "Constructor:\t\t" << this << endl;
}
Fraction::Fraction(int integer, int numerator, int denominator) : integer(integer), numerator(numerator), denominator(denominator)
{
	this->set_denominator(denominator);
	cout << "Constructor:\t\t" << this << endl;
}

Fraction::Fraction(double number)
{
	number += 1e-10;
	integer = number;
	number -= integer;
	denominator = 1e+9;
	numerator = number * denominator;
	reduce();
	cout << "doubleConstructor:\t" << this << endl;
}
Fraction::Fraction(const Fraction& other) : integer(other.integer), numerator(other.numerator), denominator(other.denominator)
{
	cout << "CopyConstructor:\t\t" << this << endl;
}
Fraction::~Fraction()
{
	cout << "Destructor:\t\t" << this << endl;
}

//Operators
Fraction& Fraction::operator=(const Fraction& other)
{
	this->integer = other.integer;
	this->numerator = other.numerator;
	this->denominator = other.denominator;
	cout << "CopyAssignment:\t\t" << this << endl;
	return *this;
}

Fraction& Fraction::operator+=(Fraction& right)
{
	cout << "Compound Assignment += :\t\t" << endl;
	return *this = *this + right;
}

Fraction& Fraction::operator-=(Fraction& right)
{
	cout << "Compound Assignment -= :\t\t" << endl;
	return *this = *this - right;
}

Fraction& Fraction::operator*=(const Fraction& right)
{
	cout << "Compound Assignment *= :\t\t" << endl;
	return *this = *this * right;
}

Fraction& Fraction::operator/=(const Fraction& right)
{
	cout << "Compound Assignment /= :\t\t" << endl;
	return *this = *this / right;
}

Fraction& Fraction::operator++()
{
	cout << "Prefix Increment ++ :\t\t" << endl;
	integer++;
	return *this;
}

Fraction& Fraction::operator--()
{
	cout << "Prefix Decrement -- :\t\t" << endl;
	integer--;
	return *this;
}

const Fraction Fraction::operator++(int)
{
	cout << "Postfix Increment ++ :\t\t" << endl;
	Fraction inc = *this;
	integer++;
	return inc;
}

const Fraction Fraction::operator--(int)
{
	cout << "Postfix Decrement -- :\t\t" << endl;
	Fraction decr = *this;
	integer--;
	return decr;
}

// Type-cast operators

Fraction::operator int()const
{
	return integer + numerator / denominator;
}

Fraction::operator double()const
{
	return integer + (double)numerator / denominator;
}

Fraction::operator Fraction() const
{
	return *this;
}

//Methods

Fraction& Fraction::to_improper()
{
	numerator += abs(integer) * denominator;
	if (integer < 0) numerator = -numerator;
	integer = 0;
	return *this;
}

Fraction& Fraction::to_proper()
{
	integer += abs(numerator) / denominator;
	if (numerator < 0)
	{
		integer = -integer;
		numerator = abs(numerator);
	}
	numerator %= denominator;
	return *this;
}

Fraction Fraction::inverted() const
{
	Fraction inverted = *this;
	inverted.to_improper();
	swap(inverted.numerator, inverted.denominator);
	return inverted;
}

Fraction& Fraction::reduce()
{
	int more, less, rest;
	if (numerator > denominator) more = numerator, less = denominator;
	else less = numerator, more = denominator;
	do
	{
		rest = more % less;
		more = less;
		less = rest;
	} while (rest);
	int GCD = more; // наибольший общий делитель;
	numerator /= GCD;
	denominator /= GCD;
	return *this;
}

void Fraction::print()const
{
	if (denominator == 0)
	{
		cout << "Zero Division" << endl;
	}
	if (integer) cout << integer;
	if (numerator)
	{
		if (integer) cout << "(";
		cout << numerator << "/" << denominator;
		if (integer) cout << ")";
	}
	else if (integer == 0) cout << 0;
	cout << endl;
}

Fraction operator+(Fraction left, Fraction right)
{
	cout << "OPERATOR+ \t\t" << endl;
	return Fraction
	(
		left.to_improper().get_numerator() * right.to_improper().get_denominator() + right.to_improper().get_numerator() * left.to_improper().get_denominator(),
		left.to_improper().get_denominator() * right.to_improper().get_denominator()
	).to_proper();
}

Fraction operator-(Fraction left, Fraction right)
{
	cout << "OPERATOR- \t\t" << endl;
	return Fraction
	(
		left.to_improper().get_numerator() * right.to_improper().get_denominator() - right.to_improper().get_numerator() * left.to_improper().get_denominator(),
		left.to_improper().get_denominator() * right.to_improper().get_denominator()
	).to_proper();
}

Fraction operator*(Fraction left, Fraction right)
{
	cout << "OPERATOR* \t\t" << endl;
	return Fraction
	(
		left.to_improper().get_numerator() * right.to_improper().get_numerator(),
		left.to_improper().get_denominator() * right.to_improper().get_denominator()
	).to_proper().reduce();
}

Fraction operator/(const Fraction& left, const Fraction& right)
{
	cout << "OPERATOR/ \t\t" << endl;
	return 	left * right.inverted();
}

bool operator==(Fraction left, Fraction right)
{
	return left.to_improper().get_numerator() * right.to_improper().get_denominator() == left.to_improper().get_denominator() * right.to_improper().get_numerator();
}

bool operator!=(const Fraction& left, const Fraction& right)
{
	return !(left == right);
}

bool operator>(Fraction left, Fraction right)
{
	return left.to_improper().get_numerator() * right.to_improper().get_denominator() > left.to_improper().get_denominator() * right.to_improper().get_numerator();
}

bool operator<(Fraction left, Fraction right)
{
	return left.to_improper().get_numerator() * right.to_improper().get_denominator() < left.to_improper().get_denominator() * right.to_improper().get_numerator();
}

bool operator>=(const Fraction& left, const Fraction& right)
{
	return !(left < right);
}

bool operator<=(const Fraction& left, const Fraction& right)
{
	return !(left > right);
}

std::ostream& operator<<(std::ostream& os, const Fraction& obj)
{
	if (obj.denominator == 0)
	{
		os << "Zero Division Error" << endl;
		return os;
	}
	if (obj.integer) os << obj.integer;
	if (obj.numerator)
	{
		if (obj.integer) os << "(";
		os << obj.numerator << "/" << obj.denominator;
		if (obj.integer) os << ")";
	}
	else if (obj.integer == 0) os << 0;
	return os;
}

std::istream& operator>>(std::istream& is, Fraction& obj)
{
	const int SIZE = 256; //размер буфера ввода
	char buffer[SIZE] = {};
	is.getline(buffer, SIZE);
	int n = 0; //кол-во введенных чисел
	int numbers[3] = {};
	const char delimiters[] = "(/, )";
	for (char* pch = strtok(buffer, delimiters); pch && n < 3; pch = strtok(NULL, delimiters))
		numbers[n++] = atoi(pch);
	for (int i = 0; i < n; i++) cout << numbers[i] << "\t"; cout << endl;

	switch (n)
	{
	case 0: obj = Fraction(); break;
	case 1:	obj = Fraction(numbers[0]); break;
	case 2:	obj = Fraction(numbers[0], numbers[1]);	break;
	case 3: obj = Fraction(numbers[0], numbers[1], numbers[2]);	break;
	}

	return is;
}