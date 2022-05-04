# coding=utf-8

lst = list(map(eval, input().split()))
lst = sorted(lst)
for i in lst:
	print(i, end=" ")

