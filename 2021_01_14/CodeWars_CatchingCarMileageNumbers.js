const validateNumber = (number) => {
  let result = false;
  let numberStr = number.toString();
  let splited = numberStr.split('');

  // # condition 0
  if (splited.length < 3) return false;

  // # condition 1
  let test1 = splited.concat();
  test1.shift();
  let zeros = test1.filter((num) => num === '0');
  if (zeros.length === test1.length) return true;

  // # condition 2
  let test2 = splited.concat();
  let setOfNums = [...new Set(test2)];
  if (setOfNums.length === 1) return true;

  // # condition 3
  let test3 = splited.concat();
  result = true;
  for (let i = 0; i < test3.length - 1; i++) {
    if (test3[i + 1] === '0') {
      if (test3[i] !== '9') {
        result = false;
        break;
      }
    } else {
      if (+test3[i] >= +test3[i + 1]) {
        result = false;
        break;
      } else {
        if (Math.abs(+test3[i] - +test3[i + 1]) !== 1) {
          result = false;
          break;
        }
      }
    }
  }
  if (result) return result;

  // # condtion 4
  let test4 = splited.concat().reverse();
  result = true;
  for (let i = 0; i < test4.length - 1; i++) {
    if (test4[i] === '0') {
      if (test4[i + 1] !== '1') {
        result = false;
        break;
      }
    } else {
      if (+test4[i] >= +test4[i + 1]) {
        result = false;
        break;
      } else {
        if (Math.abs(+test4[i] - +test4[i + 1]) !== 1) {
          result = false;
          break;
        }
      }
    }
  }
  if (result) return result;

  // # condition 5
  result = true;
  for (let i = 0; i < splited.length / 2; i++) {
    if (splited[i] !== splited[splited.length - 1 - i]) {
      result = false;
      break;
    }
  }
  return result;
};
const checkNumber = (number, awesomePhrases) => {
  return validateNumber(number) || awesomePhrases.includes(number);
};
function isInteresting(number, awesomePhrases) {
  if (checkNumber(number, awesomePhrases)) return 2;
  else if (
    checkNumber(number + 1, awesomePhrases) ||
    checkNumber(number + 2, awesomePhrases)
  )
    return 1;
  else return 0;
}
// 2 : interesting
// 1 : if an interesting number occurs within the next two miles
// 0 : number is not interesting
