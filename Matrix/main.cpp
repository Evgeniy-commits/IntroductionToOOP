#include<iostream>
//#include<cmath>
//#include<string>
//#include<conio.h>
//#include<Windows.h>

using namespace std;

#define delimiter  "\n_____________________________________\n"

class Matrix
{
private:
	int rows;
	int cols;
	int** matrix;

public:
	int get_rows() const
	{
		return rows;
	}
	int get_cols() const
	{
		return cols;
	}

	/*const int** get_matrix() const
	{
		return matrix;
	}

	int** get_matrix()
	{
		return matrix;
	}*/
	
	//			Constructors
	Matrix(int rows, int cols)
	{
		this->rows = rows;
		this->cols = cols;
		this->matrix = new int* [rows] {};
		for (int i = 0; i < rows; i++)
		{
			matrix[i] = new int[cols] {};
		}
		cout << "Default Constructor:\t" << this << endl;
	}

	~Matrix()
	{
		for (int i = 0; i < rows; i++)
		{
			delete[] matrix[i];
		}
		delete[] matrix;
		matrix = nullptr;
		rows = 0;
		cols = 0;
		cout << "Destructor:\t" << this << endl;
	}


	//			Method
	void print() const
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				cout << matrix[i][j] << "\t";
			}
			cout << endl;
		}
	}
};

#define CONSTRACTORS_CHECK

void main()
{
	setlocale(LC_ALL, "");
#ifdef CONSTRACTORS_CHECK

	Matrix m_1 (3, 3);
	m_1.print();

#endif // CONSTRACTORS_CHECK
}
