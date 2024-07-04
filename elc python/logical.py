a = 5
b = 6
c = 7

result1 = (a > b) and (a > c)
result2 = (c > a) and (c > b)
result3 = (a < b) or (a < c)
result4 = not (a < b)

print("Result 1 (a > b and a > c):", result1)
print("Result 2 (c > a and c > b):", result2)
print("Result 3 (a < b or a < c):", result3)
print("Result 4 (not a < b):", result4)
