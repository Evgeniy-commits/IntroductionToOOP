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

		
	//			Constructors
	Matrix() : rows(3), cols(3)
	{
		createRandomMatrix();
		cout << "Default Constructor:\t\t" << this << endl;
	}
	
	Matrix(int i) : rows(i), cols(2)
	{
		createMatrix();
		cout << "Constructor_1:\t\t" << this << endl;
	}

	Matrix(int i, int j) : rows(i), cols(j)
	{
		createRandomMatrix();
		cout << "Constructor_2:\t\t" << this << endl;
	}

	Matrix (const Matrix& other)
	{
		matrix = new int* [rows] {};
		for (int i = 0; i < rows; i++)
			matrix[i] = new int[cols] {};
		    int k = 0;
			for (int j = 0; j < cols; j++)
				matrix[k++][j] = other.matrix[k++][j];
		cout << "CopyConstructor:\t" << this << endl;
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

	//			Operators
	
	Matrix& operator=(const Matrix& other)
	{
		this->~Matrix();
		this->rows = other.rows;
		this->cols = other.cols;
		this->matrix = new int* [rows] {};
		for (int i = 0; i < rows; i++)
		{
			matrix[i] = new int[cols] {};
			for (int j = 0; j < cols; j++)
				matrix[i][j] = other.matrix[i][j];
		}
		cout << "CopyAssignment:\t" << this << endl;
		return *this;
	}

	//			Method

	void createMatrix()
	{
		matrix = new int* [rows] {};
		for (int i = 0; i < rows; i++)
			matrix[i] = new int[cols] {};
	}
	
	void createRandomMatrix()
	{
		matrix = new int* [rows] {};
		for (int i = 0; i < rows; i++)
		{
			matrix[i] = new int[cols] {};
			for (int j = 0; j < cols; j++)
				matrix[i][j] = rand() % 10;
		}
	}
	

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
	cout << delimiter << endl;

	Matrix B(3, 4);
	B.print();
	Matrix C = B;
	B.print();
	cout << delimiter << endl;

	Matrix D(3, 4);
	D.print();
	D = B;
	D.print();
	cout << delimiter << endl;
#endif // CONSTRACTORS_CHECK
}
