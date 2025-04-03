#ifndef BINARY_QUEUE_H
#define BINARY_QUEUE_H

#include "5.h"
#include <iostream>

class binary_queue {

	struct node {
		char* data;
		int priority;
	};

	node* heap;
	size_t size;
	size_t capasity;

	void siftUp(size_t index);
	void siftDown(size_t index);
	void resize(size_t new_capasity);

	void swap(node& a, node& b);

	void cloneup();
	void clone(binary_queue const& other);

public:

	binary_queue();
	~binary_queue() = default;
	binary_queue(const binary_queue& other) = default;
	binary_queue& operator = (const binary_queue& other) = default;

	void insert(int priority, char* data);
	char* peek();
	int peek_priority();
	void remove();

	priority_queue* merge(priority_queue* other);

};

#endif BINARY_QUEUE_H