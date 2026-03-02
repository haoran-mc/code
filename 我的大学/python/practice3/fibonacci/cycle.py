import timeit
start = timeit.default_timer()


def Fibo(n):
    f0, f1 = 1, 1
    for _ in range(n):
        yield f0
        f0, f1 = f1, f0+f1


# n = eval(input("input the number of terms: "))
n = 10
for i in Fibo(n):
    print(i, end=" ")


# listFibo = list(Fibo(n))
# for i in range(n):
#     print(listFibo[i], end=" ")

end = timeit.default_timer()
print('Running time: %s Seconds' % (end-start))
