function solution(board, r, c) {
    let answer = Infinity;

    const movingCount = (cur, next) => {
        let [y, x] = cur;
        let [ny, nx] = next;

        if (y !== ny && x !== nx) return 2;
        else if (y === ny && x !== nx) return 1;
        else if (y !== ny && x === nx) return 1;
        else return 0;
    };
    const whichOne = (cur, candidates) => {
        if (candidates.length === 1) return 0;
        if (movingCount(cur, candidates[0]) > movingCount(cur, candidates[1]))
            return 1;
        else return 0;
    };

    const permutation = (array) => {
        function p(array, temp) {
            var i, x;
            if (!array.length) {
                result.push(temp);
            }
            for (i = 0; i < array.length; i++) {
                x = array.splice(i, 1)[0];
                p(array, temp.concat(x));
                array.splice(i, 0, x);
            }
        }

        var result = [];
        p(array, []);
        return result;
    };
    const boardInfo = board.reduce((obj, e1, i1) => {
        e1.map((e2, i2) => {
            if (e2 !== 0) {
                if (!obj[e2]) obj[e2] = [[i1, i2]];
                else obj[e2].push([i1, i2]);
            }
        });
        return obj;
    }, {});
    const copyObj = (obj) => JSON.parse(JSON.stringify(obj));
    const pms = permutation(Object.keys(boardInfo));

    pms.map((pm) => {
        let curBoard = copyObj(boardInfo);
        let count1 = 0,
            count2 = 0,
            cur1 = [r, c],
            cur2 = [r, c];
        for (let i = 0; i < 2; i++) {
            let next = curBoard[pm[0]][i];
            count1 += movingCount(cur1, next) + 1;
            cur1 = [...next];
        }
        for (let i = 1; i >= 0; i--) {
            let next = curBoard[pm[0]][i];
            count2 += movingCount(cur2, next) + 1;
            cur2 = [...next];
        }

        delete curBoard[pm[0]];

        let queue = [];

        if (Object.keys(curBoard).length) {
            queue.push({
                count: count1,
                cur: cur1,
                obj: curBoard,
                curCardIdx: 1,
            });
            queue.push({
                count: count2,
                cur: cur2,
                obj: curBoard,
                curCardIdx: 1,
            });
        } else {
            answer = Math.min(answer, count1, count2);
        }
        while (queue.length) {
            let obj = queue.shift();
            let [count, cur, curBoard, cardIdx] = Object.values(obj);

            let count1 = count,
                count2 = count,
                cur1 = cur,
                cur2 = cur;
            for (let i = 0; i < 2; i++) {
                let next = curBoard[pm[cardIdx]][i];
                count1 += movingCount(cur1, next) + 1;
                cur1 = [...next];
            }
            for (let i = 1; i >= 0; i--) {
                let next = curBoard[pm[cardIdx]][i];
                count2 += movingCount(cur2, next) + 1;
                cur2 = [...next];
            }
            let nextBoard = copyObj(curBoard);
            delete nextBoard[pm[cardIdx]];
            if (Object.keys(nextBoard).length) {
                queue.push({
                    count: count1,
                    cur: cur1,
                    obj: nextBoard,
                    curCardIdx: cardIdx + 1,
                });
                queue.push({
                    count: count2,
                    cur: cur2,
                    obj: nextBoard,
                    curCardIdx: cardIdx + 1,
                });
            } else {
                answer = Math.min(answer, count1, count2);
            }
        }
    });
    // console.log("answer : ", answer);
    return answer;
}
// solution(
//     [
//       [1, 0, 0, 3],
//       [2, 0, 0, 0],
//       [0, 0, 0, 2],
//       [3, 0, 1, 0],
//     ],
//     1,
//     0
//   );
