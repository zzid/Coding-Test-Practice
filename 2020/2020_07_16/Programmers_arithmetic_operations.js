function solution(arr) {
    var num_stack = [], op_stack = [];
    arr.forEach((e,i)=>{
        if(i % 2 == 0) num_stack.push(parseInt(e))
        else op_stack.push(e)
    });
    var n = num_stack.length,
        inf = Infinity;
    var dp_max = Array(n).fill(-inf).map(()=>Array(n).fill(-inf)),
        dp_min = Array(n).fill(inf).map(()=>Array(n).fill(inf));
    for(let i =0 ;i <n; i++) dp_max[i][i] =dp_min[i][i] = num_stack[i];
    for(let mid=0; mid< n; mid++){
        for(let f=0; f< n- mid; f++){
            let t = mid+ f;
            for(let a=f; a< t; a++){
                if(op_stack[a] == '+'){
                    dp_max[f][t] = Math.max(dp_max[f][a] + dp_max[a+1][t], dp_max[f][t]);
                    dp_min[f][t] = Math.min(dp_min[f][a] + dp_min[a+1][t], dp_min[f][t]);
                }else{
                    dp_max[f][t] = Math.max(dp_max[f][a] - dp_min[a+1][t], dp_max[f][t]);
                    dp_min[f][t] = Math.min(dp_min[f][a] - dp_max[a+1][t], dp_min[f][t]);
                }
            }
        }
    }
    return dp_max[0][n-1];
  }