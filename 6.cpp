#include "6.h"
#include <iostream>

void binary_priority_queue::sift_up(int index)
{
	while (index > 1 && heap_arr[index].priority < heap_arr[index / 2].priority)
	{
		swap(heap_arr[index], heap_arr[index / 2]);
		index /= 2;
	}
}

void binary_priority_queue::sift_down(int index)
{
	while (2 * index <= _size)
	{
		int l = 2 * index;
		int r = 2 * index + 1;

		int u = (r <= _size && heap_arr[r].priority < heap_arr[l].priority ? r : l);
		if (heap_arr[index].priority <= heap_arr[u].priority) break;

		swap(heap_arr[index], heap_arr[u]);
		index = u;
	}
}

binary_priority_queue::binary_priority_queue()
{
	heap_arr = new node[init_capacity_heap];
	_capacity = init_capacity_heap;
	_size = 0;
}

binary_priority_queue::~binary_priority_queue()
{
	for (int i = 0; i < _size; ++i)
	{
		delete[] heap_arr[i].data;
	}

	delete[] heap_arr;
}

[[nodiscard]] size_t binary_priority_queue::size()const
{
	return _size;
}

[[nodiscard]] size_t binary_priority_queue::capacity()const
{
	return _capacity;
}

[[nodiscard]] const char* binary_priority_queue::top() const
{
	return heap_arr->data;
}

[[nodiscard]] int binary_priority_queue::top_priority() const
{
	return heap_arr->priority;
}

void binary_priority_queue::swap(node& one, node& two)
{
	auto temp = one;
	one = two;
	two = temp;
}