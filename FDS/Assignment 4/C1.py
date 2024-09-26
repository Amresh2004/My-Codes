import seaborn as sns
import matplotlib.pyplot as plt

# Load the iris dataset
iris = sns.load_dataset('iris')

# Create a pairplot
sns.pairplot(iris, hue='species')

# Show the plot
plt.show()