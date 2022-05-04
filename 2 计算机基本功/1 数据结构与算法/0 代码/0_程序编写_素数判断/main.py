num = int(input())
is_prime_number = True
for i in range(2, num // 2 + 1):
    if num % i == 0:
        is_prime_number = False

if is_prime_number:
    print(1)
else:
    print(0)
