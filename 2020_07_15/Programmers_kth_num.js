function solution(array, commands) {
    var answer = [];
    commands.forEach((e)=>{
        let temp = array.slice(e[0]-1, e[1]);
        temp.sort((a,b)=>{
            return a-b;
        });
        answer.push(temp[e[2]-1]);
    });
    return answer;
}