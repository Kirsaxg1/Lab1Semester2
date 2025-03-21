#include <iostream>

typedef struct PriorItem {
	int priority;
	char* data;
}PriorItem;

typedef struct PriorQueue {
	PriorItem* items;
	size_t size;
	size_t capacity;
}PriorQueue;


PriorQueue* insert_value();
PriorQueue* search_max();
PriorQueue* removeMax();
PriorQueue* merge();