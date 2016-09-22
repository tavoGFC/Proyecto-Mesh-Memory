package xmlToJson;

/**
 * 
 * @author Fernanda
 *
 */

public class nodo {
	
	/**
	 * Atributos de la clase nodo
	 */
	public String data; 
	public nodo next; 
	public nodo prev;
	
	
	/**
	 * Constructor de la clase recive un objeto y lo asigna a su elemento
	 * @param i objeto el cual va a ser adicionado como el elemento
	 */
	public nodo(String i) {
		super();
		this.data = i;
		}
	
		public void setNext(nodo next) {
			this.next = next;
		}
		
		/**
		 * Setea el nodo previo de la lista 
		 * 
		 * @param prev
		 */
		public void setPrev(nodo prev){
			this.prev = prev;
		}
		
		/**
		 * Retorna el nodo siguiente de la lista 
		 * 
		 * @return next (node)
		 */
		public nodo getNext() {
			return next;
		}
		
		/**
		 * Retorna el nodo previo de la lista 
		 * 
		 * @return prev (node)
		 */
		public nodo getPrev(){
			return prev;
		}
		
		/**
		 * Retorna la información del nodo 
		 * 
		 * @return data (info)
		 */
		public String getData() {
			return data;
		}
	}
		
	

	
	
