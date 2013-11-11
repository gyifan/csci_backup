/*
 *===================================================
 *  Name: Yifan Ge
 *  Course: CSCI 203 / Prof. Zaccone / MWF 1:00
 *  Lab Section: Tuesday 10-12AM
 *  Assignment: Lab #7
 *  Date: 10/12/2010
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
i value is -188157080
Expected value is 987654321000
x value is 9.87654321E11
Expected value is 987654321000.0

The i value is not correct. x value is correct.

/*
 *===================================================
 *
 *	Exercise 2
 *
 *===================================================
 */
f value is 434.99999999999994
Expected value is 435.0

As 4.35 in base 2 has an infinite representation, rounding error occurs.

/*
 *===================================================
 *
 *	Exercise 3
 *
 *===================================================
 */
y value is 435.0
Expected value is 435.0

The value matches what I expected.

/*
 *===================================================
 *
 *	Exercise 4
 *
 *===================================================
 */
Type mismatch: cannot convert from double to int
i value is 434
Expected value is 435

The actual value doesn't match the expected value. This is because 435 in double has rounding error, which makes f=434.99999999999994. And when we cast double to int, java truncate the value after the decimal point. So it appears 434 instead of 435.

/*
 *===================================================
 *
 *	Exercise 5
 *
 *===================================================
 */
the square of squareroot 2 is 2.0000000000000004
Expected value is 2

The answer is not what I expected.

The rounded value of f is 435
Expected value is 435

/*
 *===================================================
 *
 *	Exercise 6
 *
 *===================================================
 */
Testing printf: 1,234,567
Expected:       1,234,567

/*
 *===================================================
 *
 *	Exercise 7
 *
 *===================================================
 */
As the first answer is run as integer, java truncates all the value after the decimal point. The second answer is run as double. So it has value after the decimal point.

/*
 *===================================================
 *
 *	Exercise 8
 *
 *===================================================
 */
Since 5/9 is run as division of two integers, java will consider any integer between 0 and 1 as 0. So this made anything multiplied by 0 equal to 0.

/*
 *===================================================
 *
 *	Exercise 9
 *
 *===================================================
 */
Enter a Fahrenheit temperature: 40
40 = 23 Celsius
Enter another temperature: 40
40.0 = 22.22222222222222 Celsius

Parentheses will make java calculate anything in the parentheses first. Other calculation will do *and /first, + and - next.

/*
 *===================================================
 *
 *	Exercise 9
 *
 *===================================================
 */
Enter a Fahrenheit temperature: 40
40 = 4.444444444444445 Celsius

This is because intFahr-32.0 will gives a double as output.

