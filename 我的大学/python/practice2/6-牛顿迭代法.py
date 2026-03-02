import math

n = eval(input("Please input the number of number you want to calculate:"))
eps = 1e-6
for i in range(n):
    x = 1.0
    while x*x-i < -eps or x*x-i > eps:
        x = (x + i/x) / 2.0

    print("sqrt({}) = {:.3f}".format(i, x))
    print("math.sqrt({}) = {:.3f}".format(i, math.sqrt(i)))

    if (x - math.sqrt(i) < eps):
        print("you are right!")
    else:
        print("you are wrong!")

    print("")
