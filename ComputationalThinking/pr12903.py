def solution(s):
    answer = ''
    
    L = len(s)
    if(L%2 == 0) :
        idx = int(L/2)-1
        answer = s[idx:idx+2]
    else :
        idx = int(L/2)
        answer = s[idx]
    return answer
