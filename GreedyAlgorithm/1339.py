#!/usr/bin/env python
# coding: utf-8

# In[11]:


# 단어수학

n = int(input())
word = [list(map(lambda x: ord(x)-65, input().rstrip())) for _ in range(n)]
alpha = [0]*26

for i in range(n) :
    j = 0
    for w in word[i][::-1] :
        alpha[w] += 10 ** j
        j += 1

alpha.sort(reverse=True)
n = 9
res = 0
for a in alpha :
    res += (a*n)
    n-=1
    
print(res)


# In[2]:


print(word)


# In[4]:


map(lambda x: ord(x)-65, input().rstrip())


# In[ ]:




