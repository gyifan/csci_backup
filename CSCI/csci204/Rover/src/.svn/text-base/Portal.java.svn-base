import java.awt.Point;
import java.util.Random;

/**
 * CSCI 204, Yifan Ge
 * Assignment Rover
 * Created: Apr 29, 2011, 3:36:40 AM
 */

/**
 * This class defines the portal object. This object represents the portal in
 * the rover game. A portal contains the information of the room it's in, its
 * location, and a pointer to the paired portal.
 * 
 * @author Yifan Ge
 * 
 */
public class Portal {

	// instance fields

	/** The next portal that this portal linked to. */
	private Portal next;

	/** The room that this portal is currently in. */
	private Room thisRoom;

	/** The location of the portal. */
	private Point location;

	/**
	 * Constructs a default portal object.
	 */
	public Portal() {
		next = null;
		thisRoom = null;
		location = null;
	}

	/**
	 * Constructs a new portal object with information about the room that
	 * contains the portal, the next portal linked to, and the location of the
	 * portal.
	 * 
	 * @param location
	 *            the location of the portal
	 */
	public Portal(Point location, Room room) {
		thisRoom = room;
		this.location = location;
		next = null;
	}

	/**
	 * Sets the location of the portal.
	 * 
	 * @param location
	 *            the location of the portal
	 */
	public void setLocation(Point location) {
		this.location = location;
	}

	/**
	 * Gets the Room object that contains the current room. If the Room object
	 * is null, generates a random room.
	 * 
	 * @return the current room
	 */
	public Room getRoom() {
		if (thisRoom == null) {
			thisRoom = new Room();
			thisRoom.generateRandom();
			return thisRoom;
		} else {
			return thisRoom;
		}
	}

	/**
	 * Gets the location of the portal.
	 * 
	 * @return the location of the portal
	 */
	public Point getlocation() {
		return location;
	}

	/**
	 * Gets the next portal that this portal linked to.
	 * 
	 * @return the linked portal
	 */
	public Portal getNextPortal() {
		return next;
	}

	/**
	 * Connects this portal to the a new portal if it hasn't been connected
	 * already.
	 * 
	 */
	public void connectPortal() {
		if (next == null) {
			Random rand = new Random();
			Point newLocation = new Point(rand.nextInt(Room.SIZE),
					rand.nextInt(Room.SIZE));
			next = new Portal();
			next.setLocation(newLocation);
			next.next = this;
			next.getRoom();
			next.getRoom().setImage(newLocation.x, newLocation.y, Icon.PORTAL);
		}
	}
}
