import java.io.File;
import java.io.FilenameFilter;

/**
 * <code>PrintDirectory</code> currently prints file names in a given directory.
 * 
 * @author <a href="mailto:xmeng@bucknell.edu">Meng Xiannong</a>
 * @author other csci204 instructors
 * @version 1.1 revised 02/01/2006
 * @version 1.2 2008-02-03 by Rick Zaccone
 */
public class PrintDirectory {

	/**
	 * Lists all files and directories in a given directory.
	 * 
	 * @param dirPath
	 *            the initial directory.
	 */
	public void directoryListing(File dirPath) {

		File[] dirList = dirPath.listFiles(new MyFileFilter());

		for (int i = 0; i < dirList.length; i++) {
			if (dirList[i].isFile() == true) {
				System.out.println(dirList[i].getName());
			} else {
				System.out.println("Entering " + dirList[i].getName());
				directoryListing(dirList[i]);
				System.out.println("Leaving " + dirList[i].getName() + "\n");
			}
		}
	}

	/*
	 * File[] dirList = dirPath.listFiles(new MyFileFilter());
	 * 
	 * for (int i = 0; i < dirList.length; i++)
	 * System.out.println(dirList[i].getName());
	 */

	/**
	 * <code>main</code> driver program.
	 * 
	 * @param args
	 *            command line arguments
	 */
	public static void main(String[] args) {

		// Must use the complete path of a directory
		File dirPath;

		// Take a directory from the command line arguments
		// or use the given one.
		if (args.length > 0)
			dirPath = new File(args[0]);
		else
			dirPath = new File("/home/accounts/COURSES/csci204/"
					+ "2010-fall/student");

		PrintDirectory directoryLister = new PrintDirectory();

		directoryLister.directoryListing(dirPath);
	}
}

// Do not change MyFileFilter!

class MyFileFilter implements FilenameFilter {
	public boolean accept(File dir, String name) {
		return true;
	}
}
