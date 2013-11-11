import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Dimension;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.GridLayout;
import java.awt.Rectangle;
import java.awt.geom.Line2D;
import java.util.Hashtable;

import javax.swing.JComponent;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JSlider;
import javax.swing.SwingConstants;
import javax.swing.event.ChangeEvent;
import javax.swing.event.ChangeListener;

/**
 * This class manages all of the GUI behind the Resource Simulation
 * 
 * NOTE: This code was completed rather quickly, without much time for good
 * structure and comments. (i.e., I'm in a very early phase of an extreme 
 * programming based project. :-) This is because there is NO code here included
 * in the lab. This is only provided to make for a neat visual indication of
 * what is going on
 * 
 * @author Brian R. King
 */
class GUI extends JComponent implements ChangeListener {
	private static final long serialVersionUID = -2910828232002937618L;
	private JFrame theFrame;
	private int nBars;
	private Rectangle[] bars;
	private double[] heights;
	private Rectangle plotArea;
	private JSlider sliderSampleSize;
	private JLabel labelSampleSize;
	private JSlider sliderRequestDelay;
	private JLabel labelRequestDelay;
	private JLabel bottomLabel;

	public GUI(String title, int nServers, int maxReqDelay, int initReqDelay) {
		// Create the main frame for the GUI
		theFrame = new JFrame(title);
		theFrame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		// Set up elements to be painted by this component
		nBars = nServers;
		bars = new Rectangle[nBars];
		heights = new double[nBars];
		for(int i = 0; i < nServers; i++) {
			bars[i] = new Rectangle();
			heights[i] = 0;
		}
		plotArea = new Rectangle();
		
		// Set up the sliders
		sliderSampleSize = new JSlider(1,nBars,1);
		sliderSampleSize.addChangeListener(this);
		labelSampleSize = new JLabel();
		
		sliderRequestDelay = new JSlider(0,maxReqDelay,initReqDelay);
		sliderRequestDelay.addChangeListener(this);
		labelRequestDelay = new JLabel();
		
		// Set up the tick marks on the slider
		sliderSampleSize.setMajorTickSpacing(1);
		sliderSampleSize.setPaintTicks(true);
		
		// Add a few labels on the slider
		Hashtable<Integer,JLabel> labelTable = new Hashtable<Integer,JLabel>();
		labelTable.put(1, new JLabel("1"));
		labelTable.put((int)(nBars/2), new JLabel("" + (int)(nBars/2)));
		labelTable.put(nBars, new JLabel("" + nBars));
		sliderSampleSize.setLabelTable(labelTable);
		sliderSampleSize.setPaintLabels(true);		
		
		bottomLabel = new JLabel("Histogram Title",SwingConstants.CENTER);
	}
	
	/**
	 * Adjust the height of a single bar in the histogram b, and repaint the
	 * graph
	 * 
	 * @param iBar the index of the bar to adjust
	 * @param height is a value between 0.0 (no bar) and 1.0 (full bar) 
	 */
	public void adjustBarHeight(int iBar, double height) {
		heights[iBar] = height;
		repaint();
	}
	
	/**
	 * Set the label on the graph and repaint the graph
	 * @param <code>s</code> is the new string to display in the label
	 */
	public void setGraphLabel(String s) {
		bottomLabel.setText(s);
		if (bottomLabel.isValid())
			repaint();
	}

	/**
	 * Get the current value of the sample size slider
	 */
	public int getSampleSliderValue() { return sliderSampleSize.getValue(); }

	private void updateSampleSizeLabel() {
		labelSampleSize.setText(" Sample size [" + getSampleSliderValue() + "]: ");
	}
	
	private void updateRequestDelayLabel() {
		labelRequestDelay.setText(" Request delay (ms) [" + getRequestDelaySliderValue() + "]: ");
	}
	
	/**
	 * Get the current request delay slider value
	 */
	public int getRequestDelaySliderValue() { return sliderRequestDelay.getValue(); }
	
	/**
	 * The paintComponent method is called by the Swing framework whenever this component
	 * needs to be painted or repainted. It handles the actual drawing of the elements
	 * for the histogram
	 */
	public void paintComponent(Graphics g) {
		Graphics2D g2 = (Graphics2D) g;
		g2.setColor(Color.DARK_GRAY);
		Dimension d = getSize();
		
		// Set up the bounds around the actual plot area
		plotArea.setBounds((int)(d.getWidth()/10), (int)(d.getHeight()/10), 
				           (int)(d.getWidth()*.8), (int)(d.getHeight()*.8));
		g2.drawLine((int)plotArea.getMinX(), (int)plotArea.getMinY(),
				    (int)plotArea.getMinX(), (int)plotArea.getMaxY());
		g2.drawLine((int)plotArea.getMinX(), (int)plotArea.getMaxY(), 
				    (int)plotArea.getMaxX(), (int)plotArea.getMaxY());
		
		// Set up each of the bars of the histogram
		for(int i = 0; i < bars.length; i++) {
			bars[i].setBounds((int)(plotArea.x+(i*plotArea.getWidth()/bars.length)),
					          (int)(plotArea.y+plotArea.getHeight()*(1.0-heights[i])),
					          (int)(plotArea.getWidth()/(bars.length+1)),
					          (int)(plotArea.getHeight()*heights[i]));
		}
		
		// Fill in those bar boundaries
		for(int i =0 ; i < bars.length; i++)
			g2.fill(bars[i]);
		
	}
	
	/**
	 * Create the frame, and add the various components to the frame, including this
	 * component showing the actual histogram. Then, set the frame to be visible
	 */
	public void display() {
		if (theFrame.isVisible())
			return;
		theFrame.setLayout(new BorderLayout());
		theFrame.setSize(500, 600);
		theFrame.add(this, BorderLayout.CENTER);
		
		theFrame.add(bottomLabel,BorderLayout.SOUTH);
		
		JPanel thePanel = new JPanel(new GridLayout(2, 2));
		thePanel.add(labelSampleSize);
		thePanel.add(sliderSampleSize);
		updateSampleSizeLabel();
		thePanel.add(labelRequestDelay);
		thePanel.add(sliderRequestDelay);
		updateRequestDelayLabel();
		theFrame.add(thePanel,BorderLayout.NORTH);
		theFrame.setVisible(true);
	}

	/**
	 * This is a callback method that is invoked whenever one of the sliders change value. Here,
	 * I do nothing more than change the label next to the slider to indicate it's 
	 * current value
	 */
	@Override
	public void stateChanged(ChangeEvent e) {
		if (e.getSource() == (Object)sliderSampleSize)
			updateSampleSizeLabel();
		else if (e.getSource() == (Object)sliderRequestDelay)
			updateRequestDelayLabel();
	}


	/**
	 * Simple test function for the GUI
	 */
	public static void main(String[] args) {

		final int NUM_BARS = 15;
		
		GUI h = new GUI("Test Histogram",NUM_BARS, 100, 1);
		h.setGraphLabel("Test Label");

		h.display();
		
		for(int i = 0; i < NUM_BARS; i++)
			h.adjustBarHeight(i, (double)i/NUM_BARS);
	}


}
