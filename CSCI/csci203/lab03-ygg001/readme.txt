/*===========================================
 * Experience with Various Types of Errors
 *===========================================
 */
 
/*===========================================
 * Exercise 1
 *===========================================
 */
 The Error Message shows that the local variable z may not
 have be initialized. It reminds us that we haven't put value
 in z yet.
 
/*===========================================
 * Exercise 3a
 *===========================================
 */
 The // made the "{" after it as a comment. The Eclipse shows 
 that there is a syntax error. It's expecting a :{" after the 
 token "ErrorTest1". 
 
/*===========================================
 * Exercise 3b
 *===========================================
 */
 The similar problem happened. The // made the "{" after it as
 a comment. The Eclipse shows that there is a syntax error. It
 expects a "{" after the token ")".
 
/*===========================================
 * Exercise 3c
 *===========================================
 */
 The // made "double y = 4.5;" as a comment, which made the y
 in line 10 undefined. Eclipse shows y in line 10 cannot be 
 resolved. 
 
/*===========================================
 * Exercise 3d
 *===========================================
 */
 After taking out the quote mark. The java can't recognize ":".
 The Eclipse shows a syntax error and ask us to remove ":".
 
/*===========================================
 * Exercise 3e
 *===========================================
 */
 The class lost its content in main(). The Eclipse shows three
 errors. One is suggesting adding "}" after "{" in line 3. The
 other two are asking us to remove "{" and "}" in line 4 and
 line 13, respectively.
 
/*===========================================
 * Exercise 3f
 *===========================================
 */
 Since 4.5 has one decimal number, we can't generate it as an 
 int. The Eclipse shows mismatch of the type and number.
 
/*===========================================
 * Exercise 3g
 *===========================================
 */
 As integer is not a type, it can't be used there. The Eclipse
 shows no integer type.
 
/*===========================================
 * Semantic Errors
 *===========================================
 */
 Error is "b is NaN". Since we can't take squre root of -2, 
 NaN show it's not a number.
 
/*===========================================
 * Reading the Java String API
 *===========================================
 */
 charAt(int index);
 codePointAt(int index);
 codePointBefore(int index);
 codePointCount(int beginIndex, int endIndex);
 compareTo(String anotherString);
 
/*===========================================
 * Intent Errors
 *===========================================
 */
 As we wanted to print the value of b, it printed out value of
 a for b instead. 