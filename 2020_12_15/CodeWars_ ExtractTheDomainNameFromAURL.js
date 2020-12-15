function incrementString(strng) {
  let result = '';
  let regex = /[0-9]\w*/g;
  let numberInString = strng.match(regex);
  if (numberInString) {
    let stringInString = strng.replace(regex, '');
    let originalLength = numberInString.toString().length;
    let plusOne = (parseInt(numberInString) + 1).toString();
    result += stringInString;
    if (plusOne.length < originalLength) {
      let difference = originalLength - plusOne.length;
      while (difference--) {
        result += '0';
      }
    }
    result += plusOne;
  } else {
    result = `${strng}1`;
  }
  return result;
}
