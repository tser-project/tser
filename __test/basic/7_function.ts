/**
 * Currently not support function as return value or argument
 */

let g1_n1: number = 10;
let g1_i1: int32 = 20;
let g1_i2: int32 = 30;


/// normal function
function plus(a: number, b: number): int32 {
  return a + b;
}

console.log('plus(g1_n1, g1_i1)= ', plus(g1_n1, g1_i1));


/// nested function
function plusGenerator(a: number, b: number): int32 {
  function plus(b: int32): int32 {
    return a + b;
  }
  return plus(b);
}

console.log('plusGenerator(g1_n1, g1_i2)= ', plusGenerator(g1_n1, g1_i2));


/// function scope
function plusGenerator2(a: number, b: number): int32 {
  a++;
  function plus(b: int32): int32 {
    let a = 100;
    if (true) {
      let a = 200;
      a++;
    }
    return a + b;
  }
  return plus(b);
}

console.log('plusGenerator2(g1_n1, g1_i2)= ', plusGenerator2(g1_n1, g1_i2));


export { };