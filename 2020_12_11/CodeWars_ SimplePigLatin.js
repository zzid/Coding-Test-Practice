const makeWord = (str) => {
  if (!str.match(/[A-Za-z]/g)) return str;
  let splited = str.split('');
  splited.push(splited.shift());
  return splited.join('') + 'ay';
};
function pigIt(str) {
  return str
    .split(' ')
    .map((string) => makeWord(string))
    .join(' ');
}

/*
function pigIt(str){
  return str.replace(/(\w)(\w*)(\s|$)/g, "\$2\$1ay\$3")
}
*/
