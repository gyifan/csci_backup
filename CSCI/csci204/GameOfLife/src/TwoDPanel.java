import java.awt.Dimension;
import java.awt.Graphics;
import java.awt.Graphics2D;

import javax.swing.JPanel;

/**
 * The GameBoardCanvas class provides a canvas that will automatically draw and
 * center a graphical board for a variant on Conway's Game of Life on an
 * awt/swing component. The board will draw a 3D-ish criss-cross grid for the
 * board until the board size exceeds 100x100 cells. Live cells in the game are
 * represented by blue squares, while dead cells are represented by empty
 * squares.
 * 
 * Do not edit this class.
 * 
 * @author sm053 edited by @author michael davis
 */
public class TwoDPanel extends JPanel {

	/**
	 * The set dimensions of the game board canvas.
	 */
	private static Dimension canvasSize = new Dimension(701, 701);

	/**
	 * The game board which will be drawn on the canvas.
	 */
	private boolean[][] gameBoard;

	/**
	 * Creates a game board canvas which will draw the provided game baord.
	 * 
	 * @param gameBoard
	 *            the game board to initially draw on the canvas
	 */
	public TwoDPanel(boolean[][] gameBoard) {
		this.gameBoard = gameBoard;

	}

	/*
	 * (non-Javadoc)
	 * 
	 * @see java.awt.Component#getPreferredSize()
	 */
	@Override
	public Dimension getPreferredSize() {
		// TODO Auto-generated method stub
		return canvasSize;
	}

	/**
	 * Set the game board to be drawn to the provided game board.
	 * 
	 * @param board
	 *            the new game board to draw on the canvas
	 */
	public void setGameBoard(boolean[][] board) {
		this.gameBoard = board;
	}

	/**
	 * Returns the size of a displayed cell for the current game board in terms
	 * of pixels.
	 * 
	 * @return the pixel size of a displayed cell
	 */
	public int cellSize() {
		return (getHeight() - 1) / gameBoard.length;
	}

	/*
	 * (non-Javadoc)
	 * 
	 * @see java.awt.Canvas#paint(java.awt.Graphics)
	 */
	@Override
	public void paint(Graphics g) {
		Graphics2D g2;
		this.setLocation(1, 1);
		// determine cell size and required offset for centering grid
		// int size = getHeight() - 1;
		int cellSize = cellSize();
		int offset = 0;// (int) Math.round((size - cellSize * gameBoard.length)
		// / (double) 2);

		// paint the live and dead cells
		g2 = (Graphics2D) g;
		g2.clearRect(this.getX(), this.getY(), this.getWidth(), this
				.getHeight());
		for (int i = 0; i < gameBoard.length; i++) {
			for (int j = 0; j < gameBoard.length; j++) {
				// live cells
				if (gameBoard[i][j]) {
					g2.setColor(java.awt.Color.BLUE);
					if (gameBoard.length <= 100) {
						g2.fill3DRect(i * cellSize + offset, j * cellSize
								+ offset, cellSize, cellSize, true);
					} else {
						g2.fillRect(i * cellSize + offset, j * cellSize
								+ offset, cellSize, cellSize);
					}
				}
				// dead cells (if board size less than 100x100)
				else {
					g2.setColor(java.awt.Color.WHITE);
					if (gameBoard.length <= 100) {
						g2.fill3DRect(i * cellSize + offset, j * cellSize
								+ offset, cellSize, cellSize, false);
					} else {
						g2.fillRect(i * cellSize + offset, j * cellSize
								+ offset, cellSize, cellSize);
					}
				}
			}
		}
	}

}
