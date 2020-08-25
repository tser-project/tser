class A {
  constructor() {
    this.pa = this.pa + 100;
  }

  getPa(): number {
    return ++this.pa;
  }
  pa: number = 10 + 1;
  public name: string = "aaa";

  getName(): string {
    return this.name;
  }

  // access control is treated as 'public' currently; 
  public addPa(): void {
    this.pa++;
  }

  setName(name: string): void {
    this.name = name;
  }
}

let a: A = new A();
console.log('a.getPa()=', a.getPa());
a.addPa();
console.log('a.getPa()=', a.getPa());

console.log('a.getName()=', a.getName());
a.setName("bbb");
console.log('a.getName()=', a.getName());


export { };