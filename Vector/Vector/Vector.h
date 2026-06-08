#pragma once
template<class T>
class Vector
{
	T* arr;
	int size, count;
public:
	Vector();
	int Length();
	void Append(T);
	void Expand();
	bool empty();
	T At(int);
	void insertAt(int, T);
	void deleteAt(int);
	~Vector(void);
};

