/**
 * Class for the double nodes,
 * linear data structure.
 * 
 * @author Randy
 *
 * @param <T>: generic object
 */

public class DoublyNodeInt {
	
	
	private DoublyNodeInt next; // basic node for next
	private DoublyNodeInt prev;
	private int data; 			//data/element to be inserted
	
	
	
	/**
	 * Construct an element (data) for the list.
	 * 
	 * @param data
	 */
	public DoublyNodeInt(int data) {
		this.data = data;
	}
	
		/**
	 * Set the next node in the list. 
	 * 
	 * @param next
	 */
	public void setNext(DoublyNodeInt next) {
		this.next = next;
	}
	
	/**
	 * Set the previous node in the list. 
	 * 
	 * @param prev
	 */
	public void setPrev(DoublyNodeInt prev){
		this.prev = prev;
	}
	
	/**
	 * Returns the next node in the list. 
	 * 
	 * @return next (node)
	 */
	public DoublyNodeInt getNext() {
		return next;
	}
	
	/**
	 * Return the previous node in the list.
	 * 
	 * @return prev (node)
	 */
	public DoublyNodeInt getPrev(){
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