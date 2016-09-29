

public class main {

	public static void main(String[] args) {
		System.out.println("Hello Jupiter!!");
		
		DoublyLinkedList<Integer> doublyInt = new DoublyLinkedList<Integer>();
		//DoublyLinkedList<String> doublyString = new DoublyLinkedList<String>();
		//DoublyLinkedList<Float> doublyFloat= new DoublyLinkedList<Float>();
		//DoublyLinkedList<Double> doublyDouble = new DoublyLinkedList<Double>();
		//DoublyLinkedList<Character> doublyChar = new DoublyLinkedList<Character>();
		
		doublyInt.makeList(6, "int");
		doublyInt.print();
		doublyInt.dataToList(67);
		doublyInt.print();
		int len = doublyInt.getLength();
		System.out.println(len);
		System.out.println(doublyInt.getItem(0));
		
		
		


	}

}
