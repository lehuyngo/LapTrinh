'''class hs:
    ten=""
    tuoi=-1
    def __init__(self,ten,tuoi):
        self.ten=ten
        self.tuoi=tuoi
    def nhap(self):
        age=0
        age=input("nhap tuoi:")
        self.tuoi=int(age)
        namesss=input("nhap ten:")
        self.ten=namesss
    def xuat(self):
        print(self.ten)
        print(self.tuoi)
ngo=hs()
ngo.nhap()
ngo.xuat()'''
'''ngo.ten=input("nhap ten:")
print(ngo.ten)
ngo.tuoi=input("nhap tuoi:")
print(ngo.tuoi)'''
'''
class Car:
    def __init__(self, make, model, year):
        self.make = make
        self.model = model
        self.year = year
        self.manufacturer="huy"
        self.odometer_reading = 0
    def get_descriptive_name(self):
        long_name = f"{self.year} {self.manufacturer} {self.model}"
        return long_name.title()
    def read_odometer(self):
        print(f"This car has {self.odometer_reading} miles on it.")
    def update_odometer(self, mileage):
        if mileage >= self.odometer_reading:
            self.odometer_reading = mileage
        else:
            print("You can't roll back an odometer!")
    def increment_odometer(self, miles):
        self.odometer_reading += miles
class ElectricCar(Car):
    def __init__(self, make, model, year):
        super().__init__(make, model, year)
    def gigido(self):
        print(super().get_descriptive_name())
    def fill_gas_tank(self):
        print("This car doesn't need a gas tank!") 
my_tesla = ElectricCar('tesla', 'model s', 2019)
my_tesla.fill_gas_tank()
xeco=Car('tesla', 'model s', 2019)'''
from pizza import Car
my_new_car = Car('audi', 'a4', 2019)
print(my_new_car.get_descriptive_name())
my_new_car.odometer_reading = 23
my_new_car.read_odometer()
from random import randint
print(randint(1, 6))
