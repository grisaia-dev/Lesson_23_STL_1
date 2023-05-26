#include <iostream>
#include <map>

int main(void) {
	std::string symbols = "Hello world!!";
	std::map<char, int> mp;
	std::multimap<int, char> mtp;

	for (auto& i : symbols) mp[i]++; // Увиличиваем значения и присваиваем элементы
	for (auto& pair : mp) // Вставляем в multimap ключи и значения
		mtp.insert(std::make_pair(pair.second, pair.first)); // и сразу он сортирует

	std::cout << "[IN]: " << symbols << std::endl;
	std::cout << "[OUT]:\n";
	std::multimap<int, char>::reverse_iterator rit;	// Создаем обратный итератор
 	for (rit = mtp.rbegin(); rit != mtp.rend(); rit++) // и присваеваем ему обратный итератор отсортированного контейнера
		std::cout << rit->second << ": " << rit->first << std::endl; // выводим значение потом ключи
	return 0;
}