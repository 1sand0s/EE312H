class A{
	B b;

	A(){
		b = new B();
	}

	public static void main(String args[]){
		A a = new A();
		a.b.Display();
	}
}
