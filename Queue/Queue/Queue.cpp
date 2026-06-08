#include "Queue.h"
#include<assert.h>
template <class T>
Queue<T>::Queue() {
	size = 5;
	count = 0;
	arr = new T[size];
	front = back = -1;
}
template<class T>
int Queue<T>::length() {
	return count;
}
template<class T>
T Queue<T>::Front() {
	assert(!empty());
	return arr[front];
}
template<class T>
bool Queue<T>::empty() {
	return count == 0;
}
template<class T>
void Queue<T>::enqueue(T element) {
	if (count == size)expand();
	back = (back + 1) % size;
	if (count == 0)front = back;
	arr[back] = element;
	count++;
}
template<class T>
void Queue<T>::dequeue() {
	assert(!empty());
	if (count == 1) front = back = -1;
	else front = (front + 1)%size;
	count--;
}
template<class T>
void Queue<T>::expand() {
	int newSize = size * 2;
	T* newArr = new T[newSize];
	for (int i = 0; i < count; i++) newArr[i] = arr[(front + i) % size];
	delete[] arr;
	arr = newArr;
	front = 0;
	back = count - 1;
	size = newSize;
}
template<class T>
Queue<T>::~Queue() {
	delete[] arr;
	arr = nullptr;
}