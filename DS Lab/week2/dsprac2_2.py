import pandas as pd 
import numpy as np 
import matplotlib.pyplot as plt

df = pd.read_csv('/home/supr3me/Downloads/prima_indians_diabetes.csv',header=None)
print(df.head())
print(df.tail())
df.columns = ['preg','glu','bp','stf','ins','bmi','dpf','age','class']
plt.scatter(df['bmi'],df['glu'])
plt.xlabel('bmi')
plt.ylabel('Glucose')
df.plot()

###################################################################

W = pd.read_csv('xyz.xls',header=None)
W.head()
D = np.loadtxt('xyz.data',delimiter=",")
D[:5,:]

###################################################################

G = pd.read_excel('xyz.xlsx',sheet_name = 'Sheet1')
G.head()

##################################################################

B = pd.read_html("http://www.fdic.gov/bank/individual/failed/b anklist.html")
B.head()

##################################################################

H = pd.read_table("HR.txt")
H.head()
f = H['Department'].value_counts()
print(f)
f.plot(kind='bar')
f.plot(kind='pie')
fa = pd.crosstab(H['Gender'],H['Attrition'])
fa.plot(kind='bar')
