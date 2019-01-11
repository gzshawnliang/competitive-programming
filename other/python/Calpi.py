from __future__ import division
import random
import time
 
num = 1
for j in range(2, 100000):
    startT = time.clock()
    # 落入圆内计数
    counter = 0
    # 往正方形中扔了 10 的 j 次方次
    for i in range(10 ** j):
        x = random.uniform(-1, 1)
        y = random.uniform(-1, 1)
        # 落入了圆内
        if x**2 + y**2 < 1:
            counter = counter + 1
    endT = time.clock()
    print ( num)
    print ( 'pi:{0}'.format(4 * (counter / 10 ** j)))
    print ( 'Time:{0}'.format(endT - startT))
    print ('')
    num += 1