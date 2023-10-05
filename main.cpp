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
	std::cout << "��������� �� ������ � �������� ����������� �������\n�����: ����� �����, ������ 2309\n\n";
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
		std::cout << "��� ������ �������?\n1 - �������� ������� � ����� ������\n2 - �������� ������� � ������ ������\n";
		std::cout << "3 - ������� ��������� �������\n4 - ������� ������ �������\n5 - �������� ������� �� �������\n6 - �������� ������� �� �������\n";
		std::cout << "7 - ������� ������� �� �������\n8 - �������� ������ ������\n9 - ������� ��� �������� ������\n10 - �������� ������� �� �������\n";
		std::cout << "11 - ������, ������ �� ������\n12 - ���������� ������\n13 - �������� � ������ ������ ������, ������� � �������\n";
		std::cout << "14 - �������� � ����� ������ ������ ������\n15 - �������� � ������ ������ ������ ������\n16 - ��������� ��������� ������� ������ � ������\n";
		std::cout << "17 - �������� ������ ������� ��������� ������� ������ � ������\n18 - �������� ������ ���������� ��������� ������� ������ � ������\n";
		std::cout << "19 - �������� �������� �������\n0 - ����� �� ���������\n������� ����� �������: ";
		
		std::cin >> com;
		if (std::cin.fail()) {
			std::cout << "������� ������������ �������! ���������� ��� ���!\n\n";
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			continue;
		}

		if (com == 0) {
			exit = true;
		}

		if (com == 1) {
			do {
				std::cout << "\n������� �������� ������ �������� (����� �����): ";
				std::cin >> a;
				if (std::cin.fail()) {
					std::cout << "������� ������������ ������! ���������� ��� ���!\n";
					std::cin.clear();
					std::cin.ignore(32767, '\n');
					continue;
				}
				break;
			} 
			while (true);
			tmp = new Node(a);
			std::cout << "������ �� ���������� �������: ";
			print_list(list);
			auto start = high_resolution_clock::now();
			list->push_back(tmp);
			auto stop = high_resolution_clock::now();
			auto duration = duration_cast<milliseconds>(stop - start);
			std::cout << "������ ����� ���������� �������: ";
			print_list(list);
			std::cout << "����� ���������� ������� (� �������������): " << duration.count() << "\n\n";
		}

		if (com == 2) {
			do {
				std::cout << "\n������� �������� ������ �������� (����� �����): ";
				std::cin >> a;
				if (std::cin.fail()) {
					std::cout << "������� ������������ ������! ���������� ��� ���!\n";
					std::cin.clear();
					std::cin.ignore(32767, '\n');
					continue;
				}
				break;
			} 
			while (true);
			tmp = new Node(a);
			std::cout << "������ �� ���������� �������: ";
			print_list(list);
			auto start = high_resolution_clock::now();
			list->push_front(tmp);
			auto stop = high_resolution_clock::now();
			auto duration = duration_cast<milliseconds>(stop - start);
			std::cout << "������ ����� ���������� �������: ";
			print_list(list);
			std::cout << "����� ���������� ������� (� �������������): " << duration.count() << "\n\n";
		}

		if (com == 3) {
			std::cout << "������ �� ���������� �������: ";
			print_list(list);
			auto start = high_resolution_clock::now();
			list->deleteLast();
			auto stop = high_resolution_clock::now();
			auto duration = duration_cast<milliseconds>(stop - start);
			std::cout << "������ ����� ���������� �������: ";
			print_list(list);
			std::cout << "����� ���������� ������� (� �������������): " << duration.count() << "\n\n";
		}

		if (com == 4) {
			std::cout << "������ �� ���������� �������: ";
			print_list(list);
			auto start = high_resolution_clock::now();
			list->deleteFirst();
			auto stop = high_resolution_clock::now();
			auto duration = duration_cast<milliseconds>(stop - start);
			std::cout << "������ ����� ���������� �������: ";
			print_list(list);
			std::cout << "����� ���������� ������� (� �������������): " << duration.count() << "\n\n";
		}

		if (com == 5) {
			do {
				std::cout << "\n������� ������ ������� ������ �������� (����� ��������������� �����): ";
				std::cin >> index1;
				if (std::cin.fail()) {
					std::cout << "������� ������������ ������! ���������� ��� ���!\n";
					std::cin.clear();
					std::cin.ignore(32767, '\n');
					continue;
				}
				std::cout << "������� �������� ������ �������� (����� �����): ";
				std::cin >> a;
				if (std::cin.fail()) {
					std::cout << "������� ������������ ������! ���������� ��� ���!\n";
					std::cin.clear();
					std::cin.ignore(32767, '\n');
					continue;
				}
				break;
			} 
			while (true);
			tmp = new Node(a);
			std::cout << "������ �� ���������� �������: ";
			print_list(list);
			auto start = high_resolution_clock::now();
			list->insert(index1, tmp);
			auto stop = high_resolution_clock::now();
			auto duration = duration_cast<milliseconds>(stop - start);
			std::cout << "������ ����� ���������� �������: ";
			print_list(list);
			std::cout << "����� ���������� ������� (� �������������): " << duration.count() << "\n\n";
		}

		if (com == 6) {
			do {
				std::cout << "\n������� ������ �������� �������� (����� ��������������� �����): ";
				std::cin >> index1;
				if (std::cin.fail()) {
					std::cout << "������� ������������ ������! ���������� ��� ���!\n";
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
			if (tmp != nullptr) std::cout << "���������� ������� �� �������: " << tmp->val << "\n";
			else std::cout << "������� �� ��� ������.\n";
			std::cout << "����� ���������� ������� (� �������������): " << duration.count() << "\n\n";
		}

		if (com == 7) {
			do {
				std::cout << "\n������� ������ ���������� �������� (����� ��������������� �����): ";
				std::cin >> index1;
				if (std::cin.fail()) {
					std::cout << "������� ������������ ������! ���������� ��� ���!\n";
					std::cin.clear();
					std::cin.ignore(32767, '\n');
					continue;
				}
				break;
			} 
			while (true);
			std::cout << "������ �� ���������� �������: ";
			print_list(list);
			auto start = high_resolution_clock::now();
			list->deleteByIndex(index1);
			auto stop = high_resolution_clock::now();
			auto duration = duration_cast<milliseconds>(stop - start);
			std::cout << "������ ����� ���������� �������: ";
			print_list(list);
			std::cout << "����� ���������� ������� (� �������������): " << duration.count() << "\n\n";
		}

		if (com == 8) {
			auto start = high_resolution_clock::now();
			length = list->getLength();
			auto stop = high_resolution_clock::now();
			auto duration = duration_cast<milliseconds>(stop - start);
			std::cout << "������� ����� ������: " << length << "\n";
			std::cout << "����� ���������� ������� (� �������������): " << duration.count() << "\n\n";
		}

		if (com == 9) {
			std::cout << "������ �� ���������� �������: ";
			print_list(list);
			auto start = high_resolution_clock::now();
			list->deleteList();
			auto stop = high_resolution_clock::now();
			auto duration = duration_cast<milliseconds>(stop - start);
			std::cout << "������ ����� ���������� �������: ";
			print_list(list);
			std::cout << "����� ���������� ������� (� �������������): " << duration.count() << "\n\n";
		}

		if (com == 10) {
			do {
				std::cout << "\n������� ������ ������ �� ����� ������� (����� ��������������� �����): ";
				std::cin >> index1;
				if (std::cin.fail()) {
					std::cout << "������� ������������ ������! ���������� ��� ���!\n";
					std::cin.clear();
					std::cin.ignore(32767, '\n');
					continue;
				}
				std::cout << "������� �������� ������ �������� (����� �����): ";
				std::cin >> a;
				if (std::cin.fail()) {
					std::cout << "������� ������������ ������! ���������� ��� ���!\n";
					std::cin.clear();
					std::cin.ignore(32767, '\n');
					continue;
				}
				break;
			} 
			while (true);
			tmp = new Node(a);
			std::cout << "������ �� ���������� �������: ";
			print_list(list);
			auto start = high_resolution_clock::now();
			list->replace(index1, tmp);
			auto stop = high_resolution_clock::now();
			auto duration = duration_cast<milliseconds>(stop - start);
			std::cout << "������ ����� ���������� �������: ";
			print_list(list);
			std::cout << "����� ���������� ������� (� �������������): " << duration.count() << "\n\n";
		}

		if (com == 11) {
			auto start = high_resolution_clock::now();
			isEmpty = list->isEmpty();
			auto stop = high_resolution_clock::now();
			auto duration = duration_cast<milliseconds>(stop - start);
			std::cout << "������ " << (isEmpty ? "����.\n" : "�� ����.\n");
			std::cout << "����� ���������� ������� (� �������������): " << duration.count() << "\n\n";
		}

		if (com == 12) {
			std::cout << "������ �� ���������� �������: ";
			print_list(list);
			auto start = high_resolution_clock::now();
			list->reverse();
			auto stop = high_resolution_clock::now();
			auto duration = duration_cast<milliseconds>(stop - start);
			std::cout << "������ ����� ���������� �������: ";
			print_list(list);
			std::cout << "����� ���������� ������� (� �������������): " << duration.count() << "\n\n";
		}

		if (com == 13) {
			tmp_list = new List;
			do {
				flag = false;
				std::cout << "\n������� ������ ������� ������ ������ (����� ��������������� �����): ";
				std::cin >> index1;
				if (std::cin.fail()) {
					std::cout << "������� ������������ ������! ���������� ��� ���!\n";
					std::cin.clear();
					std::cin.ignore(32767, '\n');
					continue;
				}
				std::cout << "������� ����� ������ �������� ������ ������ (����� �����).\n����� �������� ������, ������� ��� ������ �� �����:\n";
				while (std::cin >> a) {
					tmp = new Node(a);
					tmp_list->push_back(tmp);
				}
				std::cin.clear();
				std::cin.ignore(32767, '\n');
				break;
			} 
			while (true);
			std::cout << "������ �� ���������� �������: ";
			print_list(list);
			auto start = high_resolution_clock::now();
			list->insertList(index1, tmp_list);
			auto stop = high_resolution_clock::now();
			auto duration = duration_cast<milliseconds>(stop - start);
			std::cout << "������ ����� ���������� �������: ";
			print_list(list);
			std::cout << "����� ���������� ������� (� �������������): " << duration.count() << "\n\n";
			delete tmp_list;
		}

		/*if (com == 13) {
			tmp_list = new List;
			do {
				flag = false;
				std::cout << "\n������� ������ ������� ������ ������ (����� ��������������� �����): ";
				std::cin >> index1;
				if (std::cin.fail()) {
					std::cout << "������� ������������ ������! ���������� ��� ���!\n";
					std::cin.clear();
					std::cin.ignore(32767, '\n');
					continue;
				}
				std::cout << "������� ����� ������ �������� ������ ������ (����� �����): ";
				do {
					std::cin >> a;
					if (std::cin.fail()) {
						std::cout << "������������������ ���� ������� �����������! ���������� ��� ���!\n";
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
			std::cout << "������ �� ���������� �������: ";
			print_list(list);
			auto start = high_resolution_clock::now();
			list->insertList(index1, tmp_list);
			auto stop = high_resolution_clock::now();
			auto duration = duration_cast<milliseconds>(stop - start);
			std::cout << "������ ����� ���������� �������: ";
			print_list(list);
			std::cout << "����� ���������� ������� (� �������������): " << duration.count() << "\n\n";
			delete tmp_list;
		}*/
		if (com == 19) {
			do {
				std::cout << "\n������� ������ ������� �������� �� ������������ (����� ��������������� �����): ";
				std::cin >> index1;
				if (std::cin.fail()) {
					std::cout << "������� ������������ ������! ���������� ��� ���!\n";
					std::cin.clear();
					std::cin.ignore(32767, '\n');
					continue;
				}
				std::cout << "������� ������ ������� �������� �� ������������ (����� ��������������� �����): ";
				std::cin >> index2;
				if (std::cin.fail()) {
					std::cout << "������� ������������ ������! ���������� ��� ���!\n";
					std::cin.clear();
					std::cin.ignore(32767, '\n');
					continue;
				}
				break;
			} 
			while (true);
			std::cout << "������ �� ���������� �������: ";
			print_list(list);
			auto start = high_resolution_clock::now();
			list->swap(index1, index2);
			auto stop = high_resolution_clock::now();
			auto duration = duration_cast<milliseconds>(stop - start);
			std::cout << "������ ����� ���������� �������: ";
			print_list(list);
			std::cout << "����� ���������� ������� (� �������������): " << duration.count() << "\n\n";
		}

		if (exit) {
			std::cout << "��������� ��������� ���� ������.";
			break;
		}
		std::cin.clear();
		std::cin.ignore(32767, '\n');
	}
	while (true);
	delete list;
	return 0;
}