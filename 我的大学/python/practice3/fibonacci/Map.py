import timeit
start = timeit.default_timer()


def Fibo(n):
    listFibo = [1, 1]
    list(map(lambda _: listFibo.append(sum(listFibo[-2:])), range(2, n)))
    return listFibo[:n]


# n = eval(input("input the number of terms: "))
n = 10
print(Fibo(n))

end = timeit.default_timer()
print('Running time: %s Seconds' % (end-start))
