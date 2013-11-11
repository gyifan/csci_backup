import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertFalse;
import static org.junit.Assert.assertTrue;

import org.junit.After;
import org.junit.Before;
import org.junit.Test;

/**
 * CSCI 204, Yifan Ge
 * Assiangment lab05
 * Created: Feb 24, 2011, 10:41:23 AM
 */

/**
 * @author Yifan Ge
 * 
 */
public class CashRegisterTest {
	private static final double EPSILON = 1.0e-12;

	private CashRegister register;
	private CashRegister anotherRegister;

	@Before
	public void setUp() {
		register = new CashRegister("Foo");
		anotherRegister = new CashRegister("Bar");
	}

	@Test
	public void testSimpleCase() {
		register.recordPurchase(1.82);
		register.enterPayment(1, Money.DOLLAR);
		register.enterPayment(3, Money.QUARTER);
		register.enterPayment(2, Money.NICKEL);
		double expected = 0.03;
		double actual = register.giveChange();
		assertEquals(expected, actual, EPSILON);
	}

	@Test(expected = IllegalArgumentException.class)
	public void testRecordPurchase() {
		register.recordPurchase(-3.12);
	}

	@Test
	public void testRecordPurchaseLegal() {
		register.recordPurchase(3.20);
		assertEquals(register.getPurchase(), 3.20, EPSILON);
	}

	@Test(expected = IllegalArgumentException.class)
	public void testEnterPayment() {
		register.enterPayment(-1, null);
	}

	@Test
	public void testEnterPaymentLegal() {
		register.enterPayment(2, Money.DOLLAR);
		assertEquals(2.0, register.getPayment(), EPSILON);
	}

	@Test
	public void testCompareTo() {
		assertTrue(register.compareTo(anotherRegister) == "Foo"
				.compareTo("Bar"));
	}

	@Test
	public void testEquals() {
		assertFalse(register.equals(anotherRegister));
	}

	@After
	public void tearDown() {
		register = null;
	}

}
