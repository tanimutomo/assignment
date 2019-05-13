# vring with message queue: created by hxt
import logging
import threading
import time
import queue

logging.basicConfig(level=logging.DEBUG, format='%(threadName)s: %(message)s')


def proc(id, pred_q, succ_q):
    logging.debug('start')
         # 最初のthreadでは、メッージをput
    if (id== 0):
        succ_q.put(100) #put(100)
        logging.debug('put')        
    time.sleep(1)
    # itemをget
    item = pred_q.get()
    logging.debug('get')

    logging.debug(item)

    # itemをput
    succ_q.put(item) 
    logging.debug('put')
    
    logging.debug('endloop')

#main
if __name__ == '__main__':
    # ３つのqueueを作成
    mq = [queue.Queue()]*3
    threadlist = list()   
    for i in range(3):
       t = threading.Thread(target=proc, args=(i, mq[i], mq[(i+1)%3],))
       threadlist.append(t)
       t.start()

    for thread in threadlist:
        thread.join()
    print("main is done.")
