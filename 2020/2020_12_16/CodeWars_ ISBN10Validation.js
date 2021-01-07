function validISBN10(isbn) {
  if (isbn.length !== 10 || isbn.replace(/(\d{9}X|\d{10})/g, '')) return false;
  let result = isbn.split('').reduce((value, number, index) => {
    if (number === 'X') {
      value += 10 * (index + 1);
    } else {
      value += number * (index + 1);
    }
    return value;
  }, 0);
  return result % 11 === 0;
}
