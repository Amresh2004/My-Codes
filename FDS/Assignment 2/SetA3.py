import pandas as pd

# Create a DataFrame
data = {
    'A': [10, 20, 30, 40, 50],
    'B': [15, 25, 35, 45, 55],
    'C': [5, 10, 15, 20, 25]
}
df = pd.DataFrame(data)
print("Original DataFrame:")
print(df)

# Calculate mean for each column
mean_values = df.mean()
print("\nMean values:")
print(mean_values)

# Calculate range (max - min) for each column
range_values = df.max() - df.min()
print("\nRange values:")
print(range_values)

# Calculate IQR (Interquartile Range) for each column
iqr_values = df.quantile(0.75) - df.quantile(0.25)
print("\nIQR values:")
print(iqr_values)


OUTPUT:-

Original DataFrame:
    A   B   C
0  10  15   5
1  20  25  10
2  30  35  15
3  40  45  20
4  50  55  25

Mean values:
A    30.0
B    35.0
C    15.0
dtype: float64

Range values:
A    40
B    40
C    20
dtype: int64

IQR values:
A    20.0
B    20.0
C    10.0
dtype: float64
