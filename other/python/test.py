import math
import numpy as np
from decimal import *

a1=math.sin(30*math.pi/180)
print(a1)

print(math.pi)

msg="OK"
print(msg)

a = np.array([[3,7],[9,1]])  
print ('我们的数组是：')  
print (a)
print  ('\n')  
print  (1/3)  

# 提高高进度 到50位数
getcontext().prec = 50
print (Decimal(1)/Decimal(3))