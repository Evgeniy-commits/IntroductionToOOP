#include<iostream>
#include<cmath>

using namespace std;
using std::cout;
#define delimiter  "\n_____________________________________\n"

class Fraction;
Fraction operator*(Fraction left, Fraction right);
Fraction operator/(const Fraction& left, const Fraction& right);
Fraction operator+(Fraction left, Fraction right);
Fraction operator-(Fraction left, Fraction right);


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
	explicit Fraction(int integer)
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

	Fraction(double number)
	{
		integer = (int)number;
		number -= integer;

		while ((number - int(number)) != 0)
		{
			number *= 10;
			denominator *= 10;
		}
		numerator = number;
		reduce();
		cout << "doubleConstructor:\t" << this << endl;
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

	Fraction& operator+=(Fraction& right)
	{
		cout << "Compound Assignment += :\t\t" << endl;
		return *this = *this + right;
	}

	Fraction& operator-=(Fraction& right)
	{
		cout << "Compound Assignment -= :\t\t" << endl;
		return *this = *this - right;
	}

	Fraction& operator*=(const Fraction& right)
	{
		cout << "Compound Assignment *= :\t\t" << endl;
		return *this = *this * right;
	}

	Fraction& operator/=(const Fraction& right)
	{
		cout << "Compound Assignment /= :\t\t" << endl;
		return *this = *this / right;
	}

	Fraction& operator++()
	{
		cout << "Prefix Increment ++ :\t\t" << endl;
		integer++;
		return *this;
	}
	
	Fraction& operator--()
	{
		cout << "Prefix Decrement -- :\t\t" << endl;
		integer--;
		return *this;
	}

	const Fraction operator++(int)
	{
		cout << "Postfix Increment ++ :\t\t" << endl;
		Fraction inc = *this;
		integer++;
		return inc;
	}

	const Fraction operator--(int)
	{
		cout << "Postfix Decrement -- :\t\t" << endl;
		Fraction decr = *this;
		integer--;
		return decr;
	}

	//Operators stream

	friend std::ostream& operator<<(std::ostream& os, const Fraction& obj);
	friend istream& operator>>(istream& is, Fraction& obj);
	
	// Type-cast operators

	explicit operator int()const
	{
		return integer + numerator / denominator;
	}

	explicit operator double()const
	{	
		return integer + (double)numerator / denominator;
	}

	explicit operator Fraction() const
	{
		return *this;
	}

	//Methods

	
	Fraction& to_improper()
	{
		numerator += abs(integer) * denominator;
		if (integer < 0) numerator = -numerator;
		integer = 0;
		return *this;
	}
		
	Fraction& to_proper()
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

	Fraction inverted() const
	{
		Fraction inverted = *this;
		inverted.to_improper();
		swap(inverted.numerator, inverted.denominator);
		return inverted;
	}

	Fraction& reduce()
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

	void print()const
	{
		if (denominator == 0) 
		{
			cout << "Zero Division" << endl;
			return;
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
};

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
	//return left > right || left == right;
}

bool operator<=(const Fraction& left, const Fraction& right)
{
	return !(left > right);
	//return left < right || left == right;
}

//#define CONSTRACTORS_CHECK
//#define ARITHMETIC OPERATORS
//#define INCREMENT_DECREMENT
//#define COMPARISON OPERATORS
//#define LOGICAL OPERATORS
//#define STREAMS CHECK
//#define TYPE_COVERSION_BASICS
//#define CONVERTION_FROM_OTHER_TO_CLASS
//#define CONVERTION_FROM_CLASS_TO_OTHER
#define HAVE_A_NICE_DAY

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

#ifdef ARITHMETIC OPERATORS
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

	A /= B;
	A.print();
	cout << delimiter << endl;

	C = A + B;
	C.print();
	cout << delimiter << endl;

	C = A - B;
	C.print();
	cout << delimiter << endl;
#endif // ARITHMETIC OPERATORS

#ifdef INCREMENT_DECREMENT
	Fraction A(2, 3, 4);
	A.print();

	cout << delimiter << endl;
	Fraction B = A++;
	A.print();
#endif // INCREMENT_DECREMENT

#ifdef COMPARISON OPERATORS
cout << delimiter << endl;
Fraction A(2, 3, 4);
Fraction B(3, 4, 5);
A.to_improper().print();
B.to_improper().print();
cout << (A == B) << endl;
cout << (A != B) << endl;
cout << (A > B) << endl;
cout << (A < B) << endl;
cout << (A >= B) << endl;
cout << (A <= B) << endl;
	
#endif // COMPARISON OPERATORS

#ifdef LOGICAL OPERATORS
//for (Fraction i(9, 1, 2); i > 0 ; --i)
//{
//	i.print();
//}
#endif // LOGICAL OPERATORS

#ifdef STREAMS CHECK
Fraction A;
cout << "Введите простую дробь: ";
cin >> A;
cout << A << endl;
//A.print();
#endif // STREAMS CHECK


#ifdef TYPE_COVERSION_BASICS
int a = 2;	  //No conversion
double b = 3; //Conversion from less to more
int c = b;    //Convertion from more to less without data loss
int d = 5.5;   //Convertion from more to less with data loss  
#endif // TYPE_COVERSION_BASICS

#ifdef CONVERTION_FROM_OTHER_TO_CLASS
Fraction A = (Fraction)5;
cout << A << endl;

Fraction B;
B = Fraction(8);
cout << B << endl;
#endif // CONVERTION_FROM_OTHER_TO_CLASS

#ifdef CONVERTION_FROM_CLASS_TO_OTHER
Fraction A(2, 3, 4);
A.to_improper().print();
int a = (int)A;
cout << a << endl;

double b = (double)A;
cout << b << endl;
#endif // CONVERTION_FROM_CLASS_TO_OTHER

#ifdef HAVE_A_NICE_DAY

Fraction A = 2.75;
cout << A << endl;
#endif // HAVE_A_NICE_DAY


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

istream& operator>>(istream& is, Fraction& obj)
{
	is >> obj.integer >> obj.numerator >> obj.denominator;
	return is;
}

