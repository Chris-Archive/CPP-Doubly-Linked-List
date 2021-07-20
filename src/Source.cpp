
/*
 * Source file to test List functionality.
 * 
 * Author: Chris Haidas
 */

#include <iostream>

#include "List.h"
#include "List.cpp"

using std::cout;

/**
 * A number generator that will fill
 * a List<int> with data. Data will
 * likely be the same since the number
 * generators will run within a second of
 * each other.
 */
template<typename T>
void gen_list(List<T>& list, size_t count) {
	srand((unsigned)time(NULL));

	for (size_t i = 0; i < count; ++i) {
		if (rand() % 2) {
			list.push_back(rand() % 10);
		}
		else {
			list.push_front(rand() % 10);
		}
	}
}

void test_addequ() {
	List<int> list1;
	List<int> list2;

	//generate random numbers into the list
	gen_list(list1, 4);
	gen_list(list2, 4);

	cout << "\nlist1[i] - list2[i]:\n";
	for (size_t i = 0; i < list1.size(); ++i) {
		cout << list1[i] << " - " << list2[i] << "\n";
	}

	//concatenate the two lists
	list1 += list2;

	cout << "\nConcatenated string:\n";
	for (size_t i  = 0; i < list1.size(); ++i) {
		cout << list1[i] << " ";
	}

	cout << "\n";
}

void test_iterator() {
	List<int> list;

	gen_list(list, 14);

	/**
	 * A reference cannot be used here 
	 * unless it is declared as constant
	 * since it must be an lvalue
	 */
	cout << "Using range-based for-loop:\n";
	for (const auto& x : list) {
		cout << x << " ";
	}


	cout << "\nUsing iterators directly:\n";
	for (List<int>::iterator it = list.begin(); it != list.end(); ++it) {
		cout << *it << " ";
	}
}

int main(int argc, char** argv) {
	
	test_addequ();
	test_iterator();

	return 0;
}