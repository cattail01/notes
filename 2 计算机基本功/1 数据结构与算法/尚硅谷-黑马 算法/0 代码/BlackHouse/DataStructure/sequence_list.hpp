#pragma once
// ���Ա�

namespace black_horse {
	template <class T>
	class SequenceListIterator;

	template <class T>
	class SequenceList {
	public:
		using value_type = T;			// Ԫ������
		SequenceList(int size);			// ����
		~SequenceList();				// ����
		void clear();					// ���Ա��ÿ�
		bool is_empty();				// �п�
		int length() { return N; }		// ��������
		T get(int i);					// ��ȡָ��Ԫ��
		void insert(T t);				// �ں������Ԫ��
		void insert(T t, int i);		// ��λ�ò���Ԫ��
		T remove(int i = N - 1);		// ɾ��Ԫ�أ�������ɾ����ֵ
		int index_of(const T& value);	// ����Ԫ�أ����ص�һ�γ��ֵ�λ�ã�ʧ�ܷ��� -1
		// ��ʼ������
		SequenceListIterator<SequenceList<T>> begin();
		// β�������
		SequenceListIterator<SequenceList<T>> end();
	private:
		T* eles;						// �洢���ݵ�����
		int N;							// ���鳤��
		int size;						// �����С
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
		value_type* data;	// ����point�����ʣ�	// ������������ָ������T�У�����/������λ��
	};
	// �ܽ᣺��iterator����Ʒǳ����䣬ֵ��ѧϰ

}
