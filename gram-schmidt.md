# 1.gram-schmidt Algorithm


```python
import numpy as np
from numpy import linalg as LA  #ユークリッドノルム
import random
```


```python
def gram(a,b):
    return ((np.dot(a,b)/np.dot(a,a))*a)
```

　　ベクトル
  
$$[3,2,1]^{T},[2,1,3]^{T},[1,3,2]^{T}$$

　　に対して、


```python
#直交ベクトル
a=np.array([3,2,1])
b=np.array([2,1,3])
c=np.array([1,3,2])
```

$$u_{1}=v_{1},\\u_{2}=v_{2}-proj_{u1}(v_{2}),\\u_{2}=v_{3}-proj_{u1}(v_{3})-proj_{u2}(v_{3}),\\.....\\u_{k}=v_{k}-\sum_{j=1}^{k-1}proj_{uj}(v_{k}),$$


```python
Va=a
Vb=b-gram(Va,b)
Vc=c-gram(Va,c)-gram(Vb,c)
print(Va,Vb,Vc)
print(np.dot(Va,Vb))
#直交ベクトル
```

    [3 2 1] [-0.35714286 -0.57142857  2.21428571] [-1.2   1.68  0.24]
    0.0
    

$$e_{1}=\frac{u_{1}}{||u_{1}||},\\e_{2}=\frac{u_{2}}{||u_{2}||},\\......\\e_{k}=\frac{u_{k}}{||u_{k}||},$$


```python
#絶対値
Ea=Va/LA.norm(Va,2)
Eb=Vb/LA.norm(Vb,2)
Ec=Vc/LA.norm(Vc,2)
print(Ea,Eb,Ec)
#絶対値
```

    [0.80178373 0.53452248 0.26726124] [-0.15430335 -0.24688536  0.95668077] [-0.57735027  0.80829038  0.11547005]
    

# 2.gram-schmidt Algorithm of random array

 ランダムに得られるベクトルに対してグラムシュミット化を行うアルゴリズム


```python
import numpy as np
from numpy import linalg as LA


dimension=3   #次元を指定する

def randomnumber(dimension):
    return np.random.random((dimension,dimension))

def gram(a,b):
    return ((np.dot(a,b)/np.dot(a,a))*a)

v=randomnumber(dimension)

u=np.zeros((dimension,dimension),dtype='float64')
u[0]=v[0]

x=0
sum=np.array([0,0,0],dtype='float64')

for a in range(1,dimension):
    for b in range(0,a):
        sum+=gram(u[b],v[a])
    u[a]=v[a]-sum
    
print(v)
print(u)
```

    [[0.83445609 0.45693121 0.98506537]
     [0.02304313 0.66054993 0.26186155]
     [0.82916256 0.93444297 0.9156036 ]]
    [[ 0.83445609  0.45693121  0.98506537]
     [-0.2345764   0.5194827  -0.04225522]
     [-0.14645925 -0.10007795 -0.41729469]]
    


```python
e=np.zeros((dimension,dimension),dtype='float64')

for c in range(0,dimension):
    e[c]=u[c]/LA.norm(u[c],2)
    
print(e)
```

    [[ 0.60932633  0.33365472  0.7193024 ]
     [-0.41041869  0.90889537 -0.07393041]
     [-0.32300143 -0.22071204 -0.92030227]]
    


```python
print(LA.norm(e[0],2))#ノルム
```

    0.9999999999999999
    


```python
print(LA.norm(e[1],2))
```

    1.0
    
