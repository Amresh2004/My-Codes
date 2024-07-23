import math
a = int(input("Enter the first side of the triangle: "))
b = int(input("Enter the second side of the triangle: "))
c = int(input("Enter the third side of the triangle: "))
s = (a + b + c) / 2
area = math.sqrt(s * (s - a) * (s - b) * (s - c))
perimeter = a + b + c
print("Area of the triangle =", area)
print("Perimeter of the triangle =", perimeter)