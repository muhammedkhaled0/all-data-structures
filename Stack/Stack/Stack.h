#pragma once
template <class T>
class Stack
{
	T* arr;
	int count;
	int size;
public:
	Stack();
	int Length();
	void Push(T);
	void Pop();
	T Top();
	bool empty();
	void Expand();
	~Stack();
};

