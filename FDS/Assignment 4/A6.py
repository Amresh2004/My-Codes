import numpy as np
import matplotlib.pyplot as plt
import seaborn as sns

# Load the Iris dataset
iris = sns.load_dataset('iris')

# Histogram of species sepal lengths for each species
plt.figure(figsize=(8, 4))
sns.histplot(data=iris, x='sepal_length', hue='species', element='step', stat='density', common_norm=False)
plt.title('Histogram of Sepal Length by Species')
plt.xlabel('Sepal Length')
plt.ylabel('Density')
plt.show()