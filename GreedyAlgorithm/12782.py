T = int(input())
for _ in range(T) :
  a, b = input().split()
  N0 = 0
  N1 = 0
  for i in range(len(a)) :
    #print(a[i], b[i])
    if(a[i] != b[i] and b[i] == '1') :
      N1 += 1
    elif (a[i] != b[i] and b[i] == '0') :
      N0 += 1
  print(min(N1,N0)+abs(N1-N0))
