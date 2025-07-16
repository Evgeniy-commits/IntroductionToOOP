#include<iostream>

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
	Matrix() : rows(2), cols()
	{
		createMatrix();
		cout << "Default Constructor:\t\t" << this << endl;
	}
	
	Matrix(int rows) : rows(rows), cols(1)
	{
		createMatrix();
		cout << "Constructor_1:\t\t" << this << endl;
	}

	Matrix(int rows, int cols)
	{
		this -> rows = rows;
		this -> cols = cols;
		createRandomMatrix();
		cout << "Constructor_2:\t\t" << this << endl;
	}

	Matrix (const Matrix& other)
	{
		rows = other.rows;
		cols = other.cols;
		matrix = new int* [rows];
		for (int i = 0; i < rows; i++)
		{
			matrix[i] = new int[cols] {};
		}
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				matrix[i][j] = other.matrix[i][j];
			}
		}
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
		this->rows = other.rows;
		this->cols = other.cols;
		this->matrix = new int* [rows] {};
		for (int i = 0; i < rows; i++)
		{
			this->matrix[i] = new int[cols] {};
			memcpy(this->matrix[i], other.matrix[i], cols * sizeof(int));
		}
		
		cout << "CopyAssignment:\t" << this << endl;
		return *this;
	}

	Matrix operator+(Matrix& right);
	
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

//#define CONSTRACTORS_CHECK
#define ARITHMETIC_OPERATORS
void main()
{
	setlocale(LC_ALL, "");
#ifdef CONSTRACTORS_CHECK

	/*Matrix m_1 (3, 3);
	m_1.print();
	cout << delimiter << endl;

	Matrix B(3, 4);
	B.print();
	Matrix C = B;
	B.print();
	cout << delimiter << endl;*/
	
	Matrix B(3, 4);
	B.print();
	Matrix D;
	D.print();
	D = B;
	D.print();
	cout << delimiter << endl;
#endif // CONSTRACTORS_CHECK

#ifdef ARITHMETIC_OPERATORS
	Matrix A(3, 3);
	A.print();
	cout << delimiter << endl;
	Matrix B(3, 3);
	B.print();
	cout << delimiter << endl;
	Matrix C(3, 3);
	C.print();
	cout << delimiter << endl;
	C = A + B;
	C.print();
	cout << delimiter << endl;
#endif // ARITHMETIC_OPERATORS

}

Matrix Matrix :: operator+(Matrix& right)
{
	cout << "OPERATOR+ \t\t" << endl;
	this->rows = rows;
	this->cols = cols;
	if (rows != right.rows || cols != right.cols)
	{
		cout << "Matrix sizes do not equal.";
		return *this;
	}
	
	Matrix result(rows, cols);
	result.print();

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++) 
		{
			result.matrix[i][j] = matrix[i][j] + right.matrix[i][j];
		}
	}
	return result;
}
