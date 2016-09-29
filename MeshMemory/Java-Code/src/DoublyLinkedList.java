/**
 * Class for doubly linked list, linear data structure
 * @author Randy
 *
 * @param <T>
 */

public class DoublyLinkedList <T> {
	
	private DoublyNode<T> head = null; //null node for the head of the list
	private DoublyNode<T> tail = null; //null node for the tail of the list
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
		DoublyNode<T> tmp = head;
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
	public void insertAtBeginning(T tData){
		
		DoublyNode<T> data = new DoublyNode<T>(tData);
		
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
	public void insertAtEnd(T tData){
		
		DoublyNode<T> data = new DoublyNode<T>(tData);
		
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

		StringBuilder list = new StringBuilder();
		DoublyNode<T> tmp = head;
		
		while(tmp != null){
			list.append(tmp.getData() + ",");
			tmp = tmp.getNext();
		}
		System.out.println(list);
		
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
			DoublyNode<T> temp = head;
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
	 * Return the search  element, else false.
	 * @param pData
	 * @return pData
	 */
	public Object search(T pData){
		if(isEmpty()){
			return null;
		}else{
			DoublyNode<T> tmp = head; 
			while(tmp != null){
				if(tmp.getData() == pData){
					return tmp;
				}else{
					tmp = tmp.getNext(); 
				} 
			}
			System.out.println("Item not found");
			return null;
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
	
		DoublyNode<T> tmp = head.getNext();
		
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

	/**
	 * Return the search  element, else false.
	 * @param pData
	 * @return pData
	 */
	public boolean contains(String pData){
		boolean bool = false;
		if(isEmpty()){
			return false;
		}else{
			DoublyNode<T> tmp = head; 
			while(tmp != null){
				if(tmp.getData().equals(pData)){
					bool = true;
					return bool;
				}else{
					tmp = tmp.getNext(); 
				} 
			}
			System.out.println("Item not found");
			return bool;
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
	public void makeList(int size, String type){
		if (type == "string"){
			for(int i = 0; i < size; i++){
				String emptyS = "";
				this.insertStrings(emptyS);
			}
		} else if(type == "int" ){
			for(int i = 0; i < size; i++){
				int emptyI = 0;
				this.insertInt(emptyI);
			}
			
		} else if (type == "double"){
			for(int i = 0; i < size; i++){
				double emptyD = 0;
				this.insertDouble(emptyD);
			}
			
		}else if (type == "float"){
			for(int i = 0; i < size; i++){
				float emptyF = 0;
				this.insertFloat(emptyF);
			}
			
		}else if (type == "char"){
			for(int i = 0; i < size; i++){
				char emptyC = 0;
				this.insertChar(emptyC);
			}
			
		}
		
	}
	
	/**
	 * Verifies is it is possible to add data to the list, 
	 * removes the null from the list and inser the data, 
	 * else send a message the list is full. 
	 * @param tdata
	 */
	public void dataToList(T tdata){
		int len = this.getLength() -1 ;
		if (this.getItem(len) == null){
			this.removeAtEnd();
			this.insertAtBeginning(tdata);
		}else{
			System.out.println("ERROR: the list is full");
		}
	}
	
	
	/**
	 * Insert a String (tData) at the end of the list.
	 * 
	 * @param tData
	 */
	public void insertStrings(String tData){
		
		DoublyNode<T> data = new DoublyNode<T>(tData);
		
		if(isEmpty()){
			head = tail = data;
		}else{
			tail.setNext(data); //tail.next = data;
			data.setPrev(tail); //data.prev = tail;
		}
		tail = data; //tail = head;
	}
	

	/**
	 * Insert a int (tData) at the end of the list.
	 * 
	 * @param tData
	 */
	public void insertInt(int tData){
		
		DoublyNode<T> data = new DoublyNode<T>(tData);
		
		if(isEmpty()){
			head = tail = data;
		}else{
			tail.setNext(data); //tail.next = data;
			data.setPrev(tail); //data.prev = tail;
		}
		tail = data; //tail = head;
	}
	

	/**
	 * Insert a Double (tData) at the end of the list.
	 * 
	 * @param tData
	 */
	public void insertDouble(double tData){
		
		DoublyNode<T> data = new DoublyNode<T>(tData);
		
		if(isEmpty()){
			head = tail = data;
		}else{
			tail.setNext(data); //tail.next = data;
			data.setPrev(tail); //data.prev = tail;
		}
		tail = data; //tail = head;
	}
	
	/**
	 * Insert a float (tData) at the end of the list.
	 * 
	 * @param tData
	 */
	public void insertFloat(float tData){
		
		DoublyNode<T> data = new DoublyNode<T>(tData);
		
		if(isEmpty()){
			head = tail = data;
		}else{
			tail.setNext(data); //tail.next = data;
			data.setPrev(tail); //data.prev = tail;
		}
		tail = data; //tail = head;
	}
	
	/**
	 * Insert a Char (tData) at the end of the list.
	 * 
	 * @param tData
	 */
	public void insertChar(char tData){
		
		DoublyNode<T> data = new DoublyNode<T>(tData);
		
		if(isEmpty()){
			head = tail = data;
		}else{
			tail.setNext(data); //tail.next = data;
			data.setPrev(tail); //data.prev = tail;
		}
		tail = data; //tail = head;
	}

	
	
	/**
	 * Insert a list (DoublyLinkedList) at the end of the list.
	 * 
	 * @param tData
	 */
	public void insertList(DoublyLinkedList<T> doubly){
		
		DoublyNode<T> list = new DoublyNode<T>(doubly);
		
		if(isEmpty()){
			head = tail = list;
		}else{
			tail.setNext(list); //tail.next = data;
			list.setPrev(tail); //data.prev = tail;
		}
		tail = list; //tail = head;
	}
	
}