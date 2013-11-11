import java.awt.Image;
import java.awt.Point;

public interface IRover {
	/**
	 * Pick up an item in the room at the rover's location. This is a mutator
	 * method. Called by the Gui.
	 * <P>
	 * Strategy: If we are standing on an item, pick it up. If not, do nothing.
	 * This will not pick up ship parts or portals.
	 * <P>
	 * Postconditions: the item is now in the inventory, the item is no longer
	 * in the room.
	 */
	void pickUp();

	/**
	 * Changes the image on the portal leading towards home. This is a mutator
	 * method. Called by the Gui.
	 * <P>
	 * Strategy: If the stack is empty, we must already be home, do nothing.
	 * Otherwise, peek at the top of the stack and set that portal to use its
	 * flashy image. (The image may not actually flash but it will look
	 * different than the standard portal image.)
	 * 
	 */
	void showTheWayBack();

	/**
	 * Perform the task in the task bar. This is a mutator method. Called by the
	 * Gui.
	 * <P>
	 * Strategy: If we are not standing on the relevant broken ship part or we
	 * do not have all the supplies, nothing happens. If we do happen to
	 * accomplish the task, that part of the ship gets fixed and the next task
	 * appears. If we run out of tasks, we win.
	 */
	void performTask();

	/**
	 * The rover steps to the left. This is a mutator method. Called by the Gui.
	 * <P>
	 * Strategy: If possible, the rover takes a step to the left. If the robot
	 * lands on a portal, it will be teleported. If the outer wall is in the
	 * way, nothing happens. The robot will stand on items and float above ship
	 * parts.
	 * <P>
	 * Postconditions: If an empty space, item, or ship part was to the left
	 * then the robot has moved one space to the left. If a wall was to the
	 * left, nothing has happened. If a portal was to the left, the robot has
	 * teleported to another room and is standing on the entry portal.
	 */
	void goLeft();

	/**
	 * The rover steps to the south. This is a mutator method. Called by the
	 * Gui.
	 * <P>
	 * Strategy: If possible, the rover takes a step to the south. If the robot
	 * lands on a portal, it will be teleported. If the outer wall is in the
	 * way, nothing happens. The robot will stand on items and float above ship
	 * parts.
	 * <P>
	 * Postconditions: If an empty space, item, or ship part was to the south
	 * then the robot has moved one space to the south. If a wall was to the
	 * south, nothing has happened. If a portal was to the south, the robot has
	 * teleported to another room and is standing on the entry portal.
	 */
	void goDown();

	/**
	 * The rover steps to the right. This is a mutator method. Called by the
	 * Gui.
	 * <P>
	 * Strategy: If possible, the rover takes a step to the right. If the robot
	 * lands on a portal, it will be teleported. If the outer wall is in the
	 * way, nothing happens. The robot will stand on items and float above ship
	 * parts.
	 * <P>
	 * Postconditions: If an empty space, item, or ship part was to the right
	 * then the robot has moved one space to the right. If a wall was to the
	 * right, nothing has happened. If a portal was to the right, the robot has
	 * teleported to another room and is standing on the entry portal.
	 */
	void goRight();

	/**
	 * The rover steps to the north. This is a mutator method. Called by the
	 * Gui.
	 * <P>
	 * Strategy: If possible, the rover takes a step to the north. If the robot
	 * lands on a portal, it will be teleported. If the outer wall is in the
	 * way, nothing happens. The robot will stand on items and float above ship
	 * parts.
	 * <P>
	 * Postconditions: If an empty space, item, or ship part was to the north
	 * then the robot has moved one space to the north. If a wall was to the
	 * north, nothing has happened. If a portal was to the north, the robot has
	 * teleported to another room and is standing on the entry portal.
	 */
	void goUp();

	/**
	 * Returns the inventory. Called by the Gui so it can update the inventory
	 * display. This is an accessor method.
	 * <P>
	 * The inventory will be formatted so the item count appears next to the
	 * item name. Items not found in the inventory do not appear. The string
	 * must fit inside the provide inventory window.
	 */
	String getInventory();

	/**
	 * Returns the task at the front of the task queue. This is an accessor
	 * method. Called by the Gui so it can update the task display.
	 * <P>
	 * The task must fit in 4 lines and wit in the provided task window. It must
	 * have a name that tells you what you are fixing. It must require exactly 3
	 * kinds of parts and use at least 1 of each part (so
	 * "Fixing the engine: 1 Cake, 2 Gears, and 3 Screws" would be fine).
	 * 
	 * @return the current task.
	 */
	String getTask();

	/**
	 * Returns the curent room. This is an accessor method. Called by GuiPanel
	 * so that it can draw the objects in the room.
	 * 
	 * @return the current room
	 */
	IRoom getRoom();

	/**
	 * Returns the current location of the rover as a coordinate: column (x) and
	 * row (y). This is an accessor method. Called by the GuiPanel so it can
	 * draw the rover.
	 * 
	 * @return the location of the rover in the current room.
	 */
	Point getLocation();

	/**
	 * Returns the image of the rover. This is an accessor method. Called by the
	 * GuiPanel so it can draw the rover. If the image refuses to load, this
	 * method will return null.
	 * 
	 * @return the image of the rover
	 */
	Image getImage();

}
