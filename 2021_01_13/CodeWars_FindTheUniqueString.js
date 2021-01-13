function findUniq(arr) {
  let shrinkedArr = arr.map((a) => {
    return [...new Set(a.toLowerCase())].sort().join('');
  });
  for (let i = 0; i < shrinkedArr.length; i++) {
    let item = shrinkedArr[i];
    if (shrinkedArr.indexOf(item) === shrinkedArr.lastIndexOf(item))
      return arr[i];
  }
}
