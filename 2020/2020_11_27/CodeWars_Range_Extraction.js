const pushToResult = (source, target) => {
  if (source.length > 2) {
    let sourceString = `${source[0]}-${source[source.length - 1]}`;
    target.push(sourceString);
  } else {
    target = target.concat(source);
  }
  return target;
};

function solution(list) {
  let consecutiveList = [],
    last;
  let result = list.reduce((accumulator, element, index) => {
    if (index === 0) {
      // initinal
      accumulator.push(element);
      return accumulator;
    }

    last = accumulator[accumulator.length - 1];
    if (consecutiveList.length) {
      // if consecutivity has started
      if (element - consecutiveList[consecutiveList.length - 1] === 1) {
        // if still consecutive
        consecutiveList.push(element);
      } else {
        // if not consecutive anymore
        accumulator = pushToResult(consecutiveList, accumulator);
        consecutiveList = [];
        accumulator.push(element);
      }
    } else { // if currently there is no consecutivity 
      if (element - last === 1) {
        // if consecutivity just started
        consecutiveList.push(last, element);
        accumulator.pop(); // pop the 'last'
      } else {
        accumulator.push(element);
      }
    }
    return accumulator;
  }, []);

  // if something remain on consecutiveList
  result = pushToResult(consecutiveList, result);

  return result.join(',');
}
