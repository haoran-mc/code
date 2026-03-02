# 最小公倍数
def Gcd(num1, num2):
    if lambda num2: True if not num2 else False:
        return num1
    else:
        return Gcd(num2, num1 % num2)


gcd = Gcd(24, 36)
print("gcd(24, 36) = ", gcd)
