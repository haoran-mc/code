import timeit
start = timeit.default_timer()


def Fibo(n):
    if n <= 1:
        return 1
    else:
        return Fibo(n-1) + Fibo(n-2)


# n = eval(input("input the number of terms: "))
n = 10

listFibo = []
for i in range(n):
    listFibo.append(Fibo(i))

print(listFibo)

end = timeit.default_timer()
print('Running time: %s Seconds' % (end-start))
