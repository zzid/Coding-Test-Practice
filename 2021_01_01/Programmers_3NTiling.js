function solution(n) {
  if (n % 2 != 0) return 0;
  let mod = 1000000007;
  let a = 3,
    i = 6,
    b = 11,
    c;
  if (n == 4) return b;
  while (i <= n) {
    c = (4 * b - a) % mod;
    if (c < 0) c += 1000000007;
    a = b;
    b = c;
    i += 2;
  }
  return c % mod;
}
