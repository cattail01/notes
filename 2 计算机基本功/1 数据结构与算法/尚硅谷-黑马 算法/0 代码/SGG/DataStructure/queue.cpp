// 队列的实现

#include <iostream>	// for io
#include <memory>

#include "../../BasicComponent/test_controller.hpp"	// for test

// 实现
#include "queue.hpp"

using namespace std;

namespace SGG {
	// class queue
	template<class storage_structure>
	int queue<storage_structure>::push(value_type data) {
		return datas.push_back(data);
	}

	template <class storage_structure>
	queue<storage_structure>::value_type queue<storage_structure>::pop() {
		return datas.pop_front();
	}

	template <class storage_structure>
	bool queue<storage_structure>::is_full() {
		return datas.is_full();
	}

	template <class storage_structure>
	bool queue<storage_structure>::is_empty() {
		return datas.is_empty();
	}

	// class array_for_queue
	template<typename T>
	array_for_queue<T>::array_for_queue(int size) :
		size(size + 1), rear(0), front(0) {
		datas = make_shared<T[]>(this->size);
	}

	template<typename T>
	array_for_queue<T>::~array_for_queue() {
	}

	template<typename T>
	int array_for_queue<T>::push_back(T data) {
		if (is_full())	return 0;
		datas[rear] = data;
		rear = (rear + 1) % size;
		return 1;
	}

	template<typename T>
	T array_for_queue<T>::pop_front() {
		if (is_empty()) return NULL;
		int result = front;
		front = (front + 1) % size;
		return datas[result];
	}

	template<typename T>
	bool array_for_queue<T>::is_full() {
		return (rear + 1) % size == front;
	}

	template<typename T>
	bool array_for_queue<T>::is_empty() {
		return rear == front;
	}

	template<typename T>
	int array_for_queue<T>::real_size() {
		return this->size - 1;
	}
}

// 测试
#if QUEUE_TEST
int main() {
	SGG::queue<SGG::array_for_queue<int>> afq;
	if (!afq.push(0))	cout << "error" << endl;
	else cout << afq.pop() << endl;
	for (int i = 0; i < 10; i++) {
		afq.push(i);
	}
	for (int i = 0; i < 10; i++) {
		cout << afq.pop() << endl;
	}
}
#endif	// QUEUE
