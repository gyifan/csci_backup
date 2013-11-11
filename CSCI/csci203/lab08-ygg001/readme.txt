/*
 *===================================================
 *  Name: Yifan Ge
 *  Course: CSCI 203 / Prof. Zaccone / MWF 1:00
 *  Lab Section: Tuesday 10-12AM
 *  Assignment: Lab #8
 *  Date: 10/26/2010
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
The output shows d-f doesn't not equal 0.2. This happens because double has approximated the number when computer convert decimal number into binary number. This approximation gives rise to the slight differences between 4.35-(4.35-0.2) and 0.2.

/*
 *===================================================
 *
 *	Exercise 2
 *
 *===================================================
 */
/**
	 * Compares two doubles
	 * 
	 * @param args
	 *            unused
	 */
	public static void main(String[] args) {
		double d = 4.35;
		double f = d - 0.2;
		if ((d - f) == 0.2) {
			System.out.println("Comparing doubles obeys Math laws!");
		} else {
			System.out.println("Comparing doubles does not obey Math laws!");
		}
		System.out.println("d - f: " + (d - f));
		System.out.println("Expected: 0.2\n");
		if (areClose(d - f, 0.2)) {
			System.out.println("The doubles are close!");
		} else {
			System.out.println("The doubles are not close!");
		}
		System.out.println("Expected: The doubles are close!");
	}

	/**
	 * Checks if two doubles are close
	 * 
	 * @param x
	 *            the first double
	 * @param y
	 *            the second double
	 * @return true if they are close, false if they aren't
	 */
	public static boolean areClose(double x, double y) {
		return Math.abs(x - y) <= EPSILON;
	}

}

Comparing doubles does not obey Math laws!
d - f: 0.20000000000000018
Expected: 0.2

The doubles are close!
Expected: The doubles are close!

/*
 *===================================================
 *
 *	Exercise 3
 *
 *===================================================
 */
1. false
2. false
3. true
4. negative
5. positive
6. zero
7. positive
8. zero
9. negative
10.negative
11.positive

/*
 *===================================================
 *
 *	Exercise 4
 *
 *===================================================
 */
Result1:Using ==, they are not equal!
Explanation1:This is because p3 and p4 are references to different objects.When we use ==, it only compare the references, which are very likely to be different.

Result2:Using isEqualTo method, they are equal!
Explanation2:As isEqualTo method compare the point object by comparing the x and y value of the point objects. As p3 and p4 have the same x and y value, they are equal.

Result3:
Using ==, they are equal!

Using isEqualTo method, they are equal!
Explanation3:The output of using isEqualTo method falls into the same explanation for result2. For using ==, as we assigned p4 to p3, p3 and p4 have the same reference to the same object. Hence when == compare their references, they are equal.

Result4: p4 is equal to null
Explanation4: As null is not a point object, we only can use == to compare. As null is assigned to p4, p4 has no reference, and p4 is equal to null.

Result5: 
Exception in thread "main" java.lang.NullPointerException
	at Point.main(Point.java:159)
Explanation5: As we assigned null to p4, p4 has no reference to any object. It's impossible to get x in p4.

