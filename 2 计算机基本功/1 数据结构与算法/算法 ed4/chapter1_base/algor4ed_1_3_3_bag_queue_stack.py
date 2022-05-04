"""
1.3 背包，栈，队列
1.3.3 背包，栈，队列通过链表实现
"""
from algor4ed_1_3_3_base_linklist import LinkList

class Bag:
	"""背包"""
	def __init__(self) -> None:
		self.vessel = LinkList()
	def __iter__(self):
		return self.vessel
	def add(self, item) -> None:
		pass
	def is_empty(self) -> bool:
		pass
	def size(self) -> int:
		pass

class Queue:
	"""队列"""
	def __init__(self) -> None:
		pass
	def __iter__(self):
		pass
	def enqueue(self, item) -> None:
		pass
	def dequeue(self):
		pass
	def is_empty(self) -> bool:
		pass
	def size(self) -> int:
		pass

class Stack:
	"""栈"""
	def __init__(self) -> None:
		self.vessel = LinkList()
	def __iter__():
		pass
	def push(self) -> None:
		pass
	def pop(self):
		pass
	def is_empty(self) -> bool:
		pass
	def size(self):
		pass
