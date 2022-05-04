from cProfile import label


lst = list(input().split())
lst = sorted(lst)

for i in lst:
    print(i, end=" ")
print()