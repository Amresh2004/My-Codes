import numpy as np

# Define the flattened array and weights
array = np.array([[0, 1, 2],
                  [3, 4, 5],
                  [6, 7, 8]])
weights = np.array([1, 1, 1])  # Example weights for the columns

# Compute the weighted average along axis 0 (columns)
weighted_average = np.average(array, axis=0, weights=weights)

print("Original flattened array:")
print(array)
print("\nWeighted average along the specified axis of the above flattened array:")
print(weighted_average)


OUTPUT:-
Original flattened array:
[[0 1 2]
 [3 4 5]
 [6 7 8]]

Weighted average along the specified axis of the above flattened array:
[3. 4. 5.]
