/**
 * Class for the double nodes,
 * linear data structure.
 * 
 * @author Randy
 *
 * @param <T>: generic object
 */

public class DoublyNodeString {
	
	
	private DoublyNodeString next; // basic node for next
	private DoublyNodeString prev;
	private String data; 			//data/element to be inserted
	
	
	
	/**
	 * Construct an element (data) for the list.
	 * 
	 * @param data
	 */
	public DoublyNodeString(String data) {
		this.data = data;
	}
	
		/**
	 * Set the next node in the list. 
	 * 
	 * @param next
	 */
	public void setNext(DoublyNodeString next) {
		this.next = next;
	}
	
	/**
	 * Set the previous node in the list. 
	 * 
	 * @param prev
	 */
	public void setPrev(DoublyNodeString prev){
		this.prev = prev;
	}
	
	/**
	 * Returns the next node in the list. 
	 * 
	 * @return next (node)
	 */
	public DoublyNodeString getNext() {
		return next;
	}
	
	/**
	 * Return the previous node in the list.
	 * 
	 * @return prev (node)
	 */
	public DoublyNodeString getPrev(){
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
