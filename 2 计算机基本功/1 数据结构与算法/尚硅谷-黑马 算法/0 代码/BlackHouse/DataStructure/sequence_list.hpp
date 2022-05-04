#pragma once
// 线性表

namespace black_horse {
	template <class T>
	class SequenceListIterator;

	template <class T>
	class SequenceList {
	public:
		using value_type = T;			// 元素类型
		SequenceList(int size);			// 构造
		~SequenceList();				// 析构
		void clear();					// 线性表置空
		bool is_empty();				// 判空
		int length() { return N; }		// 测量长度
		T get(int i);					// 获取指定元素
		void insert(T t);				// 在后面插入元素
		void insert(T t, int i);		// 按位置插入元素
		T remove(int i = N - 1);		// 删除元素，并返回删除的值
		int index_of(const T& value);	// 查找元素，返回第一次出现的位置，失败返回 -1
		// 开始迭代器
		SequenceListIterator<SequenceList<T>> begin();
		// 尾后迭代器
		SequenceListIterator<SequenceList<T>> end();
	private:
		T* eles;						// 存储数据的数组
		int N;							// 数组长度
		int size;						// 数组大小
		//SequenceListIterator<SequenceList<T>> _begin;
		//SequenceListIterator<SequenceList<T>> _end;
		//friend class SequenceListIterator<SequenceList<T>>;
	};

	template <class T>
	class SequenceListIterator {
	public:
		using value_type = T::value_type;
		SequenceListIterator(value_type* t);
		//T& operator =(T* t);
		bool operator !=(SequenceListIterator<T> iter);
		SequenceListIterator <T>& operator ++();
		//SequenceListIterator <T>& operator ++(int i);
		value_type& operator *();
	private:
		value_type* data;	// 或者point更合适？	// 负责管理迭代器指向容器T中（数组/链表）的位置
	};
	// 总结：该iterator的设计非常经典，值得学习

}
