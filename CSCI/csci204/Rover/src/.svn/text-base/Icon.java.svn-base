import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;

import javax.imageio.ImageIO;

/**
 * CSCI 204, Yifan Ge
 * Assignment Rover
 * Created: Apr 29, 2011, 4:13:18 AM
 */

/**
 * This enum contains the information of all the icons that the room needed.
 * 
 * @author Yifan Ge
 * 
 */
public enum Icon {

	PORTAL("portal.jpg"), FLASHINGPORTAL("portal-flashing.jpg"), ROVER(
			"rover.jpg"), GEAR("gear.jpg"), CAKE("cake.jpg"), SCREW("screw.jpg"), ENGINE(
			"engine2.jpg"), FIXEDENGINE("engine.jpg"), CABIN("cabin.jpg"), FIXEDCABIN(
			"cabin2.jpg"), EXHAUST("exhaust.jpg"), FIXEDEXHAUST("exhaust2.jpg"), WHEEL(
			"wheel.jpg"), FIXEDWHEEL("wheel2.jpg");

	/** The image object the icon contains. */
	private BufferedImage image;

	/**
	 * Constructs the icon object by reading an external file.
	 * 
	 * @param fileName
	 *            the name of the file
	 */
	Icon(String fileName) {
		try {
			image = ImageIO.read(new File(fileName));
		} catch (IOException e) {
			image = null;
		}
	}

	/**
	 * Gets the image of the icon.
	 * 
	 * @return the image of the icon
	 */
	public BufferedImage getImage() {
		return image;
	}
}
