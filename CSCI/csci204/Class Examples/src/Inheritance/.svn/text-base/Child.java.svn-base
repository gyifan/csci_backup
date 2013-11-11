package Inheritance;

// Thanks Yifan for discovering all this

public class Child extends Parent {
	public Child() {
		super(4); // comment out this call to see a bug
		System.out.println("child cons");
	}

	public Child(int x) {
		super(4);// comment out this call to see a bug
		System.out.println("child cons 2");
	}

	public static void main(String[] args) {
		// Both of these call the default parent constructor first
		// unless they have a super call to the other constructor

		// If there is no default parent constructor, you MUST call super on
		// another constructor.
		Child c = new Child();
		Child c2 = new Child(3);
	}
}
