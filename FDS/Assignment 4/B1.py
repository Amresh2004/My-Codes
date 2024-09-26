import seaborn as sns
import matplotlib.pyplot as plt

# Load the iris dataset
iris = sns.load_dataset('iris')

# Create scatter plot for petal length vs petal width
sns.scatterplot(x='petal_length', y='petal_width', data=iris)

# Display the plot
plt.title("Petal Length vs Petal Width")
plt.show()