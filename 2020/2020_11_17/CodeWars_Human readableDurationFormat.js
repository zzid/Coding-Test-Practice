function formatDuration(seconds) {
  if (seconds === 0) return "now";
  let ss = seconds % 60,
    mm = parseInt(seconds / 60) % 60, //
    hh = parseInt(seconds / 3600) % 24,
    dd = parseInt(parseInt(seconds / 3600) / 24) % 365,
    yy = parseInt(parseInt(parseInt(seconds / 3600) / 24) / 365);
  let times = [yy, dd, hh, mm, ss];
  console.log(times);
  // let domain = { 0: "year", 1: "day", 2: "hour", 3: "minute", 4: "second" };
  // CHANGED >>
  let domain = ["year", "day", "hour", "minute", "second"];
  let domainAdded = times.reduce((acc, e, i) => {
    // let str = "";
    // str += e !== 0 ? `${e} ${domain[i]}` : "";
    // CHANGED >>
    let str = e !== 0 ? `${e} ${domain[i]}` : "";
    if (e !== 0) {
      str += e > 1 ? "s" : "";
      acc.push(str);
    }
    return acc;
  }, []);
  console.log(domainAdded);
  if (domainAdded.length === 1) return domainAdded[0];
  let ret = domainAdded.reduce((acc, e, i) => {
    // if (i === domainAdded.length - 1) {
    //   acc += " and " + e;
    // } else if (i === 0) acc += e;
    // CHANGED >>
    if (i === 0) acc += e;
    else if (i === domainAdded.length - 1) acc += " and " + e;
    else acc += ", " + e;
    return acc;
  }, "");
  return ret;
}
