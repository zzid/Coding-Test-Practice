function solution(list) {
  //   let isConsecutive = false;
  let startNum = null;
  let last;
  let ret = list.reduce((acc, e, i) => {
    if (i === 0) {
      // initinal
      acc.push(e);
      return acc;
    }
    last = acc[acc.length - 1];
    if (startNum !== null) {
      acc.pop();
      if (e - last === 1) {
        acc.push(e);
      } else {
        acc.push(`${startNum}-${last}`);
        startNum = null;
      }
    } else {
      if (e - last === 1) {
        startNum = acc.pop();
      }
    }
    acc.push(e);
    console.log(acc);
    return acc;
  }, []);
  console.log(ret);
  return ret.join(',');
}
