function topThreeWords(text) {
  let numOfAppearance = {};
  let regex = /[a-zA-z']+/g;
  let words = text.match(regex);
  if (words === null) return [];
  words.map((word) => {
    let lowercaseWord = word.toLowerCase();
    if (lowercaseWord !== "'") {
      if (numOfAppearance[lowercaseWord] === undefined) {
        numOfAppearance[lowercaseWord] = 1;
      } else {
        numOfAppearance[lowercaseWord]++;
      }
    }
  });
  let sorted = Object.keys(numOfAppearance).sort((a, b) => {
    return numOfAppearance[b] - numOfAppearance[a];
  });
  return sorted.length < 3 ? sorted : sorted.slice(0, 3);
}
