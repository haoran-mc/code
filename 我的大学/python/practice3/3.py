lis = [["Wangping", "male", 1, 1, 0, 0],
       ["Lili", "female", 0, 1, 0, 1],
       ["Chenxiaomei", "female", 0, 0, 1, 0],
       ["Sunhongliang", "male", 0, 1, 1, 1],
       ["Fangliang", "male", 1, 0, 1, 0]]

cnt = 0
for i in lis:
    if i[2]+i[3]+i[4]+i[5] >= 2:
        cnt += 1
print("More than two: ", cnt)

print("\nthe condition of female: ")
for i in lis:
    if i[1] == "female":
        for j in i:
            if j != "female":
                print(j, end=" ")
        print()

print("\n3000m: ")
for i in lis:
    if i[3] == 1:
        print(i[0], i[1])
