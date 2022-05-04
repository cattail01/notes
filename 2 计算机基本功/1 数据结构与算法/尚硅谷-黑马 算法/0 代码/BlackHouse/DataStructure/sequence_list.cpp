// ���Ա�ʵ��
#include <memory>
#include <iostream>
#include <string>
// ����
#include "../../BasicComponent/test_controller.hpp"

// ʵ��
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
			cout << "��������ȷ" << endl;
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
			cout << "��ǰ���Ѿ�����" << endl;
			throw exception();
		}
		if (index < 0 || index > N) {
			cout << "����λ�ò�����" << endl;
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
			cout << "��������ȷ" << endl;
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


// ����
#if SEQUENCE_LIST_TEST
int main() {
	using namespace black_horse;
	// ���Խ���
	SequenceList<string> sl(10);
	// ��������
	sl.insert("Ҧ��");
	sl.insert("�Ʊ�");
	sl.insert("���");
	sl.insert("ղķ˹", 1);
	// ���Ի�ȡ
	cout << "���Ի�ȡ�ڶ���Ԫ�أ�" << sl.get(1) << endl;
	// ����ɾ��
	cout << "ɾ��������Ϊ��" << sl.remove(0) << "ɾ���ɹ�" << endl;
	// �������
	cout << "�������ǰ�ĳ��ȣ�" << sl.length() << endl;
	sl.clear();
	cout << "������ݺ��ĳ��ȣ�" << sl.length() << endl;
	return 0;
}

#endif
