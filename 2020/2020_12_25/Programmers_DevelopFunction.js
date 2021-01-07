function solution(progresses, speeds) {
  var answer = [],
    done = [],
    task = 1;
  var len = progresses.length;
  for (var i in progresses) {
    for (var j = 1; j < 100; j++) {
      if (progresses[i] + speeds[i] * j >= 100) {
        done[i] = j;
        break;
      }
    }
  }
  for (var i = 0; i < len; i++) {
    if (done[i] >= done[i + 1]) {
      done[i + 1] = done[i];
      task++;
    } else {
      answer.push(task);
      task = 1;
    }
  }

  return answer;
}
