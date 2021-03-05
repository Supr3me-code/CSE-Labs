import pandas as pd 
import numpy as np

s = pd.Series([3,9,-2,10,5])
print(s.sum())
print(s.min())
print(s.max())
# --------------------Creating a Data Frame
data =  [['Dinesh',10],['Nithya',12],['Raji',13]]
df = pd.DataFrame(data,columns=['Name','Age'])
print(df)
# --------------------Indexed Data Frame
data = [['Dinesh',10],['Nithya',12],['Raji',13]]
df = pd.DataFrame(data,columns=['Name','Age'])
print(df)
# --------------------Creating Data Frame using Dictionary
df1 = pd.DataFrame({'A':pd.Timestamp('20130102'),'B':np.array([3]*4,dtype='int32'),'C':pd.Categorical(['Male','Female','Male','Female'])})
print(df1)
print(df1.shape)
print(df1.dtypes)
print(df1.head())
print(df1.tail())
# df1.summary() //ERROR
print(df1.T)
# ---------------------------------------------------------------
dates = pd.date_range('20130101',periods=100)
df = pd.DataFrame(np.random.randn(100,4),index=dates,columns=list('ABCD'))
df.head()
df.tail()
print(df.index)
print(df.columns)
print(df.T)
df.sort_index(axis=1,ascending=False)
df.sort_values(by='B')
print(df[0:3])
print(df['20130105':'20130110'])
print(df.iloc[0])
print(df.iloc[0,:2])
print(df.iloc[0,0])
print(df['A'])
print(df[['A','B']])
print(df[['A','B']][:5])
# -------------------------------Boolean Indexing
print(df[df.A>0])
df['F'] = ['Male','Female','Female','Male','Female','Female']
df.loc[:,'D'] = np.array([5]*len(df))
# -------------------------------Deleting a row or column
df.drop('col_name'axis=1,inplace=True)
df.drop('row_index',axis=0,inplace=True)
# -------------------------------Concatenation of two Data Frames
Df_new = pd.concat(df1,df,axis=1)
print(Df_new.shape)
D = pd.concat(A,B,axis=0)
print(D.shape)
# -------------------------------Sorting
A.sort_values(by='Age')