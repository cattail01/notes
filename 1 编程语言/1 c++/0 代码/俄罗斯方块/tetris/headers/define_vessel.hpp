#pragma once
/**
* 俄罗斯方块容器的定义
*/

#include "define_blocks.hpp"
#include "define_blocks.hpp"

#define VESSEL_WIDTH	(10 + 1 + 1)
#define VESSEL_HEIGHT	(20 + BLOCK_HEIGHT + 1)
#define EMPTY_LINE		0x0801	// 空行数值
#define END_LINE		0XFFFF

class Vessel {
public:
	Vessel();
	unsigned long* get_form_pul() { return vessel_form_ul; }
	void set_line_form(int y, unsigned long line_form) { vessel_form_ul[y] = line_form; };
	// 碰撞测试
	bool hit_test(Block&);
private:
	// 存储容器形状
	unsigned long vessel_form_ul[VESSEL_HEIGHT];
};

Vessel::Vessel() {
	for (int i = 0; i < VESSEL_HEIGHT - 1; i++) {
		vessel_form_ul[i] = EMPTY_LINE;
	}
	vessel_form_ul[VESSEL_HEIGHT - 1] = END_LINE;
}

bool Vessel::hit_test(Block& test_block) {
	Block block = test_block;
	unsigned short block_form = block.get_form_us();
	int block_x = block.get_x();
	int block_y = block.get_y();
	for (int i = 0; i < BLOCK_HEIGHT; i++) {
		// 提取block和vessel的单行，对单行进行操作
		unsigned short block_line_bits = ((block_form >> (i * BLOCK_WIDTH)) & 0x000F);
		unsigned long vessel_line_bits = vessel_form_ul[block_y - 1 + i];
		// 形成block在容器中的投影	
		// 注意：低位代表左，经典的计算机内部表示法和习惯写法差异
		unsigned long block_line_shadow = (block_x < 0 ?		// 根据x的值移动block，使其生成在容器中的投影
			(block_line_bits >> (-block_x)) :	// 右移，位变低，实际对应block左移
			(block_line_bits << block_x));	// 同理，实际对应block右移
		if (block_line_shadow & vessel_line_bits)	// 如果有重合的部分
			return true;	// 判定生效
	}
	return false;
}