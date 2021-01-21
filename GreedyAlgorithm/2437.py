n = int(input())
arr = list(map(int, input().split()))
arr.sort()
if(arr[0] != 1) :
	print(1)
else :
	sum = 1
	for i in range(1,n) :
		if(sum+1 < arr[i]) :
			break
		else :
			sum += arr[i]
	print(sum+1)
