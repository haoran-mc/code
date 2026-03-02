import random


def getgcd(num1, num2):
    while num2 != 0:
        temp = num2
        num2 = num1 % num2
        num1 = temp

    return num1


def getlcm(num1, num2, num3, gcd):
    return num1 * num2 // gcd


a = random.randint(1, 101)
b = random.randint(1, 101)
c = random.randint(1, 101)
print("a = {}".format(a))
print("b = {}".format(b))
print("c = {}".format(c))

gcd_a_b = getgcd(a, b)
gcd_all = getgcd(gcd_a_b, c)
print("Maximum common factor = {}".format(gcd_all))

lcm = getlcm(a, b, c, gcd_all)
print("Least common multiple = {}".format(lcm))
