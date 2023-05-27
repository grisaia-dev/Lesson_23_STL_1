#include <iostream>
#include "Vector/Vector.h"

int main(void) {
	Vector<int> vec = {1, 2};
	for (auto& i : vec) {
		i = 1;
		std::cout << i << std::endl;
	}
	return 0;
}