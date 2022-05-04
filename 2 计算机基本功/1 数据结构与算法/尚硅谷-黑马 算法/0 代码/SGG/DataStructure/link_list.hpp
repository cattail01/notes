#pragma once
// Á´±í
namespace  SGG
{
	// class ForwardLinkListNode
	template<class T>
	struct ForwardLinkListNode
	{
		using value_type = T;
		T data;
		ForwardLinkListNode<T>* next;
		ForwardLinkListNode() = default;
		ForwardLinkListNode(const T& data, ForwardLinkListNode<T>* next = NULL) : data(data), next(next) {}
	};
	// class ForwardLinkList
	template <class T>
	class ForwardLinkList
	{
	public:
		using value_type = T;
		// constructor
		ForwardLinkList();
		// destructor
		~ForwardLinkList();
		// clear
		void clear();
		// is empty
		bool is_empty();
		// add items
		void add(T data);
		// visit all
		void visit(void(*f)(T data));
		// length
		int length();
		// get item
		T get(int i);
		// insert by index
		void insert(T data, int index);
		// remove an item
		T remove(int index);
		// select item and return index
		int index_of(T data);
		// join two link list
		void join(ForwardLinkList& link_list);

	private:
		ForwardLinkListNode<T>* head, * tail;
	};
}
