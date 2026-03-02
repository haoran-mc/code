import csv

dicTXL = {
    "xiaoxin": [13913000001, 18191220001],
    "xiaoliang": [13913000002, 18191220002],
    "xiaogang": [13913000003, 18191220003]
}

dicOther = {
    "daliu": [13914000001, 18191230001],
    "dawang": [13914000002, 18191230002],
    "dazhang": [13914000003, 18191230003]
}

dicWX = {
    "xiaox": "xx9907",
    "xiaogang": "gang1004",
    "dawang": "jack_w",
    "daliu": "liu666"
}

# 原先的通信录
dicTXL.update(dicOther)

# 添加隔壁宿舍
for key, value in dicTXL.items():
    value.append(str(dicTXL[key][0]))

# 添加微信
for key1, value1 in dicTXL.items():
    for key2, value2 in dicWX.items():
        if key1 == key2:
            value1[2] = value2

# 又更改了dawang的电话号码
dicTXL["dawang"][1] = 13914000004

with open("contacts.csv", "w+", newline='') as contcsv:
    writer = csv.writer(contcsv)
    lst = []
    for key, value in dicTXL.items():
        lst.append(key)
        for i in value:
            lst.append(i)
        writer.writerow(lst)
        lst.clear()

with open("contacts.csv", "r") as contcsv:
    reader = csv.reader(contcsv)
    for row in reader:
        if row[0] == "dawang":
            print("<------ dawang ------>")
            print("name:", "dawang")
            print("phone:", row[1])
            print("QQ:", row[2])
            print("wechat:", row[3])
