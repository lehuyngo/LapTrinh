"""a=[]
for i in range(2000,3201):
    if (i%7==0) and (i%5!=0):
        a.append(str(i))
print(','.join(a))"""
"""
import math
import os
import random
import re
import sys


if __name__ == '__main__':
    n = int(input("nhap:"))
    if(n%2==0): 
        if(n==4 | n>20): print("Not Weird")
        else: print("Weird")
    else: print("Weird")"""

"""def is_leap(year):
    leap = False
    if(year %4==0 ):
        if(year %100==0 ):
            if(year %400==0):
                leap=True;
            else : leap=False
        else:   leap=True
    # Write your logic here
    
    return leap

year = int(input())
print (is_leap(year))"""
import sys
 
# initializing a with range()
a = range(1,10000)
 
# initializing a with xrange()

 
# testing the size of a
# range() takes more memory
print ("The size allotted using range() is : ")
print (sys.getsizeof(a))
 
# testing the size of x
# range() takes less memory
if name=