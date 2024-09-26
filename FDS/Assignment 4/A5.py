import numpy as np
import matplotlib.pyplot as plt
import seaborn as sns

# Load the Iris dataset
iris = sns.load_dataset('iris')

# Pie chart of species frequency
species_counts = iris['species'].value_counts()

plt.figure(figsize=(6, 6))
plt.pie(species_counts, labels=species_counts.index, autopct='%1.1f%%', startangle=90)
plt.title('Pie Chart of Iris Species Frequency')
plt.show()