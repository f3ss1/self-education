import pandas as pd
import numpy as np

url = 'https://stepik.org/media/attachments/lesson/245290/trekking2.xlsx'
xlsx = pd.ExcelFile(url)

df_1 = pd.read_excel(xlsx, 'Справочник', index_col=0)
df_1.fillna(0, inplace=True)
df_2 = pd.read_excel(xlsx, 'Раскладка', index_col='Продукт')

output = np.zeros(4)

for index in set(df_2.index.values):
    output += (df_1.loc[index].values * df_2.loc[index].values.flatten().sum() / 100)
    print(df_2.loc[index].values.flatten().sum())
    print(index)
print(np.floor(output))
