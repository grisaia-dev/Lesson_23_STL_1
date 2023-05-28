#include <iostream>
#include "Vector/Vector.h"

int main(void) {
	// int
	std::cout << "Vector type INT:" << std::endl;
	Vector<int> int_vec = { 1, 2 }; // Поддерживает список инициализации
	for (const auto& i : int_vec)
		std::cout << i << " ";
	std::cout << "\t\t[size]:" << int_vec.size() << " [capacity]: " << int_vec.capacity() << std::endl;
	
	int_vec.push_back(3);
	for (const auto& i : int_vec)
		std::cout << i << " ";
	std::cout << "\t\t[size]:" << int_vec.size() << " [capacity]: " << int_vec.capacity() << std::endl;

	int_vec.push_back(3);
	for (const auto& i : int_vec)
		std::cout << i << " ";
	std::cout << "\t[size]:" << int_vec.size() << " [capacity]: " << int_vec.capacity() << std::endl;

	int_vec.push_back(43);
	int_vec.push_back(12);
	for (const auto& i : int_vec)
		std::cout << i << " ";
	std::cout << "\t[size]:" << int_vec.size() << " [capacity]: " << int_vec.capacity() << std::endl;

	// empty vector
	std::cout << "\nEmpty vector type INT:" << std::endl;
	Vector<int> empty_vec; 
	for (const auto& i : empty_vec)
		std::cout << i << " ";
	std::cout << "\t\t[size]:" << empty_vec.size() << " [capacity]: " << empty_vec.capacity() << std::endl;

	empty_vec.push_back(1);
	for (const auto& i : empty_vec)
		std::cout << i << " ";
	std::cout << "\t\t[size]:" << empty_vec.size() << " [capacity]: " << empty_vec.capacity() << std::endl;

	empty_vec.push_back(12);
	empty_vec.push_back(15);
	for (const auto& i : empty_vec)
		std::cout << i << " ";
	std::cout << "\t[size]:" << empty_vec.size() << " [capacity]: " << empty_vec.capacity() << std::endl;

	empty_vec.push_back(12);
	for (const auto& i : empty_vec)
		std::cout << i << " ";
	std::cout << "\t[size]:" << empty_vec.size() << " [capacity]: " << empty_vec.capacity() << std::endl;

	// Vector type char
	std::cout << "\nVector type CHAR:" << std::endl;
	Vector<char> char_vec;
	for (const auto& i : char_vec)
		std::cout << i << " ";
	std::cout << "\t\t[size]:" << char_vec.size() << " [capacity]: " << char_vec.capacity() << std::endl;
	
	char_vec.push_back('a');
	char_vec.push_back('b');
	for (const auto& i : char_vec)
		std::cout << i << " ";
	std::cout << "\t\t[size]:" << char_vec.size() << " [capacity]: " << char_vec.capacity() << std::endl;
	
	char_vec.push_back('c');
	char_vec.push_back('d');
	char_vec.push_back('e');
	for (const auto& i : char_vec)
		std::cout << i << " ";
	std::cout << "\t[size]:" << char_vec.size() << " [capacity]: " << char_vec.capacity() << std::endl;

	// Vector type std::string
	std::cout << "\nVector type STD::STRING:" << std::endl;
	Vector<std::string> string_vec = { "Hello" };
	for (const auto& i : string_vec)
		std::cout << i << " ";
	std::cout << "\t\t[size]:" << string_vec.size() << " [capacity]: " << string_vec.capacity() << std::endl;

	string_vec.push_back("world");
	for (const auto& i : string_vec)
		std::cout << i << " ";
	std::cout << "\t[size]:" << string_vec.size() << " [capacity]: " << string_vec.capacity() << std::endl;

	string_vec.push_back("!");
	string_vec.push_back("!");
	for (const auto& i : string_vec)
		std::cout << i << " ";
	std::cout << "[size]:" << string_vec.size() << " [capacity]: " << string_vec.capacity() << std::endl;
	return 0;
}