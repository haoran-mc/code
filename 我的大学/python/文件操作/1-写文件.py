import os
os.chdir("/home/haoran/haoran/work/python/1-class/3-文件操作")


# --------------------读文件
file = open("mydata.txt", "w")

# 连续写入的不同字符串之间不会添加任何分割符
file.write("飞雪连天射白鹭")
file.write("笑书神侠倚碧鸳")

# 同样不添加任何分割符
file = open("mydata.txt", "w")
file.writelines(["飞雪连天射白鹭\t", "笑书神侠倚碧鸳\t"])
file.writelines(["横批: 越女剑\n"])

file = open("mydata.txt", "a")
file.writelines(["飞雪连天射白鹭\t", "笑书神侠倚碧鸳\t"])
file.writelines(["横批: 越女剑\n"])

file = open("mydata.txt", "a+")
file.writelines(["飞雪连天射白鹭\t", "笑书神侠倚碧鸳\t"])
file.writelines(["横批: 越女剑\n"])


# --------------------写文件
file = open("mydata.txt", "r")
for text in file.readline():
    print(text, end="")
print("1<------>\n")

for text in file:
    print(text, end="")
print("<------>\n")

# 没读到，每次读取从上次读取之后开始
text = file.read()
print(text)

file = open("mydata.txt", "r")
text = file.readlines()
print(text)

file.close()
