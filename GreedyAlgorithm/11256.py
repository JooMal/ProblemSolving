import heapq

T = int(input())
for _ in range(T) :
  J, N = map(int, input().split())
  box = []
  for i in range(N) :
    r, c = map(int, input().split())
    heapq.heappush(box, (-1)*(r*c))
  cnt=0
  while(J > 0 ) :
    J -= (-1)*heapq.heappop(box)
    cnt+=1
  print(cnt)
  
