function removeNb(n) {
  const checkCondition = (a, b) => sum === (a + 1) * (b + 1) - 1;
  let result = [];
  let sum = (n * (n + 1)) / 2;

  for (let i = 1; i <= n; i++) {
    let j = (sum - i) / (i + 1);
    if (!Number.isInteger(j)) continue;
    if (j <= n && checkCondition(i, j)) {
      result.push([i, j]);
    }
  }
  return result;
}
