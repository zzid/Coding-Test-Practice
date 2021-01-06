function isMerge(s, part1, part2) {
  if (s.length !== part1.length + part2.length) return false;
  if (!s.length) return true;

  if (part1[0] === s[0] && isMerge(s.slice(1), part1.slice(1), part2)) {
    return true;
  }

  if (part2[0] === s[0] && isMerge(s.slice(1), part1, part2.slice(1))) {
    return true;
  }

  return false;
}
