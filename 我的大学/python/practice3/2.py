import random

lis = [None] * 20
prime = [2, 3, 5, 7]
for i in range(20):
    lis[i] = random.randint(1000, 5001)

for i in range(20):
    flag = 0
    for j in prime:
        if lis[i] % j == 0:
            flag = 1
            break
    if flag == 0:
        print(lis[i])
