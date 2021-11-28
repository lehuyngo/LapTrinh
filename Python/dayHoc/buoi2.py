"""
def inra(a,n):
    print (a[n])
    if(n<len(a)-1):
        inra(a,n+1)
b=[1,2,3,4]
inra(b,0)   
import array as arr
  
# creating an array with integer type
a = arr.array('i', [1, 2, 3])
  
# printing original array
print ("The new created array is : ", end =" ")
for i in range (0, 3):
    print (a[i], end =" ")
print()
  
# creating an array with float type
b = arr.array('d', [2.5, 3.2, 3.3])
  
# printing original array
print ("The new created array is : ", end =" ")
for i in range (0, 3):
    print (b[i], end =" ")
def inra(*argv):
    for arg in argv:
        print (arg)
a={1,2,3,4}
inra(a)






s="le thuy duong"
a=set(s)
print(a)




prin(3,4)

prin(4,6)
list1=(1,424,563,221,432,311,0)
a=set(list1)
pri"""


"""
class node:
    def __init__(self) -> None:
        self.a=0
        self.b=0
    def __init__(self, c ,d) -> None:
        self.a=c
        self.b=d
    def add(self)-> int:
        return self.a+self.b
t=node(5,6)
print(t.add())"""
import sys

randomList = ['a', 0, 2]

for nhap in randomList:
    try:
        print("Phần tử:", nhap)
        r = 1/int(nhap)
        break
    except:
        print("Có ngoại lệ ",sys.exc_info()[0]," xảy ra.")
        print("Nhập phần tử tiếp theo")
        print()
print("Kết quả với phần tử",nhap,"là:",r)