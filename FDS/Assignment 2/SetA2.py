import numpy as np

# Define two data points
point1 = np.array([1, 2, 3])
point2 = np.array([4, 5, 6])

# Compute Euclidean distance
distance = np.linalg.norm(point1 - point2)

print(f"The Euclidean distance between {point1} and {point2} is {distance}")

OUTPUT:-

The Euclidean distance between [1 2 3] and [4 5 6] is 5.196152422706632
