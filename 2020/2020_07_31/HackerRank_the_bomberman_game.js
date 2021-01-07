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


// Complete the bomberMan function below.
function bomberMan(n, grid) {
    const r = grid.length,
          c = grid[0].length;
    let full = '';
    for(let i=0; i<c; i++) full += 'O';

    function detoantion(){
        const dy = [0,1,-1,0,0],
              dx = [0,0,0,1,-1];
        // detonation
        // for(let y=0; y<r; y++){
        for(let b of bombs){
            let y = b[0], x = b[1];
            // console.log('y : '+  y + 'x : ' + x + 'bomb : ', bombs[[y,x]])
            if(bombs[[y,x]] != 1){
                for(let d=0; d<5; d++){
                    let ny = y + dy[d], nx = x + dx[d];
                    if(ny < 0 || ny >= r || nx < 0  || nx >= c) continue;
                    grid[ny] = grid[ny].substr(0,nx) + '.' + grid[ny].substr(nx+1);
                }
            }
        }
        // }
        bombs = [];
    }
    function fill(){
        for(let i=0; i<r; i++){
            for(let j =0; j<c; j++){
                if(grid[i][j] == 'O') bombs.push([i,j]);
            }
            grid[i] = full;
        }
    }
    let bombs = [];
    
    
    if(n <= 1) return grid // 0~1
    fill(); if(n % 2 == 0) return grid; // 2
    detoantion(); if(n==3) return grid; // 3
    let v2 = [].concat(grid);
    fill();
    detoantion();
    let v1 = [].concat(grid);
    if(n >5){ // 3~n
        if( (n+1) % 4 == 0 ) return v2;
        if( (n-1) % 4 == 0 ) return v1;
    }

    return grid;
}

function main() {
    const ws = fs.createWriteStream(process.env.OUTPUT_PATH);

    const rcn = readLine().split(' ');

    const r = parseInt(rcn[0], 10);

    const c = parseInt(rcn[1], 10);

    const n = parseInt(rcn[2], 10);

    let grid = [];

    for (let i = 0; i < r; i++) {
        const gridItem = readLine();
        grid.push(gridItem);
    }

    let result = bomberMan(n, grid);

    ws.write(result.join("\n") + "\n");

    ws.end();
}
