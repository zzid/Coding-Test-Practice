function dirReduc(arr) {
  const opposite = {
    NORTH: 'SOUTH',
    SOUTH: 'NORTH',
    WEST: 'EAST',
    EAST: 'WEST',
  };
  let returnArr = arr.reduce((accumulator, element) => {
    let top = accumulator.length > 0 ? accumulator[accumulator.length - 1] : -1;
    top === -1
      ? accumulator.push(element)
      : opposite[top] === element
      ? accumulator.pop()
      : accumulator.push(element);
    return accumulator;
  }, []);
  return returnArr;
}
