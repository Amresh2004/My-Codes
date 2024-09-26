import seaborn as sns
import matplotlib.pyplot as plt

# Load the iris dataset
iris = sns.load_dataset('iris')

# Create box plots for each feature and species
for feature in iris.columns[:-1]:
    sns.boxplot(x='species', y=feature, data=iris)
    plt.title(f'Boxplot for {feature}')
    plt.show()