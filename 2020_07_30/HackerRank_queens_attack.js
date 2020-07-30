'use strict';

const fs = require('fs');

process.stdin.resume();
process.stdin.setEncoding('utf-8');

let inputString = '';
let currentLine = 0;

process.stdin.on('data', inputStdin => {
    inputString += inputStdin;
});

process.stdin.on('end', _ => {
    inputString = inputString.replace(/\s*$/, '')
        .split('\n')
        .map(str => str.replace(/\s*$/, ''));

    main();
});

function readLine() {
    return inputString[currentLine++];
}

// Complete the queensAttack function below.
function queensAttack(n, k, r_q, c_q, obstacles) {
    const dr = [1,1,0,-1,-1,-1,0,1];
    const dc = [0,1,1,1,0,-1,-1,-1];
    let dict = {};
    for(let i in obstacles){
        let r = obstacles[i][0], c = obstacles[i][1];
        dict[[r,c]] = 1;
    }
    let can_go = [0,1,2,3,4,5,6,7];
    let ret =0;
    let q = [];
    q.push([r_q, c_q,-1]);
    while(q.length){
        let queen = q.shift();
        let rq = queen[0], cq = queen[1], dir = queen[2];
        if(dir === -1){
            let candidate = [];
            for(let d of can_go){
                let nr = rq + dr[d], nc = cq + dc[d];
                if(nr > n || nr < 1 || nc > n || nc < 1) continue;
                if(dict[[nr,nc]] === 1) candidate.push(d);
                else{
                    q.push([nr,nc,d]);
                    ret++;
                }
            }
            for(let i of candidate){
                let idx = can_go.indexOf(i);
                can_go.splice(idx, 1);
            }
        }
        else{
            let nr = rq + dr[dir], nc = cq +dc[dir];
            if(nr > n || nr < 1 || nc > n || nc < 1) continue;
            if(dict[[nr,nc]] !== 1){
                q.push([nr,nc,dir]);
                ret++;
            }
        }
    }

    return ret;
}

function main() {
    const ws = fs.createWriteStream(process.env.OUTPUT_PATH);

    const nk = readLine().split(' ');

    const n = parseInt(nk[0], 10);

    const k = parseInt(nk[1], 10);

    const r_qC_q = readLine().split(' ');

    const r_q = parseInt(r_qC_q[0], 10);

    const c_q = parseInt(r_qC_q[1], 10);

    let obstacles = Array(k);

    for (let i = 0; i < k; i++) {
        obstacles[i] = readLine().split(' ').map(obstaclesTemp => parseInt(obstaclesTemp, 10));
    }

    let result = queensAttack(n, k, r_q, c_q, obstacles);

    ws.write(result + "\n");

    ws.end();
}
