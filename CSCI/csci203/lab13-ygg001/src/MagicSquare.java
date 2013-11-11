import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

/**
 * A magic square is an n x n matrix which, if filled with numbers, the sum of
 * the elements in each row, each column, and the two diagonals is the same
 * value.
 * 
 * This class reads squares from a file. The first number in the file is the
 * size or order of the square. Following that will be size x size integers.
 * 
 * Rick Zaccone, 2010-04-25
 * 
 */
public class MagicSquare {
	private int[][] square;
	private int size;

	/**
	 * Constructs a magic square from the contents of a file.
	 * 
	 * @param fileName
	 *            the name of the file containing the magic square.
	 * @throws FileNotFoundException
	 *             if the file doesn't exist
	 */
	public MagicSquare(String fileName) throws FileNotFoundException {
		Scanner file = new Scanner(new File(fileName));
		size = file.nextInt();
		square = new int[size][size];

		for (int i = 0; i < size; i++)
			for (int j = 0; j < size; j++)
				square[i][j] = file.nextInt();
	}

	/**
	 * Determines the magic constant for this square. All rows, columns and
	 * diagonals should sum to this value.
	 * 
	 * @return the magic constant
	 */
	public int magicConstant() {
		return size * (size * size + 1) / 2;
	}

	/**
	 * Adds the numbers in a row of the square.
	 * 
	 * @param row
	 *            the index of the row to be summed.
	 * @return the sum of the row
	 */
	public int rowSum(int row) {
		int sum = 0;
		for (int i = 0; i < size; i++)
			sum += square[row][i];
		return sum;
	}

	/**
	 * Adds the numbers in a column of the square.
	 * 
	 * @param col
	 *            the index of the column to be summed
	 * @return the sum of the column
	 */
	public int columnSum(int col) {
		int sum = 0;
		for (int i = 0; i < size; i++)
			sum += square[i][col];
		return sum;
	}

	/**
	 * Finds the sum of the main diagonal.
	 * 
	 * @return sum the sum of the main diagonal
	 */
	public int mainDiagonalSum() {
		int sum = 0;
		for (int i = 0; i < size; i++)
			sum += square[i][i];
		return sum;
	}

	/**
	 * Finds the sum of the cross diagonal.
	 * 
	 * @return the sum of the cross diagonal
	 */
	public int crossDiagonalSum() {
		int sum = 0;
		for (int i = 0; i < size; i++)
			sum += square[size - 1 - i][i];
		return sum;
	}

	/**
	 * Determines if the square is a magic square.
	 * 
	 * @return true if square is a magic square, false otherwise
	 */
	public boolean isMagic() {
		int magicConstant = magicConstant();
		for (int row = 0; row < size; row++)
			if (rowSum(row) != magicConstant)
				return false;
		for (int col = 0; col < size; col++)
			if (columnSum(col) != magicConstant)
				return false;
		if (mainDiagonalSum() != magicConstant)
			return false;
		if (crossDiagonalSum() != magicConstant)
			return false;
		return true;
	}

	/*
	 * (non-Javadoc)
	 * 
	 * @see java.lang.Object#toString()
	 */
	public String toString() {
		String result = "";
		for (int row = 0; row < size; row++) {
			for (int col = 0; col < size; col++)
				result += String.format("%3d", square[row][col]);
			result += "\n";
		}
		result += "\n";
		for (int row = 0; row < size; row++)
			result += "row " + row + " sum: " + rowSum(row) + "\n";
		result += "\n";

		for (int col = 0; col < size; col++)
			result += "column " + col + " sum: " + columnSum(col) + "\n";
		result += "\n";

		result += "main diagonal sum:  " + mainDiagonalSum() + "\n";

		result += "cross diagonal sum: " + crossDiagonalSum() + "\n\n";

		if (isMagic())
			result += "This square is a magic square.\n";
		else
			result += "This square is not a magic square.\n";
		result += "\n--------------------------------------------\n\n";

		return result;
	}

	/**
	 * Tests the class by constructing some squares and printing them out.
	 * 
	 * @param args
	 *            unused
	 * @throws FileNotFoundException
	 *             if the file does not exist
	 */
	public static void main(String[] args) throws FileNotFoundException {
		MagicSquare square = new MagicSquare("square1.txt");
		System.out.println(square);
		square = new MagicSquare("square2.txt");
		System.out.println(square);
		square = new MagicSquare("square3.txt");
		System.out.println(square);
		square = new MagicSquare("square4.txt");
		System.out.println(square);
	}
}
