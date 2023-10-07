#pragma once

#include "Node.h"

struct List {

	Node* head;

	List();

	~List();

	unsigned long long getLength(); // �8

	Node* getItem(unsigned long long index); // �6

	bool isEmpty(); // �11

	void push_back(Node* elem); // �1

	void push_front(Node* elem); // �2

	void insert(unsigned long long index, Node* elem); // �5

	void appendList(List* list); // �14

	void frontList(List* list); // �15

	void insertList(unsigned long long index, List* list); // �13

	void deleteLast(); // �3 

	void deleteFirst(); // �4

	void deleteByIndex(unsigned long long index); // �7

	void deleteList(); // �9

	void replace(unsigned long long index, Node* elem); // �10

	void swap(unsigned long long index1, unsigned long long index2); // �19

	void reverse(); // �12

	bool isListInside(List* list); // �16

	long long searchFirstSublist(List* list); // �17

	long long searchLastSublist(List* list); // �18

};