import java.io.Serializable;
import java.util.ArrayList;

/**
 * This class represents a node in a binary tree.
 * 
 * @author Rick Zaccone
 * @version 2.0 2008-04-12
 */
public class TreeNode<T> implements Serializable {
	private T data;
	private TreeNode<T> left;
	private TreeNode<T> right;

	/**
	 * Creates a new tree node instance.
	 * 
	 */
	public TreeNode() {
		this(null, null, null);
	}

	/**
	 * Creates a new <code>TreeNode</code> instance.
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

	/**
	 * Returns the data stored in this node.
	 * 
	 * @return a reference to the data stored in this node.
	 */
	public T getData() {
		return data;
	}

	/**
	 * Returns a reference to the left node in the binary tree.
	 * 
	 * @return a reference to the left node in the binary tree, or null
	 */
	public TreeNode<T> getLeft() {
		return left;
	}

	/**
	 * Returns a reference to the right node in the binary tree.
	 * 
	 * @return a reference to the right node in the binary tree, or null
	 */
	public TreeNode<T> getRight() {
		return right;
	}

	/**
	 * Sets the data associated with this node.
	 * 
	 * @param newData
	 *            the data to be assocated with this node.
	 */
	public void setData(T newData) {
		data = newData;
	}

	/**
	 * Sets the reference to the left node of binary tree.
	 * 
	 * @param newLeft
	 *            the reference to the left node in the binary tree.
	 */
	public void setLeft(TreeNode<T> newLeft) {
		left = newLeft;
	}

	/**
	 * Sets the reference to the right node of binary tree.
	 * 
	 * @param newRight
	 *            the reference to the right node in the binary tree.
	 */
	public void setRight(TreeNode<T> newRight) {
		right = newRight;
	}

	/**
	 * Prints out the tree.
	 */
	public void print() {
		ArrayList<Boolean> lines = new ArrayList<Boolean>();
		printNodes(lines);
	}

	/**
	 * Prints this node and all of its descendants in sorted order.
	 * 
	 * @param lines
	 */
	public void printNodes(ArrayList<Boolean> lines) {
		int level = lines.size();

		if (right != null) {
			lines.add(false);
			printLines(lines, "\n");
			right.printNodes(lines);
			lines.remove(level);
		} else
			printLines(lines, "\n");

		if (level > 0) {
			boolean old = lines.remove(level - 1);
			printLines(lines, "  +--");
			System.out.println(data);
			lines.add(!old);
		} else
			System.out.println(data);

		if (left != null) {
			lines.add(true);
			left.printNodes(lines);
			printLines(lines, "\n");
			lines.remove(level);
		} else
			printLines(lines, "\n");
	}

	/**
	 * Prints out vertical lines for the printed version of the tree.
	 * 
	 * @param lines
	 *            Indicates which levels should have a vertical line
	 * @param suffix
	 *            a string to print after printing the vertical lines.
	 */
	private void printLines(ArrayList<Boolean> lines, String suffix) {
		for (Boolean line : lines)
			if (line)
				System.out.print("  |  ");
			else
				System.out.print("     ");
		System.out.print(suffix);
	}
}
