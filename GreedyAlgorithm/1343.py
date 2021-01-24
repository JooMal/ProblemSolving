n = input()

i=0
while True :
  if i >= len(n) :
    break
  
  if n[i:i+4] == 'XXXX' :
    i=i+4
    n=n.replace('X','A',4)
  elif n[i:i+2] == 'XX' :
    i=i+2
    n=n.replace('X','B',2)
  elif n[i] == '.' :
    i=i+1
  else :
    n=-1
    break

print(n)
