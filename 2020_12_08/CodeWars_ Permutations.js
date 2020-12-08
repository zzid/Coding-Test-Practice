const permutator = (inputArr) => {
  let result = [];
  const permute = (arr, m = []) => {
    if (arr.length === 0) {
      result.push(m);
    } else {
      for (let i = 0; i < arr.length; i++) {
        let curr = arr.concat();
        let next = curr.splice(i, 1);
        console.log(curr, next, m);
        permute(curr.concat(), m.concat(next));
      }
    }
  };
  permute(inputArr);
  return new Set(result.map((array) => array.join('')));
};

function permutations(string) {
  return [...permutator(string.split(''))];
}

/*
function permutations(str) {
  return str.length <= 1
    ? [str]
    : Array.from(
        new Set(
          str
            .split('')
            .map((char, i) =>
              permutations(str.substr(0, i) + str.substr(i + 1)).map(
                (p) => char + p
              )
            )
            .reduce((r, x) => r.concat(x), [])
        )
      );
}
*/
