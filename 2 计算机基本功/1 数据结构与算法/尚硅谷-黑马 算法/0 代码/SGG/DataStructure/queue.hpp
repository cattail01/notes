#pragma once
#include <memory>
#include <vector>
namespace SGG {
	// 数据结构：数组队列供给器（循环供给方式）
	// 负责提供push_back和pop_front方法
	// 暂时不写拷贝控制啦~
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

	// 数据结构：队列（fifo）
	// 注意：队列在stl（std）中已经存在，是一种容器适配器
	template<class storage_structure>
	class queue {
	private:
		// storage structure数据结构必须提供push_back和pop_front方法
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
