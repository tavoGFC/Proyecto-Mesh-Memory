/**
 * Class for doubly linked list, linear data structure
 * @author Randy
 *
 * @param <T>
 */

public class DoublyLinkedListString {
	
	private DoublyNodeString head = null; //null node for the head of the list
	private DoublyNodeString tail = null; //null node for the tail of the list
	private String id;
	
	
	/**
	 * Set the id of the list (DoublyLinkedList).
	 * 
	 * @param String id
	 */
	
	public void setID(String id){
		this.id = id;
	}
	
	/**
	 * Retur the id of the list (DoublyLinked List).
	 * 
	 * @return id
	 */
	public String getID(){
		return id;
	}
	
	/**
	 * Return the length of the list.
	 * 
	 * @return length (integer)
	 */
	public int getLength() {
		int counter = 0; 
		DoublyNodeString tmp = head;
		while (tmp != null) {
			counter++;
			tmp = tmp.getNext();
			}
		return counter;
		}
		
	/**
	 * Returns a true if empty, else false.
	 * 
	 * @return boolean 
	 */
	public boolean isEmpty(){
		return (head == null);
	}
	
	/**
	 * Insert an element (tData) at the beginning of the list.
	 * 
	 * @param pData
	 */
	public void insertAtBeginning(String tData){
		
		DoublyNodeString data = new DoublyNodeString(tData);
		
		if(isEmpty()){
			head = tail = data;
		}else{
			head.setPrev(data); //head.prev = data;
		}
		data.setNext(head); //data.next = head;
		head = data; //head = data;
	}
	
	/**
	 * Insert an element (tData) at the end of the list.
	 * 
	 * @param tData
	 */
	public void insertAtEnd(String tData){
		
		DoublyNodeString data = new DoublyNodeString(tData);
		
		if(isEmpty()){
			head = tail = data;
		}else{
			tail.setNext(data); //tail.next = data;
			data.setPrev(tail); //data.prev = tail;
		}
		tail = data; //tail = head;
	}
	
	/**
	 * Return a list (type StringBuilder) that shows all the node together.
	 * @return 
	 * 
	 * @return list 
	 */
	public void print(){

		//StringBuilder list = new StringBuilder();
		String data = "";
		DoublyNodeString tmp = head;
		
		while(tmp != null){
			data += tmp.getData() + ",";
			//list.append(tmp.getData() + ",");
			//System.out.println(tmp.getData() + ",");
			tmp = tmp.getNext();
		}
		System.out.println(data);
		
	}
	
	/**
	 * Returns the object in position i.
	 * 
	 * @param i
	 * @return Object
	 */
	public Object getItem(int i) {
		
		if (head == tail) {
			return head.getData();
		}else {
			DoublyNodeString temp = head;
			if (temp != null) {
				for (int j = 0; j != i; j++) {
					
					temp = temp.getNext();
				}
			} else {
				System.out.println("Index out of reach");
				return null;
			}
			return temp.getData();

		}
			
	}
	
	
	/**
	 * Remove the first element of the list. 
	 */
	public void removeAtBeginning(){
		
		//List only has one element
		if (head == tail) {
			head = tail = null;
		} else {
	
		DoublyNodeString tmp = head.getNext();
		
		head = head.getNext();
		head.setNext(tmp.getNext());
		head.setPrev(null);
		}
	}
	/**
	 * Remove the last element of the list. 
	 */
	public void removeAtEnd() {
		//List only has one element
		if (head == tail) {
			head = tail = null;
		} else {
			tail = tail.getPrev();
			tail.setNext(null);			
		}
	}

	//------------------------------------------------------------------------//
	
	/**
	 * From a empty list, adds the type given on aa proportion given by the size, 
	 * "keeping" the memory ready to use. 
	 * 
	 * @param size
	 * @param type
	 */
	public void makeList(int size){
		for(int i = 0; i < size; i++){
			String emptyS = "empty";
			this.insertAtBeginning(emptyS);
		}
	}
				
	
	
	/**
	 * Verifies is it is possible to add data to the list, 
	 * removes the null from the list and inser the data, 
	 * else send a message the list is full. 
	 * @param tdata
	 */
	public void dataToList(String tdata){
		int len = this.getLength() -1 ;
		if (this.getItem(len) == null){
			this.removeAtEnd();
			this.insertAtBeginning(tdata);
		}else{
			System.out.println("ERROR: the list is full");
		}
	}
	
}