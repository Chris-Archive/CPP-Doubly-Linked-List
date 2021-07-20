
/**
 * CPP file to initialize List.h member functions
 *
 * Author: Chris Haidas
 */

#pragma once
#include <initializer_list>
#include "Node.h"
#include "Node.cpp"

/**
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

	//Return the size of the list
	size_t size();

	//Return if the list is empty
	bool is_empty();

	//Return the data of the first node
	T front();

	//Return the data of the last node
	T back();

	//Returns the data at the given index
	T at(size_t index);

	/**
	 * Overloaded "[]" operator that behaves
	 * like array indexing.
	 * 
	 * Returns the data at the given index.
	 */
	T operator[](size_t index);

	/**
	 * Overloaded "+=" operator the allow
	 * a concatenation of two seperate lists.
	 * 
	 * The other list will be appended at
	 * the end of this list.
	 * 
	 */
	List<T>& operator+=(List<T>& other);

	/**
	 * An iterator class for the List
	 * 
	 */
	class iterator {
	public:
		//Default Constructor
		iterator() {
			this->itNode = nullptr;
		}

		//Assignment Constructor
		iterator(Node<T>* itOther) {
			this->itNode = itOther;
		}

		/**
		 * Overloaded equality operator
		 * 
		 * @param itOther - the other iterator
		 * @return Whether or not the addresses of
		 * these two nodes are the same.
		 */
		bool operator==(const iterator& itOther) {
			return this->itNode == itOther.itNode;
		}

		/**
		 * Overloaded inequality operator
		 *
		 * @param itOther - the other iterator
		 * @return Whether or not the addresses of
		 * these two nodes are the same.
		 */
		bool operator!=(const iterator& itOther) {
			return this->itNode != itOther.itNode;
		}

		/**
		 * Overloaded assignment operator
		 * Set this node to the other node, 
		 * 
		 * @Param 
		 * @return A reference to this object instance
		 */
		iterator& operator=(const Node<T>* itOther) {
			this->itNode = itOther;

			return *this;
		}

		/**
		 * Overload the dereference operator, so that
		 * "*it" returns the data of the node during iteration
		 * 
		 * @return Data of the node
		 */
		T operator*() {
			return this->itNode->get_data();
		}

		/**
		 * Overloaded increment operator to allow
		 * node traversal.
		 * 
		 * @return A reference of this instance
		 */
		iterator& operator++() {
			if (this->itNode) {
				this->itNode = this->itNode->get_right();
			}

			return *this;
		}

		/**
		 * Overloaded increment operator to 
		 * increment through the list, then return
		 * a copy of the iterator pre-incrementation
		 * 
		 * @return A copy of the iterator before incrementation
		 */
		iterator operator++(int) {
			return *this++;
		}

	protected:
		Node<T>* itNode;
	};

	/**
	 * Used to initialize the iteration by
	 * pointing it to the start of the list
	 * 
	 * @return An instance of the iterator 
	 * containing the head's address
	 */
	iterator begin() {
		return iterator(this->head);
	}

	/**
	 * Used to end the iteration, representing
	 * the end of a list
	 *
	 * @return nullptr
	 */
	iterator end() {
		return iterator(nullptr);
	}
private:
	Node<T>* data;

	Node<T>* head;
	Node<T>* tail;
};
