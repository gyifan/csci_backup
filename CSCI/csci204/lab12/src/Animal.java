import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.util.Scanner;

/**
 * Extra Credit: Read/Write an object file.
 * 
 * Plays the animal game
 * 
 */
public class Animal {

	private static Scanner input = new Scanner(System.in);

	/**
	 * Determines if a response is yes
	 * 
	 * @param response
	 *            the response to check
	 * @return true if it is yes, false otherwise
	 */
	public static boolean responseIsYes(String response) {
		response = response.toLowerCase();
		return response.equals("yes") || response.equals("y");
	}

	/**
	 * Plays the animal game with a given root node
	 * 
	 * @param root
	 *            node containing a question to ask
	 */
	public static void play(TreeNode<String> root) {
		String newAnimal;
		String question;

		if (root.getLeft() == null && root.getRight() == null) {
			System.out.print("Is it a " + root.getData() + "? ");
			if (responseIsYes(input.nextLine())) {
				System.out.println("**=========================**");
				System.out.println("^-^ WOW. I guessed right! ^-^");
				System.out.println("**=========================**");
			} else {
				System.out
						.print("I guessed wrong. What animal were you thinking of? ");
				newAnimal = input.nextLine();
				System.out
						.println("Type in an additional question I should have asked. ");
				question = input.nextLine();
				System.out.print("Is the correst answer yes or no? ");
				if (responseIsYes(input.nextLine())) {
					root.setRight(new TreeNode<String>(newAnimal, null, null));
					root.setLeft(new TreeNode<String>(root.getData(), null,
							null));
					root.setData(question);
				} else {
					root.setLeft(new TreeNode<String>(newAnimal, null, null));
					root.setRight(new TreeNode<String>(root.getData(), null,
							null));
					root.setData(question);
				}
			}
		} else {
			System.out.print(root.getData() + " ");
			if (responseIsYes(input.nextLine()))
				play(root.getRight());
			else
				play(root.getLeft());
		}
	}

	/**
	 * Starts program execution
	 * 
	 * @param args
	 *            any command line argument turns on debug mode
	 * @throws ClassNotFoundException
	 * @throws IOException
	 * @throws FileNotFoundException
	 */
	public static void main(String[] args) throws ClassNotFoundException,
			FileNotFoundException, IOException {
		boolean debug = args.length == 1;

		// Start with three nodes
		TreeNode<String> left = new TreeNode<String>("tiger", null, null);
		TreeNode<String> right = new TreeNode<String>("chicken", null, null);
		TreeNode<String> root = new TreeNode<String>("Does it have feathers?",
				left, right);

		String response;

		System.out.println("Welcome to the Animal Game. ");
		System.out.print("Do you want load a file? ");
		if (responseIsYes(input.nextLine())) {
			System.out.print("What's the file name? ");
			ObjectInputStream in = new ObjectInputStream(new FileInputStream(
					input.nextLine()));
			root = (TreeNode<String>) in.readObject();
		}

		do {
			System.out.print("Think of an animal.  ");
			play(root);
			if (debug)
				root.print();
			System.out.print("\nPlay again? ");
			response = input.nextLine();
		} while (responseIsYes(response));

		System.out.print("Do you want to save the file? ");
		if (responseIsYes(input.nextLine())) {
			System.out.print("What's the file name? ");
			ObjectOutputStream out = new ObjectOutputStream(
					new FileOutputStream(input.nextLine()));
			out.writeObject(root);
			out.close();
		}
	}
}
