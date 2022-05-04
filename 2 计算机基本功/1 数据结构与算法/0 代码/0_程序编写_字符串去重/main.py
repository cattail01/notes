string = input()
lst = []
for i in string:
    if i not in lst:
        lst.append(i)
result = "".join(lst)
print(result)
