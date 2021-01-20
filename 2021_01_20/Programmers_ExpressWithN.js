function solution(N, number) {
  let answer = Infinity;
  const make = (x, n) => {
    let t = "";
    for (let i = 0; i <= x; i++) t += n;
    return +t;
  };
  const dp = (n, value, k) => {
    if (value === number) {
      answer = Math.min(answer, k);
      return;
    }
    if (k === 8) return;
    for (let i = 0; i < 8 - k; i++) {
      let t = make(i, n);
      dp(n, value * t, k + i + 1);
      dp(n, value + t, k + i + 1);
      dp(n, parseInt(value / t), k + i + 1);
      dp(n, value - t, k + i + 1);
    }
  };
  dp(N, 0, 0);
  return answer === Infinity ? -1 : answer;
}
