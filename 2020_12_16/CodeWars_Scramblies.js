function scramble(str1, str2) {
  let dictionary = str1.split('').reduce((dict, char) => {
    if (!dict[char]) {
      dict[char] = 1;
    } else {
      dict[char]++;
    }
    return dict;
  }, {});
  let isValid = str2.split('').reduce((flag, char) => {
    if (!dictionary[char]) flag = false;
    else dictionary[char]--;
    return flag;
  }, true);

  return isValid;
}
