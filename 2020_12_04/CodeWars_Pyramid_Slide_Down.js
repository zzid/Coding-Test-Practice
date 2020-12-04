function longestSlideDown(pyramid) {
  let dp = pyramid.concat();
  for (let i = dp.length - 1; i >= 0; i--) {
    for (let j = 0; j < dp[i].length - 1; j++) {
      dp[i - 1][j] += Math.max(dp[i][j], dp[i][j + 1]);
    }
  }
  return dp[0][0];
}
