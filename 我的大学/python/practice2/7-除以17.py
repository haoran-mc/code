num = eval(input("Please input the number: "))

if num < 17:
    print("There is no number can divided 17!")
else:
    for i in range(num, 16, -1):
        if (i % 17 == 0):
            print("{} // 17 = {}".format(i, i // 17))
            break
