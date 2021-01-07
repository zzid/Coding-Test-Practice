function validParentheses(parens) {
  let ret = true;
  console.log(parens);
  let lefts = parens.split('').reduce((acc, e, i) => {
    if (ret) {
      if (i === 0) {
        // initial
        acc.push(e);
        return acc;
      } else {
        if (e === '(') {
          acc.push(e);
          return acc;
        } else {
          // if ')'
          if (acc.length === 0) {
            ret = false;
          } else {
            acc.pop();
            return acc;
          }
        }
      }
    }
    return acc;
  }, []);
  if (lefts.length) ret = false;
  return ret;
}
