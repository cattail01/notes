#pragma once
/**
* ����Ϸ�ڲ����Ԫ�ع�����Ϸ�����㷨ʵ��
**/

#include "base_func.hpp"
#include "define_blocks.hpp"
#include "define_vessel.hpp"

#include <list>
#include <algorithm>
#include <iostream>
#include <memory>

#define FORCEST_BLOCKS_NUM 4
const int BLOCK_INIT_POSTX = ((VESSEL_WIDTH - BLOCK_WIDTH) / 2);
const int BLOCK_INIT_POSTY = 2;

class Basic_element_controller {
public:
	// ��ʼ��
	Basic_element_controller();
	// ��ʾ������Ҫ���µ�block
	//void show_procest_blocks();
	// �ϲ�����
	void merge();
	// ����block
	int move_left_block();
	// ����block
	int move_right_block();
	// ����block
	int move_down_block();
	// ��תblock
	int rotate_block();
	// ����
	int erase_line();

private:
	Vessel vessel;
	std::list<std::shared_ptr<Block>> lst_blocks;	// list������ʹ��	// ʹ������ָ��
	int block_index;
	std::shared_ptr<Block> exchange_block;
};

Basic_element_controller::Basic_element_controller() :
	vessel(), block_index(0), exchange_block(), lst_blocks() {
	for (auto i = 0; i != FORCEST_BLOCKS_NUM; i++) {
		lst_blocks.push_back(std::make_shared<Block>(BLOCK_INIT_POSTX, BLOCK_INIT_POSTY));
		base_func::sleep(10);
	}
}

//void Basic_element_controller::show_procest_blocks() {
//	auto i = lst_blocks.begin();
//	for (++i; i != lst_blocks.end(); ++i) {
//		std::cout << i->get()->get_form_us() << "\t";
//	}
//}

void Basic_element_controller::merge() {
	Block block = *(lst_blocks.front().get());
	unsigned short block_form = block.get_form_us();
	int block_x = block.get_x();
	int block_y = block.get_y();
	for (int i = 0; i < BLOCK_HEIGHT; i++) {
		unsigned short block_line_bits = ((block_form >> (i * BLOCK_WIDTH)) & 0x000F);
		unsigned long vessel_line_bits = vessel.get_form_pul()[block_y - 1 + i];
		unsigned long block_line_shadow = block_x < 0 ?
			(block_line_bits >> (-block_x)) :
			(block_line_bits << block_x);
		vessel.set_line_form(block_y - 1 + i, block_line_shadow | vessel_line_bits);
	}
	// �ɵ�ȥ���µ���
	lst_blocks.pop_front();
	lst_blocks.push_back(std::make_shared<Block>(BLOCK_INIT_POSTX, BLOCK_INIT_POSTY));
}

int Basic_element_controller::move_left_block() {
	Block &now = *(lst_blocks.front().get());
	Block next = now;
	next.move_left();
	if(vessel.hit_test(next))
		return 0;
	now.move_left();
	return 0;
}

int Basic_element_controller::move_right_block() {
	Block& now = *(lst_blocks.front().get());
	Block next = now;
	next.move_right();
	if (vessel.hit_test(next))
		return 0;
	now.move_right();
	return 0;
}

int Basic_element_controller::move_down_block() {
	Block& now = *(lst_blocks.front().get());
	Block next = now;
	next.move_down();
	if (vessel.hit_test(next)) {
		merge();
		erase_line();
		return 0;
	}
	now.move_down();
	return 0;
}

int Basic_element_controller::rotate_block() {
	Block& now = *(lst_blocks.front().get());
	Block next = now;
	next.rotate();
	if (vessel.hit_test(next))
		return 0;
	now.rotate();
	return 0;
}

int Basic_element_controller::erase_line() {
	// ������Ⱦ��
	int line = VESSEL_HEIGHT - 2;
	int after_line = line;
	unsigned long* arr = vessel.get_form_pul();
	for (; line >= BLOCK_HEIGHT;) {
		if (arr[after_line] != 0x0fff)
			--after_line;
		--line;
		if (after_line != line) {
			arr[after_line] = arr[line];
			arr[line] = 0x0fff;
		}
	}
	for (--after_line; after_line >= 0; --after_line) {
		arr[after_line] = EMPTY_LINE;
	}
}
