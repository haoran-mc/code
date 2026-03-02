for i in range(10):
    value = pow(2, pow(2, i))
    print("value = 2^{} =".format(pow(2, i)), value)
    print("value.__sizeof__() = ", value.__sizeof__())

print("**********************************************************\n")
for i in range(200):
    value = pow(2, i)
    print("value = 2^{} =".format(i), value)
    print("value.__sizeof__() = ", value.__sizeof__())
