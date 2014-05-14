/**
 * An implementation of a minimum heap with handles
 */

public class Heap {

    private HeapElt[] array;
    int heapsize;
    int arraysize;

    /*
      The constructor has been set up with an initial array of size 4
      so that your doubleHeap() method will be tested.  Don't change
      this!
    */
    public Heap() {
		array = new HeapElt[4];
		heapsize = 0;
		arraysize = 4;
    }



    /*
      Exchanges that values at positions pos1 and pos2 in the heap array.
      Handles must be exchanged correctly as well.

      Running time = O(1)
    */
    private void exchange(int pos1, int pos2) {

	    // exchanges the handle inside the elements
		int tempHandle = array[pos1].getHandle();
		array[pos1].setHandle(array[pos2].getHandle());
		array[pos2].setHandle(tempHandle);
		
		// exchanges the elements
		HeapElt tempElt = array[pos1];
		array[pos1] = array[pos2];
		array[pos2] = tempElt;

    }



    /*
      Doubles the size of the array.  A new array is created, the elements in
      the heap are copied to the new array, and the array data member is set
      to the new array.  Data member arraysize is set to the size of the
      new array.

      Running time = O(n)
    */
    private void doubleHeap() {

	    // creates a new array with the doubled size.
		HeapElt[] tempArray = new HeapElt[2*arraysize];
		
		// copies all the elements in the old array to the new one.
		for (int i = 1; i <= heapsize; i++){
			tempArray[i] = array[i];
		}
		
		// updates the instance fields.
		array = tempArray;
		arraysize = 2*arraysize;

    }



    /*
      Fixes the heap if the value at position pos may be smaller than its
      parent.  Using exchange() to swap elements will simplify your
      implementation.  Heap elements contain records that are Comparable;
      you will need to figure out what to test and how to test it.

      Running time = O(lgn)
    */
    public void heapifyUp(int pos) {

    	// checks if the element has any parent
	    if(pos > 1){
			int parentPos = pos/2; // parent position in the array.
			
			// compares the current element with its parent.
			int compare = array[pos].getRecord().compareTo(array[parentPos].getRecord());
			
			// if the current element is larger, swaps it with its parent and then
			// recursively call heapifyUp with its parent position.
			if( compare < 0){
				exchange(pos, parentPos);
				heapifyUp(parentPos);
			}
	    }

    }

    /*
      Fixes the heap if the value at position pos may be bigger than one of
      its children.  Using exchange() to swap elements will simplify your
      implementation.  Heap elements contain records that are Comparable;
      you will need to figure out what to test and how to test it.

      Running time = O(lgn)
    */
    public void heapifyDown(int pos) {

		int childLeft = pos*2; // left child's position.
		int childRight = pos*2+1; // right child's position.
		
		// checks if the right child exists
		if(childRight <= heapsize){
			// compares with its right child.
			int compare = array[pos].getRecord().compareTo(array[childRight].getRecord());
			
			// if the child is larger, swaps the elements and then recursively call 
			// heapifyDown to the right child.
			if(compare > 0){
				exchange(pos, childRight);
				heapifyDown(childRight);
			}
		} 
		if(childLeft <= heapsize){ // checks if the left child exists
			// compares with its left child.
			int compare = array[pos].getRecord().compareTo(array[childLeft].getRecord());
			
			// if the child is larger, swaps the elements and then recursively call 
			// heapifyDown to the left child.
			if(compare > 0){
				exchange(pos, childLeft);
				heapifyDown(childLeft);
			}
		}

    }



    /*
      Insert inElt into the heap.  Before doing so, make sure that there is
      an open spot in the array for doing so.  If you need more space, call
      doubleHeap() before doing the insertion.

      Running time = O(n) w/ doubleHeap()
      Running time = O(lgn) w/o doubleHeap()
    */
    public void insert(HeapElt inElt) {
    	
    	// if the array is full, doubles the array.
    	if(arraysize == heapsize+1)
    		doubleHeap();
    	
    	// increment the heap size, set the position of the new element to 
    	// the heap size.
    	heapsize ++;
    	int pos = heapsize;
    	array[pos] = inElt;
    	array[pos].setHandle(pos);
    	
    	// heapify the heap
    	heapifyUp(pos);

    }



    /*
      Remove the minimum element from the heap and return it.  Restore
      the heap to heap order.  Assumes heap is not empty, and will
      cause an exception if the heap is empty.

      Running time = O(n)
    */
    public HeapElt removeMin() throws Exception {
	// WARNING: Will fail with empty heap!
    	if(heapsize == 0)
    		throw new Exception("Empty String.\n");
    	
    	// restore the heap to heap order.
    	for (int j = 1; j<heapsize; j++){
    		exchange(j, j+1);
    		heapifyUp(j);
    	}
    	heapsize --; // decrement the heapsize
    	
    	// return the minimum.
    	return array[heapsize+1];
    	
    }



    /*
      Return the number of elements in the heap..

      Running time = O(1)
    */
    public int getHeapsize() {

    	return heapsize;

    }

 

   /*
      Print out the heap for debugging purposes.  It is recommended to 
      print both the key from the record and the handle.

      Running time = O(n)
    */
    public void printHeap() {

    	System.out.printf("=============Heap==============\n");
		System.out.printf("key\t handle\n");
    	for(int i = 1; i <= heapsize; i++){
    		System.out.printf("%d\t %d\n", array[i].getRecord(), array[i].getHandle());
    	}
    	System.out.printf("");
    	

     }

}
