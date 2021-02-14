/* My : Floyd Warshall ( O(N) [N = graph array size (max : 200)]) */
function solution(n, s, a, b, fares) {
    let minCostArr = new Array(201)
        .fill(Infinity)
        .map(() => new Array(201).fill(Infinity));
    for (let i = 0; i <= n; i++) {
        minCostArr[i][i] = 0;
    }
    fares.map(([s, d, c]) => {
        minCostArr[s][d] = c;
        minCostArr[d][s] = c;
    });

    for (let k = 1; k <= n; k++) {
        for (let i = 1; i <= n; i++) {
            for (let j = 1; j <= n; j++) {
                minCostArr[i][j] = Math.min(
                    minCostArr[i][j],
                    minCostArr[i][k] + minCostArr[k][j]
                );
            }
        }
    }
    let answer = minCostArr[s][a] + minCostArr[s][b];
    for (let i = 1; i <= n; i++) {
        answer = Math.min(
            answer,
            minCostArr[s][i] + minCostArr[i][a] + minCostArr[i][b]
        );
    }

    return answer;
}

/* dijstra */

// function solution(n, s, a, b, fares) {

//     const dijkstra = (start) => {
//         const graph = new Map()
//         for(let i=1; i<=n; i++){
//             graph.set(i, [])
//         }

//         fares.forEach(fare => {
//             const [n1, n2, cost] = fare

//             graph.get(n1).push([n2, cost])
//             graph.get(n2).push([n1, cost])
//         })

//         const visited = Array(n+1).fill(0)
//         const costs = Array(n+1).fill(Infinity)
//         costs[0] = 0
//         costs[start] = 0

//         while(true){
//             let minNode
//             let minCost = Infinity

//             for(let i=1; i<=n; i++){
//                 if(!visited[i] && costs[i] < minCost){
//                     minNode =i
//                     minCost = costs[i]
//                 }
//             }

//             if(!minNode){
//                 break
//             }
//             visited[minNode] = 1

//             const adjacents = graph.get(minNode)
//             adjacents.forEach(adj => {
//                 const [adjNode, cost] = adj
//                 costs[adjNode] = Math.min(costs[minNode]+cost, costs[adjNode])
//             })
//         }

//         return costs
//     }

//     const costs = [a,b,s].map(s => dijkstra(s))

//     let answer = costs[2][a] + costs[2][b]

//     for(let i=1; i<=n; i++){
//         answer = Math.min(answer, costs[2][i] + costs[1][i] + costs[0][i])
//     }

//     return answer;
// }
