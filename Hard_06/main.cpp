#include <iomanip>
#include <iostream>
#include <time.h>

//#include <cstdlib>

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

	Array();                                         // ����������� �� ���������

	Array(const Array& other);                       // ����������� �����������

	Array(int size);                                 // ����������� � �����������

	~Array();                                        // ����������
	
	int getSize();                                   // ������

	void setSize(int size);                          // ������

	void input();                                    // ���� ������� � ����������

	void output();                                   // ����� ������� �� �����

	Array& operator =(const Array& other);           // ���������� ��������� =

	Array operator +(const Array& other);            // ���������� ��������� +

	Array& operator +=(int elem);                    // ���������� �������� � ����� ������� (���������� +=)

	Array& operator -(int key);                      // �������� �������� �� ����� (���������� -)

	bool operator ==(const Array& other);            // ���������� ��������� ==

	int& operator [](int elem);                      // ���������� ��������� []

	friend ostream& operator <<(ostream& os, Array& array);   // ���������� ��������� <<

	friend istream& operator >>(istream& es, Array& array);   // ���������� ��������� >>

	int search(int element);                         // ����� �������� � ������� (������� ��������������)

	void sort();                                     // ���������� ������� �� �����������
};



//-------------------------���������-------------------------------------------------





//---------------------------MAIN----------------------------------------------------
int main() {
	setlocale(LC_ALL, "RU");
	srand(time(NULL));
	
	int s, s2;                   // ������ �������

	cout << "������� ������ ������� 1 : " << endl;
	cin >> s;

	Array arr1(s);

	arr1.input();
	
	arr1.output();


	//-----�������
	arr1.sort();

	cout << arr1;

	//-----�������


	system("pause");
	return 0;
}

//----------------------------------�������------------------------------------------



//----------------------------------������ (Array)-----------------------------------

//-------------------------- ������
int Array::getSize()                                 
{
	return(size);
}

//-------------------------- ������

void Array::setSize(int size)                        
{
	this->size = size;
}

//-------------------------- ����������� �� ���������

Array::Array()                                       
{
	this->size = 1;
	arr = new int[size];
	for (int i = 0; i < size; i++)
	{
		arr[i] = 0;
	}
}

//-------------------------- ����������� �����������

Array::Array(const Array& other)                    
{
	this->size = other.size;
	arr = new int[size];
	for (int i = 0; i < size; i++)
	{
		arr[i] = other.arr[i];
	}
}
 
//-------------------------- ������������ �����������

Array::Array(int size)                              
{
	this->size = size;
	arr = new int[size];
}

//-------------------------- ����������

Array::~Array()                                     
{
	delete[] arr;
}

//-------------------------- ���� ������� � ����������

void Array::input()                                  
{
	cout << endl;
	for (int i = 0; i < size; i++)
	{
		cout << "������� " << i + 1 << "-� ������� �������: ";
		cin >> arr[i];
	}
	cout << endl;
}

//-------------------------- ����� ������� �� �����

void Array::output()                                   
{
	cout << "������:" << endl;
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << "\t";
    }
	cout << endl;
}

//-------------------------- ���������� ��������� =

Array& Array::operator =(const Array& other)         
{
	this->size = other.size;                          // ����� ������ �������, ������ ��������������

	if (this->arr != nullptr)                         // ������� ��� ������, ���� �� �� ����
	{
		delete[] this->arr;
	}

	this->arr = new int[other.size];                  // �������� ������ ������� ������ (��� �� ���� �������������)

	for (int i = 0; i < other.size; i++)              // ��������� � ��� ������ ������������� ������
	{
		this->arr[i] = other.arr[i];
	}

	return *this;                                     // ���������� �������������� ��������� �� ��� ������
}

//-------------------------- ���������� ��������� +

Array Array::operator +(const Array& other)              
{
	if (this->size == other.size)                         // ���������� ������� ��������� ������
	{
		Array rezult(other.size);                         // ������� �������������� �������

		for (int i = 0; i < other.size; i++)              // ��������� �������������� ������ 
		{
			rezult.arr[i] = this->arr[i] + other.arr[i];
		}

		return rezult;                                    // ���������� ��������������
	}
	else                                                  // ���� ������� �� �����: ����� ������, ��������� ���������
	{
		cout << endl << "������!!! �� ��������� ������� ������� ������ ��������!!! " << endl;
		system("pause");
		exit(1);
	}
}

//-------------------------- ���������� �������� � ����� ������� (���������� +=)

Array& Array::operator +=(int elem)
{
	Array buff(*this);                                    // ������� ����� ������ �������

	delete[] this->arr;                                   // ������� ��� ������
	
	this->size = buff.size + 1;

	this->arr = new int[size];                            // ������� ����� ������ ����������� ������

	for (int i = 0; i < size - 1; i++)                    
	{
		this->arr[i] = buff.arr[i];
	}

	this->arr[size - 1] = elem;                           // ��������� �� ������ ��� �������� � � ����� ���������� �����

    return *this;
}

//-------------------------- �������� �������� �� ����� (���������� -)

Array& Array::operator -(int key)
{
	Array temp(*this);                                   // ������� ����� ������ �������

	delete[] this->arr;                                  // ������� ��� ������

	size = temp.size - 1; 

	this->arr = new int[size];                           // ������� ����� ������ �� 1 ������� ������

	if (key <= temp.size)                                // ��������� , ��� ������ ������� �� �� ��������� �������
	{
		for (int i = 0, j = 0; i < temp.size; i++)       // ��������� �� ������ ��� �������� (����� �������� ����� key)
		{
			if (i + 1 != key)
			{
				this->arr[j] = temp.arr[i];
				j++;
			}
		}

		return *this;
	}
	else
	{
		cout << endl << "������!!! �� ��������� ������� �� ������������ �������!!!" << endl;
		system("pause");
		exit(1);
	}
}

//-------------------------- ���������� ��������� ==

bool Array::operator ==(const Array& other)
{
	if (this->size == other.size)                       // ���� ������� �����, ������� ������
	{
		for (int i = 0; i < size; i++)
		{
			if (this->arr[i] != other.arr[i])           // ����������� ����������, ���� ���� ���� ������� �� ����� - false
			{
				return false;
			}
		}

		return true;
	}
	else                                                // ���� ������� �� ����� - false
	{
		return false;
	}
}

//-------------------------- ���������� ��������� []

int& Array::operator [](int elem)          // int ���������� �� ������, ��� �� �� ����� �� ������ ��������, �� � ������
{                                          // ���������� �������� [], �� ����� ����� ���� ������ ��������:
	return arr[elem];                      // cout << arr1[2] << endl;    cin >> arr1[2];
}


//-------------------------- ���������� ��������� <<

ostream& operator <<(ostream& os, Array& array)
{
	cout << "������:" << endl;
	for (int i = 0; i < array.size; i++)
	{
		os << setw(4) << array.arr[i];
	}
	cout << endl;

	return os;                                        // ����� ������������:  Cout << arr1;
}

//-------------------------- ���������� ��������� >>

istream& operator >>(istream& es, Array& array)
{
	for (int i = 0; i < array.size; i++)
	{
		cout << "������� " << i + 1 << "-� ������� �������: ";
		es >> array.arr[i];
	}
	cout << endl;

	return es;                                      // ����� ������������:  cin >> arr1;
}

//-------------------------- ����� �������� ������� (������� ��������������)

int Array::search(int element)
{
	for (int i = 0; i < size; i++)            // ���������� �������� � ���� ������ ���
	{
		if (arr[i] == element)
		{
			return i;                         // ���������� ��� ����� , ���� �����
		}
	}
	return -1;                                // ���� ���, ���������� -1, ��� ������
}

//-------------------------- ���������� ������� �� �����������

void Array::sort()
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size - 1; j++) 
		{
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp; 
			}
		}
	}
}

//--------------------------
