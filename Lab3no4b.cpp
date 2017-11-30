#include <iostream>
#include <Windows.h>
#include <string>
/*
4.Реализовать шаблон класса очередь (Queue<X>), хранящий элементы произвольного
типа. Класс должен в обязательном порядке содержать методы:
Вычисление длины очереди;
Добавление нового элемента в конец очереди;
Получение элемента из головы очереди;
Удаление элемента из головы;
Поиск элемента в очереди;
Печать очереди.
б) Реализация очереди с помощью списка;
Автор: Уханов Алексей
*/


using namespace std;

template <class T> struct Node
{
	T x;//инфо данные структуры
	Node *Next; //указатель на следующее звено
};

//КЛАСС ОЧЕРЕДЬ

template <class T> class Queue
{
	Node<T> *Head, *Tail; //Указатели на начало очереди и на конец
public:
	Queue() :Head(NULL), Tail(NULL) {}; //Инициализация указателей как пустых
	~Queue() //Деструктор для освобождения памяти от всего что будет
	{
		Node<T> *temp = Head; //Временный указатель на начало очереди
		while (temp != NULL) //Пока в очереди что-то есть

		{
			temp = Head->Next; //Резерв адреса на следующий элемент очереди

			delete Head;  //Освобождение памяти от первой структуры как элемента очереди

			Head = temp;  //Сдвиг начала на следующий адрес, который берем из резерва

		}
	}

	void Add(T x) //Функция заполнения структуры Node и добавления её в очередь как элемента
	{
		Node<T> *temp = new Node<T>; //Выделение памяти для нового звена очереди
		temp->x = x; //Временное запоминание принятого параметра x
		temp->Next = NULL; //Указание, что следующее звено новосозданной структуры пока пустое

		if (Head != NULL) //Если список не пуст 
		{
			Tail->Next = temp; //Указание, что следующее звено очереди это новосозданная структура
			Tail = temp;
		}
		else Head = Tail = temp; //Если список не пуст, добавление первого элемента
	}

	void Print() //Функция отображения очереди Queue 
	{
		Node<T> *temp = Head; //Временный указатель на начало очереди
		while (temp != NULL) //Пока в очереди что-то встречается
		{
			cout << temp->x << " "; //Выводим значения из очереди на экран
			temp = temp->Next; //Сдвигаем указатель на начало на адрес следующего элемента
		}
		cout << endl;
	}

	void del() //Функция изъятия элемента
	{
		if (Head != NULL)  //Если список не пустой
		{
			Node<T> *temp = Head; //Обращаемся к началу очереди с помощью вспомогательного указателя
			Head = Head->Next; //Сдвиг начала очереди
			delete temp; //Освобождение памяти от предыдущего звена очереди
		}
	}

	bool GetEl(T &el) //Функция получения элемента из головы очереди
	{
		if (Head != NULL)  //Если список не пустой
		{
			Node<T> *temp = Head; //Обращаемся к началу очереди с помощью вспомогательного указателя
			el = Head->x;
			Head = Head->Next; //Сдвиг начала очереди
			delete temp; //Освобождение памяти от предыдущего звена очереди
			return true;
		}
		else
			return false;
	}

	int GetLength() //функция возвращающая длину очереди
	{
		int len = 0; //задаем длину равной 0
		Node<T> *ptr = Head; //устанавливаем указатель на голову

		if (ptr == NULL) //если указатель показывает сразу на NULL, то список пуст, т.е. 0 элементов
			return 0;
		else
		{
			while (ptr != NULL) //пока указатель не показывает на NULL передвигаем на следующее звено, увеличивая значение длины
			{
				ptr = ptr->Next;
				len++;
			}

			return len;
		}
	}

	bool found(T el) //функция поиска заданного элемента
	{
		Node<T> *ptr = Head;

		while ((ptr != NULL) && ((ptr->x) != el))
		{
			ptr = ptr->Next;
		}

		return (ptr != NULL);
	}
};





void main()
{
	int item, item1;

	Queue<int> qu_int;
	Queue<string> qu_str;

	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);
	item = -1;

	while (item != 0)
	{
		item = -1;
		cout << "1 - Целое число" << endl;
		cout << "2 - Строка" << endl;
		cout << "0 - Выход" << endl;

		while ((item < 0) || (item > 3))
			cin >> item;
		switch (item)
		{
		case 1:
		{
			item1 = -1;
			int stop = -999;
			while (item1 != 0)
			{
				item1 = -1;
				cout << "1-Ввести полностью" << endl;
				cout << "2-Удалить элемент из головы" << endl;
				cout << "3-Проверить наличие" << endl;
				cout << "4-Достать элемент  из очереди" << endl;
				cout << "5-Печать очереди" << endl;
				cout << "6-Длина очереди" << endl;
				cout << "0-Выход" << endl;
				while ((item1 < 0) || (item1 > 6))
					cin >> item1;
				switch (item1)
				{
				case 1:
				{
					int temp;
					cin >> temp;
					while (temp != stop)
					{
						qu_int.Add(temp);
						cin >> temp;;
					}
					break;
				}
				case 2:
				{
					qu_int.del();
					break;
				}
				case 3:
				{
					int temp;
					cout << "Введите элемент, наличие которого вы хотите проверить:" << endl;
					cin >> temp;
					if (qu_int.found(temp))
						cout << "Элемент найден." << endl;
					else
						cout << "Элемент отсутствует." << endl;
					break;
				}
				case 4:
				{
					int el;
					if (qu_int.GetEl(el))
						cout << "Элемент " << el << " успешно получен из головы очереди" << endl;
					else
						cout << "Попытка достать элемент из пустой очереди" << endl;
					break;
				}
				case 5:
				{
					cout << "Полученная очередь:" << endl;
					qu_int.Print();
					break;
				}
				case 6:
				{
					cout << "Длина очереди равна: " << qu_int.GetLength() << endl;
					break;
				}
				}
			}
			break;
		}
		case 2:
		{

			string stop = "stop";
			item1 = -1;
			while (item1 != 0)
			{
				item1 = -1;
				cout << "1-Ввести полностью" << endl;
				cout << "2-Удалить элемент из головы" << endl;
				cout << "3-Проверить наличие" << endl;
				cout << "4-Достать элемент  из очереди" << endl;
				cout << "5-Печать очереди" << endl;
				cout << "6-Длина очереди" << endl;
				cout << "0-Выход" << endl;
				while ((item1 < 0) || (item1 > 6))
					cin >> item1;
				switch (item1)
				{
				case 1:
				{
					string temp;
					cin >> temp;
					while (temp != stop)
					{
						qu_str.Add(temp);
						cin >> temp;;
					}
					break;
				}
				case 2:
				{
					qu_str.del();
					break;
				}
				case 3:
				{
					string temp;
					cout << "Введите элемент, наличие которого вы хотите проверить:" << endl;
					cin >> temp;
					if (qu_str.found(temp))
						cout << "Элемент найден." << endl;
					else
						cout << "Элемент отсутствует." << endl;
					break;
				}
				case 4:
				{
					string el;
					if (qu_str.GetEl(el))
						cout << "Элемент " << el << " успешно получен из головы очереди" << endl;
					else
						cout << "Попытка достать элемент из пустой очереди" << endl;
					break;
				}
				case 5:
				{
					cout << "Полученная очередь:" << endl;
					qu_str.Print();
					break;
				}
				case 6:
				{
					cout << "Длина очереди равна: " << qu_str.GetLength() << endl;
					break;
				}
				}
			}
			break;
		}
		}
	}
}

