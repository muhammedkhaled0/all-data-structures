#pragma once
template <class T>
class Queue
{
	T* arr;
	int front, back, count, size;
public:
	Queue();
	int length();
	void enqueue(T);
	void dequeue();
	void expand();
	T Front();
	bool empty();
	~Queue();
};

