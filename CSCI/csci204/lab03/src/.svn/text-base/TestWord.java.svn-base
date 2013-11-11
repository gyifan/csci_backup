import java.util.StringTokenizer;

import javax.swing.JOptionPane;

/**
 * <code>TestWord</code> tests the <code>Word</code> class. This code
 * adopted from 'Big Java'
 *
 * @author <a href="mailto:zaccone@bucknell.edu">Rick Zaccone</a>
 * @author <a href="mailto:xmeng@bucknell.edu">Xiannong Meng</a> revised
 *         01/25/2006
 * @version 1.1, 01/25/2006
 */
public class TestWord {

    /**
     * Execution starts here.
     *
     * @param args
     *            command line arguments.
     */
    public static void main(String[] args) {
        String input = JOptionPane.showInputDialog("Enter a sentence");
        StringTokenizer tokenizer = new StringTokenizer(input);

        while (tokenizer.hasMoreTokens()) {
            String token = tokenizer.nextToken();
            Word w = new Word(token);

            int syllables = w.countSyllables();
            System.out.println("Syllables in " + token + ": " + syllables);
        }
        System.exit(0);
    }
}
