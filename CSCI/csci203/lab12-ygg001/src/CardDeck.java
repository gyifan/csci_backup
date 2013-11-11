import java.util.Random;

/**
 * Models a deck of cards with an array of integers from 1 to n. A method
 * shuffles the cards.
 * 
 * @author Dan Hyde
 * 
 */
public class CardDeck {
	private Random generator;
	private int[] deck;

	/**
	 * Constructs a deck of cards with n cards numbered from 1 to n.
	 * 
	 * @param n
	 *            the number of cards in deck
	 */
	public CardDeck(int n) {
		generator = new Random();
		deck = new int[n];

		for (int i = 0; i < deck.length; i++) {
			deck[i] = i + 1;
		}
	}

	/**
	 * Shuffles the deck of cards.
	 * 
	 * This is how this is done. In a loop while cards are left in deck, chose a
	 * random number r from 0 to the number of cards left - 1. Swap the rth
	 * value of deck with the value in deck at index equal to the number of
	 * cards left - 1.
	 */
	public void shuffle() {
		int cardLeftToShuttle = deck.length;
		int randomCard;
		int tempVariable;
		for (int i = 0; i < deck.length; i++) {
			randomCard = generator.nextInt(cardLeftToShuttle - 1);
			tempVariable = deck[randomCard];
			deck[randomCard] = deck[cardLeftToShuttle - 1];
			deck[cardLeftToShuttle - 1] = tempVariable;
		}
	}

	/*
	 * (non-Javadoc)
	 * 
	 * @see java.lang.Object#toString()
	 */
	public String toString() {
		String deckString = "";
		for (int i = 0; i < deck.length; i++)
			deckString += deck[i] + " ";
		return deckString;
	}

	/**
	 * Tests a shuffle of a deck of 10 cards.
	 * 
	 * @param args
	 *            unused
	 */
	public static void main(String[] args) {

		System.out.println("Constructing a deck of 10 cards");
		CardDeck deck = new CardDeck(10);

		System.out.println("Original deck: " + deck);

		deck.shuffle();
		System.out.println("Shuffled:      " + deck);
		System.out.print("Expected: "
				+ "[numbers 1 to 10 in random order with no duplicates]");

	}
}
