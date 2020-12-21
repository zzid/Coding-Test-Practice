const snail = (array) => {
  if (!array[0].length) return [];
  let visited = array.concat();
  let size = visited.length;
  let cnt = Math.pow(size, 2);
  let i = 0;
  let j = 0;
  let curDir = 0;
  let directions = [
    [0, 1],
    [1, 0],
    [0, -1],
    [-1, 0],
  ];
  let result = [visited[i][j]];
  visited[i][j] = -1;
  cnt--;
  while (cnt--) {
    let nextI = i + directions[curDir][0];
    let nextJ = j + directions[curDir][1];
    if (
      nextI < 0 ||
      nextJ < 0 ||
      nextI >= size ||
      nextJ >= size ||
      visited[nextI][nextJ] === -1
    ) {
      curDir = (curDir + 1) % 4;
      nextI = i + directions[curDir][0];
      nextJ = j + directions[curDir][1];
    }
    result.push(visited[nextI][nextJ]);
    visited[nextI][nextJ] = -1;
    i = nextI;
    j = nextJ;
  }
  return result;
};
