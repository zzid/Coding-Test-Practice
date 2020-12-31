function humanReadable(seconds) {
  const makeString = (time) => (time = time < 10 ? '0' + time : time);
  let times = [];
  let hours = Math.floor(seconds / 3600);
  seconds -= hours * 3600;
  times.push(makeString(hours));

  let minutes = Math.floor(seconds / 60);
  seconds -= minutes * 60;
  times.push(makeString(minutes));
  times.push(makeString(seconds));

  return times.join(':');
}
