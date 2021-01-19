function primeFactors(n) {
  let i = 2;
  let dict = {};
  while (n / i !== 1) {
    if (n % i === 0) {
      if (!dict[i]) dict[i] = 1;
      else dict[i]++;
      n /= i;
    } else {
      i++;
    }
  }

  if (!dict[i]) dict[i] = 1;
  else dict[i]++;

  return Object.keys(dict).reduce((result, key) => {
    if (dict[key] === 1) result += `(${key})`;
    else result += `(${key}**${dict[key]})`;
    return result;
  }, "");
}
