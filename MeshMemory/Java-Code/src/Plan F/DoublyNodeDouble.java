/**
 * Class for the double nodes,
 * linear data structure.
 * 
 * @author Randy
 *
 * @param <T>: generic object
 */

public class DoublyNodeDouble {
	
	
	private DoublyNodeDouble next; // basic node for next
	private DoublyNodeDouble prev;
	private double data; 			//data/element to be inserted
	
	
	
	/**
	 * Construct an element (data) for the list.
	 * 
	 * @param data
	 */
	public DoublyNodeDouble(double data) {
		this.data = data;
	}
	
		/**
	 * Set the next node in the list. 
	 * 
	 * @param next
	 */
	public void setNext(DoublyNodeDouble next) {
		this.next = next;
	}
	
	/**
	 * Set the previous node in the list. 
	 * 
	 * @param prev
	 */
	public void setPrev(DoublyNodeDouble prev){
		this.prev = prev;
	}
	
	/**
	 * Returns the next node in the list. 
	 * 
	 * @return next (node)
	 */
	public DoublyNodeDouble getNext() {
		return next;
	}
	
	/**
	 * Return the previous node in the list.
	 * 
	 * @return prev (node)
	 */
	public DoublyNodeDouble getPrev(){
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
