#include "BST.h"
#include<assert.h>
#include<iostream>
using namespace std;
template <class T>
Node<T>::Node() {
	left = right = nullptr;
	data = T{};
}
template<class T>
Node<T>::Node(T value) {
	left = right = nullptr;
	data = value;
}
template <class T>
BST<T>::BST() {
	root = nullptr;
	count = 0;
}
template<class T>
int BST<T>::length() {
	return count;
}
template <class T>
bool BST<T>::empty() {
	return count == 0;
}
template <class T>
Node<T>* BST<T>::findNode(T value) {
	Node<T>* temp = root;
	while (temp != nullptr && temp->data != value) {
		if (value < temp->data) {
			temp = temp->left;
		}
		else {
			temp = temp->right;
		}
	}
	return temp;
}
template <class T>
bool BST<T>::contains(T value) {
	Node<T>* temp = findNode(value);
	return temp != nullptr;
}
template <class T>
void BST<T>::insert(T value) {
	assert(contains(value) == false);
	Node<T>*newNode = new Node<T>(value);
	if (root == nullptr)root = newNode;
	else {
		Node<T>* temp = root;
		while (true) {
			if (value < temp->data) {
				if (temp->left == nullptr) {
					temp->left = newNode;
					break;
				}
				else
					temp = temp->left;
			}

			else {
				if (temp->right == nullptr) {
					temp->right = newNode;
					break;
				}
				else temp = temp->right;
			}
		}
	}
	count++;
}
template <class T>
void BST<T>::traverse(int order)
{
	if (order == 0)
		inOrder(root);
	else if (order == 1)
		preOrder(root);
	else
		postOrder(root);
}
template <class T>
void BST<T>::inOrder(Node<T>* node) {
	if (node != nullptr) {
		inOrder(node->left);
		cout << node->data << endl;
		inOrder(node->right);
	}
}
template <class T>
void BST<T>::preOrder(Node<T>* node)
{
	if (node != nullptr)
	{
		cout << node->data << endl;
		preOrder(node->left);
		preOrder(node->right);
	}
}
template <class T>
void BST<T>::postOrder(Node<T>* node)
{
	if (node != nullptr)
	{
		postOrder(node->left);
		postOrder(node->right);
		cout << node->data << endl;
	}
}
template<class T>
Node<T>* BST<T>::findParent(T value) {
	assert(contains(value));
	Node<T>* parent = nullptr;
	Node<T>* child=root;
	while (child->data != value) {
		parent = child;
		if (value < child->data) {
			child = child->left;
		}
		else {
			child = child->right;

		}
	}
	return parent;
}
template<class T>
Node<T>* BST<T>::findMin(Node<T>* start) {
	Node<T>* temp = start;
	while (temp->left != nullptr)temp = temp->left;
	return temp;
}
template<class T>
void BST<T>::remove(T value) {
	assert(contains(value));
	Node<T>*temp = findNode(value);

	if (temp->left == nullptr && temp->right == nullptr) {
		if (temp == root)root = nullptr;
		else {
			Node<T>* parent = findParent(value);
			if (temp == parent->left)parent->left = nullptr;
			else parent->right = nullptr;
		}
		delete temp;

	}
	else if (temp->left == nullptr && temp->right != nullptr) {
		if (temp == root)
			root = temp->right;
		else {
			Node<T>* parent = findParent(value);
			if (value < parent->data)parent->left = temp->right;
			else parent->right = temp->right;
		}
		delete temp;
	}
	else if (temp->left != nullptr && temp->right == nullptr) {
		if (temp == root)
			root = temp->left;
		else {
			Node<T>* parent = findParent(value);
			if (value < parent->data)parent->left = temp->left;
			else parent->right = temp->left;
		}
		delete temp;
	}
	else
	{
		Node<T>* minNode = findMin(temp->right);
		Node<T>* parent = findParent(minNode->data);

		temp->data = minNode->data;

		if (parent == temp)
			parent->right = minNode->right;
		else
			parent->left = minNode->right;

		delete minNode;
	}
	count--;
}
template <class T>
void BST<T>::deleteBST(Node<T>* node)
{
	if (node == nullptr)
		return;

	deleteBST(node->left);
	deleteBST(node->right);
	delete node;
}
template <class T>
BST<T>::~BST()
{
	deleteBST(root);
}