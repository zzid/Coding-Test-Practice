function pickPeaks(arr) {
  let ret = { pos: [], peaks: [] };
  if (arr.length === 0) return ret;
  let goingUp = -1;
  arr.reduce((acc, e, i) => {
    if (i === 0) {
      // first element
      acc.push(e);
      return acc; // return
    }
    let prev = acc[acc.length - 1];
    acc.push(e);

    if (prev < e) {
      goingUp = i;
      return acc; //return
    }

    if (goingUp !== -1) {
      if (prev > e) {
        ret.pos.push(goingUp);
        ret.peaks.push(prev);
      } else if (prev === e) {
        // this mean plateau
        return acc; // so just return without changing goingUp
      }
      goingUp = -1;
    }
    return acc;
  }, []);
  return ret;
}
