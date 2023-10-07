#pragma once

#include "Node.h"

struct List {

	Node* head;

	List();

	~List();

	unsigned long long getLength(); // ¹8

	Node* getItem(unsigned long long index); // ¹6

	bool isEmpty(); // ¹11

	void push_back(Node* elem); // ¹1

	void push_front(Node* elem); // ¹2

	void insert(unsigned long long index, Node* elem); // ¹5

	void appendList(List* list); // ¹14

	void frontList(List* list); // ¹15

	void insertList(unsigned long long index, List* list); // ¹13

	void deleteLast(); // ¹3 

	void deleteFirst(); // ¹4

	void deleteByIndex(unsigned long long index); // ¹7

	void deleteList(); // ¹9

	void replace(unsigned long long index, Node* elem); // ¹10

	void swap(unsigned long long index1, unsigned long long index2); // ¹19

	void reverse(); // ¹12

	bool isListInside(List* list); // ¹16

	long long searchFirstSublist(List* list); // ¹17

	long long searchLastSublist(List* list); // ¹18

};