import seaborn as sns
import matplotlib.pyplot as plt

# Load the iris dataset
iris = sns.load_dataset('iris')

# Create a joint plot with 'kde'
sns.jointplot(x='sepal_length', y='sepal_width', data=iris, kind='kde')

# Show the plot
plt.show()