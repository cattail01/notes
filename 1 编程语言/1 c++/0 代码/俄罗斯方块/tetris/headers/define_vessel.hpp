#pragma once
/**
* ����˹���������Ķ���
*/

#include "define_blocks.hpp"
#include "define_blocks.hpp"

#define VESSEL_WIDTH	(10 + 1 + 1)
#define VESSEL_HEIGHT	(20 + BLOCK_HEIGHT + 1)
#define EMPTY_LINE		0x0801	// ������ֵ
#define END_LINE		0XFFFF

class Vessel {
public:
	Vessel();
	unsigned long* get_form_pul() { return vessel_form_ul; }
	void set_line_form(int y, unsigned long line_form) { vessel_form_ul[y] = line_form; };
	// ��ײ����
	bool hit_test(Block&);
private:
	// �洢������״
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
		// ��ȡblock��vessel�ĵ��У��Ե��н��в���
		unsigned short block_line_bits = ((block_form >> (i * BLOCK_WIDTH)) & 0x000F);
		unsigned long vessel_line_bits = vessel_form_ul[block_y - 1 + i];
		// �γ�block�������е�ͶӰ	
		// ע�⣺��λ�����󣬾���ļ�����ڲ���ʾ����ϰ��д������
		unsigned long block_line_shadow = (block_x < 0 ?		// ����x��ֵ�ƶ�block��ʹ�������������е�ͶӰ
			(block_line_bits >> (-block_x)) :	// ���ƣ�λ��ͣ�ʵ�ʶ�Ӧblock����
			(block_line_bits << block_x));	// ͬ��ʵ�ʶ�Ӧblock����
		if (block_line_shadow & vessel_line_bits)	// ������غϵĲ���
			return true;	// �ж���Ч
	}
	return false;
}