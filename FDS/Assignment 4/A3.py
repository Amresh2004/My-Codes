import numpy as np
import matplotlib.pyplot as plt

# Lists representing subject names and marks
subjects = ['Math', 'English', 'Science', 'History', 'Art']
marks = [85, 78, 92, 65, 89]

# Pie Chart
plt.figure(figsize=(6, 6))
plt.pie(marks, labels=subjects, autopct='%1.1f%%', startangle=90)
plt.title('Pie Chart of Marks in Subjects')
plt.show()

# Bar Chart
plt.figure(figsize=(8, 4))
plt.bar(subjects, marks, color='cyan')
plt.title('Bar Chart of Marks in Subjects')
plt.xlabel('Subjects')
plt.ylabel('Marks')
plt.show()