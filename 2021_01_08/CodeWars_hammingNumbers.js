function hamming(n) {
  let hammingNumbers = [1];
  let i2 = 0,
    i3 = 0,
    i5 = 0;
  for (let i = 1; i < n; i++) {
    let curNum = Math.min(
      2 * hammingNumbers[i2],
      3 * hammingNumbers[i3],
      5 * hammingNumbers[i5]
    );
    if (2 * hammingNumbers[i2] <= curNum) i2++;
    if (3 * hammingNumbers[i3] <= curNum) i3++;
    if (5 * hammingNumbers[i5] <= curNum) i5++;
    hammingNumbers.push(curNum);
  }
  return hammingNumbers[n - 1];
}
