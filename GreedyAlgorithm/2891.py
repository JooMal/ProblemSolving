N, S, R = map(int, input().split())
broken = []
have = []
if(S > 0) : broken = list(map(int, input().split()))
if(R > 0) : have = list(map(int, input().split()))

arr = [1]*N
for i in broken :
  arr[i-1] = 0
for i in have :
  t = i-1
  if(arr[t]==0) : arr[t]=1
  else :
    if(t-1 >= 0 and arr[t-1]==0) :
      arr[t-1] = 1
      continue
    elif(t+1 < N and arr[t+1]==0) :
      arr[t+1] = 1
  
ans = 0
for team in arr :
  if(team == 0) :
    ans += 1

print(ans)
