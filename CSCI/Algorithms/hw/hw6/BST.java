// BST.java: a partial implementation of a BST.

// DO NOT CHANGE any completed methods.  Complete the methods with comments
// indicating that they are not complete.  BE SURE TO INCLUDE A RUNNING TIME
// FOR EACH METHOD YOU COMPLETE.



public class BST<T extends Comparable> {

    private T key;
    private boolean isEmpty;
    private BST<T> left;
    private BST<T> right;

    public BST() {
	isEmpty = true;
    }

    /*********************************************************
     *                                                        *
     * Precondition:  None.                                   *
     * Postcondition: None.                                   *
     * Returns:       true if and only if T is an empty tree  *
     *                                                        *
     *********************************************************/

    // DO NOT CHANGE THIS METHOD
    public boolean IsEmpty() {
	return isEmpty;
    }
    
    
    /***********************************************************************
     *                                                                      *
     * Precondition:   The tree is a Binary Search Tree                     *
     * Postconditions: inData is inserted into the tree, which remains  a   *
     *                 Binary Search Tree                                   *
     *                                                                      *
     ***********************************************************************/

    // DO NOT CHANGE THIS METHOD
    public void Insert(T inData) {
	if (IsEmpty()) {
	    left = new BST<T>();
	    right = new BST<T>();
	    key = inData;
	    isEmpty = false;
	}
	else if (inData.compareTo(key) < 0)
	    left.Insert(inData);
	else
	    right.Insert(inData);
    }
    

    /************************************************************
     *							        *
     * Method:        Lookup					*
     * Precondition:  none					*
     * Postcondition: none					*
     * Returns:       true if tree has a node containing inData *
     *                false otherwise			        *
     *							        *
     ************************************************************/

    // DO NOT CHANGE THIS METHOD
    public boolean Lookup(T inData) {
	if (IsEmpty())
	    return false;
	else if (inData.equals(key))
	    return true;
	else if (inData.compareTo(key) < 0)
	    return left.Lookup(inData);
	else
	    return right.Lookup(inData);
    }
 

    // COMPLETE THE METHODS BELOW:
    
    
    /*****************************************************
     *						         *
     * Method:        FindMin			         *
     * Precondition:  none			         *
     * Postcondition: none			         *
     * Returns:       a reference to the minimum value   *
     *                in the BST or null if the BST is   *
     *                is empty.                          *
     * RUNNING TIME:                                     *
     *****************************************************/
    
    // COMPLETE THIS METHOD
    // The running time on a good BST is O(log(n)).
    public T  FindMin(){
    	if(!IsEmpty()){
    		if(!left.IsEmpty())
    			return left.FindMin();
    		else
    			return key;
    	}else
    		return null;
	
    }
    
    
    /****************************************************************
     *							            *
     * Method:        Remove	                                    *
     * Purpose:       remove a node containing inData from the tree *
     * Precondition:  tree is a Binary Search Tree                  *
     * Postcondition: node containing inData is removed IF inData   *
     *                was in the tree                               *
     * RUNNING TIME:                                                *
     ****************************************************************/

    // COMPLETE THIS METHOD
    // The running time is O(log(n))
    public void Remove(T inData){
	// hint: if necessary, call FindMin on the right subtree
    	if(!IsEmpty()){
    		if(inData.compareTo(key) == 0){
    			// Case 1: no children
    			if(left.IsEmpty() && right.IsEmpty())
    				isEmpty = true;
    			// Case 2: one child
    			else if(left.IsEmpty() && !right.IsEmpty()){
    				key = right.key;
    				left = right.left;
    				right = right.right;
    			}
    			else if(!left.IsEmpty() && right.IsEmpty()){
    				key = left.key;
    				right = left.right;
    				left = left.left;
    			}
    			// Case 3:
    			else if(!left.IsEmpty() && !right.IsEmpty()){
    				T tmp = right.FindMin();
    				right.Remove(tmp);
    				key = tmp;
    			}
    			// None of above: ERROR
    			else
    				System.out.println("Remove error: "+ inData);
    		}
    		// Not in this node, look for inData in its children
    		else{
    			if(inData.compareTo(key) < 0)
    				left.Remove(inData);
    			else
    				right.Remove(inData);
    		}
    	}
    }
    
    
    
    /****************************************************************
     *				                                    *
     * Method:        Print					    *
     * Purpose:       print the entries in the BST in alphabetical  *
     *                order                                         *
     * Precondition:  none                               	    *
     * Postcondition: the entries of the BST are printed, one to a  *
     *                line, in alphabetical	order               *
     * RUNNING TIME:                                                *
     ****************************************************************/

    // COMPLETE THIS METHOD
    // The running time on Print is O(n).
    public void Print(){
	// hint: use a (recursive) tree traversal
    	if(!IsEmpty()){
    		left.Print();
    		System.out.printf(key+" ");
    		right.Print();
    	}
    }
}
