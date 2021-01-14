#!/usr/bin/env python
# coding: utf-8

# In[6]:


n = 1
while (True) :
    L, P, V = map(int, input().split(' '))
    if(L == 0 and P == 0 and V == 0) :
        break
    
    r = V//P
    d = min(L, V%P) # V%P이 L보다 큰 경우가 발생할 수 있으므로
    res = r*L+d
    print("Case {}: {}".format(n, res))
    n+=1


# In[ ]:




