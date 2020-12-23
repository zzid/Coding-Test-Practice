function sumIntervals(intervals) {
  let numSet = new Set();
  return intervals.reduce((set, interval) => {
    for (let i = interval[0]; i < interval[1]; i++) {
      set.add(i);
    }
    return set;
  }, numSet).size;
}
