const sortString = (str) => {
  let sortedString = str.split('').sort((a, b) => {
    return a > b;
  });
  return sortedString.join('');
};
function anagrams(word, words) {
  let sortedWord = sortString(word);
  let sortedWords = words.map((word) => sortString(word));
  let ret = sortedWords.reduce((acc, e, i) => {
    if (e === sortedWord) {
      acc.push(words[i]);
    }
    return acc;
  }, []);
  return ret;
}
