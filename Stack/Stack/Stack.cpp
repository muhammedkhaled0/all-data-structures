#include "Stack.h"
#include<assert.h>
template <class T>
Stack<T>::Stack() {
	size = 5;
	arr = new T[size];
	count = 0;
}
template <class T>
int Stack<T>::Length() {
	return count;
}
template <class T>
void Stack<T>::Push(T value) {
	if (count == size) Expand();
	arr[count] = value;
	count++;
}
template <class T>
void Stack<T>::Pop() {
	assert(!empty());
	count--;
}
template <class T>
bool Stack<T>::empty() {
	return count == 0;
}
template <class T>
T Stack<T>::Top() {
	assert(!empty());
	return arr[count - 1];
}
template <class T>
void Stack<T>::Expand() {
	int newSize = size * 2;
	T* newArr = new T[newSize];
	for (int i = 0; i < count; i++) {
		newArr[i] = arr[i];
	}
	delete[] arr;
	arr = newArr;
	size = newSize;
}
template <class T>
Stack<T>::~Stack() {
	delete[] arr;
	arr = nullptr;
}



