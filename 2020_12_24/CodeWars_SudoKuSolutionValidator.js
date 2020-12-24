function validSolution(board) {
  const toSubGrid = (x, y) => {
    if (x < 3) {
      if (y < 3) return 0;
      else if (y < 6 && y >= 3) return 1;
      else if (y < 9 && y >= 6) return 2;
    } else if (x < 6 && x >= 3) {
      if (y < 3) return 3;
      else if (y < 6 && y >= 3) return 4;
      else if (y < 9 && y >= 6) return 5;
    } else if (x < 9 && x >= 6) {
      if (y < 3) return 6;
      else if (y < 6 && y >= 3) return 7;
      else if (y < 9 && y >= 6) return 8;
    }
  };

  const bitMaskingCheck = (num) => {
    let allMasked = Math.pow(2, 10) - 2; // -1 , -1 ( since 0 is not included )
    return !(allMasked ^ num);
  };

  let verticallyBitMaskedNumbers = new Array(9).fill(0);
  let subGridBitMaskedNumbers = new Array(9).fill(0);

  // check horizontally
  let result = board.reduce((flag, nums, yIndex) => {
    let horizontallyBitMaskedNumber = nums.reduce((maskedBin, num, xIndex) => {
      numToMasking = 1 << num;
      verticallyBitMaskedNumbers[xIndex] += numToMasking;
      subGridBitMaskedNumbers[toSubGrid(xIndex, yIndex)] += numToMasking;
      maskedBin += numToMasking;
      return maskedBin;
    }, 0);
    flag = bitMaskingCheck(horizontallyBitMaskedNumber);
    return flag;
  }, true);

  // check vertically, subGrid
  return [...verticallyBitMaskedNumbers, ...subGridBitMaskedNumbers].reduce(
    (flag, number) => bitMaskingCheck(number),
    result
  );
}
