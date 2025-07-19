#include "Point.h"

double Point::get_x()const
{
	return x;
}
double Point::get_y()const
{
	return y;
}
void Point::set_x(double x)
{
	this->x = x;
}
void Point::set_y(double y)
{
	this->y = y;
}

//      Constructors

Point::Point(double x, double y) : x(x), y(y)
{
	cout << "Constructor:\t" << this << endl;
}

Point::Point(const Point& other) : x(other.x), y(other.y)
{
	cout << "CopyConstructor:\t" << this << endl;
}

Point::~Point()
{
	cout << "Destructor:\t\t" << this << endl;
}

//operators

Point& Point::operator=(const Point& other)
{
	this->x = other.x;
	this->y = other.y;
	cout << "CopyAssignment:\t" << this << endl;
	return *this;
}

Point& Point::operator++()
{
	x++;
	y++;
	return *this;
}
Point Point::operator++(int) //Postfix
{
	Point old = *this; //сохр старое значение
	x++;
	y++;
	return old;
}

double Point::distance(const Point& other) const
{
	double x_distanse = this->x - other.x;
	double y_distanse = this->y - other.y;
	double distanse = sqrt(x_distanse * x_distanse + y_distanse * y_distanse);
	return distanse;
}

void Point::print() const
{
	cout << this << " : X = " << x << "\t\t" << " : Y = " << y << endl;
}

double distance(const Point& A, const Point& B)
{
	double x_distanse = A.get_x() - B.get_x();
	double y_distanse = A.get_y() - B.get_y();
	double distanse = sqrt(x_distanse * x_distanse + y_distanse * y_distanse);
	return distanse;
}

Point operator+(const Point& left, const Point& right)
{
	Point result;
	result.set_x(left.get_x() + right.get_x());
	result.set_y(left.get_y() + right.get_y());
	return result;
}

bool operator==(const Point& left, const Point& right)
{
	/*if (left.get_x() == right.get_x() && left.get_y() == right.get_y())
		return true;
	else
		return false;*/
	return left.get_x() == right.get_x() && left.get_y() == right.get_y();
}

bool operator!=(const Point& left, const Point& right)
{
	return !(left == right);
}