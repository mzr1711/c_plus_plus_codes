#pragma once

#include <iostream>

template<class T>
class MyArray
{
public:
	MyArray(int _capacity)
	{
		//std::cout << "有参构造调用" << std::endl;
		capacity = _capacity;
		size = 0;
		address = new T[capacity];
	}

	MyArray(const MyArray& array)
	{
		//std::cout << "拷贝构造调用" << std::endl;
		capacity = array.capacity;
		size = array.size;

		address = new T[capacity];

		for (int i = 0; i < size; i++)
			address[i] = array.address[i];
	}

	MyArray& operator=(const MyArray& array)
	{
		//std::cout << "operator=调用" << std::endl;
		if (address != NULL)
		{
			delete[] address;
			address = NULL;
			capacity = 0;
			size = 0;
		}

		capacity = array.capacity;
		size = array.size;
		address = new T[capacity];

		for (int i = 0; i < size; i++)
			address[i] = array.address[i];

		return *this;
	}

	~MyArray()
	{
		//std::cout << "析构调用" << std::endl;
		if (address != NULL)
		{
			delete[] address;
			capacity = 0;
			size = 0;
		}
	}

	int get_capacity()
	{
		return capacity;
	}

	int get_size()
	{
		return size;
	}

	void push_back(T val)
	{
		if (size == capacity)
		{
			std::cout << "数组已满" << std::endl;
			return;
		}

		address[size] = val;
		size++;
	}

	void pop_back()
	{
		if (size == 0)
		{
			std::cout << "数组为空" << std::endl;
			return;
		}

		size--;
	}

	T& operator[](int index)
	{
		if (index >= 0 && index < size)
			return address[index];
	}

private:
	T* address;
	int capacity;
	int size;
};