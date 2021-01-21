import sys
input = sys.stdin.readline

t = int(input())
for _ in range(t) :
	n = int(input())
	arr = [0]*(n+1)
	for _ in range(n) :
		a, b = map(int, input().split(' '))
		arr[a] = b
	min_score = arr[1]
	cnt = 0
	for i in range(2, n+1):
		if (arr[i] > min_score) :
			cnt += 1
		else :
			min_score = arr[i]
	print(n - cnt)
