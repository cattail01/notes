# 给出一段不规范的英文，只包含字母、空格“ ”、逗号“,”、句号“.”，每个句子以句号“.”结尾。
# 要求调整所有英文字母的大小写，使其满足规范：每个句子首字母大写，字母I单独写出时（两侧均为空格或标点）大写，其余字母全部小写。

# 全部转化为小写

def scan_i(string :str):
    if(string[0] != "i"):
        return False
    scan = list(string[1:])
    for i in scan:
        if i.isalpha():
            return False
    return True

def touper_i(string :str):
    lst = list(string)
    lst[0] = "I"
    return "".join(lst)



inp_formal = input().casefold()
# 分解为句子
sentences = list(inp_formal.split(". "))

# 句子首字母大写
capitalize_sentence = []
for i in sentences:
    capitalize_sentence.append(i.capitalize())
# print(capitalize_sentence)

# 查找单独的i，并大写
result = []
for i in capitalize_sentence:
    sentence = []
    for j in i.split():
        if scan_i(j):
            j = touper_i(j)
        if j == ".":
            continue
        sentence.append(j)
    
    sentence = " ".join(sentence)
    # sentence += "."
    result.append(sentence)
output = ". ".join(result)
print(output)