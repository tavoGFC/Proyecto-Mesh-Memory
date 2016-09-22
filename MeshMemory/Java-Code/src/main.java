

public class main {

	public static void main(String[] args) {
		System.out.println("Hello Jupiter!!");
		
		DoublyLinkedList doublyList = new DoublyLinkedList();
		
		double doubleVar = 49494994;
		byte byteVar = 16;
		short shortVar = 34;
		int intVar = 5;
		long longVar = 7777777;
		float floatVar = 45;
		boolean boolVar = true;
		char charVar = 'J';
		String stringVar = "Neptuno";
		
//		doublyList.insertAtEnd(doubleVar);
//		doublyList.insertAtEnd(stringVar);
//		doublyList.insertAtEnd(intVar);
//		doublyList.insertAtEnd(boolVar);
//		doublyList.insertAtEnd(floatVar);
//		doublyList.insertAtBeginning(longVar);
//		doublyList.insertAtBeginning(byteVar);
//		doublyList.insertAtBeginning(charVar);
//		doublyList.insertAtEnd(shortVar);
		
		doublyList.makeList(8, "int");
		doublyList.print();
		int largo = doublyList.getLength();
		System.out.println(largo);
		
		doublyList.dataToList(stringVar);
		doublyList.dataToList(stringVar);
		doublyList.dataToList(stringVar);
		doublyList.dataToList(stringVar);
		
		doublyList.print();
		int largo1 = doublyList.getLength();
		System.out.println(largo1);

		/**
		 * 1. LA LISTA TIENE MUCHOS METODOS, PERO ES MUY SIMPLE DE USAR
		 * 
		 * 2. EL METODO makeLIst(int size, string type) RECIBE UN ENTERO CON LA 
		 * CANTIDAD DE ESPACIOS A CREAR, Y EL TIPO ES PARA VERIFICAR QUE SEA SOLO DE
		 * ESE TIPO. 
		 * 
		 * 3. EL METODO dataToList(T data) RECIBE CUALQUIER TIPO DE DATO PARA CUALQUIER LISTA
		 * CON CUALQUIER DATO, Y BORRA EL PRIMER ELEMENTO NULL Y AGREGA AL FINAL EL ELEMENTO QUE
		 * VA INSERTAR, EL COMPITA VERIFICA QUE NO SEA NULL PARA INSERTAR, EN CUALQUIER OTRO CASO
		 * LA LISTA ESTA LLENA Y NO SE PUEDE MODIFICAR MAS. 
		 */

		

	}

}
