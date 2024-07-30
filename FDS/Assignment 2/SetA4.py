import numpy as np
from itertools import combinations

# Example dataset of points
points = np.array([[1, 2], [3, 4], [5, 6]])

# Compute the sum of Manhattan distances between all pairs of points
sum_manhattan_distance = sum(
    np.sum(np.abs(p1 - p2)) for p1, p2 in combinations(points, 2)
)

print(f"The sum of Manhattan distances between all pairs of points is {sum_manhattan_distance}")

OUTPUT:-
The sum of Manhattan distances between all pairs of points is 16
