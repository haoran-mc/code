def avg(lst):
    return int(sum(lst) / len(lst))


s = {'xiaoli': [77, 54],
     'xiaozhang': [89, 66, 78, 99],
     'xiaochen': [90],
     'xiaoyang': [69, 58, 93]}

res = {}

for key, val in s.items():
    res[key] = avg(val)

print(res)
