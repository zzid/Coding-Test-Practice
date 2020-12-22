function getPINs(observed) {
  let digits = observed.split('');
  const getCombinations = (idx, curCombination) => {
    const reachedEnd = (candidate) => result.push(curCombination + candidate);
    const goDeeper = (candidate) => {
      getCombinations(idx + 1, curCombination + candidate);
    };

    let candidates = adj[digits[idx]];

    candidates.forEach((candidate) => {
      idx !== digits.length - 1 ? goDeeper(candidate) : reachedEnd(candidate);
    });
  };

  let adj = [
    ['0', '8'],
    ['1', '2', '4'],
    ['1', '2', '3', '5'],
    ['2', '3', '6'],
    ['1', '4', '5', '7'],
    ['2', '4', '5', '6', '8'],
    ['3', '5', '6', '9'],
    ['4', '7', '8'],
    ['5', '7', '8', '9', '0'],
    ['6', '8', '9'],
  ];
  let result = [];

  getCombinations(0, '');

  return result;
}
