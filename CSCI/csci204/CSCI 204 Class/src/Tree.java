import java.util.Random;

/**
 * CSCI 204, Yifan Ge
 * Assiangment CSCI 204 Class
 * Created: Apr 27, 2011, 10:57:47 AM
 */

/**
 * @author Yifan Ge
 * 
 */
public class Tree {

	// instance fields
	private Tree left;
	private Tree right;
	private int data;

	public Tree() {
		left = null;
		right = null;
		data = 0;
	}

	public Tree(int data) {
		left = null;
		right = null;
		this.data = data;
	}

	public boolean isEmpty() {
		return false;
	}

	public int size() {
		int size = 0;
		size += 1;
		if (left != null)
			size += left.size();
		if (right != null)
			size += right.size();
		return size;
	}

	public int height() {
		int height = 0;
		int heightLeft = 0;
		int heightRight = 0;

		if (left != null)
			heightLeft = left.height();
		if (right != null)
			heightRight = right.height();
		if (heightLeft >= heightRight)
			height = heightLeft + 1;
		else
			height = heightRight + 1;
		return height;
	}

	public void insert(int data) {
		Tree node = new Tree(data);
		if (this.data < node.data) {
			if (right == null)
				right = node;
			else
				right.insert(data);
		} else {
			if (left == null)
				left = node;
			else
				left.insert(data);
		}
	}

	public void inOrderWalk() {
		if (left != null)
			left.inOrderWalk();
		System.out.print(data + " ");
		if (right != null)
			right.inOrderWalk();
	}

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		Random rand = new Random();
		System.out.println("Input numbers: ");
		Tree tree = new Tree(rand.nextInt(50));

		for (int i = 0; i < 20; i++)
			tree.insert(rand.nextInt(50));
		System.out.println(tree.size());
		tree.inOrderWalk();
	}
}
