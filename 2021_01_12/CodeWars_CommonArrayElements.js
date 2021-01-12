function common(a, b, c) {
  const makeDict = (arr) => {
    return arr.reduce((dict, e) => {
      if (!dict[e]) dict[e] = 1;
      else dict[e]++;

      return dict;
    }, {});
  };
  let aDict = makeDict(a),
    bDict = makeDict(b),
    cDict = makeDict(c);
  return Object.keys(aDict).reduce((sum, key) => {
    let minValue = Math.min(aDict[key], bDict[key], cDict[key]);
    if (!minValue) return sum;
    return (sum += parseInt(key) * minValue);
  }, 0);
}
