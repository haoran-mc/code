from functools import reduce
import timeit
start = timeit.default_timer()


def Fibo(n):
    return reduce(lambda x, _: x+[x[-1]+x[-2]], range(n-2), [1, 1])


# n = eval(input("input the number of terms: "))
n = 10
print(Fibo(n))

end = timeit.default_timer()
print('Running time: %s Seconds' % (end-start))
