import pandas as pd

url = 'https://stepik.org/media/attachments/lesson/245267/salaries.xlsx'
df = pd.read_excel(url, index_col=0)
print(df.median(axis=1).idxmax(), df.mean(axis=0).idxmax())
