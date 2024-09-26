import seaborn as sns
import matplotlib.pyplot as plt

# Load the iris dataset
iris = sns.load_dataset('iris')

# Scatter plot for Sepal Length vs Sepal Width
sns.scatterplot(x='sepal_length', y='sepal_width', data=iris)

# Display the plot
plt.title("Sepal Length vs Sepal Width")
plt.show()

# Scatter plot for Petal Length vs Petal Width
sns.scatterplot(x='petal_length', y='petal_width', data=iris)

# Display the plot
plt.title("Petal Length vs Petal Width")
plt.show()