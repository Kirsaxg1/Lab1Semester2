#include "6.final.h"
#include <iostream>
#include <cstring>


void binary_queue::swap(node& a, node& b)
{
	auto temp = a;
	a = b;
	b = temp;
}

/*
* void binary_queue::resize(size_t new_capasity)
{
	node* new_heap = new node[new_capasity];

	for (int i = 0; i < size; ++i)
	{
		new_heap[i].data = new char[std::strlen(heap[i].data) + 1];
		std::strcpy(new_heap[i].data, heap[i].data);

		new_heap[i].priority = heap[i].priority;

		delete[] heap[i].data;
	}

	delete[] heap;

	heap = new_heap;
	capasity = new_capasity;
}
*/

/*
* void binary_queue::insert(int priority, char* data)
{
	char* data_cpy = new char[std::strlen(data) + 1];
	std::strcpy(data_cpy, data);

	if (size == capasity)
	{
		resize(capasity * 2);
		capasity *= 2;
	}

	++size;
	heap[size - 1].data = data_cpy;
	heap[size - 1].priority = priority;

	siftUp(size - 1);
}
*/


void binary_queue::siftUp(size_t index)
{
	while (index > 1 && heap[index].priority < heap[index / 2].priority)
	{
		swap(heap[index], heap[index / 2]);
		index /= 2;
	}
}

void binary_queue::siftDown(size_t index)
{
	while (2 * index <= size)
	{
		int j = 2 * index;
		if (2 * index + 1 <= size && heap[2 * index + 1].priority < heap[2 * index].priority)
		{
			j = 2 * index + 1;
		}
		if (heap[j].priority >= heap[index].priority)
		{
			break;
		}
		swap(heap[j], heap[index]);
		index = j;
	}
}

binary_queue::binary_queue()
{
	heap = new node[capasity];
	size = 0;
}

binary_queue::binary_queue(const binary_queue&other)
{
	size = other.size;
	capasity = other.capasity;

	heap = new node[capasity];

	for (int i = 0; i < size; ++i)
	{
		heap[i].data = new char[std::strlen(other.heap[i].data) + 1];
		strcpy(heap[i].data, other.heap[i].data);
		heap[i].priority = other.heap[i].priority;
	}
}

binary_queue::~binary_queue()
{
	for (int i = 0; i < size; ++i)
	{
		delete[] heap[i].data;
	}
	delete[] heap;
}

void binary_queue::cloneup()
{
	if (heap)
	{
		for (int i = 0; i < size; ++i)
		{
			delete[] heap[i].data;
		}
		delete heap;
		heap = nullptr;
		size = 0;
		capasity = 0;
	}
}

void binary_queue::clone(const binary_queue& other)
{
	capasity = other.capasity;
	size = other.size;

	heap = new node[capasity];

	for (int i = 0; i < size; ++i)
	{
		heap[i].data = new char[std::strlen(other.heap[i].data) + 1];
		std::strcpy(heap[i].data, other.heap[i].data);
		heap[i].priority = other.heap[i].priority;
	}
}

binary_queue&binary_queue::operator=(const binary_queue& other)
{

	if (this != &other)
	{
		cloneup();
		clone(other);
	}

	return *this;
	
}

char* binary_queue::peek()
{
	return heap->data;
}

int binary_queue::peek_priority()
{
	return heap->priority;
} 

void binary_queue::remove()
{
	if (size == 0)
	{
		throw std::out_of_range("Heap is empty");
	}
	delete[] heap[0].data;

	heap[0] = heap[size - 1];
	--size;
	siftDown(0);
}

priority_queue* binary_queue::merge(priority_queue* other)
{
	if (other == nullptr)
	{
		throw std::invalid_argument("other is nullptr");
	}
	if (other == this)
	{
		return this;
	}
	while (other->size() > 0)
	{
		insert(other->peek(), other->peek_priority());
		other->remove();
	}
	return this;
}