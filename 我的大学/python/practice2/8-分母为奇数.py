n = eval(input("Please input 'n': "))

S = 0
print("S = ", end="")
for i in range(1, n+1):
    if i & 1:
        print("1/{}".format(i), "+ ", end="")
        S += 1 / i

print("\b\b = {:.3f}".format(S))
