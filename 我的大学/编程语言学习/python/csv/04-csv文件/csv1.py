import csv


with open("test.csv", "r") as testcsv:
    reader = csv.reader(testcsv)
    for row in reader:
        print(row)

with open("test.csv", "a") as testcsv:
    writer = csv.writer(testcsv)
    writer.writerow(["hello", "n 你好"])
    writer.writerow(["world", "n 世界"])

with open("test.csv", "a", newline="") as testcsv:
    writer = csv.writer(testcsv)
    writer.writerow(["hello", "n 你好"])
    writer.writerow(["world", "n 世界"])

with open("test.csv", "a", newline="") as testcsv:
    writer = csv.writer(testcsv)
    writer.writerows(["hello", "n 你好"])
    writer.writerows(["world", "n 世界"])
