
import pandas as pd
from pandas_profiling import ProfileReport

# Load the CSV file into a DataFrame
df = pd.read_csv(r"C:\Users\amres\Downloads\archive\SOCR-HeightWeight.csv")

# Generate the profile report
profile = ProfileReport(df, title="Pandas Profiling Report", explorative=True)

# Save the report as an HTML file
profile.to_file("report.html")

print("Profile report saved as 'report.html'")
