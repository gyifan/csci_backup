/**
 * A class to test a heap with handles
 */

public class TestHeap {

    public static void main(String[] args) {
	HeapInt[] array = new HeapInt[10];
	HeapInt[] sortedArray = new HeapInt[10];
	int hsize = 9;
	int asize = 10;
	
	Heap myHeap = new Heap();

	System.out.println("Inserting the values 4, 8,3, 7, 2, 6, 9, 1, 5 in that order.\n");

	array[1] = new HeapInt(4);
	myHeap.insert(array[1]);

	array[2] = new HeapInt(8);
	myHeap.insert(array[2]);

	array[3] = new HeapInt(3);
	myHeap.insert(array[3]);

	array[4] = new HeapInt(7);
	myHeap.insert(array[4]);

	array[5] = new HeapInt(2);
	myHeap.insert(array[5]);

	array[6] = new HeapInt(6);
	myHeap.insert(array[6]);

	array[7] = new HeapInt(9);
	myHeap.insert(array[7]);

	array[8] = new HeapInt(1);
	myHeap.insert(array[8]);

	array[9] = new HeapInt(5);
	myHeap.insert(array[9]);

	System.out.println("value  handle");
	System.out.println("-----  ------");

	for (int i =1; i <= hsize; i++) {
	    System.out.println("  " + array[i].getRecord().toString()
			       + "       "
			       + array[i].getHandle());
	}

	System.out.println("\n\nPrinting heap with printHeap(): \n");
	
	myHeap.printHeap();
	
	System.out.println("\nChanging value at root from 1 to 11 and heapifying down.");
	
	array[8].setRecord(new Integer(11));
	
	myHeap.heapifyDown(array[8].getHandle());
	
	System.out.println("\nRevised handle info:\n");
	System.out.println("value  handle");
	System.out.println("-----  ------");

	
	for (int i =1; i <= hsize; i++) {
	    System.out.println("  " + array[i].getRecord().toString()
			       + "       "
			       + array[i].getHandle());
	}
	
	System.out.println("\n\nSorting by removing minimum at each step:\n");
	while (myHeap.getHeapsize() > 0) {
	    try {
			System.out.print( myHeap.removeMin().getRecord().toString()
				      + "  ");
		} catch (Exception e) {
			// TODO Auto-generated catch block
			System.out.println("Can't remove min, the heap is empty\n");
			e.printStackTrace();
		}
	}

	System.out.println("\n");

    }
}


