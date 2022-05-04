# coding=utf-8

string = input()
alpha_count = 0
digit_count = 0

for i in string:
    if i.isalpha():
        alpha_count += 1
    elif i.isdigit():
        digit_count += 1
print(alpha_count, digit_count)


# 【问题描述】分别统计标准输入中字母、数字字符个数。
# 【输入形式】从标准输入中读取一个字符串，可以包含任意字符。
# 【输出形式】分别输出字符串中字母(大小写字母都要进行统计)、数字个数，相邻数字之间用一个空格区分，输出末尾没有空格。
# 【样例输入】C Java -and- C++ are 3 lanuages. 2006-8-24 16:34
# 【样例输出】20 12
# 【样例说明】字符串中共有20个字母，12个数字，所以输出20 12