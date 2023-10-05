#include <iostream>
#include <locale>
#include <chrono>

#include "List.h"

using namespace std::chrono;

void print_list(List* list) {
	Node* tmp = list->head;
	while (tmp != nullptr) {
		std::cout << tmp->val << " ";
		tmp = tmp->next;
	}
	std::cout << "\n";
}

int main() {
	std::setlocale(LC_ALL, "RUS");
	std::cout << "Программа по работе с линейным односвзяным списком\nАвтор: Савин Павел, группа 2309\n\n";
	short com;
	int a;
	unsigned long long index1, index2, length;
	List* list = new List;
	List* tmp_list = nullptr;
	Node* tmp = nullptr;
	bool exit = false;
	bool isEmpty;
	bool flag;
	do {
		std::cout << "Что хотите сделать?\n1 - Вставить элемент в конец списка\n2 - Вставить элемент в начало списка\n";
		std::cout << "3 - Удалить последний элемент\n4 - Удалить первый элемент\n5 - Добавить элемент по индексу\n6 - Получить элемент по индексу\n";
		std::cout << "7 - Удалить элемент по индексу\n8 - Получить размер списка\n9 - Удалить все элементы списка\n10 - Заменить элемент по индексу\n";
		std::cout << "11 - Узнать, пустой ли список\n12 - Развернуть список\n13 - Вставить в список другой список, начиная с индекса\n";
		std::cout << "14 - Вставить в конец списка другой список\n15 - Вставить в начало списка другой список\n16 - Проверить вхождение другого списка в список\n";
		std::cout << "17 - Получить индекс первого вхождения другого списка в список\n18 - Получить индекс последнего вхождения другого списка в список\n";
		std::cout << "19 - Поменять элементы местами\n0 - Выйти из программы\nВведите номер команды: ";
		
		std::cin >> com;
		if (std::cin.fail()) {
			std::cout << "Введена некорректная команда! Попробуйте еще раз!\n\n";
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			continue;
		}

		if (com == 0) {
			exit = true;
		}

		if (com == 1) {
			do {
				std::cout << "\nВведите значение нового элемента (целое число): ";
				std::cin >> a;
				if (std::cin.fail()) {
					std::cout << "Введены некорректные данные! Попробуйте еще раз!\n";
					std::cin.clear();
					std::cin.ignore(32767, '\n');
					continue;
				}
				break;
			} 
			while (true);
			tmp = new Node(a);
			std::cout << "Список до выполнения функции: ";
			print_list(list);
			auto start = high_resolution_clock::now();
			list->push_back(tmp);
			auto stop = high_resolution_clock::now();
			auto duration = duration_cast<milliseconds>(stop - start);
			std::cout << "Список после выполнения функции: ";
			print_list(list);
			std::cout << "Время выполнения функции (в миллисекундах): " << duration.count() << "\n\n";
		}

		if (com == 2) {
			do {
				std::cout << "\nВведите значение нового элемента (целое число): ";
				std::cin >> a;
				if (std::cin.fail()) {
					std::cout << "Введены некорректные данные! Попробуйте еще раз!\n";
					std::cin.clear();
					std::cin.ignore(32767, '\n');
					continue;
				}
				break;
			} 
			while (true);
			tmp = new Node(a);
			std::cout << "Список до выполнения функции: ";
			print_list(list);
			auto start = high_resolution_clock::now();
			list->push_front(tmp);
			auto stop = high_resolution_clock::now();
			auto duration = duration_cast<milliseconds>(stop - start);
			std::cout << "Список после выполнения функции: ";
			print_list(list);
			std::cout << "Время выполнения функции (в миллисекундах): " << duration.count() << "\n\n";
		}

		if (com == 3) {
			std::cout << "Список до выполнения функции: ";
			print_list(list);
			auto start = high_resolution_clock::now();
			list->deleteLast();
			auto stop = high_resolution_clock::now();
			auto duration = duration_cast<milliseconds>(stop - start);
			std::cout << "Список после выполнения функции: ";
			print_list(list);
			std::cout << "Время выполнения функции (в миллисекундах): " << duration.count() << "\n\n";
		}

		if (com == 4) {
			std::cout << "Список до выполнения функции: ";
			print_list(list);
			auto start = high_resolution_clock::now();
			list->deleteFirst();
			auto stop = high_resolution_clock::now();
			auto duration = duration_cast<milliseconds>(stop - start);
			std::cout << "Список после выполнения функции: ";
			print_list(list);
			std::cout << "Время выполнения функции (в миллисекундах): " << duration.count() << "\n\n";
		}

		if (com == 5) {
			do {
				std::cout << "\nВведите индекс вставки нового элемента (целое неотрицательное число): ";
				std::cin >> index1;
				if (std::cin.fail()) {
					std::cout << "Введены некорректные данные! Попробуйте еще раз!\n";
					std::cin.clear();
					std::cin.ignore(32767, '\n');
					continue;
				}
				std::cout << "Введите значение нового элемента (целое число): ";
				std::cin >> a;
				if (std::cin.fail()) {
					std::cout << "Введены некорректные данные! Попробуйте еще раз!\n";
					std::cin.clear();
					std::cin.ignore(32767, '\n');
					continue;
				}
				break;
			} 
			while (true);
			tmp = new Node(a);
			std::cout << "Список до выполнения функции: ";
			print_list(list);
			auto start = high_resolution_clock::now();
			list->insert(index1, tmp);
			auto stop = high_resolution_clock::now();
			auto duration = duration_cast<milliseconds>(stop - start);
			std::cout << "Список после выполнения функции: ";
			print_list(list);
			std::cout << "Время выполнения функции (в миллисекундах): " << duration.count() << "\n\n";
		}

		if (com == 6) {
			do {
				std::cout << "\nВведите индекс искомого элемента (целое неотрицательное число): ";
				std::cin >> index1;
				if (std::cin.fail()) {
					std::cout << "Введены некорректные данные! Попробуйте еще раз!\n";
					std::cin.clear();
					std::cin.ignore(32767, '\n');
					continue;
				}
				break;
			} 
			while (true);
			auto start = high_resolution_clock::now();
			tmp = list->getItem(index1);
			auto stop = high_resolution_clock::now();
			auto duration = duration_cast<milliseconds>(stop - start);
			if (tmp != nullptr) std::cout << "Полученный элемент по индексу: " << tmp->val << "\n";
			else std::cout << "Элемент не был найден.\n";
			std::cout << "Время выполнения функции (в миллисекундах): " << duration.count() << "\n\n";
		}

		if (com == 7) {
			do {
				std::cout << "\nВведите индекс удаляемого элемента (целое неотрицательное число): ";
				std::cin >> index1;
				if (std::cin.fail()) {
					std::cout << "Введены некорректные данные! Попробуйте еще раз!\n";
					std::cin.clear();
					std::cin.ignore(32767, '\n');
					continue;
				}
				break;
			} 
			while (true);
			std::cout << "Список до выполнения функции: ";
			print_list(list);
			auto start = high_resolution_clock::now();
			list->deleteByIndex(index1);
			auto stop = high_resolution_clock::now();
			auto duration = duration_cast<milliseconds>(stop - start);
			std::cout << "Список после выполнения функции: ";
			print_list(list);
			std::cout << "Время выполнения функции (в миллисекундах): " << duration.count() << "\n\n";
		}

		if (com == 8) {
			auto start = high_resolution_clock::now();
			length = list->getLength();
			auto stop = high_resolution_clock::now();
			auto duration = duration_cast<milliseconds>(stop - start);
			std::cout << "Текущая длина списка: " << length << "\n";
			std::cout << "Время выполнения функции (в миллисекундах): " << duration.count() << "\n\n";
		}

		if (com == 9) {
			std::cout << "Список до выполнения функции: ";
			print_list(list);
			auto start = high_resolution_clock::now();
			list->deleteList();
			auto stop = high_resolution_clock::now();
			auto duration = duration_cast<milliseconds>(stop - start);
			std::cout << "Список после выполнения функции: ";
			print_list(list);
			std::cout << "Время выполнения функции (в миллисекундах): " << duration.count() << "\n\n";
		}

		if (com == 10) {
			do {
				std::cout << "\nВведите индекс замены на новый элемент (целое неотрицательное число): ";
				std::cin >> index1;
				if (std::cin.fail()) {
					std::cout << "Введены некорректные данные! Попробуйте еще раз!\n";
					std::cin.clear();
					std::cin.ignore(32767, '\n');
					continue;
				}
				std::cout << "Введите значение нового элемента (целое число): ";
				std::cin >> a;
				if (std::cin.fail()) {
					std::cout << "Введены некорректные данные! Попробуйте еще раз!\n";
					std::cin.clear();
					std::cin.ignore(32767, '\n');
					continue;
				}
				break;
			} 
			while (true);
			tmp = new Node(a);
			std::cout << "Список до выполнения функции: ";
			print_list(list);
			auto start = high_resolution_clock::now();
			list->replace(index1, tmp);
			auto stop = high_resolution_clock::now();
			auto duration = duration_cast<milliseconds>(stop - start);
			std::cout << "Список после выполнения функции: ";
			print_list(list);
			std::cout << "Время выполнения функции (в миллисекундах): " << duration.count() << "\n\n";
		}

		if (com == 11) {
			auto start = high_resolution_clock::now();
			isEmpty = list->isEmpty();
			auto stop = high_resolution_clock::now();
			auto duration = duration_cast<milliseconds>(stop - start);
			std::cout << "Список " << (isEmpty ? "пуст.\n" : "не пуст.\n");
			std::cout << "Время выполнения функции (в миллисекундах): " << duration.count() << "\n\n";
		}

		if (com == 12) {
			std::cout << "Список до выполнения функции: ";
			print_list(list);
			auto start = high_resolution_clock::now();
			list->reverse();
			auto stop = high_resolution_clock::now();
			auto duration = duration_cast<milliseconds>(stop - start);
			std::cout << "Список после выполнения функции: ";
			print_list(list);
			std::cout << "Время выполнения функции (в миллисекундах): " << duration.count() << "\n\n";
		}

		if (com == 13) {
			tmp_list = new List;
			do {
				flag = false;
				std::cout << "\nВведите индекс вставки нового списка (целое неотрицательное число): ";
				std::cin >> index1;
				if (std::cin.fail()) {
					std::cout << "Введены некорректные данные! Попробуйте еще раз!\n";
					std::cin.clear();
					std::cin.ignore(32767, '\n');
					continue;
				}
				std::cout << "Введите через пробел элементы нового списка (целые числа).\nЧтобы окончить список, введите что угодно не число:\n";
				while (std::cin >> a) {
					tmp = new Node(a);
					tmp_list->push_back(tmp);
				}
				std::cin.clear();
				std::cin.ignore(32767, '\n');
				break;
			} 
			while (true);
			std::cout << "Список до выполнения функции: ";
			print_list(list);
			auto start = high_resolution_clock::now();
			list->insertList(index1, tmp_list);
			auto stop = high_resolution_clock::now();
			auto duration = duration_cast<milliseconds>(stop - start);
			std::cout << "Список после выполнения функции: ";
			print_list(list);
			std::cout << "Время выполнения функции (в миллисекундах): " << duration.count() << "\n\n";
			delete tmp_list;
		}

		/*if (com == 13) {
			tmp_list = new List;
			do {
				flag = false;
				std::cout << "\nВведите индекс вставки нового списка (целое неотрицательное число): ";
				std::cin >> index1;
				if (std::cin.fail()) {
					std::cout << "Введены некорректные данные! Попробуйте еще раз!\n";
					std::cin.clear();
					std::cin.ignore(32767, '\n');
					continue;
				}
				std::cout << "Введите через пробел элементы нового списка (целые числа): ";
				do {
					std::cin >> a;
					if (std::cin.fail()) {
						std::cout << "Последовательность была введена некорректно! Попробуйте еще раз!\n";
						std::cin.clear();
						std::cin.ignore(32767, '\n');
						flag = true;
						break;
					}
					tmp = new Node(a);
					tmp_list->push_back(tmp);
				} 
				while (!std::cin.eof());
				if (flag) continue;
				break;
			} 
			while (true);
			std::cout << "Список до выполнения функции: ";
			print_list(list);
			auto start = high_resolution_clock::now();
			list->insertList(index1, tmp_list);
			auto stop = high_resolution_clock::now();
			auto duration = duration_cast<milliseconds>(stop - start);
			std::cout << "Список после выполнения функции: ";
			print_list(list);
			std::cout << "Время выполнения функции (в миллисекундах): " << duration.count() << "\n\n";
			delete tmp_list;
		}*/
		if (com == 19) {
			do {
				std::cout << "\nВведите индекс первого элемента на перестановку (целое неотрицательное число): ";
				std::cin >> index1;
				if (std::cin.fail()) {
					std::cout << "Введены некорректные данные! Попробуйте еще раз!\n";
					std::cin.clear();
					std::cin.ignore(32767, '\n');
					continue;
				}
				std::cout << "Введите индекс второго элемента на перестановку (целое неотрицательное число): ";
				std::cin >> index2;
				if (std::cin.fail()) {
					std::cout << "Введены некорректные данные! Попробуйте еще раз!\n";
					std::cin.clear();
					std::cin.ignore(32767, '\n');
					continue;
				}
				break;
			} 
			while (true);
			std::cout << "Список до выполнения функции: ";
			print_list(list);
			auto start = high_resolution_clock::now();
			list->swap(index1, index2);
			auto stop = high_resolution_clock::now();
			auto duration = duration_cast<milliseconds>(stop - start);
			std::cout << "Список после выполнения функции: ";
			print_list(list);
			std::cout << "Время выполнения функции (в миллисекундах): " << duration.count() << "\n\n";
		}

		if (exit) {
			std::cout << "Программа завершила свою работу.";
			break;
		}
		std::cin.clear();
		std::cin.ignore(32767, '\n');
	}
	while (true);
	delete list;
	return 0;
}