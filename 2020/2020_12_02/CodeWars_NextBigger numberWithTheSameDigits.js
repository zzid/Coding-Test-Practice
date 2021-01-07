/*  
  // first approach

const permutator = (inputArr) => {
  let result = [];

  const permute = (arr, m = []) => {
    if (arr.length === 0) {
      result.push(m);
    } else {
      for (let i = 0; i < arr.length; i++) {
        let cur = arr.slice();
        let next = cur.splice(i, 1);
        permute(cur.slice(), m.concat(next));
      }
    }
  };
  permute(inputArr);

  return result.map((array) => parseInt(array.join('')));
};

function nextBigger(n) {
  let splited = n.toString().split('');
  let allPossibleNumbers = permute(splited);
  let sorted = allPossibleNumbers.sort((a, b) => {
    return a - b;
  });
  let index = sorted.lastIndexOf(n);
  return index + 1 < sorted.length ? sorted[index + 1] : -1;
  
*/

/*
  second approach 
*/
function nextBigger(n) {
  let number = n.toString();

  /* find the first decreasing */
  let pivotIndex = -1,
    pivotValue;
  for (let i = number.length - 1; i > 0; i--) {
    if (number[i] > number[i - 1]) {
      pivotIndex = i - 1;
      pivotValue = number[i - 1];
      break;
    }
  }
  if (pivotIndex === -1) return -1;
  let leftSide = number.substr(0, pivotIndex);

  /* devide and find next bigger digit */
  let dividedNumber = number.substr(pivotIndex + 1, number.length).split('');
  let nextBiggerValue, nextBiggerIndex;
  for (let i = dividedNumber.length - 1; i > 0; i--) {
    if (dividedNumber[i] > pivotValue) {
      nextBiggerIndex = i;
      break;
    }
  }

  /* to make right side to nextbigger number */
  nextBiggerValue = dividedNumber.splice(nextBiggerIndex, 1);
  dividedNumber.push(pivotValue);
  let rightSide = dividedNumber
    .sort((a, b) => {
      return a - b;
    })
    .join('');
  return parseInt(`${leftSide}${nextBiggerValue}${rightSide}`);
}
