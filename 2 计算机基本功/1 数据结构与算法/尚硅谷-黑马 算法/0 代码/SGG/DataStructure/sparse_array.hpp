#pragma once
// ϡ������ʵ��
// ϡ������Ͷ�ά����֮����໥ת��
// Լ����ϡ�������һ��Ϊ��Ϣ��
// ���ԣ�ģ�������ɣ���������ʹ��

#include <vector>
#include <array>

namespace SGG {
	template<class T> std::vector<std::array<int, 3>> TDA_to_SA(T& TDA, const int& imax, const int& jmax);	// ��ά���� �� ϡ������
	std::vector<std::vector<int>> SA_to_TDA(const std::vector<std::array<int, 3>>& SA);	// ϡ������ �� ��ά����
}
