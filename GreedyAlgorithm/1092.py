def _1092() :
  n = int(input())
  cw = list(map(int, input().split()))
  m = int(input())
  boxs = list(map(int, input().split()))

  cw.sort(reverse=True)
  boxs.sort(reverse=True)
  if(cw[0] < boxs[0]): return -1
  
  time=0
  while boxs :
    time += 1
    for c in cw :
      for i in range(len(boxs)) :
        if ( c >= boxs[i] ) :
          del boxs[i]
          break
  
  return time

print(_1092())

# 박스를 순회하면서 크레인이 들 수 있는 건 든다.
# 더이상 박스가 없으면 종료
