let g1_n1: number = 10;
let g1_i1: int32 = 20;
let g1_i2: int64 = 30;
let g1_f1: float = 40.0;
let g1_d1: double = 50.0;


/// basic
for (let i = 0; i < 10; i++) {
  g1_n1--;
}

/// continue break
for (let i = 0; i < 10; i++) {
  g1_i1--;
  if (i == 5) {
    continue;
  }
  if (g1_i1 < 13) {
    break;
  }
}


/// other cases
for (; g1_f1 > 31;) {
  g1_f1 -= 1;
}

for (; ; g1_d1 += 1) {
  if (g1_d1 > 60) {
    break;
  }
}

for (; ;) {
  g1_i2--;
  if (g1_i2 < 10) {
    break;
  }
}


console.log('g1_n1=', g1_n1, '; g1_i1=', g1_i1, '; g1_i2=', g1_i2, '; g1_f1=', g1_f1, '; g1_d1=', g1_d1);


export { };