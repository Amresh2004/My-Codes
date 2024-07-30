import numpy as np

def minkowski_distance(p, q, k):
    """
    Compute the Minkowski distance between two points.
    
    Parameters:
    p (list or numpy array): The first point.
    q (list or numpy array): The second point.
    k (float): The order of the norm.
    
    Returns:
    float: The Minkowski distance between p and q.
    """
    p = np.array(p)
    q = np.array(q)
    
    # Compute the Minkowski distance
    distance = np.sum(np.abs(p - q) ** k) ** (1 / k)
    return distance

# Example usage
p = [1, 2, 3]
q = [4, 5, 6]
k = 3  # Change k to compute different types of Minkowski distances

distance = minkowski_distance(p, q, k)
print(f"The Minkowski distance between {p} and {q} with k={k} is {distance:.2f}")

OUTPUT:-
The Minkowski distance between [1, 2, 3] and [4, 5, 6] with k=3 is 4.33
