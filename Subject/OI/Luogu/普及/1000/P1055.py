ISBN = input()
strNum = ISBN[:12]
Sum = 0
j = 1

for i in strNum:
  if i != '-':
    Sum = Sum + int(i) * j
    j += 1
  else:
    continue

if Sum % 11 == 10:
  CHECK_CODE = 'X'
else:
  CHECK_CODE = str(Sum % 11)

if CHECK_CODE == ISBN[12]:
  print("Right")
else:
  strNum = strNum + CHECK_CODE
  print(strNum)
