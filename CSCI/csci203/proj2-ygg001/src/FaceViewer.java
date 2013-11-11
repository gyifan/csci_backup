import javax.swing.JFrame;

/**
 * CSCI 203, Yifan Ge
 * Sep 22, 2010, 1:17:27 PM
 */

/**
 * @author GE
 * 
 */
public class FaceViewer {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		JFrame frame = new JFrame("FaceViewer");
		frame.setSize(500, 500);
		FaceComponent component = new FaceComponent();
		frame.add(component);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.setVisible(true);
	}
}
