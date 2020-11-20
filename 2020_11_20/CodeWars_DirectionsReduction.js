function zero(object) {
  if (object) {
    let result = '0 ' + object;
    return calculate(result);
  }
  return '0';
}
function one(object) {
  if (object) {
    let result = '1 ' + object;
    return calculate(result);
  }
  return '1 ';
}
function two(object) {
  if (object) {
    let result = '2 ' + object;
    return calculate(result);
  }
  return '2 ';
}
function three(object) {
  if (object) {
    let result = '3 ' + object;
    return calculate(result);
  }
  return '3 ';
}
function four(object) {
  if (object) {
    let result = '4 ' + object;
    return calculate(result);
  }
  return '4 ';
}
function five(object) {
  if (object) {
    let result = '5 ' + object;
    return calculate(result);
  }
  return '5 ';
}
function six(object) {
  if (object) {
    let result = '6 ' + object;
    return calculate(result);
  }
  return '6 ';
}
function seven(object) {
  if (object) {
    let result = '7 ' + object;
    return calculate(result);
  }
  return '7 ';
}
function eight(object) {
  if (object) {
    let result = '8 ' + object;
    return calculate(result);
  }
  return '8 ';
}
function nine(object) {
  if (object) {
    let result = '9 ' + object;
    return calculate(result);
  }
  return '9 ';
}

const calculate = (string) => {
  let splited = string.split(' ');
  let num1 = parseInt(splited[0]),
    num2 = parseInt(splited[2]),
    operator = splited[1];
  switch (operator) {
    case '*':
      return num1 * num2;
    case '/':
      return parseInt(num1 / num2);
    case '+':
      return num1 + num2;
    case '-':
      return num1 - num2;
  }
};

function plus() {
  return '+ ' + object;
}
function minus() {
  return '- ' + object;
}
function times(object) {
  return '* ' + object;
}
function dividedBy() {
  return '/ ' + object;
}
