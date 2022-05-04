// link list / forward link list	链表及其增删改查的实现
#include <iostream>	// for io
#include <string>	// for string
#include <stack>
#include <forward_list>
// test controller
#include "../../BasicComponent/test_controller.hpp"
// header
#include "link_list.hpp"

using namespace std;

namespace SGG {
	// class ForwardLinkList realize

	// constructor
	template <class T>
	ForwardLinkList<T>::ForwardLinkList()
	{
		head = new ForwardLinkListNode<T>;
		head->next = NULL;
		tail = head;
	}
	// destructor
	template <class T>
	ForwardLinkList<T>::~ForwardLinkList()
	{
		auto end = tail->next;
		for (ForwardLinkListNode<T>* i = head; i != end;)
		{
			auto del = i;
			i = i->next;
			delete del;
		}
	}
	// add
	template <class T>
	void ForwardLinkList<T>::add(T data)
	{
		tail->next = new ForwardLinkListNode<T>(data);
		tail = tail->next;
		tail->next = NULL;
	}
	// visit
	template <class T>
	void ForwardLinkList<T>::visit(void(*f)(T data))
	{
		for (ForwardLinkListNode<T>* i = head->next; i != tail->next; i = i->next)
			f(i->data);
	}
	// is empty
	template <class T>
	bool ForwardLinkList<T>::is_empty()
	{
		return head == tail;
	}
	// clear
	template <class T>
	void ForwardLinkList<T>::clear()
	{
		for (ForwardLinkListNode<T>* i = head->next; i != NULL;)
		{
			auto del = i;
			i = i->next;
			delete del;
		}
		tail = head;
	}
	// length
	template <class T>
	int ForwardLinkList<T>::length()
	{
		int count = 0;
		for (ForwardLinkListNode<T>* i = head->next; i != tail->next; i = i->next)
		{
			count++;
		}
		return count;
	}
	// get
	template <class T>
	T ForwardLinkList<T>::get(int index)
	{
		if (index > length() - 1)
		{
			cout << "参数过大" << endl;
			throw  exception();
		}
		ForwardLinkListNode<T>* temp = head->next;
		for (int i = 0; i < index; i++)
		{
			temp = temp->next;
		}
		return temp->data;
	}
	// insert
	template <class T>
	void ForwardLinkList<T>::insert(T data, int index)
	{
		if (index > length() - 1)
		{
			cout << "参数过大" << endl;
			throw  exception();
		}
		ForwardLinkListNode<T>* temp = head;
		for (int i = 0; i < index; i++)
		{
			temp = temp->next;
		}
		auto next = temp->next;
		temp->next = new ForwardLinkListNode<T>(data, next);
	}
	// remove
	template <class T>
	T ForwardLinkList<T>::remove(int index)
	{
		if (index > length() - 1)
		{
			cout << "参数过大" << endl;
			throw  exception();
		}
		ForwardLinkListNode<T>* temp = head;
		for (int i = 0; i < index; i++)
		{
			temp = temp->next;
		}
		ForwardLinkListNode<T>* next = temp->next->next;
		ForwardLinkListNode<T>* item = temp->next;
		T data = temp->next->data;
		temp->next = next;
		delete item;
		return data;
	}
	// index of
	template <class T>
	int ForwardLinkList<T>::index_of(T data)
	{
		int index = -1;
		ForwardLinkListNode<T>* point = head->next;
		for (int i = 0; i < length(); i++, point = point->next)
		{
			if (point->data == data)
			{
				index = i;
				break;
			}
		}
		return index;
	}
	// join
	template <class T>
	void ForwardLinkList<T>::join(ForwardLinkList& link_list)
	{
		this->tail->next = (link_list.head->next);
		this->tail = link_list.tail;
		link_list.tail = link_list.head;
	}

	// struct LinkListNode
	template<class T>
	struct LinkListNode
	{
		using value_type = T;
		T item;
		LinkListNode* pre, * next;
		LinkListNode(T item = NULL, LinkListNode* pre = nullptr, LinkListNode* next = nullptr) : item(item), pre(pre), next(next) {}
	};

	// class LinkList
	template<class T>
	class LinkList
	{
	public:
		// constructor
		LinkList();
		// destructor
		~LinkList();
		// clear link list
		void clear();
		// is empty?
		bool is_empty();
		// length of link list
		int length();
		// get the index item's reference of the link list
		T& get(const int& index);
		// insert an item
		void insert(T item);
		// insert an item by address
		void insert(T item, int index);
		// remove an item and return it
		T remove(int index);
		// found item and return index; if not, return -1;
		int index_of();

	private:
		LinkListNode<T>* head, * tail;
	};

	// class LinkList realize

	// constructor
	template <class T>
	LinkList<T>::LinkList()
	{
		head = new LinkListNode<T>();
		tail = head;
	}

	// destructor
	template <class T>
	LinkList<T>::~LinkList()
	{
		clear();
		delete head;
	}

	// clear
	template <class T>
	void LinkList<T>::clear()
	{
		while (tail != head)
		{
			LinkListNode<T>* old = tail;
			tail = tail->pre;
			delete old;
		}
	}

	// is empty
	template <class T>
	bool LinkList<T>::is_empty()
	{
		return tail == head;
	}

	// length
	template <class T>
	int LinkList<T>::length()
	{
		int length = 0;
		for (LinkListNode<T>* point = head; point != tail; point = point->next)
		{
			++length;
		}
		return length;
	}

	// get
	template <class T>
	T& LinkList<T>::get(const int& index)
	{
		// 验证index不超出范围
		if (index < 0 || index > length() - 1)
		{
			cout << "检查位置不合法！" << endl;
			throw new exception();
		}
		LinkListNode<T>* point = head->next;
		for (int i = 0; i < index; i++);
		return (point->item);
	}

	// insert 
	template <class T>
	void LinkList<T>::insert(T item)
	{
		tail->next = new LinkListNode<T>(item, tail);
		tail = tail->next;
	}

	// insert 2
	template <class T>
	void LinkList<T>::insert(T item, int index)
	{
		// 检查输入范围是否合法
		if (index < 0 || index > length())
		{
			cout << "检查位置不合法！" << endl;
			throw new exception();
		}
		// 如果在最后插入
		if (index == length())
		{
			insert(item);
			return;
		}
		// 其他位置插入
		LinkListNode<T>* point = head;
		for (int i = 0; i < index; ++i)
		{
			point = point->next;
		}
		LinkListNode<T>* next = point->next;
		point->next = new LinkListNode<T>(item, point, next);
		next->pre = point->next;
	}
	// remove
	template <class T>
	T LinkList<T>::remove(int index)
	{
		// 检查输入位置
		if (index < 0 || index > length() - 1)
		{
			cout << "检查位置不合法！" << endl;
			throw new exception();
		}
		// 定位
		LinkListNode<T>* point = head->next;
		for (int i = 0; i < index; ++i)
		{
			point = point->next;
		}
		// 删除
		T result = point->item;
		// 如果删除最后一个元素，则将尾巴前移一位
		if (index == length() - 1)
		{
			tail = tail->pre;
		}
		// 否则：将point下一个的前指针pre域指向point的上一个
		else
		{
			point->next->pre = point->pre;

		}
		// 再将前一个的下指针域指向后一个
		point->pre->next = point->next;
		delete point;
		return result;
	}
	// index of
	template <class T>
	int LinkList<T>::index_of()
	{

		return -1;
	}


}

#if LINKLIST_TEST

int main()
{
	// 单向链表测试
	/*
	SGG::ForwardLinkList<int> link_list;
	for (int i = 0; i < 10; i++)
		link_list.add(i);
	cout << link_list.length() << endl;
	link_list.visit([](int a) { cout << a << "\t"; });
	cout << endl;
	cout << link_list.get(1) << endl;
	link_list.insert(50, 0);
	link_list.visit([](int a) { cout << a << "\t"; });
	cout << endl;

	cout << link_list.index_of(2) << endl;

	// 一些面试真题

	// 求单链表中有效节点个数
	cout << link_list.length() << endl;
	// 查找单链表中倒数第k个节点
	int k = -1;
	cout << link_list.get(link_list.length() + k);
	cout << endl;
	// 单链表反转（尝试使用栈来解决）
	stack<int> stack_int;
	for (int i = 0; i < link_list.length(); i++)
	{
		stack_int.push(link_list.get(i));
	}
	SGG::ForwardLinkList<int> upside_down_link_list;
	for (int i = 0; i < link_list.length(); i++)
	{
		upside_down_link_list.add(stack_int.top());
		stack_int.pop();
	}
	upside_down_link_list.visit([](int data) {cout << data << "\t"; });	cout << endl;
	// 合并测试
	link_list.join(upside_down_link_list);

	link_list.visit([](int data) {cout << data << " "; });		cout << endl;
	*/

	// 双向链表测试

	SGG::LinkList<int> link_list;
	link_list.insert(0);
	cout << link_list.length() << endl;
	cout << link_list.get(0) << endl;
	link_list.insert(1, 0);
	cout << link_list.length() << endl;
	cout << link_list.remove(1) << endl;
	cout << link_list.length() << endl;

	return 0;
}
#endif
