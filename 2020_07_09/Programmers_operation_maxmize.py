from itertools import permutations
from copy import deepcopy
def solution(e):
    answer = 0
    op = ['*', '-', '+']
    per = permutations(op,3)
    ops= list(per)

    nums = []
    pivot = 0
    operation = []
    # parsing
    for i in range(len(e)):
        if(not e[i].isdecimal()):
            operation.append(e[i])
            nums.append(int(e[pivot:i]))
            pivot = i+1
        if i == len(e)-1:
            nums.append(int(e[pivot:i+1]))
    for i in range(len(ops)):
        temp = []
        temp.append(nums[0])
        temp2 = deepcopy(operation)
        for j in range(len(ops[i])): # permutation
            if j != 0: nex =[temp[0]]
            for a in range(len(temp2)): #operations from input
                if j == 0:
                    temp.append(nums[a+1])
                    if ops[i][j] == temp2[a]:
                        if ops[i][j] == '*':
                            front = temp.pop(-1)
                            back = temp.pop(-1)
                            temp.append(front * back)
                        elif ops[i][j] == '-':
                            front = temp.pop(-1)
                            back = temp.pop(-1)
                            temp.append(back - front)
                        else:
                            front = temp.pop(-1)
                            back = temp.pop(-1)
                            temp.append(front + back)
                else:
                    nex.append(temp[a+1])
                    if ops[i][j] == temp2[a]:
                        if ops[i][j] == '*':
                            front = nex.pop(-1)
                            back = nex.pop(-1)
                            nex.append(front * back)
                        elif ops[i][j] == '-':
                            front = nex.pop(-1)
                            back = nex.pop(-1)
                            nex.append(back - front)
                        else:
                            front = nex.pop(-1)
                            back = nex.pop(-1)
                            nex.append(front + back)
            while ops[i][j] in temp2:
                temp2.remove(ops[i][j])
            if len(temp) == 1:
                if answer < abs(temp[0]):
                    answer = abs(temp[0])
            if j!= 0:
                if len(nex) == 1:
                    if answer < abs(nex[0]):
                        answer = abs(nex[0])
            if j != 0: temp = deepcopy(nex)
                        
    return answer

print(solution("100-200*300-500+20")) #60420
print(solution("50*6-3*2")) #300