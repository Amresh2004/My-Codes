import numpy as np
import matplotlib.pyplot as plt
import seaborn as sns

# Load the Iris dataset
iris = sns.load_dataset('iris')

# Bar plot of species frequency
plt.figure(figsize=(8, 4))
sns.countplot(x='species', data=iris, palette='pastel')
plt.title('Bar Plot of Iris Species Frequency')
plt.xlabel('Species')
plt.ylabel('Count')
plt.show()