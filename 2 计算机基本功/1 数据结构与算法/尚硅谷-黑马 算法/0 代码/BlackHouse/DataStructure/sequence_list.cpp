// 线性表实现
#include <memory>
#include <iostream>
#include <string>
// 测试
#include "../../BasicComponent/test_controller.hpp"

// 实现
#include "sequence_list.hpp"

using namespace std;

namespace black_horse {


	// class SequenceList
	template <class T>
	SequenceList<T>::SequenceList(int size) :
		N(0), size(size) {
		eles = new T[size];
	}

	template <class T>
	SequenceList<T> ::~SequenceList() {
		delete[] eles;
	}

	template <class T>
	void SequenceList<T>::clear() {
		N = 0;
	}

	template <class T>
	bool SequenceList<T>::is_empty() {
		return N;
	}

	template <class T>
	T SequenceList<T>::get(int i) {
		if (i < 0 || i >= N) {
			cout << "索引不正确" << endl;
			throw exception();
		}
		return eles[i];
	}

	template <class T>
	void SequenceList<T>::insert(T t) {
		insert(t, N);
	}

	template <class T>
	void SequenceList<T>::insert(T t, int index) {
		if (index >= size) {
			cout << "当前表已经满了" << endl;
			throw exception();
		}
		if (index < 0 || index > N) {
			cout << "插入位置不合适" << endl;
			throw exception();
		}
		for (int i = N; i > index; i--) {
			eles[i] = eles[i - 1];
		}
		eles[index] = t;
		N++;
	}

	template <class T>
	T SequenceList<T>::remove(int index) {
		if (index < 0 || index >= N) {
			cout << "索引不正确" << endl;
			throw exception();
		}
		T result = eles[index];
		for (int i = index; i < N - 1; i++) {
			eles[i] = eles[i + 1];
		}
		N--;
		return result;
	}

	template <class T>
	int SequenceList<T>::index_of(const T& t) {
		for (int i = 0; i < N; i++) {
			if (eles[i] == t)	return i;
		}
		return -1;
	}

	template <class T>
	SequenceListIterator<SequenceList<T>> SequenceList<T>::begin() {
		SequenceListIterator<SequenceList<T>> result(eles);
		return result;
	}

	template <class T>
	SequenceListIterator<SequenceList<T>> SequenceList<T>::end() {
		SequenceListIterator<SequenceList<T>> result(eles + N);
		return result;
	}

	// class SequenceListIterator
	template <class T>
	SequenceListIterator<T>::SequenceListIterator(value_type* t) :
		data(t) {}

	template<class T>
	SequenceListIterator<T>::value_type& SequenceListIterator<T>::operator *() {
		return *data;
	}

	template<class T>
	SequenceListIterator <T>& SequenceListIterator<T>::operator++() {
		data++;
		return *this;
	}

	template<class T>
	bool SequenceListIterator<T>::operator!=(SequenceListIterator<T> iter) {
		return iter.data != this->data;
	}
}


// 测试
#if SEQUENCE_LIST_TEST
int main() {
	using namespace black_horse;
	// 测试建立
	SequenceList<string> sl(10);
	// 测试输入
	sl.insert("姚明");
	sl.insert("科比");
	sl.insert("麦迪");
	sl.insert("詹姆斯", 1);
	// 测试获取
	cout << "测试获取第二个元素：" << sl.get(1) << endl;
	// 测试删除
	cout << "删除的内容为：" << sl.remove(0) << "删除成功" << endl;
	// 测试清空
	cout << "清除内容前的长度：" << sl.length() << endl;
	sl.clear();
	cout << "清除内容后表的长度：" << sl.length() << endl;
	return 0;
}

#endif
