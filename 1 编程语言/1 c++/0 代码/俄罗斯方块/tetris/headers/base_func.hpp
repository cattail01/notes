#pragma once
/**
* һЩ��������
**/

#include <ctime>
#include <random>
#include <Windows.h>
namespace base_func {

	// ��ȡ����������䷶Χ֮�ڣ�
	// �������
	int get_rand_int(const int min, const int max) {
		using namespace std;
		random_device rd;
		default_random_engine eg(rd());
		uniform_int_distribution<int> distr(min, max);
		return distr(eg);
	}

	// ��ʱ����
	// �������
	void sleep(int x) {
		Sleep(x);	// windows API
	}

}// namespace base_func
