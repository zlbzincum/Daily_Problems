import threading
import time

class myThread (threading.Thread):
   def __init__(self, threadID, name, delay):
      threading.Thread.__init__(self)
      self.threadID = threadID
      self.name = name
      self.delay = delay

   def run(self):
      print("开启线程： " + self.name)
      for _ in range(1000):
         dosth()
         if self.threadID == 1:
            print("*", end = "", flush = True)
            time.sleep(self.delay)
         else:
            print(" ", end = "", flush = True)
            time.sleep(self.delay)


def dosth():
   for _ in range(10000):
      a = 15
      a = a * a * a * a


threads = []

thread1 = myThread(1, "Thread_1", 0.01)
thread2 = myThread(2, "Thread_2", 0.02)

thread1.start()
thread2.start()

threads.append(thread1)
threads.append(thread2)

for t in threads:
   t.join()

print("ok")


