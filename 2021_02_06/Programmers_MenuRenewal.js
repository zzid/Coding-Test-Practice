function solution(orders, course) {
  const combinations = (str, length) => {
    var recursive = function (active, rest, a) {
      if (!active && !rest) return;
      if (!rest) {
        if (active.length === length) a.push(active.split("").sort().join(""));
      } else {
        recursive(active + rest[0], rest.slice(1), a);
        recursive(active, rest.slice(1), a);
      }
      return a;
    };
    return recursive("", str, []);
  };

  return course
    .reduce((answer, c) => {
      let objs = orders
        .map((o) => combinations(o, c))
        .reduce((obj, com) => {
          com.forEach((s) => {
            if (!obj[s]) obj[s] = 1;
            else obj[s]++;
          });
          return obj;
        }, {});

      let maxV = Math.max(...Object.values(objs));

      Object.keys(objs).forEach((key) => {
        if (maxV <= 1) return;
        if (objs[key] === maxV) answer.push(key);
      });
      return answer;
    }, [])
    .sort();
}
