#include <iostream>
#include <set>

int main(void) {
	std::set<int> rd;
	unsigned count = 0;

	std::cout << "[IN]:" << std::endl;
	std::cin >> count;
	while (count != 0) {
		int var = 0;
		std::cin >> var;
		rd.insert(var);
		count--;
	}

	std::cout << "[OUT]:" << std::endl;
	std::set<int>::reverse_iterator rit;
	for (rit = rd.rbegin(); rit != rd.rend(); rit++)
		std::cout << *rit << std::endl;
	return 0;
}