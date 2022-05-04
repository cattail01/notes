num = int(input())
dic = {}
for i in range(num):
    lst = list(input().split())
    dic[lst[0]] = lst[1]
result = dic.get(input())
if not result:
    print("not found")
else:
    print(result)