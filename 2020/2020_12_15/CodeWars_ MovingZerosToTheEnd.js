var moveZeros = function (arr) {
  let cnt = 0;
  let result = arr.reduce((filtered, element) => {
    if (element === 0) {
      cnt++;
      return filtered;
    }
    filtered.push(element);
    return filtered;
  }, []);
  while (cnt--) result.push(0);
  return result;
};
