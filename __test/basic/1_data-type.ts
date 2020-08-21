/// data types
let g1_n1: number = 10;   // equals to int32
let g1_i1: int32 = 20;
let g1_i2: int64 = 30;
let g1_f1: float = 40.0;
const g1_d1: double = 50.0;
let g1_b1: boolean = true;
let g1_s1: string = "aaa";


/// data types automaticlly convert 
let g2_i1: int32 = g1_i2;
let g2_i2: int32 = g1_f1;
let g2_i3: int32 = g1_d1;

let g2_d1: double = g1_i1;
let g2_d2: double = g1_i2;
let g2_d3: double = g1_f1;
let g2_d4: double = g1_b1;


/// type inference (not support for function or class)
let g3_i1 = 20;    // int32
let g3_d1 = 50.0;  // double
let g3_b1 = true;  // bool
let g3_s1 = "bbb"; // string


console.log('g1_n1=', g1_n1, '; g1_d1=', g1_d1, '; g1_b1=', g1_b1, '; g1_s1=', g1_s1, '; g3_s1=', g3_s1);


export { };