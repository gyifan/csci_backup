/*
 *===================================================
 *  Name: Yifan Ge
 *  Course: CSCI 203 / Prof. Zaccone / MWF 1:00
 *  Lab Section: Tuesday 10-12AM
 *  Assignment: Lab #10
 *  Date: 11/09/2010
 *
 *===================================================
 */

/*
 *===================================================
 *
 *	Exercise 1
 *
 *===================================================
 */
import java.util.Scanner;

/**
 * Program to practice finding logic errors.
 * 
 * @author Dan Hyde
 * 
 */
public class Debug {

	/**
	 * Allows the user to enter a value for n then sums the values from 1 to n.
	 * It compiles and runs BUT it contains logic errors!
	 * 
	 * @param args
	 *            unused
	 */
	public static void main(String[] args) {
		Scanner keyboard = new Scanner(System.in);
		int n = 0;
		int k = 1;
		int sum = 0;

		System.out.print("Enter value for n: ");
		n = keyboard.nextInt();

		// System.out.println("n = " + n);
		while (k <= n) {
			sum = sum + k;
			// System.out.println("k= " + k);
			k++;
		}

		System.out.println("The sum of the integers from 1 to " + n + " is "
				+ sum);
	}
}

Test Run: 
Enter value for n: 4
The sum of the integers from 1 to 4 is 10

/*
 *===================================================
 *
 *	Exercise 2
 *
 *===================================================
 */
After I commented out the line with x = x + 1, the program ran in a dead loop. 
It kept printing "x is 1" and can't stop. This is because x value never changed 
in the loop, which meant it would can never satisfy the condition to get out of 
the loop. 

/**
 * CSCI 203, Yifan Ge
 * Nov 10, 2010, 10:35:19 PM
 */

/**
 * This class tests while loop
 * 
 * @author Yifan Ge
 * 
 */
public class TestWhile {

	/**
	 * Tests while loop
	 * 
	 * @param args
	 *            unused
	 */
	public static void main(String[] args) {
		double x = 0.1;
		while (x <= 1.0) {
			System.out.println("x is " + x);
			x = x + 0.1;
		}

	}

}

Run:
x is 0.1
x is 0.2
x is 0.30000000000000004
x is 0.4
x is 0.5
x is 0.6
x is 0.7
x is 0.7999999999999999
x is 0.8999999999999999
x is 0.9999999999999999

The loop ran 10 times.

public class TestWhile {

	/**
	 * Tests while loop
	 * 
	 * @param args
	 *            unused
	 */
	public static void main(String[] args) {
		double x = 0.1;
		while (x <= 0.3) {
			System.out.println("x is " + x);
			x = x + 0.1;
		}

	}

}

Run:
x is 0.1
x is 0.2

The loop only ran twice, but we expected it to run three times. This is because
doubles can't represent some decimal numbers precisely, such as 0.3 in this case.
This causes the loop skipped 0.3. So doubles are bad at counting the number of 
times a loop is done.

/*
 *===================================================
 *
 *	Exercise 3
 *
 *===================================================
 */
Please enter a number: 1.0
The approximation of the square root of 1.0 is 1.000000.

Please enter a number: 4.0
The approximation of the square root of 4.0 is 2.000000.

Please enter a number: 10.0
The approximation of the square root of 10.0 is 3.162278.

/*
 *===================================================
 *
 *	Exercise 4
 *
 *===================================================
 */
Testing a Table from 0 to 20 Celsius
Celsius	  Fahrenheit
   0.0        32.0
   5.0        41.0
  10.0        50.0
  15.0        59.0
Expected:
Celsius   Fahrenheit
   0.0        32.0
   5.0        41.0
  10.0        50.0
  15.0        59.0
  20.0        68.0

Testing a Table from -10 to 3 Celsius
Celsius	  Fahrenheit
 -10.0        14.0
  -5.0        23.0
   0.0        32.0
Expected:
Celsius   Fahrenheit
 -10.0        14.0
  -5.0        23.0
   0.0        32.0 

Testing a Table from 20 to 10 Celsius
Lower bound must be less than upper bound.

Expected: Lower bound must be less than upper bound.

Testing a Table from 10 to 10 Celsius
Lower bound must be less than upper bound.

Expected: Lower bound must be less than upper bound.

/*
 *===================================================
 *
 *	Exercise 5
 *
 *===================================================
 */
response: valid
Expected: valid
