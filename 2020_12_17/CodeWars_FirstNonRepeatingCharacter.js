function firstNonRepeatingLetter(s) {
  lowerCased = s.toLowerCase();
  let dictionary = lowerCased.split('').reduce((dict, char) => {
    if (!char) return dict;

    if (!dict[char]) dict[char] = 1;
    else dict[char]++;
    return dict;
  }, {});
  let resultChar = Object.keys(dictionary).reduce((result, key) => {
    if (dictionary[key] === 1 && !result) result = key;
    return result;
  }, '');
  return s.includes(resultChar) ? resultChar : resultChar.toUpperCase();
}
