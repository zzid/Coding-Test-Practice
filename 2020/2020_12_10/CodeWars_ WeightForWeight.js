const calculateNumberWeight = (numberString) => {
  let weight = 0;
  for (let i = 0; i < numberString.length; i++) {
    weight += parseInt(numberString[i]);
  }
  return { weight: weight, number: numberString };
};

function orderWeight(strng) {
  return strng
    .split(' ')
    .map((number) => calculateNumberWeight(number))
    .sort((a, b) => {
      if (a.weight === b.weight) {// string order
        if (a.number > b.number) return 1;
        else if (a.number < b.number) return -1;
        else return 0;
      }
      return a.weight - b.weight;
    })
    .map((object) => object.number)
    .join(' ');
}
