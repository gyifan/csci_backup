import javax.swing.JFrame;

/**
 * This program displays a checkerboard.
 */
public class CheckerBoardViewer {
    /**
     * Creates the checkerboard window.
     *
     * @param args
     *            unused
     */
    public static void main(String[] args) {
        JFrame frame = new JFrame("CheckerBoardViewer");
        final int frameWidth = 330;
        final int frameHeight = 360;

        frame.setSize(frameWidth, frameHeight);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        CheckerBoardComponent component = new CheckerBoardComponent();
        frame.add(component);

        frame.setVisible(true);
    }
}
