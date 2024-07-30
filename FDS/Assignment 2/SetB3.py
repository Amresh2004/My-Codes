import pandas as pd

# Read the Iris dataset
url = "https://archive.ics.uci.edu/ml/machine-learning-databases/iris/iris.data"
column_names = ['sepal_length', 'sepal_width', 'petal_length', 'petal_width', 'class']
df = pd.read_csv(url, header=None, names=column_names)

# Calculate and display column-wise mean
print("Column-wise Mean:")
print(df.mean(numeric_only=True))
print("\n")

# Calculate and display column-wise median
print("Column-wise Median:")
print(df.median(numeric_only=True))

OUTPUT:-
Column-wise Mean:
sepal_length    5.843333
sepal_width     3.054000
petal_length    3.758667
petal_width     1.198667
dtype: float64


Column-wise Median:
sepal_length    5.80
sepal_width     3.00
petal_length    4.35
petal_width     1.30
dtype: float64
