/**
 * Class for the double nodes,
 * linear data structure.
 * 
 * @author Randy
 *
 * @param <T>: generic object
 */

public class DoublyNode<T> {
	
	
	private DoublyNode<T> next; // basic node for next
	private DoublyNode<T> prev;
	private T data; 			//data/element to be inserted
	private String dataS;
	private int dataI;
	private double dataD;
	private float dataF;
	private char dataC;
	private DoublyLinkedList<T> list;
	
	
	
	/**
	 * Construct an element (data) for the list.
	 * 
	 * @param data
	 */
	public DoublyNode (T data) {
		this.data = data;
	}
	
	/**
	 * Construct an element (data) for the list.
	 * 
	 * @param data
	 */
	public DoublyNode (String data) {
		this.dataS = data;
	}
	
	/**
	 * Construct an element (data) for the list.
	 * 
	 * @param data
	 */
	public DoublyNode (int data) {
		this.dataI = data;
	}
	
	/**
	 * Construct an element (data) for the list.
	 * 
	 * @param data
	 */
	public DoublyNode (double data) {
		this.dataD = data;
	}
	
	/**
	 * Construct an element (data) for the list.
	 * 
	 * @param data
	 */
	public DoublyNode (float data) {
		this.dataF = data;
	}
	
	/**
	 * Construct an element (data) for the list.
	 * 
	 * @param data
	 */
	public DoublyNode (char data) {
		this.dataC = data;
	}
	
	
	/**
	 * Construct an element (data) for the list.
	 * 
	 * @param data
	 */
	public DoublyNode(DoublyLinkedList<T> list) {
		this.list = list;
	}

	/**
	 * Set the next node in the list. 
	 * 
	 * @param next
	 */
	public void setNext(DoublyNode<T> next) {
		this.next = next;
	}
	
	/**
	 * Set the previous node in the list. 
	 * 
	 * @param prev
	 */
	public void setPrev(DoublyNode<T> prev){
		this.prev = prev;
	}
	
	/**
	 * Returns the next node in the list. 
	 * 
	 * @return next (node)
	 */
	public DoublyNode<T> getNext() {
		return next;
	}
	
	/**
	 * Return the previous node in the list.
	 * 
	 * @return prev (node)
	 */
	public DoublyNode<T> getPrev(){
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
