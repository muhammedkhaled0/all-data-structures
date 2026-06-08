#pragma once
template<class T>
class Node {
public:
	T data;
	Node<T>* next;
	Node();
	Node(T);
};
template<class T>
class LinkedList
{
	Node<T>* head;
	Node<T>* tail;
	int count;
public:
	LinkedList();
	int Length();
	bool empty();
	T At(int);
	void InsertAt(int, T);
	void Append(T);
	void DeleteAt(int);
	~LinkedList(void);
};

