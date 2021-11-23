#include <iostream>
#include <algorithm>
#include "Header.h"

int main() {

	List a;


	a.push_back(17);
	a.push_back(7);
	a.push_back(14);
	a.push_back(4);
	a.push_back(147);
	a.push_back(2);
	a.push_front(5);
	a.push_front(115);
	a.pop_back();


	a.print();
	a.sort();
	a.print();
	


}