#include <iomanip>
#include <iostream>
#include <time.h>



using namespace std;

//---------------------�������--------------------------------------------------
/*
�������� ����� �������.����������� � ������ ����� ������ :

����������� �� ���������, ����������� � �����������, ����������� �����;
����������;
����� �������� � ������� �� �����;
���������� ��������� �� �����������;
���� � ���������� � ����� �� �����(� ���� ������� ������ � ��� ������ ������������� �������� ���������� ����� � ������);
����������� ��������� �������� :
+(������������ ��������);
+= (���������� �������� � ����� �������);
�(�������� �������� �� �����);
= (����������);
== (��������� �� ���������);
[] (������ �������� � �������� ��������).
*/

//---------------------------------������-----------------------------------------

class Array
{
private:

	int* arr;
	int size;

public:

	Array();                                        // ����������� �� ���������

	Array(const Array& other);                      // ����������� �����������

	Array(int size);                                 // ����������� � �����������

	~Array();                                        // ����������
	
	int getSize();                                   // ������

	void setSize(int size);                          // ������

	void input();                                    // ���� ������� � ����������

	void output();                                   // ����� ������� �� �����
};



//---------------------���������-------------------------------------------------





//---------------------------MAIN----------------------------------------------------
int main() {
	setlocale(LC_ALL, "RU");
	srand(time(NULL));
	
	int s;                   // ������ �������

	cout << "������� ������ ������� 1 : " << endl;
	cin >> s;

	Array arr1(s);

	arr1.input();
	
	arr1.output();



	system("pause");
	return 0;
}

//----------------------------------�������------------------------------------------



//----------------------------------������--------------------------------------------

int Array::getSize()                                 // ������
{
	return(size);
}

void Array::setSize(int size)                        // ������
{
	this->size = size;
}

Array::Array()                                       // ����������� �� ���������
{
	this->size = 1;
	arr = new int[size];
	for (int i = 0; i < size; i++)
	{
		arr[i] = 0;
	}
}

Array::Array(const Array& other)                      // ����������� �����������
{
	this->size = other.size;
	arr = new int[size];
	for (int i = 0; i < size; i++)
	{
		arr[i] = other.arr[i];
	}
}
 
Array::Array(int size)                               // ����������� � �����������
{
	this->size = size;
	arr = new int[size];
}

Array::~Array()                                      // ����������
{
	delete[] arr;
}

void Array::input()                                  // ���� ������� � ����������
{
	cout << endl;
	for (int i = 0; i < size; i++)
	{
		cout << "������� " << i + 1 << "-� ������� �������: ";
		cin >> arr[i];
	}
	cout << endl;
}

void Array::output()                                   // ����� ������� �� �����
{
	cout << endl;
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << "\t";
    }
	cout << endl;
}

