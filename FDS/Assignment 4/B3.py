import seaborn as sns
import matplotlib.pyplot as plt

# Load the iris dataset
iris = sns.load_dataset('iris')

# Box plot for Sepal Length
sns.boxplot(x='species', y='sepal_length', data=iris)
plt.title("Sepal Length Distribution Across Species")
plt.show()

# Box plot for Sepal Width
sns.boxplot(x='species', y='sepal_width', data=iris)
plt.title("Sepal Width Distribution Across Species")
plt.show()

# Box plot for Petal Length
sns.boxplot(x='species', y='petal_length', data=iris)
plt.title("Petal Length Distribution Across Species")
plt.show()

# Box plot for Petal Width
sns.boxplot(x='species', y='petal_width', data=iris)
plt.title("Petal Width Distribution Across Species")
plt.show()