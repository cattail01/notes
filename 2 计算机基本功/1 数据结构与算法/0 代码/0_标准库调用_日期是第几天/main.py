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

#��������������дһ�������û��������ڣ��������������һ��ĵڼ��졣
#��������ʽ���û��ڵ�һ������һ�����ڣ��� �� ��,�м��Կո�ָ
#�������ʽ����������һ�����һ������
#���������롿2006 2 21
#�����������52
#������˵�����û��������յĸ�ʽ���룬�м��Կո�ָ��������������������ݵĵڼ��첢��������������⻹��Ҫ�ж���һ���Ƿ�Ϊ���ꡣ
#�����ʾ��������жϷ���������������������һ����������