import pandas as pd 
import numpy as np 
import matplotlib.pyplot as plt

df = pd.read_csv('/home/supr3me/Downloads/prima_indians_diabetes.csv',header=None)
# print(df.head())
# print(df.tail())
df.columns = ['preg','glu','bp','stf','ins','bmi','dpf','age','class']
plt.scatter(df['bmi'],df['glu'])
plt.xlabel('bmi')
plt.ylabel('Glucose')
df.plot()
