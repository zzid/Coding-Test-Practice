const Calculator = function () {
  this.evaluate = (string) => {
    let splited = string.split(" ");
    let go = "",
      last,
      skip = false;
    let first = splited.reduce((acc, element) => {
      skip = false;
      e = parseInt(element) ? parseInt(element) : element;
      if (go === "*" || go === "/") {
        if (typeof last !== "number") last = parseInt(last);
        if (go === "*") {
          acc.push(last * e);
        } else {
          acc.push(last / e);
        }
        skip = true;
        go = "";
      }
      if (e === "*" || e === "/") {
        last = acc.pop();
        go = e === "*" ? "*" : "/";
      } else {
        if (!skip) acc.push(e);
      }
      return acc;
    }, []);
    console.log(first);
    if (first.length === 1) return first[0];
    let second = first.reduce((acc, e) => {
      skip = false;
      if (go === "+" || go === "-") {
        if (typeof last !== "number") last = parseInt(last);
        if (go === "+") {
          acc.push(last + e);
        } else {
          acc.push(last - e);
        }
        skip = true;
        go = "";
      }
      if (e === "+" || e === "-") {
        last = acc.pop();
        go = e === "+" ? "+" : "-";
      } else {
        if (!skip) acc.push(e);
      }
      return acc;
    }, []);
    return second[0];
  };
};
