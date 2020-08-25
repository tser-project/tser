/**
 * Only support 'Date.now()' (used for performance testing)
 */
let timeStart: int64 = Date.now(); // must be int64, 'number' or 'int32' is wrong
function fib(n: number): number {
  if (n <= 2) {
    return n;
  }
  return fib(n - 1) + fib(n - 2);
}

let result: number = fib(42);
let timeEnd: int64 = Date.now();

console.log('use time (ms): ', timeEnd - timeStart, '; result=', result);