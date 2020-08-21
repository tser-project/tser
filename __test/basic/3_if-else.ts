let g1_n1: number = 10;
let g1_i1: int32 = 20;
let g1_i2: int64 = 20;
let g1_b1: boolean = false;


/// normal case
if (g1_n1 > 10) {
  g1_i1 += 10;
} else {
  g1_i1--;
}


/// nested case
if (g1_n1 > 10) {
  g1_i2 += 10;
} else if (g1_n1 > 5) {
  if (g1_b1) {
    g1_i2 += 4;
  } else {
    g1_i2 += 5;
  }
} else if (g1_n1 > 3) {
  g1_i2 += 3;
} else {
  g1_i2++;
}


console.log('g1_i1=', g1_i1, '; g1_i2=', g1_i2);


export { };