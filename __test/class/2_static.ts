class A {
  constructor() {
    this.pa = this.pa + 100;
  }
  pa: number = 10;
  static count: number = 10;

  getPa(): number {
    return this.pa;
  }

  static nextCount(): number {
    return ++A.count;
  }
}

var c: number = A.count;
console.log('c=', c, '; A.count=', A.count, ' ; A.nextCount()= ', A.nextCount(), ' ; A.nextCount()= ', A.nextCount());


export { };