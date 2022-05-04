#pragma once
// 稀疏数组实现
// 稀疏数组和二维数组之间的相互转换
// 约定：稀疏数组第一行为信息行
// 测试：模块测试完成，可以正常使用

#include <vector>
#include <array>

namespace SGG {
	template<class T> std::vector<std::array<int, 3>> TDA_to_SA(T& TDA, const int& imax, const int& jmax);	// 二维数组 → 稀疏数组
	std::vector<std::vector<int>> SA_to_TDA(const std::vector<std::array<int, 3>>& SA);	// 稀疏数组 → 二维数组
}
