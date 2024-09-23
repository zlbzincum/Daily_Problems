import math
import threading
import time


inf = 20000000 - 1 # 2 ** 31 - 1

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
        self.result = SolveThread(self.threadID, self.result)
        # 释放锁，开启下一个线程
        # threadLock.release()

def SolveThread(threadID, result):
    s = 1
    n = 1 if threadID == 1 else inf // 2
    mxn = inf // 2 if threadID == 1 else inf

    for i in range(n, mxn):
        s = 1 / (2 * i - 1)
        flag = 1 if i % 2 == 1 else -1
        result += flag * s
    return result

if __name__ == '__main__':
    pi = 0
    print(inf)
    threads = []
    result1 = 0
    result2 = 0

    thread1 = myTread(1, "前半部分Thread",result1)
    thread2 = myTread(2, "后半部分Thread",result2)

    thread1.start()
    thread2.start()

    threads.append(thread1)
    threads.append(thread2)

    for t in threads:
        t.join()

    pi = thread1.result + thread2.result

    pi = 4 * pi
    print("数据分解并行计算的π值为:{:.6f}".format(pi))
