let g1_i1: int32 = 20;
let g1_f1: float = 40.0;
let g1_i2: int32 = 30;
let g1_i3: int32 = 30;

/// do
do {
  g1_i1--;
  if (g1_i1 < 11) {
    break;
  }
} while (g1_i1 > 5);


/// while
while (g1_f1 > 5) {
  g1_f1 -= 1;
  if (g1_f1 < 10) {
    break;
  }
}

/// continue
while (g1_i2 > 10 && g1_i3 > 10) {
  g1_i2--;
  if (g1_i2 < 15) {
    break;
  }
  if (g1_i3 < 20) {
    continue;
  }
  g1_i3--;
}


console.log('g1_i1=', g1_i1, '; g1_f1=', g1_f1, '; g1_i2=', g1_i2, '; g1_i3=', g1_i3);


export { };