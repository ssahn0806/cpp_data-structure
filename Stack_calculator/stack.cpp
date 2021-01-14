#include "Stack.h"
#include <cassert>

template <class Item>
Stack<Item>::Stack(size_t size)
{
	data = new Item[size];
	used = 0;
}

template <class Item>
Stack<Item>::~Stack()
{
	delete[] data;
	used = 0;
}

template <class Item>
void Stack<Item>::push(const Item& entry)
{
	//assert(size() < capacity); // overflow
	data[used++] = entry;
}

template <class Item>
void Stack<Item>::pop()
{
	assert(!empty()); // underflow
	used--;
}

template <class Item>
Item Stack<Item>::top() const
{
	assert(!empty()); // underflow
	return data[used - 1];
}

template <class Item>
bool Stack<Item>::empty() const
{
	return used == 0;
}

template <class Item>
size_t Stack<Item>::size() const
{
	return used;
}