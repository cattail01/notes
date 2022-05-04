# coding=utf-8
import calendar
cal = calendar.Calendar()

inp_lst = list(map(int, input().split()))
year = inp_lst[0]
month = inp_lst[1]
day = inp_lst[2]
count = 0;
for mon in range(1, month):
	for i in cal.monthdayscalendar(year, mon):
		for j in i:
			if j > 0:
				count += 1
count += day
print(count)

#【问题描述】编写一个程序，用户输入日期，计算该日期是这一年的第几天。
#【输入形式】用户在第一行输入一个日期（年 月 日,中间以空格分割）
#【输出形式】程序在下一行输出一个整数
#【样例输入】2006 2 21
#【样例输出】52
#【样例说明】用户以年月日的格式输入，中间以空格分割，程序计算出该天是输入年份的第几天并输出该天数。另外还需要判断这一年是否为闰年。
#编程提示：闰年的判断方法，下面两个条件满足一个就是闰年