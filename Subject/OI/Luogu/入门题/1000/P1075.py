import math
n = int(input())
if n == 2:
  print(2)
  exit(0)
i = 2
while i <= math.sqrt(n):
  if n % i == 0:
    break
  i += 1
print(int(n/i))
