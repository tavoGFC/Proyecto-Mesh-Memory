package xmlToJson;

/**
 * 
 * @author Fernanda
 *
 */

public class listaDoble {

	nodo cabeza;
	nodo fin;
	
	/**
	 * Constructor de la clase Lista
	 */
	public listaDoble(){
		cabeza = null;
		fin = null;
	}
	 
	/*
	 * Verifica si la lista está vacia
	 */
	private boolean estaVacia(){
		
		boolean vacia = false;
		if (cabeza == null){
			vacia = true;
		}
		return vacia;
	}
	
	/**
	 * Enlaza los nodos que se van agregando
	 * @param nodoA
	 * @param nodoB
	 */
	private void enlazar(nodo nodoA, nodo nodoB){
		
		nodoA.next = nodoB;
		nodoB.prev = nodoA;
		
	}
	
	/**
	 * Agrega un nuevo objeto al inicio de la lista
	 * @param ndato Es el objeto que se va a agregar en la lista
	 */
	public void interInicio(String ndato){
		
		nodo nuevo = new nodo (ndato);
		if( estaVacia()){
			cabeza = nuevo;
			fin = nuevo;
		}
		else{
			enlazar(nuevo, cabeza);
			cabeza = nuevo;
		}
	}
	
	/**
	 * Agrega un nuevo objeto al final de la lista
	 * @param ndato Es el objeto que se va a agregar en la lista
	 */
	public void insertFin(String ndato){
			
		nodo nuevo = new nodo (ndato);
		if( estaVacia()){
			cabeza = nuevo;
			fin = nuevo;
		}
		else{
			enlazar(fin, nuevo);
			fin = nuevo;
			}
		}
		
		/**
		 * Función que elimina un objeto del inicio
		 */
		public void elimInicio(){
			
			if(!estaVacia()){
				nodo primero = cabeza.next;
				if (primero == null){
					cabeza = null;
					fin = null;
				}
				else{
					primero.prev = null;
					cabeza = primero;
				}
			}
		}
		
		/**
		 * Elimina un objeto del final
		 */
		public void elimFinal(){
			if(!estaVacia()){
				nodo ultimo = fin.prev;
				if (ultimo == null){
					cabeza = null;
					fin = null;
				}
				else{
					ultimo.prev = null;
					cabeza = ultimo;
				}
			}
		}
		
		/**
		 * Función que permite buscar ogjetos en la lista
		 * @param dato elemento que se busca en la lista
		 * @return retorna el objeto buscado
		 */
		public nodo busqueda(String dato){
			nodo buscado = null;
			nodo iterador = cabeza;
			while (buscado == null && iterador != null){
				if(iterador.data == dato){
					buscado = iterador;
				}
				iterador = iterador.next;
			}
			return buscado;
		}
		
		/**
		 * Función que muestra todos los objetos contenidos en la lista
		 */
		public void mostrar(){
			nodo iterador = cabeza;
			while (iterador != null){
				System.out.println(iterador.data);
				iterador = iterador.next;
			}
			System.out.println("null");
		}
		
		/**
		 * Funcion que indica cuantos objetos hay en la lista
		 * @return retorna cantidad de elementos de la lista
		 */
		public int largo() {
			int counter = 0; 
			nodo tmp = cabeza;
			
			while (tmp != null) {
				counter++;
				tmp = tmp.getNext();
				}
			return counter;
		}
		
		/**
		 * Función que permite obtener el objeto contenido en el indice indicado
		 * @param i indice del objeto que se quiere obtener
		 * @return retorna objeto en la posición i
		 */
		public String obtener(int i) {
			
			if (cabeza == fin) {
				return cabeza.getData();
			}
			
			else  {
			
				nodo temp = cabeza;
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
		 * Funcion que imprime todos los objetos de la lista
		 */
		public void imprimir(){
			nodo temp;
			temp=this.cabeza;
			if (cabeza==null){
				System.out.println("Lista vacia");
				return;
			}
			while(temp!=this.fin){
				System.out.println(temp.data.toString());
				temp=temp.next;
			}
			System.out.println(this.fin.data.toString());
			
		}
}
