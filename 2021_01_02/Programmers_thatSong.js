function solution(m, musicinfos) {
  let  names = [];
  const charConverter = (str) => {
    let result = str;
    result = result.replace(/C#/gi, "Q");
    result = result.replace(/D#/gi, "W");
    result = result.replace(/F#/gi, "R");
    result = result.replace(/G#/gi, "T");
    result = result.replace(/A#/gi, "Y");
    return result;
  };

  const sameCheck = (str) => {
    for (let i = 0; i < str.length; i++) {
      if (str[i] === m[0]) {
        if (str.slice(i, i + m.length) == m) {
          return true;
        }
      }
    }
    return false;
  };
  m = charConverter(m);
  let start, end, name, j;
  for (let i = 0; i < musicinfos.length; i++) {
    let temp = musicinfos[i].split(",");
    for (let j = 0; j < temp.length; j++) {
      if (j == 0) {
        let ti = temp[j].split(":"),
          hh = ti[0],
          mm = ti[1];
        start = parseInt(hh) * 60 + parseInt(mm);
      } else if (j == 1) {
        let ti = temp[j].split(":"),
          hh = ti[0],
          mm = ti[1];
        end = parseInt(hh) * 60 + parseInt(mm);
        if (end > 1440) end = 1440;
      } else if (j == 2) {
        name = temp[j];
      } else if (j == 3) {
        let time = end - start,
          t = "";
        let maked = charConverter(temp[j]);
        if (time > maked.length) {
          let x = parseInt(time / maked.length),
            y = time % maked.length;
          for (let a = 0; a < x; a++) t += maked;
          for (let a = 0; a < y; a++) t += maked[a];
        } else {
          for (let a = 0; a < time; a++) {
            t += maked[a];
          }
        }
        if (sameCheck(t)) {
          names.push({
            n: name,
            leng: time,
            idx: i,
          });
        }
      }
    }
  }
  if (names.length > 0) {
    names.sort((a, b) => {
      if (a.leng === b.leng) {
        return a.idx - b.idx;
      }
      return b.leng - a.leng;
    });
    return names[0].n;
  }
  return "(None)";
}
