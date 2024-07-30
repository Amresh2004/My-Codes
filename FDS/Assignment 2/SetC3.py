import numpy as np

def cross_correlation_1d(a, b):
    """
    Compute the cross-correlation of two 1-dimensional arrays.
    
    Parameters:
    a (numpy array): The first array.
    b (numpy array): The second array.
    
    Returns:
    numpy array: The cross-correlation of the arrays.
    """
    return np.correlate(a, b, mode='full')

# Define the arrays
array1 = np.array([0, 1, 3])
array2 = np.array([2, 4, 5])

# Compute the cross-correlation
cross_corr = cross_correlation_1d(array1, array2)

print("Original array1:")
print(array1)
print("\nOriginal array2:")
print(array2)
print("\nCross-correlation of the said arrays:")
print(cross_corr)

OUTPUT:-

Original array1:
[0 1 3]

Original array2:
[2 4 5]

Cross-correlation of the said arrays:
[ 0  5 19 14  6]
