import time;  # This is required to include time module.

counter = 100          # An integer assignment
miles   = 1000.0       # A floating point
name    = "John"       # A string

print (counter)
print (miles)
print (name)
print ( "time:", time.asctime( time.localtime(time.time())))

sum = 0
for x in [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]:
    sum = sum + x
    print(x,":",sum)
