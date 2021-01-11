function generateHashtag(str) {
  let result = str.split(" ").reduce((resultStr, e) => {
    if (e !== "") {
      return (resultStr += `${e.charAt(0).toUpperCase()}${e.slice(1)}`);
    }
    return resultStr;
  }, "");
  return (result === "" || result.length >= 140 )? false : `#${result}`;
}
