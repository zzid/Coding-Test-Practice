var maxSequence = function (arr) {
  if (arr.length === 0) return 0;
  let retArr = arr.reduce((acc, e, i) => {
    if (acc.length) {
      let lastAndNow = acc[acc.length - 1] + e;
      acc.push(lastAndNow > e ? lastAndNow : e);
    } else {
      acc.push(e);
    }
    return acc;
  }, []);
  let maxVal = Math.max(...retArr);
  return maxVal < 0 ? 0 : maxVal;
};
