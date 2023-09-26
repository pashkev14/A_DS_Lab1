#pragma once

#include "Node.h"

struct List {

	Node* head;

	List(); // DONE

	~List(); // DONE

	unsigned int getLength(); // DONE

	Node* getItem(unsigned int index); // DONE

	bool isEmpty(); // DONE

	void push_back(Node* elem); // DONE

	void push_front(Node* elem); // DONE

	void insert(unsigned int index, Node* elem); // DONE

	void appendList(List* list); // DONE

	void frontList(List* list); // DONE

	void insertList(unsigned int index, List* list); // DONE

	void deleteLast(); // DONE

	void deleteFirst(); // DONE

	void deleteByIndex(unsigned int index); // DONE

	void deleteList(); // DONE

	void replace(unsigned int index, Node* elem); // DONE

	void reverse(); // DONE

};