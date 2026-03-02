import csv
with open("test.csv", "a") as testcsv:
    writer = csv.writer(testcsv)
    writer.writerow(['hello', 'n 你好'])
    writer.writerow(['world', 'n 世界'])

with open("test.csv", "a", newline='') as testcsv:
    writer = csv.writer(testcsv)
    writer.writerow(['hello', 'n 你好'])
    writer.writerow(['world', 'n 世界'])

with open("test.csv", "a", newline='') as testcsv:
    writer = csv.writer(testcsv)
    writer.writerows(['hello', 'n 你好'], ['world', 'n 世界'])
