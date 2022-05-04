# coding = utf-8

figurs_number = int(input())
figurs = list(map(int, input().split()))
max_num = min_num = figurs[0]
for i in range(figurs_number):
    if figurs[i] > max_num:
        max_num = figurs[i]
    elif figurs[i] < min_num:
        min_num = figurs[i]
print(max_num, min_num)

# 【问题描述】编写一个程序，用户输入若干整数，试找出其中的最大数和最小数。
# 【输入形式】用户在第一行待输入数据个数，在第二行输入数据。
# 【输出形式】程序在下一行输出数据的最大值和最小值
# 【样例输入】
# 5
# 89 62 96 74 52    
# 【样例输出】96 52
# 【样例说明】用户第一次输入的为数据个数，在下一行依次输入数据。输出为5个数中的最大值和最小值，输出时候两个数之间用空格分隔。

