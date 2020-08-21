class A {
  constructor() {
    this.a = this.a + 100;
  }
  a: number = 11;
  b: string = "abc";
  getA(): number {
    return this.a;
  }
  getB(): string {
    return this.b;
  }
}

class B {
  b: number = 12;
  aa: A;
  constructor() {
    this.aa = new A();
  }
  getB(): number {
    return ++this.b;
  }
}

let aa: A = new A();
let cc2 = aa.getA();
let bb: B = new B();
let cc = bb.aa.getA();
console.log('>>bb.getB()=', bb.getB());
console.log('>>bb.aa.getA() = ', bb.aa.getA(), bb.aa.getB());

// class A {
//   public a: number = 11;
//   private _b: number = 22;
//   c: number = 33;
//   // readonly "ccc": number = 3;
//   // static 3: number = 5;

//   constructor(a: number) {
//     this.a = a;
//     // this.c = this.a + 100;
//   }

//   getA(): number {
//     return this.a;
//   }

//   setA(aa: number): void {
//     this.a = aa + 1 + 10;
//   }

//   getC(): number {
//     // return 6;
//     return this.c;
//   }

//   static getX(): number {
//     return 1;
//   }
// };

// class B extends A {
//   a: number = 100;
//   d: number = 101;
//   c: number = 44;

//   getAA(): number {
//     return this.a;
//   }

//   getCC(): number {
//     // return this.a + super.c;
//     return this.d;
//   }
// };

// final class C extends B {
//   a: number = 333;
//   c: number = 55;
//   public f: number = 444;
// }

// function test(b: number): number {
//   let a: A = new C(399);
//   let out: number = a.getC();
//   a.setA(110);
//   return out;
// }
// console.log('value of A.getX: ', A.getX());

// let timeStart: int64 = Date.now();
// // let bb = test(1);
// // console.log('value of bb: ', bb);
// let timeEnd: int64 = Date.now();
// console.log('timeEnd:', timeEnd, '; timeStart:', timeStart);
// console.log('use time:', timeEnd - timeStart);
