var a1 = 20;
var a2 = 20;
var a3 = 20;
var a4 = 20;
var b: string = "aa";
var c = false;
var d = 2.1;

// base test
switch (a1) {
  case 10:
    a1 = a1 + 100;
    c = false;
    break;
  case 20:
    a1 = a1 + 200;
    c = true;
    break;
  case 30:
    a1 = a1 + 300;
    c = true;
  default:
    a1 = a1 + 500;
  case 40:
    a1 = a1 + 400;
    c = true;
    break;
}

// string test
switch (b) {
  case "aa":
    a2 = a2 + 100;
    break;
  case "bb":
    a2 = a2 + 200;
    break;
  default:
    a2 = a2 + 300;
}

// bool test
switch (c) {
  case true:
    a3 = a3 + 100;
    c = false;
    break;
  case false:
    a3 = a3 + 200;
    c = true;
}

// float test
switch (d) {
  case 1.1:
    a4 = a4 + 100;
  // d++;
  case 2.1:
    a4 = a4 + 200;
  case 3.1:
    a4 = a4 + 300;
  default:
    a4 = a4 + 400;
}


console.log('a1=', a1, '; a2=', a2, '; a3=', a3, '; a4=', a4);

export { };