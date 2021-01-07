function solution(input, markers) {
  let result = markers.reduce((accumulator, marker) => {
    let regex = new RegExp(`\\${marker}.*`, 'g');
    accumulator = accumulator.replace(regex, '');
    return accumulator;
  }, input);
  result = result.replace(/( \n)/g, '\n');
  return result.trim();
}
