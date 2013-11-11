package Streams;

import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.io.Serializable;

// Demonstrates reading and writing whole objects to a file
public class ObjectIO implements Serializable {
	private int i;
	private String s;
	private ObjectIO obj;
	private String[] array;

	public ObjectIO(int i, String s, ObjectIO obj) {
		this.s = s;
		this.obj = obj;
		this.i = i;
		if (i > 0)
			array = new String[i];
		else
			array = new String[3];
		array[0] = s;
	}

	// Print the ObjectIO
	// Here is an example of what will print
	// int: 3, String: yo, array: yo null null, ObjectIO: null
	public String toString() {
		String str = "int: " + i + ", String: " + s + ", array:";
		for (int x = 0; x < array.length; x++)
			str += " " + array[x];
		str += ", \n\tObjectIO: ";
		if (obj == null)
			str += "null";
		else
			str += obj.toString();
		return str;
	}

	public static void main(String[] args) throws IOException,
			ClassNotFoundException {
		// Can we stuff multiple seperate objects in a file?
		// Can we stuff complex objects with references and arrays in a file?

		// The complex object...
		ObjectIO two = new ObjectIO(4, "hi", null);
		ObjectIO one = new ObjectIO(6, "bye", two);

		// Another object...
		ObjectIO three = new ObjectIO(3, "yup", null);

		// one is a reference to an ObjectIO, that contains a reference to the
		// other ObjectIO. three is a reference to a seperate ObjectIO.
		// Print them so we know what they contain.
		System.out.println(one);
		System.out.println(three);

		// Write them to a file
		ObjectOutputStream out = new ObjectOutputStream(new FileOutputStream(
				"mydata.dat"));
		out.writeObject(one);
		out.writeObject(three);
		out.close();

		// / Read them from the file
		ObjectInputStream in = new ObjectInputStream(new FileInputStream(
				"mydata.dat"));
		ObjectIO oneAgain = (ObjectIO) in.readObject();
		ObjectIO threeAgain = (ObjectIO) in.readObject();

		// Print them so we know they are unharmed
		System.out.println(oneAgain);
		System.out.println(threeAgain);
	}
}
