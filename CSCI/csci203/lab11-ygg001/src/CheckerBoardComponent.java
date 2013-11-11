import java.awt.Graphics;
import java.awt.Graphics2D;

import javax.swing.JComponent;

/**
 * This component draws a checkerboard.
 *
 * @author zaccone
 *
 */
@SuppressWarnings("serial")
public class CheckerBoardComponent extends JComponent {
    /*
     * (non-Javadoc)
     *
     * @see javax.swing.JComponent#paintComponent(java.awt.Graphics)
     */
    public void paintComponent(Graphics g) {
        Graphics2D g2 = (Graphics2D) g;
        final int numSquares = 8;
        int size = Math.min(getWidth(), getHeight()) / numSquares;
        CheckerBoard board = new CheckerBoard(numSquares, size);

        board.draw(g2);
    }
}
