var pre = [],post = [], dict ={};
function make_str(a){
    return a[0]+','+a[1];
}
function find_max(list){
    let maxv = list[0][1];
    let index = 0;
    for(let i=1; i<list.length; i++){
        if(maxv < list[i][1]){
            maxv = list[i][1];
            index = i;   
        }
    }
    return index;
}
class tree{
    constructor(list){
        this.node = list[find_max(list)];
        let right = list.filter(e => e[0] > this.node[0]);
        let left = list.filter(e => e[0] < this.node[0]);
        if(right.length != 0) this.right = new tree(right);
        else this.right = null

        if(left.length != 0) this.left = new tree(left);
        else this.left = null
    }
}

function somefix(tree){
    pre.push(dict[make_str(tree.node)]);
    if(tree.left !== null){
        somefix(tree.left);
    }
    if(tree.right !== null){
        somefix(tree.right);
    }
    post.push(dict[make_str(tree.node)]);
}
function solution(nodeinfo) {
    var answer =[];
    for(let i in nodeinfo) dict[nodeinfo[i]] = parseInt(i) +1;
    let t = new tree(nodeinfo);
    somefix(t);
    answer.push(pre,post);
    return answer;
}