function modulus(m, a) {
  let pm = Math.abs(m);
  let pa = Math.abs(a);

  while (pm >= pa) {
    let diff = pm - pa;
    pm = diff;
  }
  return m < 0 ? -pm : pm;
}
function buildInModOperator(a, m) {
  // how Js does modulo arithmetic
  return a - m * Math.ceil(a / m);
}
