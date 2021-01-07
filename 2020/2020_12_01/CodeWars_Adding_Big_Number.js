function add(a, b) {
  let biggerNumber, smallerNumber;
  if (a.length >= b.length) {
    biggerNumber = a;
    smallerNumber = b;
  } else {
    biggerNumber = b;
    smallerNumber = a;
  }
  let biggerArray = biggerNumber.split('').reverse();
  let smallerArray = smallerNumber.split('').reverse();
  let sumArray = [];
  let plusOne = false,
    i;
  for (let i = 0; i < smallerArray.length; i++) {
    let sum = parseInt(biggerArray[i]) + parseInt(smallerArray[i]);
    if (plusOne) {
      sum += 1;
      plusOne = false;
    }
    if (sum >= 10) {
      plusOne = true;
      sum -= 10;
    }
    sumArray[i] = sum;
  }
  for (let i = smallerArray.length; i < biggerArray.length; i++) {
    let num = parseInt(biggerArray[i]);
    if (plusOne) {
      num += 1;
      plusOne = false;
    }
    if (num >= 10) {
      plusOne = true;
      num -= 10;
    }
    sumArray[i] = num;
  }
  if (plusOne) sumArray.push(1);
  return sumArray.reverse().join('');
}
