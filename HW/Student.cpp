#include "Student.h"

Student::Student()
{
	name = nullptr;
	marks = nullptr;
	markCount = 0;
	cout << "Отработал конструктор 1: " << name << endl;
	system("pause");
}

Student::Student(const char* studentName,
	const int studentMarkCount)
{
	createName(studentName);

	marks = new int[studentMarkCount];
	for (int i = 0; i < studentMarkCount; i++) marks[i] = 0;
	markCount = studentMarkCount;
	cout << "Отработал конструктор 2: " << name << endl;
	system("pause");
}

Student::Student(const char* studentName,
	const int studentMarkCount,
	const int* studentMarks)
{
	createName(studentName);

	marks = new int[studentMarkCount];
	for (int i = 0; i < studentMarkCount; i++) marks[i] = studentMarks[i];
	markCount = studentMarkCount;
	cout << "Отработал конструктор 3: " << name << endl;
	system("pause");
}

Student::~Student()
{
	cout << "Отработал деструктор" << name << endl;
	if (name != nullptr) delete[] name;
	if (marks != nullptr) delete[] marks;
	system("pause");
}

void Student::createName(const char* studentName)
{
	int nameLength = strlen(studentName);
	name = new char[nameLength + 1];
	for (int i = 0; i <= nameLength; i++) name[i] = studentName[i];
}

void Student::setName(const char* studentName)
{
	delete[] name;
	createName(studentName);
}

double Student::getAver()
{
	double sum = 0;
	for (int i = 0; i < markCount; i++) sum += marks[i];
	return sum / markCount;
}

//void Student::setName(const char* studentName)
//{
//	strcpy_s(name, 20, studentName);
//}

void Student::setMark(int mark, int index)
{
	if (index < 0 || index >= markCount) return;
	if (mark < 1 || mark > 12) mark = 0;
	marks[index] = mark;
}