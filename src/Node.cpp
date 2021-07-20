
/* 
 * CPP file to initialize Node.h member functions
 * 
 * Author: Chris Haidas
 */

#pragma once

#include "Node.h"

template<typename T>
Node<T>::Node() {
	this->data = T();

	this->left = nullptr;
	this->right = nullptr;
}

template<typename T>
Node<T>::Node(T data, Node<T>* left, Node<T>* right) {
	this->data = data;

	this->left = left;
	this->right = right;
}

template<typename T>
Node<T>& Node<T>::operator=(T data) {
	this->set_data(data);

	return *this;
}

template<typename T>
void Node<T>::set_data(T data) {
	this->data = data;
}

template<typename T>
void Node<T>::set_left(Node<T>* left) {
	this->left = left;
}

template<typename T>
void Node<T>::set_right(Node<T>* right) {
	this->right = right;
}

template<typename T>
T Node<T>::get_data() {
	return this->data;
}

template<typename T>
Node<T>* Node<T>::get_left() {
	return this->left;
}

template<typename T>
Node<T>* Node<T>::get_right() {
	return this->right;
}

