x=int(input("nhap so:"))
def gt(a):
    if(a==0):return 1
    return a*gt(a-1)
print(gt(x))