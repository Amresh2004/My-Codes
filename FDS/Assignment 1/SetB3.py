import pandas as pd

# Load the dataset
file_path = r'C:\Users\amres\Downloads\archive\ds_salaries.csv'  # Use raw string to handle backslashes
df = pd.read_csv(file_path)

# Print basic statistical details of the data
print("Basic statistical details of the data:")
print(df.describe())

OUTPUT:-

Basic statistical details of the data:
       Unnamed: 0    work_year        salary  salary_in_usd  remote_ratio
count  607.000000   607.000000  6.070000e+02     607.000000     607.00000
mean   303.000000  2021.405272  3.240001e+05  112297.869852      70.92257
std    175.370085     0.692133  1.544357e+06   70957.259411      40.70913
min      0.000000  2020.000000  4.000000e+03    2859.000000       0.00000
25%    151.500000  2021.000000  7.000000e+04   62726.000000      50.00000
50%    303.000000  2022.000000  1.150000e+05  101570.000000     100.00000
75%    454.500000  2022.000000  1.650000e+05  150000.000000     100.00000
max    606.000000  2022.000000  3.040000e+07  600000.000000     100.00000
