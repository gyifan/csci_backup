import java.awt.Color;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.geom.Arc2D;
import java.awt.geom.Ellipse2D;
import java.awt.geom.Rectangle2D;

import javax.swing.JComponent;

/**
 * CSCI 203, Yifan Ge
 * Sep 22, 2010, 1:27:42 PM
 */

/**
 * @author GE
 * 
 */
@SuppressWarnings("serial")
public class FaceComponent extends JComponent {

	public void paintComponent(Graphics g) {
		Graphics2D g2 = (Graphics2D) g;
		Color orange = new Color(231, 97, 37);
		Color blue = new Color(0, 52, 116);
		double width = this.getWidth() - 1;
		double height = this.getHeight() - 1;

		// draws face

		Ellipse2D.Double face = new Ellipse2D.Double(0.0, 0.0, width, height);
		g2.setColor(orange);
		g2.fill(face);
		g2.setColor(Color.BLACK);
		g2.draw(face);

		// draws eyes

		double leftEyeX = (1.0 / 3.0) * (width) - 0.05 * (height);
		double eyeY = (1.0 / 3.0) * height - 0.05 * height;
		double eyeWidth = 0.1 * height;
		double eyeHeight = eyeWidth;
		Ellipse2D.Double leftEye = new Ellipse2D.Double(leftEyeX, eyeY,
				eyeWidth, eyeHeight);
		g2.setColor(blue);
		g2.fill(leftEye);
		g2.setColor(Color.BLACK);
		g2.draw(leftEye);

		double rightEyeX = (2.0 / 3.0) * width - 0.05 * height;
		Ellipse2D.Double rightEye = new Ellipse2D.Double(rightEyeX, eyeY,
				eyeWidth, eyeHeight);
		g2.setColor(blue);
		g2.fill(rightEye);
		g2.setColor(Color.BLACK);
		g2.draw(rightEye);

		// draws Mouth

		double mouthX = leftEyeX;
		double mouthHeight = 0.2 * height;
		double mouthY = (2.0 / 3.0) * height - 0.5 * mouthHeight;
		double mouthWidth = rightEyeX + eyeWidth - leftEyeX;

		Rectangle2D.Double mouthBox = new Rectangle2D.Double(mouthX, mouthY,
				mouthWidth, mouthHeight);
		Arc2D.Double mouth = new Arc2D.Double(mouthBox, 180, 180, Arc2D.CHORD);
		g2.setColor(Color.BLACK);
		g2.fill(mouth);

		// draws nose

		double noseX = 0.5 * width - 0.05 * height;
		double noseY = 0.5 * height - 0.025 * height;
		double noseWidth = eyeWidth;
		double noseHeight = 0.5 * eyeWidth;
		Ellipse2D.Double nose = new Ellipse2D.Double(noseX, noseY, noseWidth,
				noseHeight);
		g2.setColor(Color.RED);
		g2.fill(nose);
		g2.setColor(Color.BLACK);
		g2.draw(nose);

		// draws tooth

		double toothWidth = 0.125 * mouthWidth;
		double toothHeight = 0.375 * mouthHeight;
		double toothX = 0.5 * width - 0.5 * toothWidth;
		double toothY = mouthY + 0.5 * mouthHeight;
		Rectangle2D.Double tooth = new Rectangle2D.Double(toothX, toothY,
				toothWidth, toothHeight);
		g2.setColor(Color.WHITE);
		g2.fill(tooth);

	}
}
