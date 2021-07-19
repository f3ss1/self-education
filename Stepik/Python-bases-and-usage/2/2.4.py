import pandas as pd

out_dict = {}

for i in range(1, 1001):
    path = 'rogaikopyta/' + str(i) + '.xlsx'
    df = pd.read_excel(path)
    ns = df['Unnamed: 1'][0]
    salary = int(df['Unnamed: 3'][0])
    if ns in out_dict:
        out_dict[ns] += salary
    else:
        out_dict[ns] = salary
for person in sorted(out_dict):
    print(person, out_dict[person])
