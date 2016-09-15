package xmlToJson;

public class nodo {
	 
	public String data; 
	public nodo next; 
	public nodo prev;
	
	
	public nodo(String i) {
		super();
		this.data = i;
		}
	
		public void setNext(nodo next) {
			this.next = next;
		}
		
		/**
		 * Set the previous node in the list. 
		 * 
		 * @param prev
		 */
		public void setPrev(nodo prev){
			this.prev = prev;
		}
		
		/**
		 * Returns the next node in the list. 
		 * 
		 * @return next (node)
		 */
		public nodo getNext() {
			return next;
		}
		
		/**
		 * Return the previous node in the list.
		 * 
		 * @return prev (node)
		 */
		public nodo getPrev(){
			return prev;
		}
		
		/**
		 * Returns the data (info)  of a node.
		 * 
		 * @return data (info)
		 */
		public String getData() {
			return data;
		}
	}
		
	

	
	
