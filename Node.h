
/*
 * 
 * This file defines a template node class
 * for data structures to use.
 * 
 * Author Chris Haidas
 */

#pragma once

template<typename T>
class Node {
public:
	
	Node();
	Node(T data, Node<T>* prev = nullptr, Node<T>* next = nullptr);

	/* 
	 * Overloaded "=" operator to assign
	 * data directly into the node
	 * without using set_data(T)
	 * 
	 */
	Node<T>& operator=(T data);

	void set_data(T data);
	T get_data();

	void set_left(Node<T>* left);
	Node<T>* get_left();

	void set_right(Node<T>* right);
	Node<T>* get_right();

protected:

	//The data the node is holding
	T data;

	//Pointers to the previous/left and next/right nodes
	Node<T>* left;
	Node<T>* right;
};