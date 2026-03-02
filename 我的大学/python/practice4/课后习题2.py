score = {"012": [90, 94, 97, 86, 85, 89, 88, 85],
         "005": [91, 91, 92, 98, 90, 96, 90, 95],
         "108": [96, 86, 97, 96, 87, 86, 86, 96],
         "037": [95, 95, 94, 93, 97, 98, 99, 95],
         "066": [95, 87, 94, 94, 93, 99, 96, 97],
         "020": [89, 97, 91, 95, 89, 94, 97, 92]}

rank = {}
for key, value in score.items():
    value.sort()
    rank[key] = sum(value[1:-1]) // 6

lis = [(value, key) for key, value in rank.items()]
lis.sort(reverse=True)
lis = [(key, value) for value, key in lis]

print(lis)
