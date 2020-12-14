function add(n) {
  chain = (n2) => add(n + n2);
  chain.valueOf = () => n;
  return chain;
}
// https://developer.mozilla.org/ko/docs/Web/JavaScript/Reference/Global_Objects/Object/valueOf
