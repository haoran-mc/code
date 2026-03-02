# 导入内置库
import timeit
# 使用内置函数default_timer()来计算程序运行的时间
start = timeit.default_timer()

"""
函数定义的语法
def 函数名 ([参数列表]):
    函数体
"""


# 定义一个函数生成斐波那契数列的前n项
def Fibo(n):
    f0, f1 = 1, 1
    for _ in range(n):
        yield f0
        f0, f1 = f1, f0+f1


n = 10
# 函数调用
for i in Fibo(n):
    print(i, end=" ")

end = timeit.default_timer()
print('Running time: %s Seconds' % (end-start))
