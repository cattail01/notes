"""
1.3.2 定容栈
"""
class FixedCapacityStackOfStrings:
	"""
	关于string的定容栈
	只能处理string
	不支持迭代
	"""
	def __init__(self) -> None:
		self.a = [str]
	def push(self, item:str) -> None:
		self.a.append(item)
	def pop(self) -> str:
		return self.a.pop()
	def is_empty(self) -> bool:
		return len(self.a) == 0
	def size(self) -> int:
		return len(self.a)

class FixedCapacityStack:
	"""
	泛型定容栈定容栈
	不支持迭代
	"""
	def __init__(self) -> None:
		self.a = []
	def push(self, item) -> None:
		self.a.append(item)
	def pop(self):
		return self.a.pop()
	def is_empty(self) -> bool:
		return len(self.a) == 0
	def size(self) -> int:
		return len(self.a)

if __name__ == "__main__":
    pass
