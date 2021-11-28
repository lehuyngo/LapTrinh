
import os
print(os.getcwd())
os.chdir('C:\\Users\\Administrator\\Desktop\\LapTrinh\\Python')
try: 
    with open('C:/Users/Administrator/Desktop/LapTrinh/Python/tescase.txt') as fileobject:
        contents = fileobject.read()
        print(contents)
        fileobject.close()
except FileNotFoundError:
    print("not found")
"""try:
    print(5/0)
except ZeroDivisionError:
    print("You can't divide by zero!")
try:
 answer = int(5) / int(1)
except ZeroDivisionError:print("You can't divide by 0!")
else: print(answer)"""
import os
os.chdir
import json
numbers = [2, 3, 5, 7, 11, 13]
filename = 'numbers.json'
with open(filename, 'w') as f:
    json.dump(numbers, f)
f.close()
with open(filename) as f:
    aray=json.load(f)
print(aray)