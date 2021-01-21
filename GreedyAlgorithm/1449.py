n, l = map(int, input().split())
arr = list(map(int, input().split()))
arr.sort()

tapeL = 0 # 이어지는 구멍들을 메우기 위해 지금까지 사용한 테이프의 길이
ans = 1 # 사용한 테이프의 갯수

for i in range(1,n) :
  recL = arr[i]-arr[i-1]
  tapeL += recL
  if(tapeL >= l) :
    ans += 1
    tapeL = 0
print(ans)
