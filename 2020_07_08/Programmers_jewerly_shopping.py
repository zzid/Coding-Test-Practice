def solution(gems):
    # answer = [1000000, -100000]
    # cnt = len(set(gems))
    # d = {}
    # for i in range(len(gems)):
    #     if gems[i] not in d:
    #         d[gems[i]] = [i+1]
    #     else: d[gems[i]].append(i+1)
    # for keys in d:
    #     answer[0] = min(answer[0], d[keys][0])
    #     answer[1] = max(answer[1], d[keys][0])
    answer = [1, len(gems)]
    cnt = len(set(gems))
    for i in range(len(gems)):
        temp_c = len(set(gems[answer[0]-1:i+1]))
        if temp_c == cnt:
            if answer[1] - answer[0] > i - answer[0]: answer[1] = i+1
            if answer[1] - answer[0] == cnt: return answer;
            for j in range(answer[0]-1, i):
                if len(set(gems[j:i+1])) < cnt:
                    if answer[1] - answer[0] > i+1 - j:
                        # print(answer, ' ', answer[1] - answer[0] , i+1-j)
                        answer = [j,i+1]
                        break
    return answer