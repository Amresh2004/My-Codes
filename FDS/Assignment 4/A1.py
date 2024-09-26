import numpy as np
import matplotlib.pyplot as plt

# Generate random array of 50 integers
data = np.random.randint(1, 100, 50)

# Line Chart
plt.figure(figsize=(8, 4))
plt.plot(data, color='blue', marker='o', linestyle='-', label='Random Data')
plt.title('Line Chart of Random Integers')
plt.xlabel('Index')
plt.ylabel('Value')
plt.legend()
plt.show()

# Scatter Plot
plt.figure(figsize=(8, 4))
plt.scatter(range(len(data)), data, color='green', label='Random Data')
plt.title('Scatter Plot of Random Integers')
plt.xlabel('Index')
plt.ylabel('Value')
plt.legend()
plt.show()

# Histogram
plt.figure(figsize=(8, 4))
plt.hist(data, bins=10, color='purple')
plt.title('Histogram of Random Integers')
plt.xlabel('Value')
plt.ylabel('Frequency')
plt.show()

# Box Plot
plt.figure(figsize=(8, 4))
plt.boxplot(data, patch_artist=True)
plt.title('Box Plot of Random Integers')
plt.show()