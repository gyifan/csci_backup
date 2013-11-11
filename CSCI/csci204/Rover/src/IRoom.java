import java.awt.Image;

public interface IRoom {
	/**
	 * The room needs a SIZE public static instance field. The size must be 15
	 * in order to fit in the window.
	 */

	/**
	 * Returns true if the given space is occupied, false if it is not. It could
	 * be occupied by a portal, item, or ship part. The rover doesn't count as
	 * occupying a space (it floats and it gets drawn separately). This is an
	 * accessor method. Called by the GuiPanel to draw the room.
	 * 
	 * @param column
	 *            The column (x) coordinate
	 * @param row
	 *            The row (y) coordinate
	 * @return
	 */
	boolean isOccupied(int column, int row);

	/**
	 * Return the image of the item in the grid at this location. Assumes that
	 * the location is occupied. If the location is not occupied, this will
	 * throw a null pointer exception. If something is wrong with the image, it
	 * may be null. This is an accessor method. Called by the GuiPanel to draw
	 * the room.
	 */
	Image getImage(int column, int row);

}
