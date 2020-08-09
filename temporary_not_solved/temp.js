var adj = [], adj_t = [];
document.onload = solution(9,[[0,1],[0,3],[0,7],[8,1],[3,6],[1,2],[4,7],[7,5]],[[8,5],[6,7],[4,1]]);
// document.onload = solution(9,[[0,1],[0,3],[0,7],[8,1],[3,6],[1,2],[4,7],[7,5]],[[4,1],[8,7],[6,5]]);
function parse(cur,prv){
    adj_t[cur].forEach((e)=>{
        if(e !== prv){
            adj[e].push(cur);
            parse(e,cur);
        }
    });
}

function solution(n, path, order) {
    var answer = true;

    for(let i=0; i<n; i++){
        adj.push([]);
        adj_t.push([]);
    }
    path.forEach((e)=>{
        adj_t[e[1]].push(e[0]);
        adj_t[e[0]].push(e[1]);
    })
    parse(0,-1);
    order.forEach((e)=>{
        adj[e[1]].push(e[0]);
    })
    console.log(adj)
    order.forEach((e)=>{
        if(search(e[0],e[0]) === false) return answer = false;
    });
    
    console.log(adj)
    return answer = true;
}