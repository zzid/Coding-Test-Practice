function productFib(prod) {
  let fibNums = [0, 1];
  let curIdx = 2;
  let curProd = 0;
  while (curProd < prod) {
    fibNums[curIdx] = fibNums[curIdx - 1] + fibNums[curIdx - 2];
    curProd = fibNums[curIdx] * fibNums[curIdx - 1];
    if (curProd === prod) return [fibNums[curIdx - 1], fibNums[curIdx], true];
    else if (curProd > prod)
      return [fibNums[curIdx - 1], fibNums[curIdx], false];
    curIdx++;
  }
}
