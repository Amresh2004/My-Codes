import pandas as pd

# Create DataFrame
data = {
    'Name': ['Alice', 'Bob', 'Charlie', 'David', 'Eve'],
    'Graduation Percentage': [85, 90, 78, 92, 88],
    'Age': [22, 23, 21, 24, 22]
}
df = pd.DataFrame(data)

# Calculate averages
average_age = df['Age'].mean()
average_grad_percentage = df['Graduation Percentage'].mean()

# Display results
print(f"Average age: {average_age}")
print(f"Average graduation percentage: {average_grad_percentage}")

# Describe statistics
print(df.describe())

OUTPUT:-
Average age: 22.4
Average graduation percentage: 86.6
       Graduation Percentage        Age
count               5.000000   5.000000
mean               86.600000  22.400000
std                 5.458938   1.140175
min                78.000000  21.000000
25%                85.000000  22.000000
50%                88.000000  22.000000
75%                90.000000  23.000000
max                92.000000  24.000000
