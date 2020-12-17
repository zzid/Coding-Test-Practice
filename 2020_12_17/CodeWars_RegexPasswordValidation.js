function validate(password) {
  let regex = /^(?=.*[A-Z])(?=.*[a-z])(?=.*\d)[A-Za-z\d]{6,}$/;
  return password.match(regex);
}
