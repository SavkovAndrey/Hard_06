#include <iomanip>
#include <iostream>
#include "func.h"
#include "Array1.h"

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


//---------------------------MAIN----------------------------------------------------
int main() {
	setlocale(LC_ALL, "RU");
	srand(time(NULL));

	int s;                

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

