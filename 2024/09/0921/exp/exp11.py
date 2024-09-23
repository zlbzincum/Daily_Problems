import math


if __name__ == '__main__':
    pi = 0
    i = 1
    n = 1
    s = 1
    while abs(s) >= 1e-7 :
        s = 1 / (2 * n - 1)
        pi += i * s
        n += 1
        i = -i



    pi = 4 * pi
    print("数据分解并行计算的π值为:{:.6f}".format(pi))

