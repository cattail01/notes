# coding=utf-8

inp = input()
is_palindrome = True	
for i in range(len(inp) // 2):
	if inp[i] != inp[len(inp) - 1 - i]:
		is_palindrome = False
		break

if is_palindrome:
	print("Yes")
else:
	print("No")



