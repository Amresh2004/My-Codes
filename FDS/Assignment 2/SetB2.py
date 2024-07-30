import pandas as pd
import matplotlib.pyplot as plt

# Read the CSV file
df = pd.read_csv("https://archive.ics.uci.edu/ml/machine-learning-databases/iris/iris.data", 
                 header=None, 
                 names=['sepal_length', 'sepal_width', 'petal_length', 'petal_width', 'class'])

# Find number of records for each distinct value of class attribute
class_counts = df['class'].value_counts()

print("Number of records for each distinct class:")
print(class_counts)

# Visualize the class distribution
plt.figure(figsize=(8, 6))
class_counts.plot(kind='bar')
plt.title('Number of Records for Each Distinct Class')
plt.xlabel('Class')
plt.ylabel('Count')
plt.tight_layout()
plt.show()

OUTPUT:-
Number of records for each distinct class:
class
Iris-setosa        50
Iris-versicolor    50
Iris-virginica     50
Name: count, dtype: int64
