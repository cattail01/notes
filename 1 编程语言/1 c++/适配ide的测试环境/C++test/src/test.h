#ifndef	TEST
#define TEST

#include <iostream>
#include <sstream>
#include <iomanip>


namespace my_test {

// �����������
void test_len(size_t len1, size_t len2, size_t len3, size_t wide)
{
	std::string str1, str2, str3;
	std::stringstream ss;
	// �ַ����������
	ss << len1 << " " << len2 << " " << len3;
	ss >> str1 >> str2 >> str3;
	// �������
	str1 += "   |";
	std::cout << std::setw(wide) << str1;
	str2 += "   |";
	std::cout << std::setw(wide) << str2;
	str3 += "   |";
	std::cout << std::setw(wide) << str3 << "\n";
}



}	// namespace my_test

#endif	// TEST