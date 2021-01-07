function josephusSurvivor(n, k) {
  let arr = Array(n)
    .fill(0)
    .map((e, i) => i + 1);
  let curIndex = 0;
  const getNextIndex = () => {
    let result = (curIndex + k - 1) % arr.length;
    return result;
  };
  curIndex = getNextIndex();
  while (arr.length !== 1) {
    arr.splice(curIndex, 1);
    curIndex = getNextIndex();
  }
  return arr[0];
}
