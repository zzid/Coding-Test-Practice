function rgb(r, g, b) {
  return [r, g, b].reduce((hex, num) => {
    if (num < 0) return (hex += '00');
    if (num > 255) return (hex += 'FF');
    let hexNum = num.toString(16).toUpperCase();
    if (hexNum.length < 2) hexNum = '0' + hexNum;

    return (hex += hexNum);
  }, '');
}
