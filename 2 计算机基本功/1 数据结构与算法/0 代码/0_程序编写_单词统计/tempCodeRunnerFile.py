import string

inp = input()
dic = dict()
for i in inp:
    if (i in string.punctuation) or (i.isspace()) or (i == "！") or (i.isdigit()):
        continue
    elif dic.get(i) == None:
        dic[i] = 0
    dic[i] += 1
lst = list(dict(sorted(dic.items(), key=lambda x: x[1], reverse=True)).keys())
max_value = dic[lst[0]]
max_lst = []
for i in lst:
    if dic[i] == max_value:
        max_lst.append(i)
count = 0
for i in sorted(max_lst):
    print(i + ":" + str(max_value), end=" ")
    count += 1
    if count % 5 == 0: print()
