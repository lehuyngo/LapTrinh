'''def double(num):
     """Funtion to double the value"""
     return 2*num
print(double.__doc__)
input("\n\n Nhấn phím emter để thoát")

hoa="hồng"
la=3
canh=5.5
print(hoa)
hoa, la, canh="đỏ",4,7
print(la)
print(type(hoa))


b=8+2j
print(b)
#số thập phân
from decimal import Decimal as D
print(D('2.2')+D('1.1'))
print(0.1)
print(D('4.0')*D('2.50'))
#print(decimal.Decimal(0.1))

# Phân số
x=[1,2,3,4,5]
print(x[0:5])


a=[
  [1,2,3],
  [2,3,4],
  [3,4,5] 
  ]
print(a)


a = 1 - 2
print(a)
message = "HELLO python prash course world!"
print(message.title())
print(message.upper())
print(message.lower())

first_name = "ada"
last_name = "lovelace"
full_name = f"{first_name} {last_name}" # giữa các dấu{} {} là số space trong string ghép
print(full_name)
ten="ngo"
dem="huy"
ho="le"
#hoten=f"{ho} {dem} {ten}"
#print(hoten)
#print(f"Hello, {hoten.title()}!")
full_name = "{}     {}".format(first_name,last_name)
hoten="{} {} {}".format(ho,dem,ten)
print(hoten)
print("Python") 
print("\tPython") #\t là cách tab
print("Languages:\nPython\nC\nJavaScript") #\n là xuống dòng
hoa='    hồng lựu  '
print(hoa)
print(hoa.rstrip())   # xóa dấu cách ở cuối khi in ra
print(hoa.lstrip()) #xóa dấu cách đầu
print(hoa.strip())
message = "One of Python's strengths is its diverse community."
print(message)
#message = 'One of Python's strengths is its diverse community.' lỗi ko dc dùng nháy đơn trong nhay đơn, tương tự nháy kép
# print(message)




# integer
print(2*3)
print(2**3)

xemay=["yamaha","suzuki","dream"]
print(xemay[1])
str=f"xe dau tien cua toi là {xemay[1]}"
print(str)
xemay.append("wave")
print(xemay)
#xemay=[]
#print(xemay)
#xemay.insert(1,"wave")
#print(xemay)
#del xemay[0]
print(xemay)
#print(xemay.pop(2)) #lệnh xóa tại vị trí
#xemay.remove('suzuki'); print(xemay)
xemay.sort()
print(xemay)
for xe in xemay:
 print(f"{xe},\t")
for v in range(1,5):
 print(v)
numbers = list(range(1, 6))
#print(numbers)
#even_numbers = list(range(1, 11, 2))
#print(even_numbers)
#print(numbers[1:])
#print(numbers[:4])
so=xemay
print(so)
dimensions = (200, 50)
#dimensions[0]=250 lỗi
my_t = (3,)
print(my_t)
cars = ['audi', 'bmw', 'subaru', 'toyota']
for car in cars:
  if car == 'bmw':
      print(car.upper())
  else:
      print(car.title())
tuoi=18
if tuoi>18:
    print('dutuoi')
elif tuoi==18: print('gandu')
else: print("chua du")
alien_0 = {'color': 'green', 'points': 5}
print(alien_0['color'])
print(alien_0['points'])
alien_0 = {'color': 'green', 'points': 5}
print(alien_0)
alien_0['x_position'] = 0
alien_0['y_position'] = 25
print(alien_0)
alien_0 = {'color': 'green'}
print(f"The alien is {alien_0['color']}.")
alien_0['color'] = 'yellow'
print(f"The alien is now {alien_0['color']}.")
for x,y in alien_0.items():
  print(f"ten:{x}")
  print(f"gia tri:{y}")
for z in alien_0.keys():
  print(z) 
favorite_languages ={
        'jen': 'python',
        'sarah': 'c',
        'edward': 'ruby',
        'phil': 'python',
    }
for name in favorite_languages.keys():
 print(name.title())
friends = ['phil', 'sarah']
for name in favorite_languages.keys():
 print(name.title())
 if name in friends:
  language = favorite_languages[name].title()
print(language)
favorite_languages ={
        'jen': 'python',
        'sarah': 'c',
        'edward': 'ruby',
        'phil': 'python',
    }
for ten in favorite_languages.values():
  print(ten)
aliens = []
for alien_number in range(30):
 new_alien = {'color': 'green', 'points': 5, 'speed': 'slow'}
aliens.append(new_alien)
# Show the first 5 aliens.
for alien in aliens[:5]:
 print(alien)

favorite_languages = {
'jen': ['python', 'ruby'],
'sarah': ['c'],
'edward': ['ruby', 'go'],
'phil': ['python', 'haskell'],
}
print(favorite_languages['edward'][0])
message = input("Tell me something, and I will repeat it back to you: ")
print(message)
prompt = "If you tell us who you are, we can personalize the messages you see."
prompt += "What is your first name? "
print(prompt)
tuoi=input("ban may tuoi:")
tuoi=int(tuoi)
print(tuoi)
current_number = 0
while current_number < 10:
  current_number += 1
  if current_number % 2 == 0:
    break
  print(current_number)
'''
import sys
import pygame
class AlienInvasion:
    def __init__(self):
        pygame.init()
        self.screen = pygame.display.set_mode((1200, 800))
        pygame.display.set_caption("Alien Invasion")
    def run_game(self):
        while True:
            for event in pygame.event.get():
                if event.type == pygame.QUIT:
                    sys.exit()
                    pygame.display.flip()
if __name__ == '__main__':
    ai = AlienInvasion()
    ai.run_game()