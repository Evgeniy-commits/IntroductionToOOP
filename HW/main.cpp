#include "Student.h"

void main()
{
	setlocale(LC_ALL, "");
	
	//cout << "������������ ��������." << endl << endl;
	//Student student("������ �.�.", 3, new int[3]{10, 10, 9});
	////cout << "����� ������ ������������" << endl;

	///*student.setMark(10, 0);
	//student.setMark(10, 1);
	//student.setMark(9, 2);*/
	//
	//cout << "������� ���� " << student.getName() << " : " << fixed 
	//	<< setprecision(2) << student.getAver() << endl;
	//_getch();
	
	
	cout << "������������ ��������." << endl << endl;

	const int size = 3;
	Student* students = new Student[size]
	{
		{"������� 1", 3, new int[3] {10, 10, 9}},
		{"������� 2", 3, new int[3] {8, 10, 8}},
		{"������� 3", 3, new int[3] {12, 10, 8}}
	};

	double sum = 0; 
	for (Student* stud = students; stud < students + size; stud++)
	{
		double aver = stud->getAver();
		cout << "������� ���� " << stud -> getName() << " : " << fixed
			<< setprecision(2) << aver << endl;
		sum += aver;
	}
	cout << endl;
	
	cout << "������� ���� �� ������: " << " : " << fixed 
		<< setprecision(2) << sum / size << endl;
	delete[] students;
	_getch();
}

