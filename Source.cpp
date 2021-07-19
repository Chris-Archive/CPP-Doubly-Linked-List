
/*
 * Source file to test List functionality
 * 
 * Author: Chris Haidas
 */

#include <iostream>

#include "List.h"
#include "List.cpp"

using std::cout;

void test_addequ() {
	List<int> list1;
	List<int> list2;

	//generate random numbers into the list
	for (int i = 0; i < 10; ++i) {
		//random chance to push back or push front
		if (rand() % 2) {
			list1.push_back(rand() % 10);
			list2.push_back(rand() % 10);
		}
		else {
			list1.push_front(rand() % 10);
			list2.push_front(rand() % 10);
		}
	}

	for (size_t i = 0; i < list1.size(); ++i) {
		cout << list1[i] << " - " << list2[i] << "\n";
	}

	//concatenate the two lists
	list1 += list2;

	cout << "\nconcatenated string:\n";
	for (size_t i  = 0; i < list1.size(); ++i) {
		cout << list1[i] << " ";
	}
}

int main(int argc, char** argv) {
	srand((unsigned)time(NULL));

	test_addequ();

	return 0;
}