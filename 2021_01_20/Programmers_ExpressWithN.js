function solution(N, number) {
  var answer = Infinity;
  var make = function (x, n) {
    var t = "";
    for (var i = 0; i <= x; i++) {
      t = t.concat(n);
    }
    return parseInt(t);
  };
  function dp(n, value, k) {
    if (value == number) {
      answer = Math.min(answer, k);
      return;
    }
    if (k == 8) {
      return;
    }
    for (var i = 0; i < 8 - k; i++) {
      var t = make(i, n);
      dp(n, value * t, k + i + 1);
      dp(n, value + t, k + i + 1);
      dp(n, parseInt(value / t), k + i + 1);
      dp(n, value - t, k + i + 1);
    }
  }
  dp(N, 0, 0);
  if (answer == Infinity) answer = -1;
  return answer;
}
