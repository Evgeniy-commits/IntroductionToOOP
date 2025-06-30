#include<iostream>
#include<cmath>
using namespace std;

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

	double distance(Point other)
	{
		double x_distanse = this -> x - other.x;
		double y_distanse = this -> y - other.y;
		double distanse = sqrt(x_distanse * x_distanse + y_distanse * y_distanse);
		return distanse;
	}
};

double distance(Point A, Point B)
{
	double x_distanse = A.get_x() - B.get_x();
	double y_distanse = A.get_y() - B.get_y();
	double distanse = sqrt(x_distanse * x_distanse + y_distanse * y_distanse);
	return distanse;
}

//#define STRUCT_POINT

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

	
	Point A;
	A.set_x(2);
	A.set_y(3);
	cout << A.get_x() << "\t" << A.get_y() << endl;

	Point B;
	B.set_x(7);
	B.set_y(8);
	cout << B.get_x() << "\t" << B.get_y() << endl;

	cout << "Расстояние между точками" << A.distance(B) << endl;
	cout << "Расстояние между точками" << B.distance(A) << endl;
	cout << "Расстояние между точками" << distance(A, B) << endl;
}