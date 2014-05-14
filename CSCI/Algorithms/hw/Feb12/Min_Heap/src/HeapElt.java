/**
 * A generic class for heap elements that include handles
 */

public class HeapElt {

    protected Comparable record;

    protected int handle = 0;

    public void setRecord(Comparable inRec){
	record = inRec;
    }

    public Comparable getRecord() {
	return record;
    }

    public void setHandle(int inHandle){
	handle = inHandle;
    }

    public int getHandle() {
	return handle;
    }

}

