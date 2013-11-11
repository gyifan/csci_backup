package Recursion;
import java.awt.*;
import java.awt.event.*;
/* How to use the EasyGui:
 *   1) extend it
 *        public class myClass extends EasyGui { ... }
 *   2) in your constructor, call the EasyGui constructor with a title
 *        super("Fractals");
 *   3) make an array of strings to hold menu options and call makeMenu	
 *     	  String[] fractals = {"Sierpinski", "Koch"};
 *   	  makeMenu(fractals);
 *   4) implement the run method which is called by the menu options
 *        public void run(String s) { ... }
 *      be aware that run may be called with strange strings so check
 *      the string and don't assume its value.
 *   6) You can draw polygons
 *        Polygon p = new Polygon();
 *        p.addPoint(p1.x, p1.y);
 *        p.addPoint(p2.x, p2.y);
 *        p.addPoint(p3.x, p3.y);
 *        drawPolygon(p);
 *   7) You can draw lines
 *        Point p1 = new Point(20,30);
 *        Point p2 = new Point(50,90);
 *        drawLine(p1,p2);
 *   8) You can get the window width and height and set the line color
 *        getHeight(); getWidth(); setLineColor(Color.WHITE);
 *   9) You can also clear the window
 *        clearWindow();
 *   See the Java 6 API - Graphics for more methods.            
 */
public abstract class EasyGui extends Frame implements ActionListener {
	EasyGui(String title) {
		// Setup window properties
		super(title);
		setSize(800, 800);
		setLocation(100, 100);
		setBackground(Color.WHITE);
		setResizable(true);
	}
		
	public void makeMenu(String[] menuOptions) {    
		MenuBar menubar = new MenuBar();
		Menu m = new Menu("Controls");

		for(int i=0; i < menuOptions.length; i++) {
 		    MenuItem one = new MenuItem(menuOptions[i]);
		    one.addActionListener(this);
		    m.add(one);
		}

		MenuItem two = new MenuItem("Quit");
		two.addActionListener(this);
		m.add(two);

		menubar.add(m);
		setMenuBar(menubar);
		
	    setVisible(true);
    }
	
	// Respond to menu buttons
    public void actionPerformed(ActionEvent e) {
	    String arg = e.getActionCommand();
	    if ("Quit".equals(arg))        { dispose(); }
	    else                           { run(arg); }
    }

    public abstract void run(String s) ;

    void drawLine(Point p1, Point p2) {
    	Graphics g = this.getGraphics();
    	g.drawLine(p1.x, p1.y, p2.x, p2.y);
    }
    
    void drawLine(int x1, int y1, int x2, int y2) {
    	Graphics g = this.getGraphics();
    	g.drawLine(x1, y1, x2, y2);
    }
    
    void drawPolygon(Polygon p) {
       	Graphics g = this.getGraphics();
        g.drawPolygon(p);
    }
    
    void setLineColor(Color c) {
    	Graphics g = this.getGraphics();
    	g.setColor(c);
    }
    
    void clearWindow() {
    	Graphics g = this.getGraphics();
    	g.clearRect(0,0,getWidth(), getHeight());
    }
}

