#include<iostream>
#include<cmath>

using namespace std;

#define delimiter  "\n_____________________________________\n"

class Fraction;
Fraction operator*(Fraction left, Fraction right);

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
	Fraction()
	{
		this->integer = 0;
		this->numerator = 0;
		this->denominator = 1;
		cout << "DefaultConstructor:\t\t" << this << endl;
	}
	Fraction(int integer)
	{
		this->integer = integer;
		this->numerator = 0;
		this->denominator = 1;
		cout << "SingleArgumentConstructor:\t\t" << this << endl;
	}
	Fraction(int numerator, int denominator)
	{
		this->integer = 0;
		this->numerator = numerator;
		set_denominator(denominator);
		cout << "Constructor:\t\t" << this << endl;
	}
	Fraction(int integer, int numerator, int denominator)
	{
		this->integer = integer;
		this->numerator = numerator;
		this -> set_denominator(denominator);
		cout << "Constructor:\t\t" << this << endl;
	}
	Fraction(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyConstructor:\t\t" << this << endl;
	}
	~Fraction()
	{
		cout << "Destructor:\t\t" << this << endl;
	}

	//Operators
	Fraction& operator=(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyAssignment:\t\t" << this << endl;
		return *this;
	}

	Fraction& operator*=(const Fraction& right)
	{
		cout << "Compound Assignment *= :\t\t" << endl;
		/*Fraction Self = *this;
		Self.to_improper();
		right.to_improper();
		numerator = numerator * right.numerator;
		denominator = denominator * right.denominator;*/
		return *this = *this * right;
	}

	//Methods
	Fraction& to_improper()
	{
		numerator += integer * denominator;
		integer = 0;
		return *this;
	}

	Fraction& to_proper()
	{
		integer += numerator / denominator;
		numerator %= denominator;
		return *this;
	}

	Fraction inverted() const
	{
		Fraction inverted = *this;
		inverted.to_improper();
		swap(inverted.numerator, inverted.denominator);
		return inverted;
	}
	void print()const
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
};


Fraction operator*(Fraction left, Fraction right)
{
	return Fraction
	(
	left.to_improper().get_numerator() * right.to_improper().get_numerator(),
	left.to_improper().get_denominator() * right.to_improper().get_denominator()
	).to_proper();
}

Fraction operator/(const Fraction& left, const Fraction& right)
{
	return 	left * right.inverted();		
}

//#define CONSTRACTORS_CHECK

void main()
{
	setlocale(LC_ALL, "");

#ifdef CONSTRACTORS_CHECK
	Fraction A;
	A.print();

	Fraction B = 5;
	B.print();

	Fraction C(1, 2);
	C.print();

	Fraction D( 2, 3, 4 );
	D.print();
#endif // CONSTRACTORS_CHECK

	Fraction A(2, 3, 4);
	A.print();
	cout << delimiter << endl;
	Fraction B(3, 4, 5);
	B.print();
	cout << delimiter << endl;
	Fraction C = A * B;
	C.print();
	cout << delimiter << endl;

	C = A / B;
	C.print();
	cout << delimiter << endl;

	A *= B;
	A.print();
	cout << delimiter << endl;
}














//#include<iostream>
//#include<cmath>
//#include<stdlib.h>
//
//using namespace std;
//
//#define delimiter  "\n_____________________________________\n"
//
//class Fraction
//{
//	int integer;		//целая часть
//	int numerator;		//числитель
//	int denominator;	//знаменатель
//public:
//	int get_integer() const
//	{
//		return integer;
//	}
//	int get_numerator() const
//	{
//		return numerator;
//	}
//	int get_denominator() const
//	{
//		return denominator;
//	}
//	void set_integer(int integer)
//	{
//		this->integer = integer;
//	}
//	void set_numerator(int numerator)
//	{
//		this->numerator = numerator;
//	}
//	void set_denominator(int denominator)
//	{
//		if (denominator == 0) denominator = 1;
//		this->denominator = denominator;
//	}
//
//	// Constructor
//	Fraction()
//	{
//		this->integer = 0;
//		this->numerator = 0;
//		this->denominator = 1;
//		cout << "DefaultConstructor:\t\t" << this << endl;
//	}
//	Fraction(int integer)
//	{
//		this->integer = integer;
//		this->numerator = 0;
//		this->denominator = 1;
//		cout << "SingleArgumentConstructor:\t\t" << this << endl;
//	}
//	Fraction(int numerator, int denominator)
//	{
//		this->integer = 0;
//		this->numerator = numerator;
//		set_denominator(denominator);
//		cout << "Constructor:\t\t" << this << endl;
//	}
//	Fraction(int integer, int numerator, int denominator)
//	{
//		this->integer = integer;
//		this->numerator = numerator;
//		this->set_denominator(denominator);
//		cout << "Constructor:\t\t" << this << endl;
//	}
//	Fraction(const Fraction& other)
//	{
//		this->integer = other.integer;
//		this->numerator = other.numerator;
//		this->denominator = other.denominator;
//		cout << "CopyConstructor:\t\t" << this << endl;
//	}
//	~Fraction()
//	{
//		cout << "Destructor:\t\t" << this << endl;
//	}
//
//	//Operators
//	Fraction& operator=(const Fraction& other)
//	{
//		this->integer = other.integer;
//		this->numerator = other.numerator;
//		this->denominator = other.denominator;
//		cout << "CopyAssignment:\t\t" << this << endl;
//		return *this;
//	}
//
//	Fraction& operator+=(Fraction& right)
//	{
//		cout << "Compound Assignment += :\t\t" << endl;
//		Fraction Self = *this;
//		Self.to_improper();
//		right.to_improper();
//		numerator = numerator * right.denominator + right.numerator * denominator;
//		denominator = denominator * right.denominator;
//		return Self.to_proper();
//	}
//
//	Fraction& operator-=(Fraction& right)
//	{
//		cout << "Compound Assignment -= :\t\t" << endl;
//		Fraction Self = *this;
//		Self.to_improper();
//		right.to_improper();
//		numerator = numerator * right.denominator - right.numerator * denominator;
//		denominator = denominator * right.denominator;
//		return Self.to_proper();
//	}
//
//	Fraction& operator*=(Fraction& right)
//	{
//		cout << "Compound Assignment *= :\t\t" << endl;
//		Fraction Self = *this;
//		Self.to_improper();
//		right.to_improper();
//		numerator = numerator * right.numerator;
//		denominator = denominator * right.denominator;
//		return Self.to_proper();
//	}
//
//	Fraction& operator/=(Fraction& right)
//	{
//		cout << "Compound Assignment /= :\t\t" << endl;
//		Fraction Self = *this;
//		Self.to_improper();
//		right.to_improper();
//		numerator = numerator * right.denominator;
//		denominator = denominator * right.numerator;
//		return Self.to_proper();
//	}
//
//	const Fraction operator++(int)
//	{
//		cout << "Increment ++ :\t\t" << endl;
//		Fraction inc = *this;
//		inc.to_improper();
//		numerator = numerator + denominator;
//		return inc;
//	}
//
//	const Fraction operator--(int)
//	{
//		cout << "Increment ++ :\t\t" << endl;
//		Fraction decr = *this;
//		decr.to_improper();
//		numerator = numerator - denominator;
//		return decr;
//	}
//
//	//Methods
//	Fraction& to_improper()
//	{
//		numerator += abs(integer) * denominator;
//		if (integer < 0) numerator = -numerator;
//		integer = 0;
//		return *this;
//	}
//
//	Fraction& to_proper()
//	{
//		integer += abs(numerator) / denominator;
//		if (numerator < 0)
//		{
//			integer = -integer;
//			numerator = abs(numerator);
//		}
//		numerator %= denominator;
//		return *this;
//	}
//
//	void print() const
//	{
//		if (integer) cout << integer;
//		if (numerator)
//		{
//			if (integer) cout << "(";
//			cout << numerator << "/" << denominator;
//			if (integer) cout << ")";
//		}
//		else if (integer == 0) cout << 0;
//		cout << endl;
//	}
//};
//
//
//Fraction operator+(Fraction left, Fraction right)
//{
//	return Fraction
//	(
//		left.to_improper().get_numerator() * right.to_improper().get_denominator() + right.to_improper().get_numerator() * left.to_improper().get_denominator(),
//		left.to_improper().get_denominator() * right.to_improper().get_denominator()
//	).to_proper();
//}
//
//Fraction operator-(Fraction left, Fraction right)
//{
//	return Fraction
//	(
//		left.to_improper().get_numerator() * right.to_improper().get_denominator() - right.to_improper().get_numerator() * left.to_improper().get_denominator(),
//		left.to_improper().get_denominator() * right.to_improper().get_denominator()
//	).to_proper();
//}
//
//Fraction operator*(Fraction left, Fraction right)
//{
//	//left.to_improper();
//	//right.to_improper();
//	//Fraction result;
//	//result.set_numerator(left.get_numerator() * right.get_numerator());
//	//result.set_denominator(left.get_denominator() * right.get_denominator());
//	//return result;
//	/*Fraction result
//	(
//		left.get_numerator() * right.get_numerator(),
//		left.get_denominator() * right.get_denominator()
//	);*/
//	//result.to_proper();
//	return Fraction
//	(
//		left.to_improper().get_numerator() * right.to_improper().get_numerator(),
//		left.to_improper().get_denominator() * right.to_improper().get_denominator()
//	).to_proper();
//}
//
//
//Fraction operator/(Fraction left, Fraction right)
//{
//	return Fraction
//	(
//		left.to_improper().get_numerator() * right.to_improper().get_denominator(),
//		left.to_improper().get_denominator() * right.to_improper().get_numerator()
//	).to_proper();
//}
//
////Fraction operator+=(Fraction& self, Fraction& right)
////{
////	cout << "Compound Assignment += :\t\t" << endl;
////	self.to_improper().set_numerator(self.to_improper().get_numerator() * right.to_improper().get_denominator() + right.to_improper().get_numerator() * self.to_improper().get_denominator());
////	self.to_improper().set_denominator(self.to_improper().get_denominator() * right.to_improper().get_denominator());
////	return self.to_proper();
////}
////
////Fraction operator-=(Fraction& self, Fraction& right)
////{
////	cout << "Compound Assignment -= :\t\t" << endl;
////	self.set_numerator(self.to_improper().get_numerator() * right.to_improper().get_denominator() - right.to_improper().get_numerator() * self.to_improper().get_denominator());
////	self.set_denominator(self.to_improper().get_denominator() * right.to_improper().get_denominator());
////	return self.to_proper();
////}
////
////Fraction operator*=(Fraction& self, Fraction& right)
////{
////	cout << "Compound Assignment *= :\t\t" << endl;
////	self.to_improper().set_numerator(self.to_improper().get_numerator() * right.to_improper().get_numerator());
////	self.to_improper().set_denominator(self.to_improper().get_denominator() * right.to_improper().get_denominator());
////	return self.to_proper();
////}
////
////Fraction operator/=(Fraction& self, Fraction& right)
////{
////	cout << "Compound Assignment /= :\t\t" << endl;
////	self.to_improper().set_numerator(self.to_improper().get_numerator() * right.to_improper().get_denominator());
////	self.to_improper().set_denominator(self.to_improper().get_denominator() * right.to_improper().get_numerator());
////	return self.to_proper();
////}
//
//bool operator==(Fraction& left, Fraction& right)
//{
//	return left.to_improper().get_numerator() * right.to_improper().get_denominator() == left.to_improper().get_denominator() * right.to_improper().get_numerator();
//}
//
//bool operator!=(Fraction& left, Fraction& right)
//{
//	return !(left == right);
//}
//
//bool operator>(Fraction& left, Fraction& right)
//{
//	return left.to_improper().get_numerator() * right.to_improper().get_denominator() > left.to_improper().get_denominator() * right.to_improper().get_numerator();
//}
//
//bool operator<(Fraction& left, Fraction& right)
//{
//	return left.to_improper().get_numerator() * right.to_improper().get_denominator() < left.to_improper().get_denominator() * right.to_improper().get_numerator();
//}
//
//bool operator>=(Fraction& left, Fraction& right)
//{
//	return left.to_improper().get_numerator() * right.to_improper().get_denominator() >= left.to_improper().get_denominator() * right.to_improper().get_numerator();
//}
//
//bool operator<=(Fraction& left, Fraction& right)
//{
//	return left.to_improper().get_numerator() * right.to_improper().get_denominator() <= left.to_improper().get_denominator() * right.to_improper().get_numerator();
//}
//
////#define CONSTRACTORS_CHECK
////#define ARITHMETIC OPERATORS
//#define COMPOUND ASSIGNMENTS
////#define INCREMENT_DECREMENT
////#define COMPARISON OPERATORS
//
//void main()
//{
//	setlocale(LC_ALL, "");
//
//#ifdef CONSTRACTORS_CHECK
//	Fraction A;
//	A.print();
//
//	Fraction B = 5;
//	B.print();
//
//	Fraction C(1, 2);
//	C.print();
//
//	Fraction D(2, 3, 4);
//	D.print();
//#endif // CONSTRACTORS_CHECK
//
//#ifdef ARITHMETIC OPERATORS
//	Fraction A(1, 2, 3);
//	A.print();
//	cout << delimiter << endl;
//
//	Fraction B(2, 3, 4);
//	B.print();
//	cout << delimiter << endl;
//
//	Fraction C = A * B;
//	C.print();
//	cout << delimiter << endl;
//
//	Fraction D = A / B;
//	D.print();
//	cout << delimiter << endl;
//
//	Fraction E = A + B;
//	E.print();
//	cout << delimiter << endl;
//
//	Fraction F = A - B;
//	F.print();
//	cout << delimiter << endl;
//#endif // ARITHMETIC OPERATORS
//
//#ifdef COMPOUND ASSIGNMENTS
//	Fraction A(1, 2, 3);
//	A.print();
//	/*A.to_improper().print();
//	A.to_proper().print();
//	A.to_improper().print();*/
//	cout << delimiter << endl;
//
//	Fraction B(2, 3, 4);
//	B.print();
//	cout << delimiter << endl;
//
//	A.to_improper().print();
//	B.to_improper().print();
//	A += B;
//	A.print();
//	B += A;
//	B.print();
//
//	cout << delimiter << endl;
//	Fraction C(1, 2, 3);
//	Fraction D(2, 3, 4);
//	C.to_improper().print();
//	D.to_improper().print();
//	C -= D;
//	C.to_improper().print();
//	C.to_proper().print();
//	D -= C;
//	D.to_proper().print();
//#endif // COMPOUND ASSIGNMENTS
//
//#ifdef INCREMENT_DECREMENT
//	Fraction A(1, 2, 3);
//	A.print();
//	A.to_improper().print();
//	A++;
//	A.print();
//	A--;
//	A.print();
//	A--;
//	A.print();
//#endif // INCREMENT_DECREMENT
//
//#ifdef COMPARISON OPERATORS
//	cout << delimiter << endl;
//	Fraction A(1, 2, 3);
//	Fraction B(2, 3, 4);
//	A.to_improper().print();
//	B.to_improper().print();
//
//	cout << (A == B) << endl;
//	cout << (A != B) << endl;
//	cout << (A > B) << endl;
//	cout << (A < B) << endl;
//	cout << (A >= B) << endl;
//	cout << (A <= B) << endl;
//
//#endif // COMPARISON OPERATORS
//
//}