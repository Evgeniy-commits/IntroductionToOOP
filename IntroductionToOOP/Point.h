#pragma once

#include<iostream>
#include<cmath>
using namespace std;

#define delimiter  "\n_____________________________________\n"

class Point;
double distance(const Point& A, const Point& B);
Point operator+(const Point& left, const Point& right);
bool operator==(const Point& left, const Point& right);
bool operator!=(const Point& left, const Point& right);

class Point
{
	double x;
	double y;
public:
	double get_x()const;
	double get_y()const;
	void set_x(double x);
	void set_y(double y);

	//      Constructors
	Point(double x = 0, double y = 0);
	Point(const Point& other);
	~Point();

	//operators
	Point& operator=(const Point& other);
	Point& operator++();
	Point operator++(int);
	double distance(const Point& other) const;
	void print() const;
};