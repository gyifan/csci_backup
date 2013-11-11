/*
 * Exercise for lab02
 * 
 * @author Yifan ge
 * 
 */
public interface Date {

	public void setDate(int month, int day, int year);

	public void displayShort();

	public void displayVerbose();

	public void nextDay();

	/*
	 * An interface cannot define instance variables, so here are the instance
	 * variables that should be used for the implementation of this lab (should
	 * they be public or private?)
	 * 
	 * int month;
	 * 
	 * int day;
	 * 
	 * int year;
	 * 
	 * It will also be necessary to implement the following "helper method"
	 * (should it be public or private?)
	 * 
	 * boolean isLeapYear();
	 * 
	 * The class constructors must include:
	 * 
	 * public Date();
	 * 
	 * public Date(int month, int day, int year);
	 */

}
