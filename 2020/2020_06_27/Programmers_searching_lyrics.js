function TrieNode(key){
    this.key = key;
    this.children = {};
    this.parent = null;
    this.end = false;
    this.count =0;
}
function Trie(leng){
    this.root = new TrieNode(null);
};
Trie.prototype.insert = function(word){
    var node = this.root;
    node.count++;
    for(let i=0; i<word.length; i++){
        if(!node.children[word[i]]){
            node.children[word[i]] = new TrieNode(word[i]);
            node.children[word[i]].parent = node;
        }
        node.children[word[i]].count++;
        node = node.children[word[i]];
        if(i == word.length -1){
            node.end = true;
            node.leng = word.length;
        }
    }
};
Trie.prototype.find = function(prefix){
    var node = this.root;
    for(let i=0; i<prefix.length; i++){
        if(prefix[i] == '?') break;
        if(node.children[prefix[i]]) node = node.children[prefix[i]];
        else return 0;
    }
    return node.count;
};
function solution(words, queries) {
    var answer = [];
    var Tries ={},
        Tries_r = {};
    for(let i in words){
        let len = words[i].length;
        if(!Tries[len]) Tries[len] = new Trie(len);
        Tries[len].insert(words[i]);
        if(!Tries_r[len]) Tries_r[len] = new Trie(len);
        Tries_r[len].insert(words[i].split('').reverse().join(''));
    }
    for(let i in queries){
        let len = queries[i].length;
        if(!Tries_r[len] || !Tries[len]) answer.push(0);
        else{
            if(queries[i][0] =='?'){
                if(queries[i][len-1] =='?'){
                    answer.push(Tries_r[len].root.count);
                }else{
                    let q = queries[i].split('').reverse().join('');
                    answer.push(Tries_r[len].find(q));
                }
            }else {
                answer.push(Tries[len].find(queries[i]));
            }
        }
    }
    return answer;
}
