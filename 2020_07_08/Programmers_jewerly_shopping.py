def solution(gems):
    cnt = len(set(gems))
    d = {}
    answer = [1, len(gems)]
    change = False
    k = gems[0]
    for i in range(len(gems)):
        if gems[i] == k: change = True
        if gems[i] not in d:
            d[gems[i]] = i
        else: d[gems[i]] = i
        if len(d) == cnt:
            if change:
                k = min(d.keys(), key = lambda a : d[a])
                change = False
            leng = i - d[k]
            if leng < answer[1] -answer[0]:
                answer = [d[k]+1,i+1]
    return answer