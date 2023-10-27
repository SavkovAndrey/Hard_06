#include <iomanip>
#include <iostream>
#include <time.h>

//#include <cstdlib>

using namespace std;

//---------------------ЗАДАНИЕ--------------------------------------------------
/*
Написать класс «массив».Реализовать в классе такие методы :

конструктор по умолчанию, конструктор с параметрами, конструктор копии;
деструктор;
поиск элемента в массиве по ключу;
сортировка элементов по возрастанию;
ввод с клавиатуры и вывод на экран(в виде методов класса и при помощи перегруженных операций потокового ввода и вывода);
перегрузить следующие операции :
+(поэлементное сложение);
+= (добавление элемента в конец массива);
–(удаление элемента по ключу);
= (присвоение); 
== (сравнение по элементам);
[] (взятие элемента с заданным индексом).
*/

//---------------------------------КЛАССЫ-----------------------------------------

class Array
{
private:

	int* arr;
	int size;

public:

	Array();                                         // конструктор по умолчанию

	Array(const Array& other);                       // конструктор копирования

	Array(int size);                                 // конструктор с параметрами

	~Array();                                        // деструктор
	
	int getSize();                                   // геттер

	void setSize(int size);                          // сеттер

	void input();                                    // ввод массива с клавиатуры

	void output();                                   // вывод массива на экран

	Array& operator =(const Array& other);           // перегрузка оператора =

	Array operator +(const Array& other);            // перегрузка оператора +

	Array& operator +=(int elem);                    // добавление элемента в конец массива (перегрузка +=)

	Array& operator -(int key);                      // удаление элемента по ключу (перегрузка -)

	bool operator ==(const Array& other);            // перегрузка оператора ==

	int& operator [](int elem);                      // перегрузка оператора []

	friend ostream& operator <<(ostream& os, Array& array);   // перегрузка оператора <<

	friend istream& operator >>(istream& es, Array& array);   // перегрузка оператора >>

	int search(int element);                         // поиск элемента в массиве (первого встретившегося)

	void sort();                                     // сортировка массива по возрастанию
};



//-------------------------ПРОТОТИПЫ-------------------------------------------------

void menu();



//---------------------------MAIN----------------------------------------------------
int main() {
	setlocale(LC_ALL, "RU");
	srand(time(NULL));

	
	int s;                 // размер массива

	cout << "Введите размер массива 1 : " << endl;
	cin >> s;

	Array arr1(s);
    arr1.input();
	arr1.output();

	while(true)
	{
		menu();
		int n;
		cin >> n;

		switch (n)
		{
		case 1:
		   {
			int s2;
			cout << "Введите размер массива 2 : " << endl;
			cin >> s2;
			Array arr2(s2);
			cin >> arr2;
			Array result = arr1 + arr2;
			cout << result;

			break;
		   }
	    
		case 2:
		   {
			cout << "Какой элемент добавить в конец массива?" << endl;
			int num;
			cin >> num;
			arr1 += num;
			cout << "Итог:" << endl;
			cout << arr1;

			break;
		   }
		case 3:
		   {
			cout << "Элемент с каким номером удалить из массива?" << endl;
			int num;
			cin >> num;
			arr1 - num;
			cout << "Итог:" << endl;
			cout << arr1;

			break;
		   }

		case 4:
		   {
			cout << "Введите размер и элементы массива для сравнения" << endl;
			int s3;
			cin >> s3;
			Array arr3(s3);
			cin >> arr3;
			if (arr1 == arr3)
			{
				cout << endl << "Массивы равны" << endl;
			}
			else
			{
				cout << endl << "Массивы не равны" << endl;
			}

			break;
		   }

		case 5:
		   {
			cout << endl << "выберите индекс элемента, который нужно взять:" << endl;
			int num;
			cin >> num;
			cout << "Элемент с индексом " << num << " это: " << arr1[num] << endl;

			break;
		   }

		case 6:
		   {
			cout << endl << "номер какого элемента вы хотите найти?" << endl;
			int elem;
			cin >> elem;
			if (arr1.search(elem) >= 0)
			{
				cout << endl << "элемент " << elem << " имеет индекс: " << arr1.search(elem) << endl;
			}
			else
			{
				cout << endl << "Такого элемента нет в массиве!" << endl;
			}

			break;
		   }

		case 7:
		   {
			cout << "Массив был отсортирован по возрастанию, результат: " << endl;
			arr1.sort();
			cout << arr1;

			break;
		   }
		case 0:
		   {
			cout << endl << "Вы вышли из программы." << endl;
			system("pause");
			return 0;
            break;
		   }
		}


	}



	system("pause");
	return 0;
}

//----------------------------------ФУНКЦИИ------------------------------------------

void menu()
{
	cout << endl;
	cout << endl << "ВОЗМОЖНЫЕ ДЕЙСТВИЯ:" << endl;;
	cout << endl << "1 - Суммирование массивов";
	cout << endl << "2 - Добавление элемента в конец массива";
	cout << endl << "3 - удаление элемента по номеру";
	cout << endl << "4 - сравнить массивы по элементно";
	cout << endl << "5 - взять элемент с заданным индексом";
	cout << endl << "6 - найти номер элемента по значению (первого встретившегося)";
	cout << endl << "7 - провести сортировку массива по возрастанию";
	cout << endl << "0 - выйти из программы";
	cout << endl;
	cout << endl << "Выберете действие:";
}

//----------------------------------МЕТОДЫ (Array)-----------------------------------

//-------------------------- ГЕТТЕР
int Array::getSize()                                 
{
	return(size);
}

//-------------------------- СЕТТЕР

void Array::setSize(int size)                        
{
	this->size = size;
}

//-------------------------- КОНСТРУКТОР ПО УМОЛЧАНИЮ

Array::Array()                                       
{
	this->size = 1;
	arr = new int[size];
	for (int i = 0; i < size; i++)
	{
		arr[i] = 0;
	}
}

//-------------------------- КОНСТРУКТОР КОПИРОВАНИЯ

Array::Array(const Array& other)                    
{
	this->size = other.size;
	arr = new int[size];
	for (int i = 0; i < size; i++)
	{
		arr[i] = other.arr[i];
	}
}
 
//-------------------------- КОНСТРУКТОРС ПАРАМЕТРАМИ

Array::Array(int size)                              
{
	this->size = size;
	arr = new int[size];
}

//-------------------------- ДЕСТРУКТОР

Array::~Array()                                     
{
	delete[] arr;
}

//-------------------------- ВВОД МАССИВА С КЛАВИАТУРЫ

void Array::input()                                  
{
	cout << endl;
	for (int i = 0; i < size; i++)
	{
		cout << "введите " << i + 1 << "-й элемент массива: ";
		cin >> arr[i];
	}
	cout << endl;
}

//-------------------------- ВЫВОД МАССИВА НА ЭКРАН

void Array::output()                                   
{
	cout << "Массив:" << endl;
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << "\t";
    }
	cout << endl;
}

//-------------------------- ПЕРЕГРУЗКА ОПЕРАТОРА =

Array& Array::operator =(const Array& other)         
{
	this->size = other.size;                          // берем нашему размеру, размер присваеваемого

	if (this->arr != nullptr)                         // очищаем наш массив, если он не пуст
	{
		delete[] this->arr;
	}

	this->arr = new int[other.size];                  // выделяем нашему массиву память (что бы влез присваеваемый)

	for (int i = 0; i < other.size; i++)              // переносим в наш массив пресваеваемый массив
	{
		this->arr[i] = other.arr[i];
	}

	return *this;                                     // возвращаем разименованный указатель на наш объект
}

//-------------------------- ПЕРЕГРУЗКА ОПЕРАТОРА +

Array Array::operator +(const Array& other)              
{
	if (this->size == other.size)                         // сравниваем размеры слогаемых матриц
	{
		Array result(other.size);                         // создаем результирующую матрицу

		for (int i = 0; i < other.size; i++)              // заполняем результирующую суммой 
		{
			result.arr[i] = this->arr[i] + other.arr[i];
		}

		return result;                                    // возвращаем результирующую
	}
	else                                                  // если матрицы не равны: пишем ошибку, завершаем программу
	{
		cout << endl << "ОШИБКА!!! Вы пытаетесь сложить матрицы разных размеров!!! " << endl;
		system("pause");
		exit(1);
	}
}

//-------------------------- ДОБАВЛЕНИЕ ЭЛЕМЕНТА В КОНЕЦ МАССИВА (ПЕРЕГРУЗКА +=)

Array& Array::operator +=(int elem)
{
	Array buff(*this);                                    // создаем копию нашего массива

	delete[] this->arr;                                   // удаляем наш массив
	
	this->size = buff.size + 1;

	this->arr = new int[size];                            // создаем новый массив увеличенной длинны

	for (int i = 0; i < size - 1; i++)                    
	{
		this->arr[i] = buff.arr[i];
	}

	this->arr[size - 1] = elem;                           // переносим из буфера все элементы и в конце дописываем новый

    return *this;
}

//-------------------------- УДАЛЕНИЕ ЭЛЕМЕНТА ПО КЛЮЧУ (перегрузка -)

Array& Array::operator -(int key)
{
	Array temp(*this);                                   // создаем копию нашего массива

	delete[] this->arr;                                  // очищаем наш массив

	size = temp.size - 1; 

	this->arr = new int[size];                           // создаем новый массив на 1 элемент меньше

	if (key <= temp.size)                                // проверяем , что выбран элемент не за пределами массива
	{
		for (int i = 0, j = 0; i < temp.size; i++)       // переносим из буфера все элементы (кроме элемента номер key)
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
		cout << endl << "ОШИБКА!!! Вы пытаетесь удалить не существующий элемент!!!" << endl;
		system("pause");
		exit(1);
	}
}

//-------------------------- ПЕРЕГРУЗКА ОПЕРАТОРА ==

bool Array::operator ==(const Array& other)
{
	if (this->size == other.size)                       // если размеры равны, смотрим дальше
	{
		for (int i = 0; i < size; i++)
		{
			if (this->arr[i] != other.arr[i])           // поэлементно сравниваем, если хоть один элемент не равен - false
			{
				return false;
			}
		}

		return true;
	}
	else                                                // если размеры не равны - false
	{
		return false;
	}
}

//-------------------------- ПЕРЕГРУЗКА ОПЕРАТОРА []

int& Array::operator [](int elem)          // int возвращаем по ссылке, что бы мы могли не только выводить, но и менять
{                                          // перегрузив оператор [], мы можем через него менять элементы:
	return arr[elem];                      // cout << arr1[2] << endl;    cin >> arr1[2];
}


//-------------------------- ПЕРЕГРУЗКА ОПЕРАТОРА <<

ostream& operator <<(ostream& os, Array& array)
{
	cout << "Массив:" << endl;
	for (int i = 0; i < array.size; i++)
	{
		os << setw(4) << array.arr[i];
	}
	cout << endl;

	return os;                                        // можно использовать:  Cout << arr1;
}

//-------------------------- ПЕРЕГРУЗКА ОПЕРАТОРА >>

istream& operator >>(istream& es, Array& array)
{
	for (int i = 0; i < array.size; i++)
	{
		cout << "Введите " << i + 1 << "-й элемент массива: ";
		es >> array.arr[i];
	}
	cout << endl;

	return es;                                      // можно использовать:  cin >> arr1;
}

//-------------------------- ПОИСК ЭЛЕМЕНТА МАССИВА (ПЕРВОГО ВСТРЕТИВШЕГОСЯ)

int Array::search(int element)
{
	for (int i = 0; i < size; i++)            // перебираем элементы и ищем нужный нам
	{
		if (arr[i] == element)
		{
			return i;                         // возвращаем его номер , если нашли
		}
	}
	return -1;                                // если нет, возвращаем -1, как ошибку
}

//-------------------------- СОРТИРОВКА МАССИВА ПО ВОЗРАСТАНИЮ

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
