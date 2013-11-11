package Polymorphism;

public class MethodPolymorphism {

	public int foo() { return 3; }
	public int foo(double x) { return 4; }
	public int foo(boolean x) { return 5; }
	public int foo(int x, boolean y, String z) { return 6; }
	public int foo(int x, boolean y, int z) { return 7; }
	
	// public void foo() { } // A different return type is not allowed.
	
	public static void main(String[] args) {
		MethodPolymorphism mp = new MethodPolymorphism();
		// These calls all match up with the method that has the same input types.
		System.out.println(mp.foo());
		System.out.println(mp.foo(3.14));
		System.out.println(mp.foo(true));
		System.out.println(mp.foo(2, true, "hi"));
		System.out.println(mp.foo(2, true, 8));
		
		// Which foo method wil this call?
		System.out.println(mp.foo(6));
	}
}
