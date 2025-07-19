#include <Fraction.h>

//#define CONSTRACTORS_CHECK
#define ARITHMETIC OPERATORS
//#define INCREMENT_DECREMENT
//#define COMPARISON OPERATORS
//#define LOGICAL OPERATORS
//#define STREAMS CHECK
//#define TYPE_COVERSION_BASICS
//#define CONVERTION_FROM_OTHER_TO_CLASS
//#define CONVERTION_FROM_CLASS_TO_OTHER
//#define HAVE_A_NICE_DAY

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

	Fraction D(2, 3, 4);
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
	cout << "¬ведите простую дробь: ";
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

	Fraction A = 3.33;
	cout << A << endl;
#endif // HAVE_A_NICE_DAY
}
