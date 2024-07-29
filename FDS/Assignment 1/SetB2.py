import pandas as pd

# Load the dataset
file_path = r'C:\Users\amres\Downloads\archive\ds_salaries.csv'  # Use raw string to handle backslashes
df = pd.read_csv(file_path)

# Print the shape of the DataFrame
print("Shape of the DataFrame:")
print(df.shape)

# Print the size of the DataFrame
print("\nSize of the DataFrame:")
print(df.size)

# Print the datatypes of the DataFrame
print("\nDatatypes of the DataFrame:")
print(df.dtypes)

OUTPUT:-

Shape of the DataFrame:
(607, 12)

Size of the DataFrame:
7284

Datatypes of the DataFrame:
Unnamed: 0             int64
work_year              int64
experience_level      object
employment_type       object
job_title             object
salary                 int64
salary_currency       object
salary_in_usd          int64
employee_residence    object
remote_ratio           int64
company_location      object
company_size          object
dtype: object
