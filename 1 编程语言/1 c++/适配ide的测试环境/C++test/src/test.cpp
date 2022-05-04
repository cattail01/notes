// 马拦过河卒
// 原理：二叉树的遍历
#include <iostream>
using namespace std;

typedef struct {
	int x, y;
}node;

// 回溯
node* review(node* point, const node& end_point) {
	while (true) {
		if (point->x == 0 && point->y == 0) {
			return point;
		}
		node old = *point;
		--point;
		// cout << "*" << point->x << point->y << "*" << "\t";
		if (old.y - point->y == 0 && (point->y != end_point.y))   // 若是平移且可以下移
		{

			return point;
		}
		else    continue;
	}
	return point;
}
// 检查是否为不可到达点
bool cant_go(node* point, node* nodes, const int& length) {
	for (int i = 0; i < length; i++) {
		if (point->x == nodes[i].x && point->y == nodes[i].y)  return true;
	}
	return false;
}

int main() {
	node end_point, horse_control_nodes[9];
	// 接受输入
	cin >> end_point.x >> end_point.y >> horse_control_nodes[0].x >> horse_control_nodes[0].y;
	// 计算马的控制点(从左上的点为1，逆时针开始)
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

	// 检查：原点或终点是否在马控制点上（即为不可实现的目标）

	// 生成记录卒子移动的栈、记录成功的次数
	node stack[end_point.x + end_point.y + 2 + 1], * point = &stack[0];
	for (auto& i : stack) {
		i.x = i.y = 0;
	}
	point->y = point->x = 0;    (point + 1)->y = 0;
	int count = 0;
	// 卒子开始移动
	while (true) {
		// 设置跳出条件：当终点等于原点 或 卒子在原点且下一个点是（0，1）
		if ((end_point.x == 0 && end_point.y == 0) || (point->x == 0 && point->y == 0 && (point + 1)->y == 1))
			break;
		// 如果能右移(不到边界且下一个点不是栈内上一个点)则右移；如果不能，则检查是否能下移；移动后将新点压入栈内；
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
		// 之后检查该点性质：如果是endpoint，则统计 + 1并回溯；如果是不可到达点,或y最高点，直接回溯
		// 回溯后尝试下移
			// 回溯生成新函数，同时应当检查点，若指向原点，则无法回溯
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

		// 检查该点，若为原点且第二个点是下面的点则跳出循环
		if (point->x == 0 && point->y == 0 && (point + 1)->y - 1 == point->y)
			break;
	}
	cout << count << endl;
	return 0;
}
