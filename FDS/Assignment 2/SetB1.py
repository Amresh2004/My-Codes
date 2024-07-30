import pandas as pd

# Load the iris dataset from the URL
url = 'https://archive.ics.uci.edu/ml/machine-learning-databases/iris/iris.data'
column_names = ['sepal_length', 'sepal_width', 'petal_length', 'petal_width', 'class']
df = pd.read_csv(url, header=None, names=column_names)

# Display the first few rows of the dataset
print("Iris Dataset:")
print(df.head())

# Take a sample from the dataset
sample_df = df.sample(frac=0.1)  # Sample 10% of the data
print("\nSample of the Dataset:")
print(sample_df)

# Display maximum and minimum values of all numeric attributes
max_values = df.max(numeric_only=True)
min_values = df.min(numeric_only=True)

print("\nMaximum values of all numeric attributes:")
print(max_values)
print("\nMinimum values of all numeric attributes:")
print(min_values)

OUTPUT:-
Iris Dataset:
   sepal_length  sepal_width  petal_length  petal_width        class
0           5.1          3.5           1.4          0.2  Iris-setosa
1           4.9          3.0           1.4          0.2  Iris-setosa
2           4.7          3.2           1.3          0.2  Iris-setosa
3           4.6          3.1           1.5          0.2  Iris-setosa
4           5.0          3.6           1.4          0.2  Iris-setosa

Sample of the Dataset:
     sepal_length  sepal_width  petal_length  petal_width            class
49            5.0          3.3           1.4          0.2      Iris-setosa
83            6.0          2.7           5.1          1.6  Iris-versicolor
139           6.9          3.1           5.4          2.1   Iris-virginica
90            5.5          2.6           4.4          1.2  Iris-versicolor
95            5.7          3.0           4.2          1.2  Iris-versicolor
138           6.0          3.0           4.8          1.8   Iris-virginica
105           7.6          3.0           6.6          2.1   Iris-virginica
69            5.6          2.5           3.9          1.1  Iris-versicolor
28            5.2          3.4           1.4          0.2      Iris-setosa
107           7.3          2.9           6.3          1.8   Iris-virginica
42            4.4          3.2           1.3          0.2      Iris-setosa
82            5.8          2.7           3.9          1.2  Iris-versicolor
8             4.4          2.9           1.4          0.2      Iris-setosa
101           5.8          2.7           5.1          1.9   Iris-virginica
70            5.9          3.2           4.8          1.8  Iris-versicolor

Maximum values of all numeric attributes:
sepal_length    7.9
sepal_width     4.4
petal_length    6.9
petal_width     2.5
dtype: float64

Minimum values of all numeric attributes:
sepal_length    4.3
sepal_width     2.0
petal_length    1.0
petal_width     0.1
dtype: float64
​
