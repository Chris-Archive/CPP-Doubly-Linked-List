
/*
 * CPP file to initialize List.h member functions
 *
 * Author: Chris Haidas
 */

#pragma once
#include "Node.h"
#include "Node.cpp"

/*
 * A Doubly Linked List with extra functionality.
 * 
 */
template<typename T>
class List {
public:
	
	//Default Constructor
	List();

	//Copy Constructor
	List(List<T>& other);

	//Destructor
	~List();
	
	//Push the data at the end of the list
	void push_back(T data);

	//Push the data at the front of the list
	void push_front(T data);

	//Pop the data at the back
	void pop_back();

	//Pop the data at the front
	void pop_front();

	//Return the size of th elist
	size_t size();

	//Return if the list is empty
	bool is_empty();

	//Return the data of the first node
	T front();

	//Return the data of the last node
	T back();

	//Returns the data at the given index
	T at(size_t index);

	/*
	 * Overloaded "[]" operator that behaves
	 * like array indexing.
	 * 
	 * Returns the data at the given index.
	 */
	T operator[](size_t index);

	/*
	 * Overloaded "+=" operator the allow
	 * a concatenation of two seperate lists.
	 * 
	 * The other list will be appended at
	 * the end of this list.
	 * 
	 */
	List<T>& operator+=(List<T>& other);



private:
	Node<T>* data;

	Node<T>* head;
	Node<T>* tail;
};

