/**
 * Class for the double nodes,
 * linear data structure.
 * 
 * @author Randy
 *
 * @param <T>: generic object
 */

public class DoublyNodeFloat {
	
	
	private DoublyNodeFloat next; // basic node for next
	private DoublyNodeFloat prev;
	private float data; 			//data/element to be inserted
	
	
	
	/**
	 * Construct an element (data) for the list.
	 * 
	 * @param data
	 */
	public DoublyNodeFloat(float data) {
		this.data = data;
	}
	
		/**
	 * Set the next node in the list. 
	 * 
	 * @param next
	 */
	public void setNext(DoublyNodeFloat next) {
		this.next = next;
	}
	
	/**
	 * Set the previous node in the list. 
	 * 
	 * @param prev
	 */
	public void setPrev(DoublyNodeFloat prev){
		this.prev = prev;
	}
	
	/**
	 * Returns the next node in the list. 
	 * 
	 * @return next (node)
	 */
	public DoublyNodeFloat getNext() {
		return next;
	}
	
	/**
	 * Return the previous node in the list.
	 * 
	 * @return prev (node)
	 */
	public DoublyNodeFloat getPrev(){
		return prev;
	}
	
	/**
	 * Returns the data (info)  of a node.
	 * 
	 * @return data (info)
	 */
	public Object getData() {
		return data;
	}
}
