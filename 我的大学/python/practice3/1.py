# 初始化列表
lis = [54, 36, 75, 28, 50]
print(lis)

# 列表后插入元素42
lis.append(42)
print(lis)

# 列表中元素28前插入元素66
lis.insert(lis.index(28), 66)
print(lis)

# 删除列表中元素28并输出
print(lis.pop(lis.index(28)))
print(lis)

# 逆序排列列表
lis.sort(reverse=True)
print(lis)

# 清空列表
del lis[:]
print(lis)
