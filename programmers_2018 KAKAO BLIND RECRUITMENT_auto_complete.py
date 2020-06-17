# https://programmers.co.kr/learn/courses/30/lessons/17685
class Trie:
    def __init__(self):
        self.val = 0
        self.children = {}
def solution(words):
    answer = 0
    root = {}
    for i in words:
        child = root
        for j in range(len(i)):
            if i[j] not in child:
                child[i[j]] = Trie()
                child[i[j]].val +=1
            else:
                child[i[j]].val += 1 
            child = child[i[j]].children
    for i in words:
        child = root
        for j in range(len(i)):
            if child[i[j]].val == 1:
                answer +=1
                break
            else:
                answer +=1
                child = child[i[j]].children
    return answer

print(solution(["go","gone","guild"])) # ==7 )
print(solution(["abc","def","ghi","jklm"]) )# == 4)
print(solution(["word","war","warrior","world"]))# == 15)

