function solution(n, build_frame) {
    var answer = [];
    build_frame.forEach(a=>{
        //let x = a[0], y=a[1], cat = a[2], con = a[3];
        if(a[3] ==0){
            if(!erase(a[0],a[1],a[2])) build(a[0],a[1],a[2]);
        }else build(a[0],a[1],a[2]);
        //console.log(answer)
    });
    function exist(x,y,cat){
        let ret = -1;
        answer.forEach((a,i)=>{
            if(a[0] === x && a[1] === y && a[2] === cat) ret = i;
        });
        if(ret < 0) return false;
        return ret+1;
    }
    function build(x, y, cat){
        if(cat == 0){// 기둥
            
            if(y == 0){
                answer.push([x,y,0]);
            }
            else if(exist(x,y-1,0)){
                answer.push([x,y,0]);
            }
            else if(exist(x,y,1) || exist(x-1,y,1)){
                answer.push([x,y,0]);
            }
        }else{// 보
            if(exist(x,y-1,0) || exist(x+1,y-1,0)){
                answer.push([x,y,1]);
            }
            else if(exist(x-1,y,1)&& exist(x+1,y,1)){
                answer.push([x,y,1]);
            }
        }
    }
    function buildTest(x, y, cat){
        let ret= true;
        if(cat == 0){// 기둥
            if(y == 0 || exist(x,y-1,0) || (exist(x,y,1) || exist(x-1,y,1))) ret = true;
            else return false;
        }else{// 보
            if((exist(x,y-1,0) || exist(x+1,y-1,0)) || (exist(x-1,y,1)&& exist(x+1,y,1))) ret = true;
            else return false;
        }
        return ret;
    }
    function erase(x, y, cat){
        //console.log(answer.indexOf([x,y,cat]));
        if(!exist(x,y,cat)) return false;
        answer.splice(exist(x,y,cat)-1,1);
        for(let b in answer){
            if(!buildTest(answer[b][0],answer[b][1],answer[b][2])) return false;
        }
        return true;
    }
    
    answer.sort((a,b)=>{
        if(a[0] == b[0]){
            if(a[1] == b[1]){return a[2] - b[2];}
            return a[1] - b[1];
        }
        return a[0] - b[0];
    });
    return answer;
}