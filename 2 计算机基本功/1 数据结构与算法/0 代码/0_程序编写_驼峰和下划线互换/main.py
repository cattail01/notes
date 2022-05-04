lst = list(input().split())
for i in range(1, len(lst) - 1):
    alpha = lst [i][0]
    alpha = alpha.upper()
    lst[i] = alpha + "."
lst[0] = lst[0].capitalize()
lst[-1] = lst[-1].capitalize()
print(" ".join(lst))
