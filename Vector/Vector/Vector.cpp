#include "Vector.h"
#include<assert.h>
template <class T>
Vector<T>::Vector() {
	count = 0;
	size = 5;
	arr = new T[size];
}
template<class T>
int Vector<T>::Length() {
	return count;
}
template<class T>
bool Vector<T>::empty() {
	return count == 0;
}
template<class T>
T Vector<T>::At(int pos) {
	assert(pos>=0 && pos<count);
	return arr[pos];
}
template<class T>
void Vector<T>::Append(T value) {
	if (count == size) Expand();
	arr[count] = value;
	count++;
}
template<class T>
void Vector<T>::Expand() {
	int newSize = size * 2;
	T* newArr = new T[newSize];
	for (int i = 0; i < count;i++) newArr[i] = arr[i];
	size = newSize;
	delete[] arr;
	arr = newArr;
}
template<class T>
void Vector<T>::insertAt(int pos,T value) {
	assert(pos >= 0 && pos <= count);
	if (count == size)Expand();
	for (int i = count-1; i >=pos; i--) {
		arr[i + 1] = arr[i];
	}
	arr[pos] = value;
	count++;

}
template<class T>
void Vector<T>::deleteAt(int pos) {
	assert(pos >= 0 && pos < count);
	for (int i = pos; i < count - 1; i++)arr[i] = arr[i + 1];
	count--;
}
template<class T>
Vector<T>::~Vector() {
	delete[] arr;
	arr = nullptr;
}