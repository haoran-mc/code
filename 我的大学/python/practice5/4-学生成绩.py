def good(dict):
    lst = []
    for key, value in dict.items():
        if value[0] >= 85 and value[1] >= 85 and value[2] >= 85:
            lst.append(key)
    return lst


def score(dict):
    dicScore = {}
    for key, value in dict.items():
        sumi = round(sum(value) / 1.0, 2)
        avgi = round(sumi / 3.0, 2)
        dicScore[key] = [sumi, avgi]
    return dicScore


def sorting(dict):
    lst = []
    for key, value in dict.items():
        lst.append([sum(value), key])
    lst.sort()
    res = []
    for j in lst:
        res.append([j[1], j[0]])
    return res


dict = {'01': [67, 88, 45],
        '02': [97, 68, 85],
        '03': [97, 98, 95],
        '04': [67, 48, 45],
        '05': [82, 58, 75],
        '06': [96, 49, 65]}

print("每门成绩均达到85分: ")
listGood = good(dict)
for i in range(len(listGood)):
    print(listGood[i], end=" " if i % 5 else "\n")

print("")
print("学号 总分 平均分")
dicScore = score(dict)
for key, value in dicScore.items():
    print(key, value[0], "{:.2f}".format(value[1]))

print("")
print("学号 总分")
listSort = sorting(dict)
for i in range(len(listSort)):
    print(listSort[i][0], listSort[i][1], end="\n")
