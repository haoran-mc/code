import math

for angle in range(0, 90+1):
    if angle % 5 == 0:
        # print(angle, end="")
        # print("    sin(", angle, ") = ", end="")
        # print((float)(math.sin(angle/90 * math.pi)), end="")
        # print("    cos(", angle, ") = ", end="")
        # print((float)(math.cos(angle/90 * math.pi)))

        print("angle = {};  sin({}) = {:.3f};  cos({}) = {:.3f}".format(
            angle,
            angle, math.sin(angle/180 * math.pi),
            angle, math.cos(angle/180 * math.pi)))
