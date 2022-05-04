#pragma once
#include <memory>
#include <vector>
namespace SGG {
	// ���ݽṹ��������й�������ѭ��������ʽ��
	// �����ṩpush_back��pop_front����
	// ��ʱ��д����������~
	template <typename T>
	class array_for_queue {
	public:
		using value_type = T;
		array_for_queue(int size = 10);
		~array_for_queue();
		int push_back(T data);
		T pop_front();
		bool is_full();
		bool is_empty();
		int real_size();
	private:
		std::shared_ptr<T[]> datas;
		int size;
		int rear, front;
	};

	// ���ݽṹ�����У�fifo��
	// ע�⣺������stl��std�����Ѿ����ڣ���һ������������
	template<class storage_structure>
	class queue {
	private:
		// storage structure���ݽṹ�����ṩpush_back��pop_front����
		storage_structure datas;
	public:
		using value_type = storage_structure::value_type;
		bool is_full();
		bool is_empty();
		int push(value_type data);
		value_type pop();
	protected:
	};
}// namespace SGG
