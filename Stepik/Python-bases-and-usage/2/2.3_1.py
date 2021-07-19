import pandas as pd

url = 'https://stepik.org/media/attachments/lesson/245290/trekking1.xlsx'
df = pd.read_excel(url, index_col=0)
df.fillna(0, inplace=True)
o_list = df.sort_values(by='ККал на 100', axis=0, ascending=False).index.values
for item in o_list:
    print(item)
