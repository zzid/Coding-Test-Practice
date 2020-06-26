n = int(input())
rects = []
idxs = {}
for i in range(n):
    temp = int(input())
    if temp in idxs:
        idxs[temp].append(i)
    else:
        idxs[temp] = [i]
    rects.append(temp)
area = 0
for keys in idxs:
    for i in idxs[keys]:
        leng = 1
        pivot = keys
        for j in range(i+1,n):
            if rects[j] < pivot:
                break
            else:
                leng +=1
        for j in range(i-1,-1,-1):
            if rects[j] < pivot:
                break
            else:
                leng +=1
        temp_a = pivot * leng
        if temp_a > area: area = temp_a
print(area)


