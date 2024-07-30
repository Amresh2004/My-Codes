import pandas as pd

url = 'https://archive.ics.uci.edu/ml/machine-learning-databases/nursery/nursery.data'

columns = ['parents', 'has_nurs', 'form', 'children', 'housing', 'finance', 'social', 'health', 'class']

df = pd.read_csv(url, header=None, names=columns)

print("First few rows of the dataset:")
print(df.head())

split_attribute = 'parents'

grouped = df.groupby(split_attribute)

means = grouped.mean(numeric_only=True)
print(f"\nComparing means based on the '{split_attribute}' attribute:")
print(means)

OUTPUT:-
First few rows of the dataset:
  parents has_nurs      form children     housing     finance         social  \
0   usual   proper  complete        1  convenient  convenient        nonprob   
1   usual   proper  complete        1  convenient  convenient        nonprob   
2   usual   proper  complete        1  convenient  convenient        nonprob   
3   usual   proper  complete        1  convenient  convenient  slightly_prob   
4   usual   proper  complete        1  convenient  convenient  slightly_prob   

        health      class  
0  recommended  recommend  
1     priority   priority  
2    not_recom  not_recom  
3  recommended  recommend  
4     priority   priority  

Comparing means based on the 'parents' attribute:
Empty DataFrame
Columns: []
Index: [great_pret, pretentious, usual]
