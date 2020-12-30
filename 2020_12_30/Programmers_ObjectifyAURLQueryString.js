function convertQueryToMap(query) {
  const hexToASCII = (hex) => String.fromCharCode(parseInt(hex, 16));

  const getValue = (str) => {
    if (!str) return str; // if str is undefined
    let hexCodes = str.match(/\%.{2}/g);
    if (!hexCodes) return str; // if there is no hex code
    return hexCodes.reduce((result, hexCode) => {
      let regex = new RegExp(hexCode, 'g');
      return result.replace(regex, hexToASCII(hexCode.replace(/%/g, '')));
    }, str);
  };

  if (!query) return {};
  let queries = query.split('&');
  return queries.reduce((obj, query) => {
    let keyAndValue = query.split('=');
    let keys = keyAndValue[0].split('.');
    let value = getValue(keyAndValue[1]);
    let curObj = obj;
    keys.map((key, index) => {
      if (!curObj[key]) {
        curObj[key] = index === keys.length - 1 ? value : {};
      }
      curObj = index === keys.length - 1 ? obj : curObj[key];
    });
    return obj;
  }, {});
}
