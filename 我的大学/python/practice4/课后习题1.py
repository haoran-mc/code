dicTXL = {"xiaoxin": [13913000001, 18191220001],
          "xiaoliang": [13913000002, 18191220002],
          "xiaogang": [13913000003, 18191220003]}

dicOther = {"daliu": [13914000001, 18191230001],
            "dawang": [13914000002, 18191230002],
            "dazhang": [13914000003, 18191230003]}

dicWX = {"xiaox": "xx9907",
         "xiaogang": "gang1004",
         "dawang": "jack_w",
         "daliu": "liu666"}

dicTXL.update(dicOther)
print("add other roommates:")
for key, value in dicTXL.items():
    print(key, value)

for key, value in dicTXL.items():
    value.append(str(dicTXL[key][0]))

for key1, value1 in dicTXL.items():
    for key2, value2 in dicWX.items():
        if key1 == key2:
            value1[2] = value2

print("\nadd wechat number:")
for key, value in dicTXL.items():
    print(key, value)

dicTXL["dawang"][1] = 13914000004
print("\nchange dawang's number:")
for key, value in dicTXL.items():
    print(key, value)

name = input("\ninput the student's name to query it's info: ")
if name in dicTXL:
    print(dicTXL[name])
else:
    print("没有该同学的联系方式")
