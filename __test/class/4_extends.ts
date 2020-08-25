let g1_i1: int32 = 3;

class A {
  constructor() {
    this.pa = this.pa + 100;
  }
  pa: number = 10;
  name: string = "aaa";

  getPa(): number {
    return this.pa;
  }

  static count(): number {
    return g1_i1++;
  }

  getName(): string {
    return this.name;
  }
};

class B extends A {
  pa: number = 20;
  getPa(): number {
    return this.pa;
  }
  getClassName(): string {
    return "B";
  }
};

class C extends B {

};

let vc_c: C = new C();
let vc_b: B = new C();
let vc_a: A = new C();
let vc_c_b: B = vc_c;
let vc_c_a: A = vc_c;

let vb_b: B = new B();
let vb_a: A = new B();
let vb_b_a: A = vb_b;

let va_a: A = new A();

console.log('[vc] vc_c.getPa()=', vc_c.getPa(), '; vc_b.getPa()=', vc_b.getPa(), '; vc_a.getPa()=', vc_a.getPa());
console.log('[vc] vc_c_b.getPa()=', vc_c_b.getPa(), '; vc_c_a.getPa()=', vc_c_a.getPa());
console.log('[vb] vb_b.getPa()=', vb_b.getPa(), '; vb_a.getPa()=', vb_a.getPa(), '; vb_b_a.getPa()=', vb_b_a.getPa());
console.log('[va] va_a.getPa()=', va_a.getPa());

console.log('vc_c.getClassName()=', vc_c.getClassName(), '; vc_b.getClassName()=', vc_b.getClassName(), '; vc_c_b.getClassName()=', vc_c_b.getClassName(), '; vb_b.getClassName()=', vb_b.getClassName());

export { };