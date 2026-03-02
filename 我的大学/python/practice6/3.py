with open("cloud.txt", "r") as file:
    dic = {}
    for line in file.readlines():
        words = line.split()
        for word in words:
            dic[word] = dic.get(word, 0) + 1
    lst = list(dic.items())
    lst.sort(key=lambda x: x[1], reverse=True)
    write = open("fre.txt", "w")
    for i in range(30):
        word, count = lst[i]
        write.writelines("{}\t{}\n".format(word, count))
    write.close()
