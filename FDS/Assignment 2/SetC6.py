import pandas as pd
import numpy as np
from scipy.stats import hmean, gmean

# Create a DataFrame with 5 subjects and marks for 10 students
data = {
    'Subject1': [85, 90, 78, 92, 88, 76, 95, 89, 84, 91],
    'Subject2': [78, 83, 80, 85, 82, 77, 88, 81, 79, 86],
    'Subject3': [88, 85, 91, 89, 87, 90, 92, 84, 88, 86],
    'Subject4': [92, 88, 84, 90, 86, 91, 89, 87, 85, 93],
    'Subject5': [79, 81, 77, 83, 80, 82, 78, 84, 79, 85]
}

df = pd.DataFrame(data)

# Compute the arithmetic mean for each subject
arithmetic_mean = df.mean()

# Compute the geometric mean for each subject
geometric_mean = df.apply(lambda x: gmean(x[x > 0]))

# Compute the harmonic mean for each subject
harmonic_mean = df.apply(lambda x: hmean(x[x > 0]))

# Display the results
print("Arithmetic Mean:")
print(arithmetic_mean)
print("\nGeometric Mean:")
print(geometric_mean)
print("\nHarmonic Mean:")
print(harmonic_mean)


OUTPUT:-
Arithmetic Mean:
Subject1    86.8
Subject2    81.9
Subject3    88.0
Subject4    88.5
Subject5    80.8
dtype: float64

Geometric Mean:
Subject1    86.601904
Subject2    81.829132
Subject3    87.965890
Subject4    88.453358
Subject5    80.760773
dtype: float64

Harmonic Mean:
Subject1    86.397963
Subject2    81.758797
Subject3    87.931767
Subject4    88.406703
Subject5    80.721689
dtype: float64
