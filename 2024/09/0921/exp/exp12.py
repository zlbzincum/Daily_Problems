import math
import threading
import time

class myTread (threading.Thread):
    def __init__(self, threadID, name, result):
        threading.Thread.__init__(self)
        self.threadID = threadID
        self.name = name
        self.result = result

    def run(self):
        print ("开启线程： " + self.name)
        # 获取锁，用于线程同步
        # threadLock.acquire()
        SolveThread(self.threadID, self.result)
        # 释放锁，开启下一个线程
        # threadLock.release()

def SolveThread(threadID, result):
    s = 1
    n = 1 if threadID == 1 else 2
    i = 1 if threadID == 1 else -1

    while abs(s) >= 1e-7 :
        s = 1 / (2 * n - 1)
        result.append(i * s)
        n += 2


if __name__ == '__main__':
    pi = 0
    threads = []
    result1 = []
    result2 = []

    thread1 = myTread(1, "奇数部分Thread",result1)
    thread2 = myTread(2, "偶数部分Thread",result2)

    thread1.start()
    thread2.start()

    threads.append(thread1)
    threads.append(thread2)

    for t in threads:
        t.join()

    pi = sum(result1) + sum(result2)

    pi = 4 * pi
    print("数据分解并行计算的π值为:{:.6f}".format(pi))