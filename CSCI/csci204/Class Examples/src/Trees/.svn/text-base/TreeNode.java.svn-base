package Trees;

public class TreeNode<T> {

	private T data;
	private TreeNode<T> left;
	private TreeNode<T> right;

	/** Creates a new tree node instance. */
	public TreeNode() {
		this(null, null, null);
	}

	/** Creates a new tree node instance. */
	public TreeNode(T newData) {
		this(newData, null, null);
	}

	/**
	 * Creates a new TreeNode instance.
	 * 
	 * @param newData
	 *            the data to be associated with this node.
	 * @param newleft
	 *            a reference to the left node in the binary tree.
	 * @param newright
	 *            a reference to the right node in the binary tree.
	 */
	public TreeNode(T newData, TreeNode<T> newLeft, TreeNode<T> newRight) {
		data = newData;
		left = newLeft;
		right = newRight;
	}

	public int size() {
		return 1;
	}

	public int height() {
		return 1;
	}

	public void printPreOrder() {
	}

	public void printInOrder() {
	}

	public void printPostOrder() {
	}

	// General tree. You just add and remove wherever you like.
	public static void main(String[] args) {
		/*            ___W___
		 *          _B_     _Q_
		 *         E   T   Z   M
		 */
		
		// create the tree
		TreeNode<String> root = new TreeNode("W");
		
		// add and delete done with getters and setters
		root.setLeft(new TreeNode("B");
		root.setRight(new TreeNode("Q");
		TreeNode<String> node;
		node = root.getLeft();
		node.setLeft(new TreeNode("E");
		node.setRight(new TreeNode("T");
		node = root.getRight();
		node.setLeft(new TreeNode("Z");
		node.setRight(new TreeNode("M");
		
		System.out.println("Size: " + root.size()); // 7
		// is empty makes no sense here since the root is a node too
		System.out.println("Height: " + root.height()); // 3
		System.out.print("Preorder: ");
		root.printPreOrder(); // W B E T Q Z M
		System.out.print("Inorder: ");
		root.printInOrder();
		System.out.print("Postorder: ");
		root.printPostOrder();

	}
}
