import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.geom.Point2D;
import java.util.Random;

import javax.swing.JComponent;

/**
 * Creates a sky with stars.
 *
 * @author Rick Zaccone
 *
 */
@SuppressWarnings("serial")
public class StarsComponent extends JComponent {
    private static final int NUM_STARS = 200;

    /*
     * (non-Javadoc)
     *
     * @see javax.swing.JComponent#paintComponent(java.awt.Graphics)
     */
    public void paintComponent(Graphics g) {
        Graphics2D g2 = (Graphics2D) g;

        Stars sky = new Stars();
        Random generator = new Random();
        int frameWidth = getWidth();
        int frameHeight = getHeight();

        for (int i = 0; i < NUM_STARS; i++) {
            double x = frameWidth * generator.nextDouble();
            double y = frameHeight * generator.nextDouble();
            sky.add(new Point2D.Double(x, y));
        }
        sky.draw(g2);
    }
}
