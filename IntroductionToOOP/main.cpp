#include<iostream>
#include<cmath>
using namespace std;

#define delimiter  "\n_____________________________________\n"

class Point
{
	double x;
	double y;
public:
	double get_x()const
	{
		return x;
	}
	double get_y()const
	{
		return y;
	}
	void set_x(double x)
	{
		this -> x = x;
	}
	void set_y(double y)
	{
		this -> y = y;
	}

	//      Constructors

	/*Point()
	{
		x = y = 0;
		cout << "DefaultConstructor:\t" << this << endl;
	}*/
	/*Point(double x)
	{
		this-> x = x;
		this-> y = 0;
		cout << "SingleArgumentConstructor:\t" << this << endl;
	}*/

	Point(double x = 0, double y = 0)
	{
		this->x = x;
		this->y = y;
		cout << "Constructor:\t" << this << endl;
	}

	Point(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyConstructor:\t" << this << endl;
	}

	~Point()
	{
		cout << "Destructor:\t\t" << this << endl;
	}

	double distance(const Point& other) const
	{
		//this -> *= 100;
		//other.x *= 100;
		double x_distanse = this -> x - other.x;
		double y_distanse = this -> y - other.y;
		double distanse = sqrt(x_distanse * x_distanse + y_distanse * y_distanse);
		return distanse;
	}

	void print() const
	{
		cout << this << " : X = " << x << "\t\t" << " : Y = " << y << endl;
	}
};

double distance(const Point& A, const Point& B)
{
	double x_distanse = A.get_x() - B.get_x();
	double y_distanse = A.get_y() - B.get_y();
	double distanse = sqrt(x_distanse * x_distanse + y_distanse * y_distanse);
	return distanse;
}

//#define STRUCT_POINT
#define DISTANCE_CHECK
//#define CONSTRUCTOR_CHECK

void main()
{
	setlocale(LC_ALL, "");

#ifdef STRUCT_POINT
	int a;
	Point A;	// Объявление переменной 'А' типа 'Point'
	// Создание объекта 'А'структуры 'Point'
	A.x = 2;
	A.y = 3;
	cout << A.x << "\t" << A.y << endl;

	Point* pA = &A;
	cout << pA->x << "\t" << pA->y << endl;
#endif // STRUCT_POINT

#ifdef DISTANCE_CHECK
	Point A;
	A.set_x(2);
	A.set_y(3);
	cout << A.get_x() << "\t" << A.get_y() << endl;

	Point B;
	B.set_x(7);
	B.set_y(8);
	cout << B.get_x() << "\t" << B.get_y() << endl;
	cout << delimiter << endl;
	cout << "Расстояние между точками" << A.distance(B) << endl;
	cout << delimiter << endl;
	cout << "Расстояние между точками" << B.distance(A) << endl;
	cout << delimiter << endl;
	cout << "Расстояние между точками" << distance(A, B) << endl;
	cout << delimiter << endl;
#endif // DISTANCE_CHECK
	
#ifdef CONSTRUCTOR_CHECK
	Point A;
	A.print();
	//{
	//	Point A; // Видимость объекта ограничена фигурными скобками
	//			// суцествует только в ней потом деструктор
	//	Point B;
	//}
	Point B = 5;
	B.print();

	Point C(7, 8);
	C.print();

	Point D = C;
	D.print();
#endif // CONSTRUCTOR_CHECK
}