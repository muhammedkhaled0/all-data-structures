#pragma once
template <class T>
class Node {
public:
	Node<T>* left,* right;
	T data;
	Node();
	Node(T);
};
template <class T>
class BST
{
	Node<T>* root;
	int count;
public:
	BST();
	bool contains(T);
	Node<T>* findNode(T);
	void insert(T val);
	int length();
	bool empty();
	void traverse(int);

	void inOrder(Node<T>*);
	void preOrder(Node<T>*);
	void postOrder(Node<T>*);

	Node<T>* findParent(T);
	Node<T>* findMin(Node<T>*);
	void remove(T val);
	void deleteBST(Node<T>*);
	~BST();

};

