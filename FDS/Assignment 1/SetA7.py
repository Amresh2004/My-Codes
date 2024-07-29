import pandas as pd
import matplotlib.pyplot as plt

data = {
    'name': ['A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'],
    'age': [1, 2, 3, 4, 5, 6, 7, 8, 9, 10],
    'percentage': [85.5, 92.3, 78.6, 88.4, 79.5, 91.2, 85.7, 90.1, 87.6, 83.4]
}

df = pd.DataFrame(data)

add_data = {
    'name': ['K', 'L', None, 'N', 'O'],
    'age': [23, 30, 25, None, 29],
    'percentage': [85.5, None, 78.6, 79.5, 91.2]
}
add_df = pd.DataFrame(add_data)

df = pd.concat([df, add_df], ignore_index=True)

df['remarks'] = ""

print(df)

df = df.drop(columns=['remarks'])

df = df.dropna()

plt.figure(figsize=(10, 6))
plt.plot(df['name'], df['percentage'], marker='o', linestyle='-')
plt.xlabel('Name')
plt.ylabel('Percentage')
plt.title('Name vs Percentage')
plt.grid(True)
plt.tight_layout()
plt.show()
