// ����������
// ԭ���������ı���
#include <iostream>
using namespace std;

typedef struct {
	int x, y;
}node;

// ����
node* review(node* point, const node& end_point) {
	while (true) {
		if (point->x == 0 && point->y == 0) {
			return point;
		}
		node old = *point;
		--point;
		// cout << "*" << point->x << point->y << "*" << "\t";
		if (old.y - point->y == 0 && (point->y != end_point.y))   // ����ƽ���ҿ�������
		{

			return point;
		}
		else    continue;
	}
	return point;
}
// ����Ƿ�Ϊ���ɵ����
bool cant_go(node* point, node* nodes, const int& length) {
	for (int i = 0; i < length; i++) {
		if (point->x == nodes[i].x && point->y == nodes[i].y)  return true;
	}
	return false;
}

int main() {
	node end_point, horse_control_nodes[9];
	// ��������
	cin >> end_point.x >> end_point.y >> horse_control_nodes[0].x >> horse_control_nodes[0].y;
	// ������Ŀ��Ƶ�(�����ϵĵ�Ϊ1����ʱ�뿪ʼ)
	horse_control_nodes[1].x = horse_control_nodes[0].x - 1;
	horse_control_nodes[1].y = horse_control_nodes[0].y - 2;

	horse_control_nodes[2].x = horse_control_nodes[0].x - 2;
	horse_control_nodes[2].y = horse_control_nodes[0].y - 1;

	horse_control_nodes[3].x = horse_control_nodes[0].x - 2;
	horse_control_nodes[3].y = horse_control_nodes[0].y + 1;

	horse_control_nodes[4].x = horse_control_nodes[0].x - 1;
	horse_control_nodes[4].y = horse_control_nodes[0].y + 2;

	horse_control_nodes[5].x = horse_control_nodes[0].x + 1;
	horse_control_nodes[5].y = horse_control_nodes[0].y + 2;

	horse_control_nodes[6].x = horse_control_nodes[0].x + 2;
	horse_control_nodes[6].y = horse_control_nodes[0].y + 1;

	horse_control_nodes[7].x = horse_control_nodes[0].x + 2;
	horse_control_nodes[7].y = horse_control_nodes[0].y - 1;

	horse_control_nodes[1].x = horse_control_nodes[0].x + 1;
	horse_control_nodes[1].y = horse_control_nodes[0].y - 2;

	// ��飺ԭ����յ��Ƿ�������Ƶ��ϣ���Ϊ����ʵ�ֵ�Ŀ�꣩

	// ���ɼ�¼�����ƶ���ջ����¼�ɹ��Ĵ���
	node stack[end_point.x + end_point.y + 2 + 1], * point = &stack[0];
	for (auto& i : stack) {
		i.x = i.y = 0;
	}
	point->y = point->x = 0;    (point + 1)->y = 0;
	int count = 0;
	// ���ӿ�ʼ�ƶ�
	while (true) {
		// �����������������յ����ԭ�� �� ������ԭ������һ�����ǣ�0��1��
		if ((end_point.x == 0 && end_point.y == 0) || (point->x == 0 && point->y == 0 && (point + 1)->y == 1))
			break;
		// ���������(�����߽�����һ���㲻��ջ����һ����)�����ƣ�������ܣ������Ƿ������ƣ��ƶ����µ�ѹ��ջ�ڣ�
		if (point->x < end_point.x) {
			node old = *point;
			++old.x;
			*(++point) = old;
		}

		else if (point->y < end_point.y) {
			auto old = *point;
			++old.y;
			*(++point) = old;
		}
		// cout << (point->x) << " " << (point->y) << "\t\t";
		// ֮����õ����ʣ������endpoint����ͳ�� + 1�����ݣ�����ǲ��ɵ����,��y��ߵ㣬ֱ�ӻ���
		// ���ݺ�������
			// ���������º�����ͬʱӦ�����㣬��ָ��ԭ�㣬���޷�����
		if (point->x == end_point.x && point->y == end_point.y) {
			count++;
			point = review(point, end_point);
			if (point->y < end_point.y) {
				auto old = *point;
				++old.y;
				*(++point) = old;
			}
			// cout << "**" << point->x << point->y <<  "**" << "\t";
		}

		else if (cant_go(point, horse_control_nodes, 9)) {
			point = review(point, end_point);
			if (point->y < end_point.y) {
				auto old = *point;
				++old.y;
				*(++point) = old;
			}
		}

		// ���õ㣬��Ϊԭ���ҵڶ�����������ĵ�������ѭ��
		if (point->x == 0 && point->y == 0 && (point + 1)->y - 1 == point->y)
			break;
	}
	cout << count << endl;
	return 0;
}
