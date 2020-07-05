def solution(f):
    global inp, ex
    for i in range(f,len(inp)-len(ex)+1):
        flag = True
        if inp[i] != ex[0]: continue
        if inp[i: i+len(ex)] != ex:
            flag = False
        # for j in range(len(ex)):
        #     if inp[i+j] != ex[j]:
        #         flag = False
        #         break
        #     else: canBe = True
        if flag:
            inp = inp[:i] + inp[i+len(ex):]
            if len(inp) == 0:
                return -1
            # if canBe: return i-len(ex)
            # else: return i
            return i-len(ex)
    return 0


inp = str(input())
ex = str(input())
prtFlag = 0
dec =0
# canBe = False
while 1:
    # canBe = False
    dec = solution(dec)
    if dec == -1:
        prtFlag = 1
        break
    elif dec == 0: break
if prtFlag == 1: print("FRULA")
else: print(inp)
