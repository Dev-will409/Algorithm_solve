def solution(k, m, score):
    answer = 0
    
    s = sorted(score, reverse = True)
    
    for i in range(len(s)):
        if(i % m == m-1):
            answer += (m*s[i])
        
    
    return answer