import random as rd

target = rd.randint(1, 100)
print("number guess:")
count = 0

while True:
    guess = eval(input("input"))
    count += 1
    if guess > target:
        print("big")
    elif guess < target:
        print("small")
    else:
        print("yes")
        break
