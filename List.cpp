
/*
 * CPP file to initialize List.h member functions
 *
 * Author: Chris Haidas
 */

#include "List.h"
/*
 * This is the cpp file for the 
 * List.h header class
 * 
 */

template<typename T>
List<T>::List() {
	this->data = nullptr;
	this->head = nullptr;
	this->tail = nullptr;
}

template<typename T>
List<T>::List(List<T>& other) {
	for (size_t i = 0; i < other.size(); ++i) {
		this->push_back(other[i]);
	}
}

template<typename T>
List<T>::~List() {
	while (this->head) {
		this->pop_back();
	}
}

template<typename T>
void List<T>::push_back(T data) {
	Node<T>* newNode = new Node<T>(data);

	if (this->is_empty()) {
		this->head = newNode;
		this->tail = newNode;
	}
	else {
		Node<T>* tempTail = this->tail;

		tempTail->set_right(newNode);
		newNode->set_left(tempTail);

		this->tail = newNode;
	}
}

template<typename T>
void List<T>::push_front(T data) {
	Node<T>* newNode = new Node<T>(data);

	if (this->is_empty()) {
		this->head = newNode;
		this->tail = newNode;
	}
	else {
		Node<T>* tempHead = this->head;

		newNode->set_right(tempHead);
		tempHead->set_left(newNode);

		this->head = newNode;
	}
}

template<typename T>
void List<T>::pop_back() {
	if(this->size() > 1) {
		Node<T>* tempTail = this->tail;

		this->tail->get_left()->set_right(nullptr);
		this->tail = tempTail->get_left();

		delete tempTail;
	}
	else {
		delete this->tail;

		this->head = nullptr;
		this->tail = nullptr;
	}
}

template<typename T>
void List<T>::pop_front() {
	if (this->size() > 1) {
		Node<T>* tempHead = this->head;

		this->head->get_right()->set_left(nullptr);
		this->head = tempHead->get_right();

		delete tempHead;
	}
	else {
		delete this->head;

		this->head = nullptr;
		this->tail = nullptr;
	}
}

template<typename T>
T List<T>::front() {
	return this->head->get_data();
}

template<typename T>
T List<T>::back() {
	return this->tail->get_data();
}

template<typename T>
T List<T>::at(size_t index) {
	Node<T>* iterator = this->head;
	
	for (size_t i = 0; i < index; ++i) {
		iterator = iterator->get_right();
	}

	return iterator->get_data();
}

template<typename T>
T List<T>::operator[](size_t index) {
	return this->at(index);
}

template<typename T>
size_t List<T>::size() {
	Node<T>* iterator = this->head;
	size_t size = 0;

	while (iterator) {
		size++;

		iterator = iterator->get_right();
	}
	
	return size;
}

template<typename T>
bool List<T>::is_empty() {
	return this->head == nullptr;
}

template<typename T>
List<T>& List<T>::operator+=(List<T>& other) {
	//Input into this List instance
	for (size_t i = 0; i < other.size(); ++i) {
		this->push_back(other[i]);
	}

	//Return a reference of this object
	return *this;
}