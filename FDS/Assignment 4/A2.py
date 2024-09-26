import numpy as np
import matplotlib.pyplot as plt

# Generate random array of 50 integers
data = np.random.randint(1, 100, 50)

# Add outliers
data_with_outliers = np.append(data, [150, -50])

# Box Plot with Outliers
plt.figure(figsize=(8, 4))
plt.boxplot(data_with_outliers, patch_artist=True)
plt.title('Box Plot with Outliers')
plt.show()