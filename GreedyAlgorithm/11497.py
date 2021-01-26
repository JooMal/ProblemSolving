# 11497
import sys
input = sys.stdin.readline

t = int(input())
for _ in range(t) :
	n = int(input())
	arr = list(map(int, input().split()))
	arr.sort()
	arr1 = arr[::2]
	if(len(arr)%2==1) : arr2 = arr[-2:0:-2]
	else : arr2 = arr[-1:0:-2]
	ans = arr1 + arr2
	tmp = 0
	for i in range(len(ans)-1) :
		tmp = max(tmp,abs(ans[i]-ans[i+1]))
	print(tmp)
