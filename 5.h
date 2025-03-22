#include <iostream>

//typedef struct PriorItem {
//	int priority;
//	char* data;
//}PriorItem;
//
//typedef struct PriorQueue {
//	PriorItem* items;
//	size_t size;
//	size_t capacity;
//}PriorQueue;
//
//
//PriorQueue* insert_value();
//PriorQueue* search_max();
//PriorQueue* removeMax();
//PriorQueue* merge();

class priority_queue {

public:

	priority_queue(); 
	~priority_queue() = default;
	priority_queue& operator = (const priority_queue& other) = default;
	priority_queue(const priority_queue& other) = default;

	[[nodiscard]]void insert(char* str, int priority);
	[[nodiscard]] int search()const;
	[[nodiscard]] void remove()const;
	priority_queue* merge(priority_queue* other);

};