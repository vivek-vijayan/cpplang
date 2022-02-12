#include "add.h"
#include<iostream>

int main()
{
	Add addition;
	addition.set(4,5);
	std::cout << "Output is  : " << addition.sum();
	return 0;
}

