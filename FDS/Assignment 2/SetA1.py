import numpy as np

# Original 2D array
array = np.array([[0, 1], [2, 3]])
print("Original flattened array:")
print(array)

# Flatten the array
flat_array = array.flatten()

# Find the maximum and minimum values
max_value = np.max(flat_array)
min_value = np.min(flat_array)

print("\nMaximum value of the above flattened array:")
print(max_value)
print("Minimum value of the above flattened array:")
print(min_value)
