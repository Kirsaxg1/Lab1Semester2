#ifndef  PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

class priority_queue {

public:

	virtual ~priority_queue() = default;

	virtual void insert(int priority, char* data);
	virtual char* peek() = 0;
	virtual char* peek_priority() = 0;
	virtual priority_queue* merge(priority_queue* other) = 0;


	virtual size_t size() = 0;
	virtual void remove() = 0;
};
#endif // ! PRIORITY_QUEUE_H
