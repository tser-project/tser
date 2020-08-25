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
}


class B {
  pca: A;
  pb: number = 12;
  constructor() {
    this.pca = new A();
  }
  getPb(): number {
    return ++this.pb;
  }
  getPca(): A {
    return this.pca;
  }
  getPca_Pa(): number {
    return this.pca.getPa();
  }
}

let b: B = new B();
console.log('b.pca.getPa()      = ', b.pca.getPa());
let pca: A = b.getPca();
console.log('pca.getPa()        = ', pca.getPa());
console.log('b.getPca().getPa() = ', b.getPca().getPa());
console.log('b.getPca_Pa()      = ', b.getPca_Pa());


class C {
  pcb: B = new B();
  pb: number = 3;

  getPcb_pb(): number {
    return this.pcb.getPb();
  }

  getPcb_Pca_Pa(): number {
    return this.pcb.pca.getPa();
  }

  getPcb_Pca_Pa2(): number {
    return this.pcb.getPca().getPa();
  }
}

let c: C = new C();

console.log('c.getPcb_Pca_Pa()  = ', c.getPcb_Pca_Pa());
console.log('c.getPcb_Pca_Pa2() = ', c.getPcb_Pca_Pa2());
console.log('c.getPcb_Pca_Pa2() = ', c.pcb.pca.getPa(), ' ; ', c.pcb.getPca().getPa());
console.log('c.getPcb_pb()      = ', c.getPcb_pb());

export { };
