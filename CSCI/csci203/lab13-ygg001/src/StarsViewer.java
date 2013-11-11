import java.awt.Color;

import javax.swing.JFrame;

/**
 * Displays a sky of stars.
 *
 * @author Rick Zaccone
 */
public class StarsViewer {
    /**
     * Creates the frame for the stars and adds the stars component.
     *
     * @param args
     *            unused
     */
    public static void main(String[] args) {
        JFrame frame = new JFrame("Stars Viewer");

        final int frameWidth = 300;
        final int frameHeight = 300;

        frame.setSize(frameWidth, frameHeight);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        frame.add(new StarsComponent());
        frame.getContentPane().setBackground(Color.BLACK);

        frame.setVisible(true);
    }
}
