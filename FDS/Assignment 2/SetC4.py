import pandas as pd

# URL of the dataset (Iris dataset in this example)
url = 'https://archive.ics.uci.edu/ml/machine-learning-databases/iris/iris.data'

# Define column names
columns = ['sepal_length', 'sepal_width', 'petal_length', 'petal_width', 'class']

# Read the CSV file into a DataFrame
df = pd.read_csv(url, header=None, names=columns)

# Describe the dataset
print("Dataset Description:")
print(df.describe(include='all'))

# Compute the mean value of numeric attributes
print("\nMean values of numeric attributes:")
print(df.mean())

# Check for missing values
print("\nMissing values in each column:")
print(df.isnull().sum())

OUTPUT:-

Dataset Description:
        sepal_length  sepal_width  petal_length  petal_width        class
count     150.000000   150.000000    150.000000   150.000000          150
unique           NaN          NaN           NaN          NaN            3
top              NaN          NaN           NaN          NaN  Iris-setosa
freq             NaN          NaN           NaN          NaN           50
mean        5.843333     3.054000      3.758667     1.198667          NaN
std         0.828066     0.433594      1.764420     0.763161          NaN
min         4.300000     2.000000      1.000000     0.100000          NaN
25%         5.100000     2.800000      1.600000     0.300000          NaN
50%         5.800000     3.000000      4.350000     1.300000          NaN
75%         6.400000     3.300000      5.100000     1.800000          NaN
max         7.900000     4.400000      6.900000     2.500000          NaN

Mean values of numeric attributes:
