package xmlToJson;
;

public class listaDoble {

	nodo cabeza;
	nodo fin;
	
	public listaDoble(){
		cabeza = null;
		fin = null;
	}
	 
	private boolean estaVacia(){
		
		boolean vacia = false;
		if (cabeza == null){
			vacia = true;
		}
		return vacia;
	}
	
	private void enlazar(nodo nodoA, nodo nodoB){
		
		nodoA.next = nodoB;
		nodoB.prev = nodoA;
		
	}
	
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
		
		public void mostrar(){
			nodo iterador = cabeza;
			while (iterador != null){
				System.out.println(iterador.data);
				iterador = iterador.next;
			}
			System.out.println("null");
		}
		
		public int largo() {
			int counter = 0; 
			nodo tmp = cabeza;
			
			while (tmp != null) {
				counter++;
				tmp = tmp.getNext();
				}
			return counter;
		}
		
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

		public void Imprimir(){
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
