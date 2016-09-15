package xmlToJson;



/**
 * 
 * @author Ricardo
 *
 */
public class separador {

	public separador() {	}
	
	/**
	 * separa la informacion que contiene un string, esta 
	 * informacion debe estar separada por el signo "/", por ejemplo "hola/como/estas" e inserta esta 
	 * informacion en una lista
	 * @param mensaje
	 * @return
	 */
	public listaDoble separar(String mensaje){
		listaDoble lista=new listaDoble();
		int i=0;
		int j=0;
		String temp;
		while (j<mensaje.length()){
			if (mensaje.charAt(j)=='/'){
				temp=mensaje.substring(i,j);
				lista.insertFin(temp);
				i=j+1;
				j++;
			}
			else{
				j++;
			}
		}
		temp=mensaje.substring(i,j);
		lista.insertFin(temp);
		return lista;
	}
}