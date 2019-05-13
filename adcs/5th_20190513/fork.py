#
# A thread creationg by hxt
# 
import time
import threading
 
def proc(id):
    for i in range(id+2):
        time.sleep(1)
        print("thread",id,"count",i)
#
# main 
#

if __name__ == '__main__':
    threadlist = list()   
    for i in range(2): 
        t = threading.Thread(target=proc, args=(i, ))
        threadlist.append(t)
        t.start()
 
    print(threadlist)
    for thread in threadlist:
        thread.join()
 
    print("All thread is ended.")
