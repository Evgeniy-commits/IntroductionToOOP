#include<iostream>
#include<cmath>

using namespace std;

class Distance
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
		this->x = x;
	}
	void set_y(double y)
	{
		this->y = y;
	}
	double getDistance(double x , double y)
	{
		return sqrt(pow(x, 2) + pow(y, 2));
	}



};

double distanceBetween(double x_1, double x_2, double y_1, double y_2);

void main()
{
	setlocale(LC_ALL, "");
	
	Distance A;
	A.set_x(3);
	A.set_y(4);
	cout << A.get_x() << "\t" << A.get_y() << endl;
	cout << A.getDistance(A.get_x(), A.get_y()) << endl << endl;

	double x_1 = 1;
	double y_1 = 2;
	double x_2 = 3;
	double y_2 = 4;
	cout << distanceBetween(x_1, y_1, x_2, y_2) << endl;

}

double distanceBetween(double x_1, double x_2, double y_1, double y_2)
{
	return sqrt(pow(x_2 - x_1, 2) + pow(y_2 - y_1, 2));
}