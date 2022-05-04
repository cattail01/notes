// 稀疏数组的实现

#include <iostream>	// for io
#include <vector>	// for vector
#include <array>	// for array
#include <fstream>	// for file io

#include "../../BasicComponent/test_controller.hpp"	// for test

// 实现
#include "sparse_array.hpp"

using namespace std;

// 尚硅谷名称空间
namespace SGG {
	// 函数：TDA_to_SA
	// 功能：生成稀疏数组
	// 参数：一个二维的容器，该容器的大小
	// 返回：vector的稀疏数组
	// 注意：生成的稀疏数组第一行为原数组的信息行，imax,jmax,有效数据数量
	template<class T>
	vector<array<int, 3>> TDA_to_SA(T& TDA, const int& imax, const int& jmax) {
		vector<array<int, 3>> SA;
		SA.push_back({ imax, jmax, 0 });
		int useful_data_count = 0;
		for (int i = 0; i < imax; i++) {
			for (int j = 0; j < jmax; j++) {
				if (TDA[i][j] != 0) {
					useful_data_count++;
					SA.push_back({ i, j, TDA[i][j] });
				}
			}
		}
		SA[0][2] = useful_data_count;
		return SA;
	}
	// 功能：将稀疏数组转化为原数组
	// 参数：稀疏数组	decltype(TDA_to_SA())
	// 返回：原数组的二维容器
	vector<vector<int>> SA_to_TDA(const vector<array<int, 3>>& SA) {
		vector<vector<int>> TDA;
		for (int i = 0; i < SA[0][0]; i++) {
			TDA.push_back({});
			for (int j = 0; j < SA[0][1]; j++) {
				TDA[i].push_back(0);
			}
		}
		for (int i = 1; i < SA.size(); i++) {
			TDA[SA[i][0]][SA[i][1]] = SA[i][2];
		}
		return TDA;
	}
}	// namespace SGG

template<class T>
inline void print_TDA(T& TDA) {
	for (const auto& i : TDA) {
		for (const auto& j : i) {
			cout << j << "\t";
		}
		cout << endl;
	}
}

// 测试
#if SPARSE_ARRAY_TEST
int main()
{
	//cout << "hello algorithm!" << endl;
	// 棋盘生成（0是没有棋子的点）
	array<array<int, 11>, 11> checker_broad;
	for (auto& i : checker_broad) {
		for (auto& j : i) {
			j = 0;
		}
	}

	// 棋子导入（1黑子，2白子）
	checker_broad[1][2] = 1;
	checker_broad[2][3] = 2;

	// 原始棋盘检查
	cout << "原始棋盘检查：" << endl;
	print_TDA(checker_broad);

	// 生成稀疏数组
	auto SA = SGG::TDA_to_SA(checker_broad, 11, 11);

	// 打印稀疏数组
	cout << "打印稀疏数组" << endl;
	print_TDA(SA);

	// 存储稀疏数组
	fstream fs;
	string addr = "../../Data/sparse_array.data";
	fs.open(addr, ios::in | ios::out);
	if (!fs.is_open()) {
		throw exception();
	}
	for (auto& i : SA) {
		for (auto& j : i) {
			fs << j << "\t";
		}
		fs << endl;
	}
	fs.close();

	// 提取稀疏数组
	ifstream ifs;
	ifs.open(addr);
	decltype(SA) fSA;
	while (true)
	{
		if (!ifs) {
			break;
		}
		array<int, 3> item;
		for (int i = 0; i < 3; i++) {
			ifs >> item[i];
		}
		fSA.push_back(item);
	}

	// 稀疏数组生成二维数组
	auto TDA = SGG::SA_to_TDA(fSA);

	// 打印原数组
	cout << "打印原数组" << endl;
	print_TDA(TDA);

	return 0;
}
#endif // SPARSE_ARRY_TEST
