#include<iostream>
#include<cmath>

using namespace std;

#define delimiter  "\n_____________________________________\n"

class Fraction
{
	int integer;		//����� �����
	int numerator;		//���������
	int denominator;	//�����������
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
	//left.to_improper();
	//right.to_improper();
	//Fraction result;
	//result.set_numerator(left.get_numerator() * right.get_numerator());
	//result.set_denominator(left.get_denominator() * right.get_denominator());
	//return result;
	/*Fraction result
	(
		left.get_numerator() * right.get_numerator(),
		left.get_denominator() * right.get_denominator()
	);*/
	//result.to_proper();
	return Fraction
	(
		left.to_improper().get_numerator() * right.to_improper().get_numerator(),
		left.to_improper().get_denominator() * right.to_improper().get_denominator()
	).to_proper();
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

	Fraction A(1, 2, 3);
	A.print();
	cout << delimiter << endl;
	Fraction B(2, 3, 4);
	B.print();
	cout << delimiter << endl;
	Fraction C = A * B;
	C.print();
	cout << delimiter << endl;
}