#include <iostream>
#include <map>

int main(void) {
	std::string symbols = "Hello world!!";
	std::map<char, int> mp;
	std::multimap<int, char> mtp;

	for (auto& i : symbols) mp[i]++; // ����������� �������� � ����������� ��������
	for (auto& pair : mp) // ��������� � multimap ����� � ��������
		mtp.insert(std::make_pair(pair.second, pair.first)); // � ����� �� ���������

	std::cout << "[IN]: " << symbols << std::endl;
	std::cout << "[OUT]:\n";
	std::multimap<int, char>::reverse_iterator rit;	// ������� �������� ��������
 	for (rit = mtp.rbegin(); rit != mtp.rend(); rit++) // � ����������� ��� �������� �������� ���������������� ����������
		std::cout << rit->second << ": " << rit->first << std::endl; // ������� �������� ����� �����
	return 0;
}