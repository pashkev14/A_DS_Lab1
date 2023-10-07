#include "List.h"

List::List() {
	this->head = nullptr;
}

List::~List() {
	this->deleteList();
}

unsigned long long List::getLength() {
	unsigned long long length = 0;
	Node* tmp = this->head;
	while (tmp != nullptr) {
		tmp = tmp->next;
		++length;
	}
	return length;
}

Node* List::getItem(unsigned long long index) {
	Node* tmp = this->head;
	unsigned long long length = 0;
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

void List::insert(unsigned long long index, Node* elem) {
	if (this->isEmpty() && index != 0) return;
	if (index == 0) {
		this->push_front(elem);
		return;
	}
	Node* cur = this->head, *prev = nullptr;
	unsigned long long len = 0;
	while (cur != nullptr && len != index) {
		prev = cur;
		cur = cur->next;
		++len;
	}
	if (cur == nullptr) return;
	prev->next = elem;
	elem->next = cur;
}

void List::appendList(List* list) {
	if (list->isEmpty()) return;
	if (this->isEmpty()) {
		this->head = list->head;
		return;
	}
	Node* tmp = this->head, * prev = nullptr;
	while (tmp != nullptr) {
		prev = tmp;
		tmp = tmp->next;
	}
	prev->next = list->head;
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

void List::insertList(unsigned long long index, List* list) {
	if (list->isEmpty()) return;
	if (this->isEmpty() && index != 0) return;
	if (index == 0) {
		this->frontList(list);
		return;
	}
	Node* cur = this->head, *prev = nullptr;
	unsigned long long len = 0;
	while (cur != nullptr && len != index) {
		prev = cur;
		cur = cur->next;
		++len;
	}
	if (cur == nullptr) return;
	Node* other_cur = list->head;
	while (other_cur->next != nullptr) other_cur = other_cur->next;
	prev->next = list->head;
	other_cur->next = cur;
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

void List::deleteByIndex(unsigned long long index) {
	if (this->isEmpty()) return;
	if (index == 0) {
		this->deleteFirst();
		return;
	}
	Node* cur = this->head, *prev = nullptr;
	unsigned long long len = 0;
	while (cur != nullptr && len != index) {
		prev = cur;
		cur = cur->next;
		++len;
	}
	if (cur == nullptr) return;
	prev->next = cur->next;
	delete cur;
}

void List::deleteList() {
	while (!this->isEmpty()) this->deleteFirst();
}

void List::replace(unsigned long long index, Node* elem) {
	if (this->isEmpty()) return;
	Node* cur = this->head;
	if (index == 0) {
		elem->next = cur->next;
		this->head = elem;
		delete cur;
		return;
	}
	Node* prev = nullptr;
	unsigned long long len = 0;
	while (cur != nullptr && len != index) {
		prev = cur;
		cur = cur->next;
		++len;
	}
	if (cur == nullptr) return;
	prev->next = elem;
	elem->next = cur->next;
	delete cur;
}

void List::swap(unsigned long long index1, unsigned long long index2) {
	if (this->isEmpty() || index1 == index2 || this->head->next == nullptr) return;
	Node* prev1 = nullptr, * toSwap1 = this->head;
	unsigned long long len1 = 0;
	while (toSwap1 != nullptr && len1 != index1) {
		prev1 = toSwap1;
		toSwap1 = toSwap1->next;
		++len1;
	}
	Node* prev2 = nullptr, * toSwap2 = this->head;
	unsigned long long len2 = 0;
	while (toSwap2 != nullptr && len2 != index2) {
		prev2 = toSwap2;
		toSwap2 = toSwap2->next;
		++len2;
	}
	if (toSwap1 == nullptr || toSwap2 == nullptr) return;
	if (prev1 == nullptr) this->head = toSwap2;
	else prev1->next = toSwap2;
	if (prev2 == nullptr) this->head = toSwap1;
	else prev2->next = toSwap1;
	Node* tmp = toSwap2->next;
	toSwap2->next = toSwap1->next;
	toSwap1->next = tmp;
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

bool List::isListInside(List* list) {
	if (this->isEmpty() && list->isEmpty()) return true;
	if (this->isEmpty() || list->isEmpty()) return false;
	Node* cur1 = this->head, *cur2 = list->head;
	Node* tmp;
	while (cur1 != nullptr) {
		tmp = cur1;
		while (cur2 != nullptr) {
			if (tmp == nullptr) return false;
			if (tmp->val == cur2->val) {
				tmp = tmp->next;
				cur2 = cur2->next;
			}
			else break;
		}
		if (cur2 == nullptr) return true;
		cur2 = list->head;
		cur1 = cur1->next;
	}
	return false;
}

long long List::searchFirstSublist(List* list) {
	if (this->isEmpty() && list->isEmpty()) return -1;
	if (this->isEmpty() || list->isEmpty()) return -1;
	long long index = 0;
	Node* cur1 = this->head, * cur2 = list->head;
	Node* tmp;
	while (cur1 != nullptr) {
		tmp = cur1;
		while (cur2 != nullptr) {
			if (tmp == nullptr) return -1;
			if (tmp->val == cur2->val) {
				tmp = tmp->next;
				cur2 = cur2->next;
			}
			else break;
		}
		if (cur2 == nullptr) return index;
		cur2 = list->head;
		cur1 = cur1->next;
		++index;
	}
	return -1;
}

long long List::searchLastSublist(List* list) {
	if (this->isEmpty() && list->isEmpty()) return -1;
	if (this->isEmpty() || list->isEmpty()) return -1;
	long long curIndex = 0, lastIndex = -1;
	Node* cur1 = this->head, * cur2 = list->head;
	Node* tmp;
	while (cur1 != nullptr) {
		tmp = cur1;
		while (cur2 != nullptr) {
			if (tmp == nullptr) return -1;
			if (tmp->val == cur2->val) {
				tmp = tmp->next;
				cur2 = cur2->next;
			}
			else break;
		}
		if (cur2 == nullptr) lastIndex = curIndex;
		cur2 = list->head;
		cur1 = cur1->next;
		++curIndex;
	}
	return lastIndex;
}