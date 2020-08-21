let g1_i1: int32 = 20;
let g1_f1: float = 40.0;

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

// while ((g1_f1 > 5) && g1_f1 > 10) {
//   g1_f1 -= 1;
//   if (g1_f1 < 10) {
//     break;
//   }
// }


console.log('g1_i1=', g1_i1, '; g1_f1=', g1_f1);


export { };