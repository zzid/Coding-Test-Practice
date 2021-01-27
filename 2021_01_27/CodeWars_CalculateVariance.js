const variance = (numbers) => {
  const mean =
    numbers.reduce((sum, number) => {
      return (sum += number);
    }, 0) / numbers.length;

  return (
    numbers.reduce((result, number) => {
      return (result += (number - mean) ** 2);
    }, 0) / numbers.length
  );
};
