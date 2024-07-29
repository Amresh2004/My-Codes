import pandas as pd

data = {
    'name': ['A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'],
    'age': [1, 2, 3, 4, 5, 6, 7, 8, 9, 10],
    'percentage': [85.5, 92.3, 78.6, 88.4, 79.5, 91.2, 85.7, 90.1, 87.6, 83.4]
}

df = pd.DataFrame(data)

print(df)