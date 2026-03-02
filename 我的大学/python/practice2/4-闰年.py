for year in range(2000, 3000):
    if (year % 4 == 0 and year % 100 != 0) or (year % 400 == 0):
        print(year, " ", end="")

print("\n")
