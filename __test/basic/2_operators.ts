let g1_n1: number = 10;
let g1_i1: int32 = 20;
let g1_i2: int64 = 30;
let g1_f1: float = 40.0;
let g1_d1: double = 50.0;

/// '+', '-', '*', '/'
g1_n1 = 20 + 10;
g1_i1 = g1_i1 + 20;
g1_f1 = g1_f1 + 30.0;
g1_d1 = g1_d1 - 40;

g1_i2 = g1_i2 * 3;

g1_i1 = g1_i1 / 3;
g1_f1 = g1_f1 / 3;


/// '++', '--'
g1_n1++;
g1_i1++;
g1_i2--;

/// priority
let g2_i1 = 20;
let g2_i2 = g2_i1 + 10 * g2_i1 - 10;     // 210
const g2_i3 = (g2_i1 + 10) * (g2_i1 - 10); // 300

console.log('g2_i2=', g2_i2, '; g2_i3=', g2_i3);


/// '+=', '-=', '*=', '/='
g1_n1 += 1;
g1_i1 -= 1;
g1_i2 *= 2;
g1_f1 /= 2;

/// '<', '>', '<=', '>='
let g3_b1: boolean = g1_n1 > 1;
let g3_b2 = g1_i1 < 1;
let g3_b3 = g1_i2 >= 1;
let g3_b4 = g1_f1 <= 1;
let g3_b5 = g1_d1 <= 100;


/// !
class A { };
let g4_a1: A = null;
const g4_a2: A = new A();

let g4_b1: boolean = !10;
let g4_b2: boolean = !0;
let g4_b3: boolean = !g1_n1;
let g4_b4: boolean = !g1_f1;
let g4_b5: boolean = !!g1_d1;
let g4_b6: boolean = !true;
let g4_b7: boolean = !"";
let g4_b8: boolean = !g4_a1;
let g4_b9: boolean = !g4_a2;


/// 'A? B:C'
let g5_b1 = g3_b1 ? 20 : 10;
let g5_b2 = g3_b1 ? 20.0 : 10;
let g5_b3 = g1_d1 > 50 ? 20.0 : 10;


/// '&&', '||'
let g6_1b: boolean = g1_i1 > 1 && (g1_i1 > 2 || g1_i1 > 3) && g1_i1 > 4 || g1_i1 > 5;


console.log('g3_b5=', g3_b5, '; g4_b7=', g4_b7, '; g5_b1=', g5_b1, '; g5_b3=', g5_b3, '; g6_1b=', g6_1b);


export { };