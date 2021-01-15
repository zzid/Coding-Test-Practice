function score(dice) {
  let dict = dice.reduce((result, num) => {
    if (!result[num]) result[num] = 1;
    else result[num]++;
    return result;
  }, {});
  return Object.keys(dict).reduce((sum, key) => {
    let count = dict[key];
    key = +key;
    if (key === 1 || key === 5) {
      if (count >= 3) {
        sum += key === 1 ? 1000 : 500;
        count -= 3;
      }
      if (count > 0) sum += key === 1 ? 100 * count : 50 * count;
    } else {
      if (count >= 3) {
        if (key === 6) sum += 600;
        else if (key === 4) sum += 400;
        else if (key === 3) sum += 300;
        else if (key === 2) sum += 200;
      }
    }
    return sum;
  }, 0);
}
