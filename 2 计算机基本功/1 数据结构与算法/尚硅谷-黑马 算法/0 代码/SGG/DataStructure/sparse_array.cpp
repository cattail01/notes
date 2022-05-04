// ϡ�������ʵ��

#include <iostream>	// for io
#include <vector>	// for vector
#include <array>	// for array
#include <fstream>	// for file io

#include "../../BasicComponent/test_controller.hpp"	// for test

// ʵ��
#include "sparse_array.hpp"

using namespace std;

// �й�����ƿռ�
namespace SGG {
	// ������TDA_to_SA
	// ���ܣ�����ϡ������
	// ������һ����ά���������������Ĵ�С
	// ���أ�vector��ϡ������
	// ע�⣺���ɵ�ϡ�������һ��Ϊԭ�������Ϣ�У�imax,jmax,��Ч��������
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
	// ���ܣ���ϡ������ת��Ϊԭ����
	// ������ϡ������	decltype(TDA_to_SA())
	// ���أ�ԭ����Ķ�ά����
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

// ����
#if SPARSE_ARRAY_TEST
int main()
{
	//cout << "hello algorithm!" << endl;
	// �������ɣ�0��û�����ӵĵ㣩
	array<array<int, 11>, 11> checker_broad;
	for (auto& i : checker_broad) {
		for (auto& j : i) {
			j = 0;
		}
	}

	// ���ӵ��루1���ӣ�2���ӣ�
	checker_broad[1][2] = 1;
	checker_broad[2][3] = 2;

	// ԭʼ���̼��
	cout << "ԭʼ���̼�飺" << endl;
	print_TDA(checker_broad);

	// ����ϡ������
	auto SA = SGG::TDA_to_SA(checker_broad, 11, 11);

	// ��ӡϡ������
	cout << "��ӡϡ������" << endl;
	print_TDA(SA);

	// �洢ϡ������
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

	// ��ȡϡ������
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

	// ϡ���������ɶ�ά����
	auto TDA = SGG::SA_to_TDA(fSA);

	// ��ӡԭ����
	cout << "��ӡԭ����" << endl;
	print_TDA(TDA);

	return 0;
}
#endif // SPARSE_ARRY_TEST
