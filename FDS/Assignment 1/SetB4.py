import pandas as pd

# Load the dataset
file_path = r'C:\Users\amres\Downloads\archive\ds_salaries.csv'  # Use raw string to handle backslashes
df = pd.read_csv(file_path)

# Get the number of observations
num_observations = df.shape[0]
print(f"Number of observations: {num_observations}")

# Get the number of missing values per column
missing_values = df.isnull().sum()
print("\nNumber of missing values per column:")
print(missing_values)

# Get the number of NaN values per column
nan_values = df.isna().sum()
print("\nNumber of NaN values per column:")
print(nan_values)

OUTPUT:-

Number of observations: 607

Number of missing values per column:
Unnamed: 0            0
work_year             0
experience_level      0
employment_type       0
job_title             0
salary                0
salary_currency       0
salary_in_usd         0
employee_residence    0
remote_ratio          0
company_location      0
company_size          0
dtype: int64

Number of NaN values per column:
Unnamed: 0            0
work_year             0
experience_level      0
employment_type       0
job_title             0
salary                0
salary_currency       0
salary_in_usd         0
employee_residence    0
remote_ratio          0
company_location      0
company_size          0
dtype: int64
