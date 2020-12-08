function dblLinear(n) {
  let arr = [1],
    y = 0,
    z = 0;

  while (arr.length <= n) {
    let yValue = 2 * arr[y] + 1,
      zValue = 3 * arr[z] + 1;
    if (yValue > zValue) {
      z++;
      arr.push(zValue);
    } else if (yValue < zValue) {
      y++;
      arr.push(yValue);
    } else {
      y++;
      z++;
      arr.push(yValue);
    }
  }
  return arr[n];
}
