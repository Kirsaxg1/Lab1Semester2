#ifndef BINARY_HEAP_H
#define BINARY_HEAP_H

#include "5.h"
#include <iostream>

class binary_priority_queue {

public:

	binary_priority_queue();
	~binary_priority_queue() = default;
	binary_priority_queue(const binary_priority_queue& other) = default;
	binary_priority_queue& operator=(const binary_priority_queue& other) = default;

	[[nodiscard]] size_t size() const;
	[[nodiscard]] size_t capacity() const;

	void insert(const char* data, size_t priority);
	[[nodiscard]] const char* top() const;
	[[nodiscard]] int top_priority() const;
	void remove();

	priority_queue* merge(priority_queue* other);

private:

	const size_t init_capacity_heap = 8;
	const size_t capacity_heap_growth = 2;

	struct node {
		char* data;
		int priority;
	};

	node* heap_arr;
	size_t _size;
	size_t _capacity;

	void sift_up(int index);
	void sift_down(int index);
	//void build_heap();
	void swap(node& one, node& two);

	void resize(size_t new_capacity);

	//int parent(int i);
	//int leftChild(int i);
	//int rightChild(int i);
};

#endif // !BINARY_HEAP_H