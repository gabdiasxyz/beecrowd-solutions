n = int(input())

even = []
odd = []

for _ in range(n):
    num = int(input())
    if num%2 is 0:
        even.append(num)
    else:
        odd.append(num)

even.sort()
odd.sort(reverse=True)

sorted = even+odd

for number in sorted:
    print(number)