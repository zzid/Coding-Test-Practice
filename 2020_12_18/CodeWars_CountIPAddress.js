const numberOfIPs = (IP) => {
  return IP.split('.').reduce((sum, ip, idx) => {
    sum += ip * Math.pow(256, 3 - idx);
    return sum;
  }, 0);
};
function ipsBetween(start, end) {
  return numberOfIPs(end) - numberOfIPs(start);
}
