#include "List.h"

List::List() {
	this->head = nullptr;
}

List::~List() {
	this->deleteList();
}

unsigned int List::getLength() {
	unsigned int length = 0;
	Node* tmp = this->head;
	while (tmp != nullptr) {
		tmp = tmp->next;
		++length;
	}
	return length;
}

Node* List::getItem(unsigned int index) {
	Node* tmp = this->head;
	unsigned int length = 0;
	while (tmp != nullptr) {
		if (length == index) return tmp;
		tmp = tmp->next;
		++length;
	}
	return nullptr;
}

bool List::isEmpty() {
	return this->head == nullptr;
}

void List::push_back(Node* elem) {
	if (this->isEmpty()) {
		this->head = elem;
		return;
	}
	Node* tmp = this->head;
	while (tmp->next != nullptr) tmp = tmp->next;
	tmp->next = elem;
}

void List::push_front(Node* elem) {
	elem->next = this->head;
	this->head = elem;
}

void List::insert(unsigned int index, Node* elem) {
	if (this->isEmpty() && index != 0) return;
	if (index == 0) {
		this->push_front(elem);
		return;
	}
	Node* tmp = this->head;
	unsigned int length = 0;
	while (tmp->next->next != nullptr) {
		if (length + 1 == index) {
			elem->next = tmp->next;
			tmp->next = elem;
			return;
		}
		tmp = tmp->next;
		++length;
	}
}

void List::appendList(List* list) {
	if (list->isEmpty()) return;
	if (this->isEmpty()) {
		this->head = list->head;
		return;
	}
	Node* tmp = this->head;
	while (tmp->next != nullptr) tmp = tmp->next;
	tmp->next = list->head;
}

void List::frontList(List* list) {
	if (list->isEmpty()) return;
	Node* tmp = list->head;
	while (tmp->next != nullptr) {
		tmp = tmp->next;
	}
	tmp->next = this->head;
	this->head = list->head;
}

void List::insertList(unsigned int index, List* list) {
	if (list->isEmpty()) return;
	if (this->isEmpty() && index != 0) return;
	if (index == 0) {
		this->frontList(list);
		return;
	}
	Node* this_tmp = this->head;
	unsigned int length = 0;
	while (this_tmp->next->next != nullptr) {
		if (length + 1 == index) {
			Node* other_tmp = list->head;
			while (other_tmp->next != nullptr) other_tmp = other_tmp->next;
			other_tmp->next = this_tmp->next;
			this_tmp = list->head;
			return;
		}
		this_tmp = this_tmp->next;
		++length;
	}
}

void List::deleteLast() {
	if (this->isEmpty()) return;
	if (this->head->next == nullptr) {
		delete this->head;
		this->head = nullptr;
		return;
	}
	Node* tmp = this->head;
	while (tmp->next->next != nullptr) {
		tmp = tmp->next;
	}
	delete tmp->next;
	tmp->next = nullptr;
}

void List::deleteFirst() {
	if (this->isEmpty()) return;
	Node* tmp = this->head->next;
	delete this->head;
	this->head = tmp;
}

void List::deleteByIndex(unsigned int index) {
	if (this->isEmpty()) return;
	if (index == 0) {
		this->deleteFirst();
		return;
	}
	Node* tmp = this->head;
	unsigned int length = 0;
	while (tmp->next->next != nullptr) {
		if (length + 1 == index) {
			Node* toDel = tmp->next;
			tmp->next = toDel->next;
			delete toDel;
			return;
		}
		tmp = tmp->next;
		++length;
	}
}

void List::deleteList() {
	while (!this->isEmpty()) this->deleteFirst();
}

void List::replace(unsigned int index, Node* elem) {
	if (this->isEmpty()) return;
	Node* tmp = this->head;
	unsigned int length = 0;
	while (tmp->next->next != nullptr) {
		if (length + 1 == index) {
			Node* toDel = tmp->next;
			elem->next = toDel->next;
			tmp->next = elem;
			delete toDel;
			return;
		}
		tmp = tmp->next;
		++length;
	}
}

void List::reverse() {
	Node* cur = this->head;
	Node* prev = nullptr, * next = nullptr;
	while (cur != nullptr) {
		next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
	}
	this->head = prev;
}