#include "Fraction.h"

Fraction::Fraction()
{
	this->integer = 0;
	this->numerator = 0;
	this->denominator = 1;
	cout << "DefaultConstructor:\t\t" << this << endl;
}

Fraction::Fraction(int integer)
{
	this->integer = integer;
	this->numerator = 0;
	this->denominator = 1;
	cout << "SingleArgumentConstructor:\t\t" << this << endl;
}

Fraction::Fraction(int numerator, int denominator)
{
	this->integer = 0;
	this->numerator = numerator;
	set_denominator(denominator);
	cout << "Constructor:\t\t" << this << endl;
}

Fraction::Fraction(int integer, int numerator, int denominator)
{
	this->integer = integer;
	this->numerator = numerator;
	this->set_denominator(denominator);
	cout << "Constructor:\t\t" << this << endl;
}

Fraction::Fraction(const Fraction& other)
{
	this->integer = other.integer;
	this->numerator = other.numerator;
	this->denominator = other.denominator;
	cout << "CopyConstructor:\t\t" << this << endl;
}

Fraction::~Fraction()
{
	cout << "Destructor:\t\t" << this << endl;
}

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

void Fraction::print() const
{
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

const Fraction& Fraction::operator=(const Fraction& other)
{
	this->integer = other.integer;
	this->numerator = other.numerator;
	this->denominator = other.denominator;
	cout << "CopyAssignment:\t\t" << this << endl;
	return *this;
}



const Fraction& Fraction::operator+=(Fraction& right)
{
	cout << "Compound Assignment += :\t\t" << endl;
	Fraction Self = *this;
	Self.to_improper();
	right.to_improper();
	numerator = numerator * right.denominator + right.numerator * denominator;
	denominator = denominator * right.denominator;
	return Self.to_proper();
}

const Fraction& Fraction::operator-=(Fraction& right)
{
	cout << "Compound Assignment -= :\t\t" << endl;
	Fraction Self = *this;
	Self.to_improper();
	right.to_improper();
	numerator = numerator * right.denominator - right.numerator * denominator;
	denominator = denominator * right.denominator;
	return Self.to_proper();
}

const Fraction& Fraction::operator*=(Fraction& right)
{
	cout << "Compound Assignment *= :\t\t" << endl;
	Fraction Self = *this;
	Self.to_improper();
	right.to_improper();
	numerator = numerator * right.numerator;
	denominator = denominator * right.denominator;
	return Self.to_proper();
}

const Fraction& Fraction::operator/=(Fraction& right)
{
	cout << "Compound Assignment /= :\t\t" << endl;
	Fraction Self = *this;
	Self.to_improper();
	right.to_improper();
	numerator = numerator * right.denominator;
	denominator = denominator * right.numerator;
	return Self.to_proper();
}

Fraction Fraction::operator++(int)
{
	cout << "Increment ++ :\t\t" << endl;
	Fraction inc = *this;
	inc.to_improper();
	numerator = numerator + denominator;
	return inc;
}

Fraction Fraction::operator--(int)
{
	cout << "Decrement -- :\t\t" << endl;
	Fraction inc = *this;
	inc.to_improper();
	numerator = numerator - denominator;
	return inc;
}

const Fraction& Fraction::operator+(Fraction& right)
{
	Fraction Res = *this;
	Res.to_improper();
	right.to_improper();
	numerator = numerator * right.denominator + right.numerator * denominator;
	denominator = denominator * right.denominator;
	return Res.to_proper();
}

const Fraction& Fraction::operator-(Fraction& right)
{
	Fraction Res = *this;
	Res.to_improper();
	right.to_improper();
	numerator = numerator * right.denominator - right.numerator * denominator;
	denominator = denominator * right.denominator;
	return Res.to_proper();
}

const Fraction& Fraction::operator*(Fraction& right)
{
	Fraction Res = *this;
	Res.to_improper();
	right.to_improper();
	numerator = numerator * right.numerator;
	denominator = denominator * right.denominator;
	return Res.to_proper();
}

const Fraction& Fraction::operator/(Fraction& right)
{
	Fraction Res = *this;
	Res.to_improper();
	right.to_improper();
	numerator = numerator * right.denominator;
	denominator = denominator * right.numerator;
	return Res.to_proper();
}

bool Fraction::operator==(Fraction& right)
{
	Fraction left = *this;
	left.to_improper();
	right.to_improper();
	return left.numerator * right.denominator == left.denominator * right.numerator;
}

bool Fraction::operator!=(Fraction& right)
{
	Fraction left = *this;
	left.to_improper();
	right.to_improper();
	return !(left.numerator * right.denominator == left.denominator * right.numerator);
}

bool Fraction::operator>(Fraction& right)
{
	Fraction left = *this;
	left.to_improper();
	right.to_improper();
	return left.numerator * right.denominator > left.denominator * right.numerator;
}

bool Fraction::operator<(Fraction& right)
{
	Fraction left = *this;
	left.to_improper();
	right.to_improper();
	return left.numerator * right.denominator < left.denominator * right.numerator;
}

bool Fraction::operator>=(Fraction& right)
{
	Fraction left = *this;
	left.to_improper();
	right.to_improper();
	return left.numerator * right.denominator >= left.denominator * right.numerator;
}

bool Fraction::operator<=(Fraction& right)
{
	Fraction left = *this;
	left.to_improper();
	right.to_improper();
	return left.numerator * right.denominator <= left.denominator * right.numerator;
}