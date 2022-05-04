#pragma once
/**
* 俄罗斯方块基础方块元素的定义
**/

#include "base_func.hpp"

#define BLOCK_HEIGHT 4	// 单个方块的高度
#define BLOCK_WIDTH 4

// 定义方块类型代号
typedef enum BlockType {
	BT_S = 0,	// s block
	BT_Z,		// z block
	BT_J,		// j block
	BT_L,		// l block
	BT_I,		// i block
	BT_T,		// t block
	BT_O,		// o block
	BT_NUM			// 为类型总数
}BlockType;

// 定义方块状态（角度为逆时针方向旋转后的结果）
typedef enum BlockState {
	BS_0 = 0,
	BS_90,
	BS_180,
	BS_270,
	BS_NUM
}BlockState;

// 方块形状存储(unsigned short)
// 低四位表示第一行
static unsigned short g_block_list[BT_NUM][BS_NUM] = {
	{0x0630, 0x0132, 0x0630, 0x0132}, //S
	{0x0360, 0x0231, 0x0360, 0x0231}, //Z
	{0x0170, 0x0223, 0x0074, 0x0622}, //J
	{0x0470, 0x0322, 0x0071, 0x0226}, //L
	{0x00F0, 0x2222, 0x00F0, 0x2222}, //I
	{0x0270, 0x0232, 0x0072, 0x0262}, //T
	{0x0660, 0x0660, 0x0660, 0x0660}  //O
};

// 方块类的定义
class Block {
private:
	int x;	// 方块的水平位置（向右为正，左端为0）
	int y;	// 方块的垂直位置（向下为正，顶端为0）
	int bl_type;	// 方块种类
	int bl_state;	// 方块状态
public:
	// constracter and destructer
	Block(int ix = 0, int iy = 0):
		x(ix), y(iy),
		bl_type(base_func::get_rand_int(1, 100) % BT_NUM),
		bl_state(base_func::get_rand_int(1, 100) % BS_NUM)
	{}
	//int destroy() { delete this; }
	// copy controller(do without)
	// setter and getter
	void set_x(const int &x) { this->x = x; }
	const int& get_x() { return x; }
	void set_y(const int &y) { this->y = y; }
	const int& get_y() { return y; }
	// form getter (get an unsigned short data)
	unsigned short get_form_us();
	// move controller
	void move_left();
	void move_right();
	void move_down();
	void rotate();
};

// 获取图形
// 测试完毕
unsigned short Block::get_form_us() {
	return g_block_list[bl_type][bl_state];
}
// 左移
void Block::move_left() {
	x -= 1;
}
// 右移
void Block::move_right() {
	x += 1;
}
// 下移
void Block::move_down() {
	y += 1;
}
// 旋转
void Block::rotate() {
	bl_state = (bl_state + 1) % BS_NUM;
}
