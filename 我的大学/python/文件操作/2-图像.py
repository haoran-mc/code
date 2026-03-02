# 没成功
import os


def BGR2RGB(img):
    b = img[:, :, 0].copy()
    g = img[:, :, 1].copy()
    r = img[:, :, 2].copy()
    # RGB -> BGR
    img[:, :, 0] = r
    img[:, :, 1] = g
    img[:, :, 2] = b
    return img


os.chdir("/home/haoran/haoran/work/python/class/文件")
file = open("img.png", "a+")
