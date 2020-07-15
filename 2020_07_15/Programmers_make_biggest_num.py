def solution(number, k):
    answer = ''
    leng = len(number)
    ret_leng = leng-k
    start = 0
    for i in range(ret_leng):
        idx= 0
        for j in range(9,0,-1):
            if str(j) in number[start : leng-ret_leng+i+1]:
                idx = number[start : leng-ret_leng+i+1].index(str(j))
                break
        idx += start
        answer += str(number[idx])
        start = idx+1
    return answer

print('#1 : ', solution("1924", 2)) # '94'
print('#2 : ', solution("1231234", 3)) # '3234'
print('#3 : ', solution("4177252841", 4)) # '775841'

# JS
# function solution(number, k) {
#   let answer;
#   const greatestNumbers = [];

#   [...number].forEach((value, i) => {
#     while (k > 0 && greatestNumbers[greatestNumbers.length - 1] < value) {
#       greatestNumbers.pop();
#       k--;
#     }
#     greatestNumbers.push(value);
#     console.log(greatestNumbers)
#   });

#   if (k)
#       greatestNumbers.splice(greatestNumbers.length - k, k);
#   answer = greatestNumbers.join("");

#   return answer;
# }