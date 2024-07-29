import pandas as pd

# Load the dataset
url = r'C:\Users\amres\Downloads\archive\ds_salaries.csv'  # Use raw string to handle backslashes
df = pd.read_csv(url)

# Print the shape of the DataFrame
print("Shape of the DataFrame:")
print(df.shape)

# Print the size of the DataFrame
print("\nSize of the DataFrame:")
print(df.size)

# Print the datatypes of the DataFrame
print("\nDatatypes of the DataFrame:")
print(df.dtypes)

# Print the first 10 rows
print("\nFirst 10 rows:")
print(df.head(10))

# Print the last 10 rows
print("\nLast 10 rows:")
print(df.tail(10))

# Print 20 random rows
print("\nRandom 20 rows:")
print(df.sample(20))


OUTPUT:-

# Shape of the DataFrame:
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

First 10 rows:
   Unnamed: 0  work_year experience_level employment_type  \
0           0       2020               MI              FT   
1           1       2020               SE              FT   
2           2       2020               SE              FT   
3           3       2020               MI              FT   
4           4       2020               SE              FT   
5           5       2020               EN              FT   
6           6       2020               SE              FT   
7           7       2020               MI              FT   
8           8       2020               MI              FT   
9           9       2020               SE              FT   

                    job_title    salary salary_currency  salary_in_usd  \
0              Data Scientist     70000             EUR          79833   
1  Machine Learning Scientist    260000             USD         260000   
2           Big Data Engineer     85000             GBP         109024   
3        Product Data Analyst     20000             USD          20000   
4   Machine Learning Engineer    150000             USD         150000   
5                Data Analyst     72000             USD          72000   
6         Lead Data Scientist    190000             USD         190000   
7              Data Scientist  11000000             HUF          35735   
8       Business Data Analyst    135000             USD         135000   
9          Lead Data Engineer    125000             USD         125000   

  employee_residence  remote_ratio company_location company_size  
0                 DE             0               DE            L  
1                 JP             0               JP            S  
2                 GB            50               GB            M  
3                 HN             0               HN            S  
4                 US            50               US            L  
5                 US           100               US            L  
6                 US           100               US            S  
7                 HU            50               HU            L  
8                 US           100               US            L  
9                 NZ            50               NZ            S  

Last 10 rows:
     Unnamed: 0  work_year experience_level employment_type       job_title  \
597         597       2022               SE              FT    Data Analyst   
598         598       2022               MI              FT  Data Scientist   
599         599       2022               MI              FT  Data Scientist   
600         600       2022               EN              FT    Data Analyst   
601         601       2022               EN              FT    Data Analyst   
602         602       2022               SE              FT   Data Engineer   
603         603       2022               SE              FT   Data Engineer   
604         604       2022               SE              FT    Data Analyst   
605         605       2022               SE              FT    Data Analyst   
606         606       2022               MI              FT    AI Scientist   

     salary salary_currency  salary_in_usd employee_residence  remote_ratio  \
597  170000             USD         170000                 US           100   
598  160000             USD         160000                 US           100   
599  130000             USD         130000                 US           100   
600   67000             USD          67000                 CA             0   
601   52000             USD          52000                 CA             0   
602  154000             USD         154000                 US           100   
603  126000             USD         126000                 US           100   
604  129000             USD         129000                 US             0   
605  150000             USD         150000                 US           100   
606  200000             USD         200000                 IN           100   

    company_location company_size  
597               US            M  
598               US            M  
599               US            M  
600               CA            M  
601               CA            M  
602               US            M  
603               US            M  
604               US            M  
605               US            M  
606               US            L  

Random 20 rows:
     Unnamed: 0  work_year experience_level employment_type  \
165         165       2021               SE              FT   
86           86       2021               EN              FT   
492         492       2022               MI              FT   
191         191       2021               EN              FT   
77           77       2021               MI              PT   
470         470       2022               MI              FT   
139         139       2021               EN              FT   
258         258       2021               SE              FT   
595         595       2022               SE              FT   
546         546       2022               SE              FT   
70           70       2020               MI              FT   
166         166       2021               EN              FT   
313         313       2022               MI              FT   
335         335       2022               SE              FT   
292         292       2022               MI              FT   
125         125       2021               MI              FT   
207         207       2021               SE              FT   
112         112       2021               SE              FT   
188         188       2021               SE              FT   
504         504       2022               SE              FT   

                         job_title  salary salary_currency  salary_in_usd  \
165                Data Specialist  165000             USD         165000   
86                    Data Analyst   50000             EUR          59102   
492                 Data Scientist  150000             PLN          35590   
191      Machine Learning Engineer   21844             USD          21844   
77   3D Computer Vision Researcher  400000             INR           5409   
470                   Data Analyst  135000             USD         135000   
139                 Data Scientist   80000             USD          80000   
258      Machine Learning Engineer  185000             USD         185000   
595         Data Analytics Manager  109280             USD         109280   
546                  Data Engineer  110500             USD         110500   
70                  Data Scientist   55000             EUR          62726   
166                  Data Engineer   80000             USD          80000   
313                  Data Engineer   60000             GBP          78526   
335                  Data Engineer  132320             USD         132320   
292                 Data Scientist  130000             USD         130000   
125       Principal Data Scientist  151000             USD         151000   
207                  Data Engineer  165000             USD         165000   
112             Lead Data Engineer   75000             GBP         103160   
188                  Data Engineer   65000             EUR          76833   
504                  Data Engineer  115000             USD         115000   

    employee_residence  remote_ratio company_location company_size  
165                 US           100               US            L  
86                  FR            50               FR            M  
492                 PL           100               PL            L  
191                 CO            50               CO            M  
77                  IN            50               IN            M  
470                 US           100               US            M  
139                 US           100               US            M  
258                 US            50               US            L  
595                 US           100               US            M  
546                 US           100               US            M  
70                  FR            50               LU            S  
166                 US           100               US            L  
313                 GB             0               GB            M  
335                 US           100               US            M  
292                 US             0               US            M  
125                 US           100               US            L  
207                 US             0               US            M  
112                 GB           100               GB            S  
188                 RO            50               GB            S  
504                 US           100               US            M #
