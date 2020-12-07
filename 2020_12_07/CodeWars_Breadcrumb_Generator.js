const ignoreString = ['the','of','in','from','by','with','and','or','for','to','at','a'];
const makeATag = (href, str, separator) => {
  str = handleMoreThan30(str);
  return `<a href="${href}">${str}</a>${separator}`;
};
const makeSpanTag = (str) => {
  let noHTML = str.split('.')[0];
  noHTML = handleMoreThan30(noHTML);
  return `<span class="active">${noHTML}</span>`;
};
const handleMoreThan30 = (str) => {
  let parsed = str.replace('-', '');
  if (parsed.length >= 30) {
    let splited = str.split('-');
    return splited
      .map((string) => {
        if (!ignoreString.includes(string)) {
          return string[0];
        }
      })
      .join('')
      .toUpperCase();
  } else return str.replace(/-/g, ' ').toUpperCase();
};
function generateBC(url, separator) {
  url = url.replace(/(http|https):\/\//g,'');
  let splited = url.split('/');
  console.log(url, splited);
  if (splited[splited.length - 1].match('index') || splited[splited.length - 1] === ''){
    splited.pop();
  }

  if (splited.length === 1) return makeSpanTag('home');
  let stack = '';
  let result = splited.map((str, index) => {
    str = str.replace(/[#\?].*/g, '');
    if (index === 0) return `<a href="/">HOME</a>${separator}`;
    else if (index === splited.length - 1) return makeSpanTag(str);
    else {
      if (stack === '') stack = `/${str}/`;
      else stack += `${str}/`;
      return makeATag(stack, str, separator);
    }
  });
  return result.join('');
}
