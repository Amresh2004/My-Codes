import matplotlib.pyplot as plt

# Sample data
heights = [150, 160, 170, 180, 190]
weights = [50, 60, 70, 80, 90]

# Create scatter plot
plt.scatter(heights, weights, color='blue', marker='o')

# Add labels and title
plt.xlabel('Height (cm)')
plt.ylabel('Weight (kg)')
plt.title('Height vs Weight Scatter Plot')

# Display the plot
plt.grid(True)
plt.show()

OUTPUT:-

