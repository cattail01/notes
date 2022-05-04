#pragma once
/**
* 一些基础功能
**/

#include <ctime>
#include <random>
#include <Windows.h>
namespace base_func {

	// 获取随机数（区间范围之内）
	// 测试完毕
	int get_rand_int(const int min, const int max) {
		using namespace std;
		random_device rd;
		default_random_engine eg(rd());
		uniform_int_distribution<int> distr(min, max);
		return distr(eg);
	}

	// 延时函数
	// 测试完毕
	void sleep(int x) {
		Sleep(x);	// windows API
	}

}// namespace base_func
