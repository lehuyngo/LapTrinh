class chuoi:
    def __init__(self) -> None:
        pass
    def nhap(self):
        self.s=input("nhap chuoi:")
    def xuat(self):
        print(self.s.upper())
a=chuoi()
a.nhap()
a.xuat()
print(abs.__doc__)