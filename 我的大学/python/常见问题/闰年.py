year = eval(input("输入需要判断的年份："))

if (year % 4 == 0 and year % 100 != 0) or (year % 400 == 0):
    print("It is leap")
else:
    print("It is not leap")
