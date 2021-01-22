import heapq

N, K = map(int, input().split())
jew = [list(map(int, input().split())) for _ in range(N)] # m, v
bag= [int(input()) for _ in range(K)]

jew = sorted(jew, key=lambda x : x[0])
bag.sort()

ans = 0

h = []
j_idx = 0
for b in bag :
    while(True) :
        if(j_idx >= N) :
            break
        j = jew[j_idx]
        if(j[0] <= b) :
            heapq.heappush(h, -j[1])
            j_idx+=1
        else :
            break
    if(h) : 
        ans -= heapq.heappop(h)
			
print(ans)
