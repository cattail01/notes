"""
1.3.3 链表
对本书基础数据结构——链表的封装
"""

__all__ = ['LinkList']

class NumException(Exception):
    """数据不符合规范异常"""
    def __init__(self, *args: object) -> None:
        super().__init__(*args)
        self.err = args[0]
    def __str__(self) -> str:
        return self.err

class LinkListNode:
    """链表结点"""
    def __init__(self, data = None) -> None:
        self.data = data
        self.next:LinkListNode = None
        self.previous:LinkListNode = None

class LinkList:
    """双向链表"""
    def __init__(self) -> None:
        empty_head:LinkListNode = LinkListNode()
        self.head = empty_head
        self.tail = empty_head
        self.iterator_p = empty_head
    def size(self) -> int:
        count = 0
        for i in self:
            count += 1
        return count
    def push_pack(self, data) -> None:
        node = LinkListNode(data)
        node.previous = self.tail
        self.tail.next = node
        self.tail = self.tail.next
    def push_front(self, data) -> None:
        node = LinkListNode(data)
        node.previous = self.head
        node.next = self.head.next
        self.head.next = node
    def pop_back(self):
        node = self.tail
        self.tail = self.tail.previous
        self.tail.next = None
        node.previous = None
        return node.data
    def pop_front(self):
        node = self.head.next
        self.head.next = self.head.next.next
        self.head.next.previous = self.head
        node.previous, node.next = None, None
        return node.data
    def get_value(self, addr:int):
        if not (0 <= addr < self.size()):
            raise NumException("输入范围错误")
        result = self.head
        for i in range(addr + 1):
            result = result.next
        return result.data
    def insert(self, addr:int, data):
        if not (0 <= addr <= self.size()):
            raise NumException("输入范围错误")
        previous_node = self.head
        for i in range(addr):
            previous_node = previous_node.next
        node = LinkListNode(data)
        next_node = previous_node.next
        previous_node.next = node
        node.previous = previous_node
        node.next = next_node
        if next_node != None:
            next_node.previous = node
        else:
            self.tail = node
        return self
    def delete(self, addr:int):
        if not (0 <= addr < self.size()):
            raise NumException("输入范围错误")
        node = self.head
        for i in range(addr + 1):
            node = node.next
        previous_node = node.previous
        next_node = node.next
        previous_node.next = next_node
        if next_node != None:
            next_node.previous = previous_node
        else:
            self.tail = previous_node
        del node
        return self
    def copy(self):
        llst = LinkList()
        for i in self:
            llst.push_pack(i)
        return llst
    def for_each(self, begin:int = None, end:int = None, func = None, *args):
        if end == None:
            end = self.size() - 1
        if begin == None:
            begin = 0
        if (begin > end) or not (0 <= begin < self.size()) or not(0 <= end < self.size()):
            raise NumException("输入数值错误")
        begin_node = self.head
        end_node = self.head
        for i in range(begin + 1):
            begin_node = begin_node.next
        for i in range(end + 1):
            end_node = end_node.next
        while True:
            if begin_node == end_node:
                func(begin_node.data, *args)
                break
            if func != None:
                func(begin_node.data, *args)
            begin_node = begin_node.next
        return self
    def for_each_copy(self, begin:int = None, end:int = None, func = None, *args):
        llst = self.copy()
        llst.for_each(begin, end, func,  *args)
        return llst
    def __iter__(self):
        return self
    def __next__(self):
        if self.head == self.tail:
            raise StopIteration
        if self.iterator_p == self.tail:
            self.iterator_p = self.head		# 为了第二次迭代器的使用
            raise StopIteration
        self.iterator_p = self.iterator_p.next
        return self.iterator_p.data
    def __str__(self) -> str:
        result = "linklist("
        for i in self:
            result += (str(i) + " ")
        result += ")"
        return result

"""
测试代码
"""
if __name__ == "__main__":
    llst = LinkList()
    llst.push_pack(1)
    llst.push_pack(1)
    print(llst.size())
    print(llst.get_value(0))
    print(llst)
    llst.for_each(func=lambda a: print(a, end=" "))
    print(llst.for_each_copy(func=lambda a: print(a, end=" ")))
    print(llst.insert(2, "hello"))
    print(llst.insert(0, "hello"))
    print(llst.delete(llst.size() - 1))
    print(llst.delete(0))
