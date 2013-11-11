public class TestDates {
    public static void main(String[] argv){
        Dates d = new Dates(12,31,1999);   // December 31, 1999

        d.displayShort();                  // 12/31/99
        System.out.println();              // new line
        d.displayVerbose();                // December 31, 1999
        System.out.println();              // new line

        d.nextDay();                       // increment to the next big day !!
        d.displayShort();                  // 01/01/00
        System.out.println();              // new line
        d.displayVerbose();                // January 1, 2000
        System.out.println();              // new line

                                           // now let's test a leap year
        d.setDate(2,27,2000);
        d.nextDay();                       // should be 2/28/00
        d.nextDay();                       // should be 2/29/00
        d.displayShort();                  // 02/29/00
        System.out.println();              // new line
        d.displayVerbose();                // February 29, 2000
        System.out.println();              // new line

        // Now a non-leap year. Should see
        // 03/01/00.
        d.setDate(2, 28, 1900);
        d.nextDay();
        d.displayShort();
        System.out.println();
        d.displayVerbose();
        System.out.println();
        // One more...
        d.setDate(9, 26, 2001);
        d.displayShort();
        System.out.println();
        d.displayVerbose();
        System.out.println();
    }
}
