#include<Strh.h>

//#define CONSTRACTORS_CHECK 
//#define COPY_SEMANTIC 
//#define MOVE_METHODS

void main()
{
	setlocale(LC_ALL, "");
#ifdef CONSTRACTORS_CHECK
	String str1;
	str1.print();

	String str2{ 5 };
	str2.print();

	String str3 = "Hello";
	cout << str3 << endl;

	String str4{ "World" };
	cout << str4 << endl;
	String str5 = str3 + str4;
	cout << str5 << endl;
	cout << delimiter << endl;
#endif // CONSTRACTORS_CHECK

#ifdef COPY_SEMANTIC
	cout << delimiter << endl;
	String str1 = "Hello";
	cout << str1 << endl;
	cout << delimiter << endl;
	String str2 = str1;
	cout << str2 << endl;
	cout << delimiter << endl;
	String str3;
	str1 = str1;
	str3 = str1;
	cout << str3 << endl;
	cout << delimiter << endl;
#endif // COPY_SEMANTIC

#ifdef MOVE_METHODS
	String str3 = "Hello";
	cout << str3 << endl;
	cout << delimiter << endl;
	String str4{ "World" };
	cout << str4 << endl;
	cout << delimiter << endl;
	String str5;
	str5 = str3 + str4;
	cout << delimiter << endl;
	cout << str5 << endl;
#endif // MOVE_METHODS

	String str1;  //DefaultConstructor
	str1.print();

	//String str2 = 5;
	String str2(5); //������ ����, �.� explicit
	str2.print();

	String str3 = "Hello"; //SingleArgument Constructor
	str3.print();

	String str4();  //� ���� ������ ���������� DefaultConstructor
	//����� ����������� �������
	//�.� ( ) �� ������ ����� ����� ������������ �� ���������
	//���� ���� ������������� ���� ������� ����������� �� ���������,
//str4 �� �������� ��������
	String str5{};  //���� �������� ������ �����������
	str5.print();

	String str6{ 6 };  //���� �������� ������ �����������
	str6.print();

	String str7{ "World" };  //���� �������� ������ �����������
	str7.print();

	String str8 = str7;  //����� CopyConstructor
	str8.print();

	String str9(str8);	//����� CopyConstructor
	str9.print();

	String str10{ str9 };	//����� CopyConstructor
	str10.print();
	//�������� ������ ���������� ������������ � ������� �������������

	String str11 = str3 + str8;
	str11.print();
	cout << str11 << endl;
}

