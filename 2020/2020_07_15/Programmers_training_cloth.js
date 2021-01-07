function solution(n, lost, reserve) {
    var answer= n, temp = [];
    lost.forEach((e)=>{
        let val = reserve.indexOf(e);
        if(val != -1){
            reserve.splice(val,1);
            temp.push(e);
        }
    })
    temp.forEach((e)=>{
        lost.splice(lost.indexOf(e),1);
    })
    // console.log(lost, reserve)
    for(let i in lost){
        let a = reserve.indexOf(lost[i]);
        let val = reserve.indexOf(lost[i]-1);
        if(val == -1){
            val = reserve.indexOf(lost[i]+1);
            if(val == -1) answer--;
            else reserve.splice(val,1);
        }else reserve.splice(val,1);
    }
    return answer;
}