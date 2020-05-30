class trs():
    def __init__(self, etime, val):
        self.etime = etime
        self.val = val
    def arrtime(self, length):
        return self.etime + length

def solution(bridge_length, weight, truck_weights):
    answer, i,time = 0,1,1
    cur =[trs(time,truck_weights[0])]
    sums = truck_weights[0]
    # if weight >= sum(truck_weights):
    #     return len(truck_weights) + bridge_length
    while 1:
        time += 1
        if i == len(truck_weights):
            answer = cur[len(cur)-1].arrtime(bridge_length)
            break
        if sums + truck_weights[i] <= weight:
            if cur[0].arrtime(bridge_length) <= time:
                sums -= cur[0].val
                time = cur[0].arrtime(bridge_length)
                cur.pop(0)
            sums += truck_weights[i]
            cur.append(trs(time,truck_weights[i]))
            i += 1
        else:
            sums -= cur[0].val
            time = bridge_length + cur[0].etime 
            cur.pop(0)
            if sums + truck_weights[i] <= weight:
                sums += truck_weights[i]
                cur.append(trs(time,truck_weights[i]))
                i += 1
        # print("time : " ,time, " / " , sums, " i : " , i )
    return answer

print(solution(5,5,[2, 2, 2, 2, 1, 1, 1, 1, 1]))