#include<iostream>
#include<cmath>
#include<stdlib.h>
#include"Fraction.h"

using namespace std;

#define delimiter  "\n_____________________________________\n"

//#define CONSTRACTORS_CHECK
//#define ARITHMETIC OPERATORS
#define COMPOUND ASSIGNMENTS
//#define INCREMENT_DECREMENT
//#define COMPARISON OPERATORS

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
	Fraction A(1, 2, 3);
	A.print();
	cout << delimiter << endl;

	Fraction B(2, 3, 4);
	B.print();
	cout << delimiter << endl;

	Fraction C = A * B;
	C.print();
	cout << delimiter << endl;

	Fraction D = A / B;
	D.print();
	cout << delimiter << endl;

	Fraction E = A + B;
	E.print();
	cout << delimiter << endl;

	Fraction F = A - B;
	F.print();
	cout << delimiter << endl;
#endif // ARITHMETIC OPERATORS

#ifdef COMPOUND ASSIGNMENTS
	Fraction A(1, 2, 3);
	A.print();
	/*A.to_improper().print();
	A.to_proper().print();
	A.to_improper().print();*/
	cout << delimiter << endl;

	Fraction B(2, 3, 4);
	B.print();
	cout << delimiter << endl;

	A.to_improper().print();
	B.to_improper().print();
	A += B;
	A.print();
	B += A;
	B.print();

	cout << delimiter << endl;
	Fraction C(1, 2, 3);
	Fraction D(2, 3, 4);
	C.to_improper().print();
	D.to_improper().print();
	C -= D;
	C.to_improper().print();
	C.to_proper().print();
	D -= C;
	D.to_proper().print();
#endif // COMPOUND ASSIGNMENTS

#ifdef INCREMENT_DECREMENT
	Fraction A(1, 2, 3);
	A.print();
	A.to_improper().print();
	A++;
	A.print();
	A--;
	A.print();
	A--;
	A.print();
#endif // INCREMENT_DECREMENT

#ifdef COMPARISON OPERATORS
	cout << delimiter << endl;
	Fraction A(1, 2, 3);
	Fraction B(2, 3, 4);
	A.to_improper().print();
	B.to_improper().print();

	cout << (A == B) << endl;
	cout << (A != B) << endl;
	cout << (A > B) << endl;
	cout << (A < B) << endl;
	cout << (A >= B) << endl;
	cout << (A <= B) << endl;
	
#endif // COMPARISON OPERATORS

}

