import pandas as pd
import numpy as np

url = 'https://stepik.org/media/attachments/lesson/245290/trekking3.xlsx'
xlsx = pd.ExcelFile(url)

df_1 = pd.read_excel(xlsx, 'Справочник', index_col=0)
df_1.fillna(0, inplace=True)
df_2 = pd.read_excel(xlsx, 'Раскладка', index_col='Продукт')
#print(df_2)

for i in range(1, 10):
    output = np.zeros(4)
    for index in set(df_2.loc[df_2['День'] == i].index.values):
        output += (df_1.loc[index].values * df_2.loc[df_2['День'] == i].loc[index]['Вес в граммах'].sum() / 100)
    print(np.array(np.floor(output), dtype=np.int))

