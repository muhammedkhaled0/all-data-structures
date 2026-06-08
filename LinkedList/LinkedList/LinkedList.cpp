#include "LinkedList.h"
#include <assert.h>

template<class T>
Node<T>::Node() {
	data = T{};
	next = nullptr;
}
template<class T>
Node<T>::Node(T value) {
	data = value;
	next = nullptr;
}
template<class T>
LinkedList<T>::LinkedList() {
	head = tail = nullptr;
	count = 0;
}
template<class T>
int LinkedList<T>::Length() {
	return count;
}
template<class T>
bool LinkedList<T>::empty() {
	return count == 0;
}
template<class T>
T LinkedList<T>::At(int pos) {
	assert(pos >= 0 && pos < count);
	Node<T>* temp = head;
	for (int i = 0; i < pos; i++)temp = temp->next;
		return temp->data;
}
template<class T>
void LinkedList<T>::Append(T value) {
	Node<T>* newNode = new Node(value);
	if (count == 0) {
		head = tail = newNode;
	}
	else {
		tail->next = newNode;
		tail = newNode;
	}
	count++;
}
template<class T>
void LinkedList<T>::InsertAt(int pos,T value) {
	assert(pos >= 0 && pos < count);
	Node<T>* newNode = new Node(value);
	Node<T>*temp = head;
	if (pos == 0) {
		newNode->next = head;
		head = newNode;
	}
	else {
		for (int i = 0; i < pos-1; i++) {
			temp = temp->next;
		}
		newNode->next = temp->next;
		temp->next = newNode;
	}
	count++;
}

template<class T>
void LinkedList<T>::DeleteAt(int pos) {
	assert(pos >= 0 && pos < count);
	Node<T>* temp = head;
	if(pos==0){
		head = head->next;
		delete temp;
		if (count == 1) tail = nullptr;
	}
	else {
		for (int i = 0; i < pos-1; i++)
			temp = temp->next;
		Node<T>* del = temp->next;
		temp->next = del->next;
		if (del==tail)tail = temp;
		delete del;
	}
	count--;
}
template<class T>
LinkedList<T>::~LinkedList() {
	while (head!= nullptr)DeleteAt(0);
}


