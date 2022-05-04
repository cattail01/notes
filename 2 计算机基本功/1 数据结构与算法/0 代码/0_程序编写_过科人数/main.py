
import copy
lst = list(map(int, input().split()))
num = copy.copy(lst[0])
del lst[0]
del lst[num:]
print(lst)
lst.reverse()
for i in lst:
    print(i, end=" ")
print()