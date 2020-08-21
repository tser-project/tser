var a = 20;
var b: string = "aa";
var c = false;
var d = 2.1;

// base test
switch (a) {
  case 10:
    a = a + 100;
    c = false;
    break;
  case 20:
    a = a + 200;
    c = true;
    break;
  case 30:
    a = a + 300;
    c = true;
  default:
    a = a + 500;
  case 40:
    a = a + 400;
    c = true;
    break;
}

// string test
switch (b) {
  case "aa":
    a = a + 100;
    break;
  case "bb":
    a = a + 200;
    break;
  default:
    a = a + 300;
}

// bool test
switch (c) {
  case true:
    a = a + 100;
    c = false;
    break;
  case false:
    a = a + 200;
    c = true;
}

// float test
switch (d) {
  case 1.1:
    d = d + 100;
  // d++;
  case 2.1:
    d = d + 200;
  case 3.1:
    d = d + 300;
  default:
    d = d + 400;
}

console.log('a=', a, '; b=', b, '; c=', c, '; d=', d);