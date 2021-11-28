"""x, y = input("Enter a two value: ").split()
print("Number of boys: ", x)
print("Number of girls: ", y)
print()
 
# taking three inputs at a time
x, y, z = input("Enter a three value: ").split()
print("Total number of students: ", x)
print("Number of boys is : ", y)
print("Number of girls is : ", z)
print()
 
# taking two inputs at a time
a, b = input("Enter a two value: ").split()
print("First number is {} and second number is {}".format(a, b))
print()
 
# taking multiple inputs at a time
# and type casting using list() function
x = list(map(int, input("Enter a multiple value: ").split()))
print("List of students: ", x)"""

y="huyngo"
y[0].upper
print(y[0])
print(ascii(70))
danhsach = ['Python','PŸTHON','√', 'ö','Pythön', 'Š', 'Œ','Ž',10, '©']
print(ascii(danhsach))
inp = input('Write Text: ')
inp = inp.lower()
op = []
for character in inp:
    number = ord(character) - 96
    op.append(number)
print(op)
num=ord(y[0])
print(num)
Pt=1
tuple1=("a",1,"2","fdsđ")
print(tuple1[0])
list1=["2","aa"]
list1.sort()
print(list1[0])
str1="a b c d"
list1=str1.split(" ")
print(list1)


set1 = set()
print("Initial blank Set: ")
print(set1)
 
# Creating a Set with
# the use of a String
set1 = set("GeeksForGeeks")
print("\nSet with the use of String: ")
print(set1)
 
# Creating a Set with
# the use of Constructor
# (Using object to Store String)
String = 'GeeksForGeeks'
set1 = set(String)
print("\nSet with the use of an Object: " )
print(set1)
 
# Creating a Set with
# the use of a List
set1 = set(["Geeks", "For", "Geeks"])
print("\nSet with the use of List: ")
print(set1)