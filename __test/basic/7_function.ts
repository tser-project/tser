var a: number = 11;
a++;
var b: number = a + 3.0;
var d: float = 3 + a;
var c: boolean = true;
var e: int64 = 32;

if (c) {
  e++;
}

console.log('>>e=', e);

function readd1(a: number): number {
  var b: number = 1111;
  if (c) {
    var b: number = 2222;
    a = a + 10;
    if (a > 50) {
      a = a + 20 + 3.3;
    } else {
      a = a + 30;
    }
  } else if (a > 20) {
    a = a + 40;
  } else {
    a = a + 50;
  }
  b = b + 3333;
  a = a + 60;
  return a;
}

var f: double = readd1(b);

function add(aa: number, bb: number): number {
  var d: number = 3;
  function readd(d: number): number {
    aa = aa + 1;
    return d + aa + 1;
  }
  // console.log('>>aa');
  aa = aa + 10;
  bb = bb + 20;
  return a + aa + bb + d + readd(99) + readd1(3);
}
var cv: int64;
cv = add(a, b);

for (; b > 15; b--) {
  a--;
  var d: number = 10;
  d++;
  if (a < 5) {
    break;
  }
}

do {
  a--;
  if (a < 111) {
    break;
  }
} while (a > 5);

while (a > 5) {
  a--;
  if (a < 111) {
    break;
  }
}

a = a > 5 ? 100 : 200;

function fa(): number {
  var d: number = 111;
  if (d > 10) {
    d = d + 40;
    return 11;
  } else if (d > 5) {
    return 22;
  }
  for (var c: number = 1; c < a; c++) {
    b = b + 33;
    if (c > 5) {
      c = c + 20;
      return 0;
    } else if (c > 10) {
      c = c + 30;
    } else {
      c = c + 40;
      continue;
    }
    d = b--;
  }
  if (a > 10) {
    return 0;
  }
  d = d + 44;
  return 1;
}
fa();
