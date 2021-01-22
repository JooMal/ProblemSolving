S = input()
ans = ""
N0 = 0
N1 = 0

for i in range(1, len(S)) :
  if(S[i-1] != S[i]) :
    ans += S[i-1]
    if(S[i-1] == "0") : N0+=1
    else : N1+=1
if(ans and (S[len(S)-1] != ans[len(ans)-1])) : 
  ans+=S[len(S)-1]
  if(S[len(S)-1] == "0") : N0+=1
  else : N1+=1

print(min(N0,N1))
