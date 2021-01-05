function decompose(n) {
  const recursiveFunc = (n, remain) => {
    if (remain === 0) return [];
    for (let i = n - 1; i > 0; i--) {
      let nextRemain = remain - i ** 2;
      if (nextRemain >= 0) {
        let returned = recursiveFunc(i, nextRemain);
        if (returned) {
          returned.push(i);
          return returned;
        }
      }
    }
    return null;
  };
  return recursiveFunc(n, n ** 2);
}
