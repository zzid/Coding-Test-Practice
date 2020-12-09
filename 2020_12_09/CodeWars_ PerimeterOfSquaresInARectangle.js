const fib = (n) => {
  let fibArr = Array(n).fill(0);
  let accumulator = 0;
  for (let i = 0; i <= n; i++) {
    if (i === 0 || i === 1) {
      fibArr[i] = 1;
      accumulator++;
      continue;
    }
    fibArr[i] = fibArr[i - 1] + fibArr[i - 2];
    accumulator += fibArr[i];
  }
  return accumulator;
};
function perimeter(n) {
  return 4 * fib(n);
}
