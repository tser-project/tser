/**
 * Support 'debug', 'log', 'info', 'warn', 'error' currently.
 */

let g1_n1: number = 10;
let g1_i1: int32 = 20;
let g1_f2: float = 30.123;
let g1_b1 = true;

console.log('g1_n1=', g1_n1, '; g1_b1=', g1_b1, '; g1_f2=', g1_f2);

class A { };
let a: A = null;
console.debug('a=', a);


console.error('boolean: ', true, '; double: ', 3.2);
