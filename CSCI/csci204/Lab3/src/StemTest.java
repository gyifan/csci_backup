public class StemTest {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		Apple apple = new Apple();
		CrabApple crabApple = new CrabApple();

		apple.setStem("black");
		crabApple.setStem("brown");
		apple.getStem();
		crabApple.getStem();

	}

}
